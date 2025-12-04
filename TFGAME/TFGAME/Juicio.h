#pragma once
#include "GameOver.h"
#include "Win.h"

namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Juicio
	/// </summary>
	public ref class Juicio : public System::Windows::Forms::Form
	{
	public:
		Juicio(void)
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
		~Juicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juicio::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(824, 531);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Juicio::panel1_Paint);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Plum;
			this->button1->Location = System::Drawing::Point(382, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(342, 77);
			this->button1->TabIndex = 0;
			this->button1->Text = L"La inteligencia artificial debe tomar las decisiones importantes. Es más precisa "
				L"y no se equivoca como los humanos.";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Juicio::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::PowderBlue;
			this->button2->Location = System::Drawing::Point(382, 375);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(342, 77);
			this->button2->TabIndex = 1;
			this->button2->Text = L"La inteligencia artificial debe ser una herramienta poderosa, pero nunca un reemp"
				L"lazo del juicio humano.\nSu lugar está a nuestro lado, no por encima ni en nuestr"
				L"o lugar.";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Juicio::button2_Click);
			// 
			// Juicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(824, 532);
			this->Controls->Add(this->panel1);
			this->Name = L"Juicio";
			this->Text = L"Juicio";
			this->Load += gcnew System::EventHandler(this, &Juicio::Juicio_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Juicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		GameOver^ go = gcnew GameOver();
		go->ShowDialog();
		this->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Win^ w = gcnew Win();
	w->ShowDialog();
	this->Close();
}
};
}
