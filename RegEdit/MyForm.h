#pragma once

namespace RegEdit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Win32;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		static void loadSubTree(TreeNode ^node);
		void selectedKeyRead();
		void editValue();
	public: static array<String^>^ MyForm::readKeyValue(RegistryKey ^key, String^ name);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Value;



	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column_Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(12, 12);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(180, 289);
			this->treeView1->TabIndex = 0;
			this->treeView1->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &MyForm::treeView1_BeforeExpand);
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::treeView1_AfterSelect);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column_Name,
					this->Column_Type, this->Column_Value
			});
			this->dataGridView1->Location = System::Drawing::Point(198, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(393, 289);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellDoubleClick);
			// 
			// Column_Name
			// 
			this->Column_Name->HeaderText = L"Имя";
			this->Column_Name->Name = L"Column_Name";
			this->Column_Name->ReadOnly = true;
			// 
			// Column_Type
			// 
			this->Column_Type->HeaderText = L"Тип";
			this->Column_Type->Name = L"Column_Type";
			this->Column_Type->ReadOnly = true;
			// 
			// Column_Value
			// 
			this->Column_Value->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column_Value->HeaderText = L"Значение";
			this->Column_Value->Name = L"Column_Value";
			this->Column_Value->ReadOnly = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 313);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->treeView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		void loadTree();

	private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		loadTree();
	}

	private: System::Void treeView1_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) {
		for each(TreeNode ^childNode in e->Node->Nodes)
		{
			if (childNode->Nodes->Count == 0)
				loadSubTree(childNode);
		}
	}

	private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		selectedKeyRead();
	}

	private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		editValue();
	}
	};
}
