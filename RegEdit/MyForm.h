#pragma once

namespace RegEdit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace Microsoft::Win32;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	private: System::Windows::Forms::ToolStripMenuItem^  removeSectionToolStripMenuItem;
	public:

		Thread^ monitor;
		void loadTree();
		void setMonitor();
		static void loadSubTree(TreeNode ^node);
		void selectedKeyRead();
		void editValue();
		void addValue(bool itIsSection);
		void removeValue(bool itIsSection);
	public: static array<String^>^ MyForm::readKeyValue(RegistryKey ^key, String^ name);

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TreeView^  treeView1;
	protected:

	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::ContextMenuStrip^  TableMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column_Value;
	private: System::Windows::Forms::ToolStripMenuItem^  addSectionStripMenuItem;
	private: System::ComponentModel::IContainer^  components;



	protected:

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column_Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column_Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TableMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addSectionStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeSectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->TableMenuStrip->SuspendLayout();
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
			this->treeView1->Click += gcnew System::EventHandler(this, &MyForm::treeView1_Click);
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
			this->dataGridView1->ContextMenuStrip = this->TableMenuStrip;
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
			this->Column_Name->HeaderText = L"Name";
			this->Column_Name->Name = L"Column_Name";
			this->Column_Name->ReadOnly = true;
			// 
			// Column_Type
			// 
			this->Column_Type->HeaderText = L"Type";
			this->Column_Type->Name = L"Column_Type";
			this->Column_Type->ReadOnly = true;
			// 
			// Column_Value
			// 
			this->Column_Value->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column_Value->HeaderText = L"Value";
			this->Column_Value->Name = L"Column_Value";
			this->Column_Value->ReadOnly = true;
			// 
			// TableMenuStrip
			// 
			this->TableMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->editToolStripMenuItem,
					this->addToolStripMenuItem, this->addSectionStripMenuItem, this->removeToolStripMenuItem, this->removeSectionToolStripMenuItem
			});
			this->TableMenuStrip->Name = L"TableMenuStrip";
			this->TableMenuStrip->Size = System::Drawing::Size(175, 114);
			this->TableMenuStrip->Opened += gcnew System::EventHandler(this, &MyForm::TableMenuStrip_Opened);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->editToolStripMenuItem->Text = L"Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::editToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->addToolStripMenuItem->Text = L"Add Parameter";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addToolStripMenuItem_Click);
			// 
			// addSectionStripMenuItem
			// 
			this->addSectionStripMenuItem->Name = L"addSectionStripMenuItem";
			this->addSectionStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->addSectionStripMenuItem->Text = L"Add Section";
			this->addSectionStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addSectionStripMenuItem_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->removeToolStripMenuItem->Text = L"Remove Parameter";
			this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::removeToolStripMenuItem_Click);
			// 
			// removeSectionToolStripMenuItem
			// 
			this->removeSectionToolStripMenuItem->Name = L"removeSectionToolStripMenuItem";
			this->removeSectionToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->removeSectionToolStripMenuItem->Text = L"Remove Section";
			this->removeSectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::removeSectionToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 313);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->treeView1);
			this->Name = L"MyForm";
			this->Text = L"RegEdit";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->TableMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		loadTree();
		setMonitor();
	}

	private: System::Void treeView1_BeforeExpand(System::Object^  sender, System::Windows::Forms::TreeViewCancelEventArgs^  e) {
		for each(TreeNode ^childNode in e->Node->Nodes)
			loadSubTree(childNode);
	}

	private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		selectedKeyRead();
	}

	private: System::Void dataGridView1_CellDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		editValue();
	}

	private: System::Void treeView1_Click(System::Object^  sender, System::EventArgs^  e) {
		selectedKeyRead();
	}

	private: System::Void TableMenuStrip_Opened(System::Object^  sender, System::EventArgs^  e) {
		if (dataGridView1->SelectedCells->Count == 0)
		{
			TableMenuStrip->Items[0]->Enabled = false;
			TableMenuStrip->Items[3]->Enabled = false;
		}
		else
		{
			TableMenuStrip->Items[0]->Enabled = true;
			TableMenuStrip->Items[3]->Enabled = true;
		}
		if (treeView1->SelectedNode == nullptr)
		{
			TableMenuStrip->Items[1]->Enabled = false;
			TableMenuStrip->Items[2]->Enabled = false;
		}
		else
		{
			TableMenuStrip->Items[1]->Enabled = true;
			TableMenuStrip->Items[2]->Enabled = true;
		}
	}

	private: System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		editValue();
	}

	private: System::Void addToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		addValue(false);
	}

	private: System::Void addSectionStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		addValue(true);
	}

	private: System::Void removeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		removeValue(false);
	}

	private: System::Void removeSectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		removeValue(true);
	}
	};
}
