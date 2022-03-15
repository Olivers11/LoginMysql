#pragma once
#include "DB.h";
#include "Registro.h";

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txt_name;
	protected:
	private: System::Windows::Forms::TextBox^ txt_pass;
	private: System::Windows::Forms::Button^ btn_login;
	private: System::Windows::Forms::Button^ btn_reg;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_pass = (gcnew System::Windows::Forms::TextBox());
			this->btn_login = (gcnew System::Windows::Forms::Button());
			this->btn_reg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txt_name
			// 
			this->txt_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_name->Location = System::Drawing::Point(84, 64);
			this->txt_name->Multiline = true;
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(213, 41);
			this->txt_name->TabIndex = 0;
			// 
			// txt_pass
			// 
			this->txt_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_pass->Location = System::Drawing::Point(84, 165);
			this->txt_pass->Multiline = true;
			this->txt_pass->Name = L"txt_pass";
			this->txt_pass->Size = System::Drawing::Size(213, 41);
			this->txt_pass->TabIndex = 1;
			// 
			// btn_login
			// 
			this->btn_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_login->Location = System::Drawing::Point(84, 266);
			this->btn_login->Name = L"btn_login";
			this->btn_login->Size = System::Drawing::Size(213, 39);
			this->btn_login->TabIndex = 2;
			this->btn_login->Text = L"Login";
			this->btn_login->UseVisualStyleBackColor = true;
			this->btn_login->Click += gcnew System::EventHandler(this, &Form1::btn_login_Click);
			// 
			// btn_reg
			// 
			this->btn_reg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reg->Location = System::Drawing::Point(84, 311);
			this->btn_reg->Name = L"btn_reg";
			this->btn_reg->Size = System::Drawing::Size(213, 39);
			this->btn_reg->TabIndex = 3;
			this->btn_reg->Text = L"Registrar";
			this->btn_reg->UseVisualStyleBackColor = true;
			this->btn_reg->Click += gcnew System::EventHandler(this, &Form1::btn_reg_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(406, 398);
			this->Controls->Add(this->btn_reg);
			this->Controls->Add(this->btn_login);
			this->Controls->Add(this->txt_pass);
			this->Controls->Add(this->txt_name);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_login_Click(System::Object^ sender, System::EventArgs^ e) {
		DB^ database = gcnew DB();
		if (database->exist(txt_name->Text, txt_pass->Text)) {
			MessageBox::Show("Bienvenido!");
		}
		else {
			MessageBox::Show("Usuario no existente :C");
		}
		
	}
	private: System::Void btn_reg_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginMysql::Registro^ registro = gcnew LoginMysql::Registro();
		this->Visible = false;
		registro->ShowDialog();
		this->Visible = true;
	}
};
}
