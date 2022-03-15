#pragma once
#include "DB.h";

namespace LoginMysql {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Registro
	/// </summary>
	public ref class Registro : public System::Windows::Forms::Form
	{
	public:
		Registro(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Registro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_reg;
	protected:
	private: System::Windows::Forms::TextBox^ txt_pass;
	private: System::Windows::Forms::TextBox^ txt_name;
	private: System::Windows::Forms::TextBox^ txt_pass2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_reg = (gcnew System::Windows::Forms::Button());
			this->txt_pass = (gcnew System::Windows::Forms::TextBox());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->txt_pass2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btn_reg
			// 
			this->btn_reg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reg->Location = System::Drawing::Point(104, 257);
			this->btn_reg->Name = L"btn_reg";
			this->btn_reg->Size = System::Drawing::Size(213, 39);
			this->btn_reg->TabIndex = 5;
			this->btn_reg->Text = L"Guardar Usuario";
			this->btn_reg->UseVisualStyleBackColor = true;
			this->btn_reg->Click += gcnew System::EventHandler(this, &Registro::btn_reg_Click);
			// 
			// txt_pass
			// 
			this->txt_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_pass->Location = System::Drawing::Point(104, 137);
			this->txt_pass->Multiline = true;
			this->txt_pass->Name = L"txt_pass";
			this->txt_pass->Size = System::Drawing::Size(213, 41);
			this->txt_pass->TabIndex = 4;
			// 
			// txt_name
			// 
			this->txt_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_name->Location = System::Drawing::Point(104, 55);
			this->txt_name->Multiline = true;
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(213, 41);
			this->txt_name->TabIndex = 3;
			// 
			// txt_pass2
			// 
			this->txt_pass2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_pass2->Location = System::Drawing::Point(104, 184);
			this->txt_pass2->Multiline = true;
			this->txt_pass2->Name = L"txt_pass2";
			this->txt_pass2->Size = System::Drawing::Size(213, 41);
			this->txt_pass2->TabIndex = 6;
			// 
			// Registro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 350);
			this->Controls->Add(this->txt_pass2);
			this->Controls->Add(this->btn_reg);
			this->Controls->Add(this->txt_pass);
			this->Controls->Add(this->txt_name);
			this->Name = L"Registro";
			this->Text = L"Registro";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_reg_Click(System::Object^ sender, System::EventArgs^ e) {
		DB^ database = gcnew DB();
		if (txt_pass2->Text == txt_pass->Text)
		{
			database->insert(txt_name->Text, txt_pass->Text);
			this->Close();
		}
		else {
			MessageBox::Show("Las contraseñas no coinsiden");
		}
	}
	};
}
