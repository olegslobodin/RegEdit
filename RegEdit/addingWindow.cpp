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
		/*RegistryKey ^parentKey, ^newKey;
		if (node->Parent)
			parentKey = (RegistryKey^)node->Parent->Tag;
		key->Close();
		if (parentKey)
			newKey = parentKey->OpenSubKey("Description", RegistryKeyPermissionCheck::ReadWriteSubTree, Security::AccessControl::RegistryRights::WriteKey);
	*/
		key->CreateSubKey(textBox1->Text);
	}
}