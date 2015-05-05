#include "Editor.h"
#include <Windows.h>

using namespace RegEdit;

String^ baseConvert(String^ source, int old_base, int new_base);
int myAtoi(char c);

void Editor::initialize()
{
	InitializeComponent();
	base = 0;
	textBox1->Text = paramName;
	switch (key->GetValueKind(paramName))
	{
	case RegistryValueKind::Binary:
		buildGUI(true, false, true);
		base = 16;
		break;
	case RegistryValueKind::DWord:
		buildGUI(false, true, true);
		base = (radioButton1->Checked) ? 16 : 10;
		textBox2->MaxLength = (base == 16) ? 8 : 10;
		break;
	case RegistryValueKind::QWord:
		buildGUI(false, true, true);
		base = (radioButton1->Checked) ? 16 : 10;
		textBox2->MaxLength = (base == 16) ? 16 : 20;
		break;
	case RegistryValueKind::String:
		buildGUI(false, false, false);
		break;
	case RegistryValueKind::ExpandString:
		buildGUI(false, false, false);
		break;
	case RegistryValueKind::MultiString:
		buildGUI(true, false, false);
		break;
	}
}

void Editor::buildGUI(bool multiline, bool showRadix, bool UpperCase)
{
	textBox2->Multiline = multiline;
	textBox2->Width = (showRadix) ? 220 : 380;
	textBox2->CharacterCasing = (UpperCase) ? CharacterCasing::Upper : CharacterCasing::Normal;
	lines = MyForm::readKeyValue(key, paramName);
	textBox2->Lines = lines;
	groupBox1->Visible = showRadix;
	this->Size = (multiline) ? this->MaximumSize : this->MinimumSize;
}

void Editor::changeBase(int base){
	this->base = base;		//new_base
	if (base == 16)
	{
		textBox2->MaxLength = (key->GetValueKind(paramName) == RegistryValueKind::DWord) ? 8 : 16;
		textBox2->Text = baseConvert(textBox2->Text, 10, 16);
	}
	else
	{
		textBox2->MaxLength = (key->GetValueKind(paramName) == RegistryValueKind::DWord) ? 10 : 20;
		textBox2->Text = baseConvert(textBox2->Text, 16, 10);
	}
}

String^ baseConvert(String^ source, int old_base, int new_base)
{
	UInt64 temp = 0;
	for each(char c in source)
	{
		temp *= old_base;
		temp += myAtoi(c);
	}
	char s[100];
	int i = 0;

	while (temp > 0)
	{
		int d = temp % new_base;
		char c = (d < 10) ? d + '0' : d + 'A' - 10;
		s[i++] = c;
		s[i] = 0;
		temp /= new_base;
	}

	for (int j = 0; j < i / 2; j++)		//reverse
	{
		char c = s[i - j - 1];
		s[i - j - 1] = s[j];
		s[j] = c;
	}
	return gcnew String(s);
}

void Editor::saveChanges()
{
	lines = textBox2->Lines;
	array<Byte>^ bytes = gcnew array<Byte>(lines[0]->Length / 2);

	switch (key->GetValueKind(paramName))
	{
	case RegistryValueKind::MultiString:
		key->SetValue(paramName, (Object^)lines, RegistryValueKind::MultiString);
		break;
	case RegistryValueKind::Binary:
		for (int i = 0; i < lines[0]->Length; i += 2)
		{
			int temp = myAtoi(lines[0][i]);
			if (i + 1 < lines[0]->Length)
			{
				temp *= 16;
				temp += myAtoi(lines[0][i + 1]);
			}
			bytes[i / 2] = (Byte)temp;
		}
		key->SetValue(paramName, (Object^)bytes);
		break;
	default:
		key->SetValue(paramName, (Object^)lines[0], key->GetValueKind(paramName));
	}
	mainForm->selectedKeyRead();
	this->Close();
}

int myAtoi(char c)
{
	int temp;
	if (c >= '0' && c <= '9')
		temp = c - '0';
	else if (c >= 'a'&& c <= 'z')
		temp = c - 'a' + 10;
	else if (c >= 'A'&& c <= 'Z')
		temp = c - 'A' + 10;
	return temp;
}