#include "MyForm.h"
#include <Windows.h>

using namespace RegEdit;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

void MyForm::loadTree()
{
	TreeNode ^Root = gcnew TreeNode("HKEY_CLASSES_ROOT");
	Root->Tag = Registry::ClassesRoot;
	treeView1->Nodes->Add(Root);
	loadSubTree(Root);

	TreeNode ^Current_user = gcnew TreeNode("HKEY_CURRENT_USER");
	Current_user->Tag = Registry::CurrentUser;
	treeView1->Nodes->Add(Current_user);
	loadSubTree(Current_user);


	TreeNode ^Local_Machine = gcnew TreeNode("HKEY_LOCAL_MACHINE");
	Local_Machine->Tag = Registry::LocalMachine;
	treeView1->Nodes->Add(Local_Machine);
	loadSubTree(Local_Machine);


	TreeNode ^Users = gcnew TreeNode("HKEY_USERS");
	Users->Tag = Registry::Users;
	treeView1->Nodes->Add(Users);
	loadSubTree(Users);


	TreeNode ^Current_config = gcnew TreeNode("HKEY_CURRENT_CONFIG");
	Current_config->Tag = Registry::CurrentConfig;
	treeView1->Nodes->Add(Current_config);
	loadSubTree(Current_config);
}

void MyForm::loadSubTree(TreeNode ^node)
{
	if (node->GetNodeCount(false) > 0)
		return;
	RegistryKey ^key = (RegistryKey^)node->Tag;
	array<String^>^ a = key->GetSubKeyNames();
	for each(String^ name in a)
	{
		TreeNode ^child = gcnew TreeNode(name);
		try{
			child->Tag = key->OpenSubKey(name, RegistryKeyPermissionCheck::Default, Security::AccessControl::RegistryRights::ReadKey);
			node->Nodes->Add(child);
		}
		catch (...){}
	}
}

void MyForm::selectedKeyRead()
{
	RegistryKey ^key = (RegistryKey^)treeView1->SelectedNode->Tag;
	if (!key)
		return;
	dataGridView1->Rows->Clear();
	for each(String^ name in key->GetValueNames())
	{
		dataGridView1->Rows->Add(name, key->GetValueKind(name), key->GetValue(name));
	}
}