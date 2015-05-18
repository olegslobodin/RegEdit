#include "addingWindow.h"

using namespace RegEdit;

void addingWindow::initialize()
{
	InitializeComponent();
	button1->Enabled = false;
	if (itIsSection)
	{
		this->groupBox1->Hide();
		this->Size = this->MinimumSize;
	}
}

void addingWindow::add()
{
	if (itIsSection)
	{
		try
		{
			key->CreateSubKey(textBox1->Text);
		}
		catch (System::UnauthorizedAccessException^ e)
		{
			try
			{
				RegistryKey^ parentKey = (RegistryKey^)node->Parent->Tag;
				key = parentKey->OpenSubKey(node->Text, true);
				key->CreateSubKey(textBox1->Text);
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message);
			}
		}
		f->loadSubTree(node);
		for each(TreeNode ^childNode in node->Nodes)
			f->loadSubTree(childNode);
	}
	else
	{
		RegistryValueKind type;
		Object^ value = "";
		if (radioButton1->Checked)
			type = RegistryValueKind::String;
		if (radioButton2->Checked)
		{
			type = RegistryValueKind::Binary;
			array<Byte>^ arr = gcnew array<Byte>(1);
			arr[0] = 0;
			value = arr;
		}
		if (radioButton3->Checked)
		{
			type = RegistryValueKind::DWord;
			value = 0;
		}
		if (radioButton4->Checked)
		{
			type = RegistryValueKind::QWord;
			value = 0;
		}
		if (radioButton5->Checked)
		{
			type = RegistryValueKind::MultiString;
			array<String^>^ arr = gcnew array<String^>(1);
			arr[0] = "";
			value = arr;
		}
		if (radioButton6->Checked)
			type = RegistryValueKind::ExpandString;

		key->SetValue(textBox1->Text, value, type);
		f->selectedKeyRead();			//refresh table
	}
	this->Close();
}