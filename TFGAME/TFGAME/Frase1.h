#pragma once
#include "MyForm.h"
namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Frase1
	/// </summary>
	public ref class Frase1 : public System::Windows::Forms::Form
	{
	public:
		Frase1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &Frase1::Frase_KeyDown);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Frase1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelFrase;
	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartPosition = FormStartPosition::CenterScreen;

			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Frase1::typeid));
			this->panelFrase = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panelFrase
			// 
			this->panelFrase->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelFrase.BackgroundImage")));
			this->panelFrase->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panelFrase->Location = System::Drawing::Point(0, 0);
			this->panelFrase->Name = L"panelFrase";
			this->panelFrase->Size = System::Drawing::Size(618, 438);
			this->panelFrase->TabIndex = 0;
			this->panelFrase->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Frase1::panel1_Frase);
			// 
			
			// Frase1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 435);
			this->Controls->Add(this->panelFrase);
			this->Name = L"Frase1";
			this->Text = L"Frase1";
			this->Load += gcnew System::EventHandler(this, &Frase1::Frase1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void Frase1_Load(System::Object^ sender, System::EventArgs^ e) {
		

	}
	private: System::Void Frase_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space)
		{
			this->Hide();
			MyForm^ juego = gcnew MyForm();
			juego->ShowDialog();
			this->Close();
		}
	}

	private: System::Void panel1_Frase(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	};
}
