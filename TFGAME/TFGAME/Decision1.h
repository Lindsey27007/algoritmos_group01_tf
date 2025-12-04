#pragma once
#include "GameOver.h"
#include "InstruccionesMundo2.h"

namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Decision1
	/// </summary>
	public ref class Decision1 : public System::Windows::Forms::Form
	{
	public:
		Decision1(void)
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
		~Decision1()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Decision1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->panel1->Size = System::Drawing::Size(830, 533);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Decision1::panel1_Paint);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->Location = System::Drawing::Point(441, 410);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(322, 77);
			this->button2->TabIndex = 1;
			this->button2->Text = L"La confianza ciega puede ser peligrosa. Prefiero depender de mi propia sabiduría "
				L"y habilidades, y así mantener el control.";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Decision1::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Location = System::Drawing::Point(441, 301);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(322, 85);
			this->button1->TabIndex = 0;
			this->button1->Text = L"A veces la confianza en la inteligencia artificial es un camino incierto, pero cr"
				L"eo que juntos podemos enfrentar cualquier desafío. Acepto tu ayuda con cautela.."
				L".";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Decision1::button1_Click);
			// 
			// Decision1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(828, 533);
			this->Controls->Add(this->panel1);
			this->Name = L"Decision1";
			this->Text = L"Decision1";
			this->Load += gcnew System::EventHandler(this, &Decision1::Decision1_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide(); 
		GameOver^ go = gcnew GameOver();
		go->ShowDialog(); 
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		InstruccionesMundo2^ inst = gcnew InstruccionesMundo2();
		inst->ShowDialog();
		this->Close();
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
private: System::Void Decision1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
