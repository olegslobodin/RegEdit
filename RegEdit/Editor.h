#pragma once

#include "MyForm.h"

namespace RegEdit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Win32;

	/// <summary>
	/// Сводка для Editor
	/// </summary>
	public ref class Editor : public System::Windows::Forms::Form
	{
	public:
		Editor(RegistryKey ^key, String ^name)
		{
			this->key = key;
			this->paramName = name;
			initialize();
		}

		void initialize();
		void buildGUI(bool multiline, bool showRadix, bool UpperCase);
		void changeBase(int base);
		void saveChanges();
		int base;
		bool wrongSymbolPrinted;
		String^ OldTextTB2;
		RegistryKey^ key;
		String^ paramName;
		array<String^>^ lines;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	public:
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Editor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(12, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(380, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 68);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(380, 153);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Editor::textBox2_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Editor::textBox2_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Параметр";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Значение";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(236, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Ок";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Editor::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(317, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Editor::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(238, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(154, 70);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Система счисления";
			this->groupBox1->Visible = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(7, 43);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(86, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Десятичная";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(7, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(127, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->Text = L"Шестнадцатиричная";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Editor::radioButton1_CheckedChanged);
			// 
			// Editor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 262);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(420, 300);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(420, 200);
			this->Name = L"Editor";
			this->Text = L"Editor";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (wrongSymbolPrinted)
		{
			textBox2->Text = OldTextTB2;
			wrongSymbolPrinted = false;
			textBox2->SelectionStart = textBox2->Text->Length;
		}
	}

	private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		wchar_t c = e->KeyChar;
		OldTextTB2 = textBox2->Text;
		switch (base)
		{
		case 16:
			if (!(c == '\b' || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')))
				wrongSymbolPrinted = true;
			break;
		case 10:
			if (!(c == '\b' || (c >= '0' && c <= '9')))
				wrongSymbolPrinted = true;
			break;
		}
	}

	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (radioButton1->Checked)
			changeBase(16);
		else
			changeBase(10);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		saveChanges();
	}
	};
}
