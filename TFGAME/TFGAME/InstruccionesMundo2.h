#pragma once
#include "Frase2.h"

namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InstruccionesMundo2
	/// </summary>
	public ref class InstruccionesMundo2 : public System::Windows::Forms::Form
	{
	public:
		InstruccionesMundo2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &InstruccionesMundo2::InstruccionesMundo2_KeyDown);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InstruccionesMundo2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
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
			this->StartPosition = FormStartPosition::CenterScreen;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InstruccionesMundo2::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel1";
			this->panel2->Size = System::Drawing::Size(824, 533);
			this->panel2->TabIndex = 0;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InstruccionesMundo2::panel1_Paint);
			// 
			// InstruccionesMundo2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(827, 532);
			this->Controls->Add(this->panel2);
			this->Name = L"InstruccionesMundo2";
			this->Text = L"InstruccionesMundo2";
			this->Load += gcnew System::EventHandler(this, &InstruccionesMundo2::InstruccionesMundo2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &InstruccionesMundo2::InstruccionesMundo2_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


	private: System::Void InstruccionesMundo2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Space) { // verificamos tecla ESPACIO
			this->Hide();
			Frase2^ f = gcnew Frase2();
			f->ShowDialog();
			this->Close();
		}

	}

	private: System::Void InstruccionesMundo2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
