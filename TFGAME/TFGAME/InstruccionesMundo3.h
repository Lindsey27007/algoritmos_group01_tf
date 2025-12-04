#pragma once
#include "Frase3.h"
namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InstruccionesMundo3
	/// </summary>
	public ref class InstruccionesMundo3 : public System::Windows::Forms::Form
	{
	public:
		InstruccionesMundo3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->KeyPreview = true;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InstruccionesMundo3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InstruccionesMundo3::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(827, 531);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InstruccionesMundo3::panel1_Paint);
			// 
			// InstruccionesMundo3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 532);
			this->Controls->Add(this->panel1);
			this->Name = L"InstruccionesMundo3";
			this->Text = L"InstruccionesMundo3";
			this->KeyDown += gcnew KeyEventHandler(this, &InstruccionesMundo3::InstruccionesMundo3_KeyDown);
			this->Load += gcnew System::EventHandler(this, &InstruccionesMundo3::InstruccionesMundo3_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void InstruccionesMundo3_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


	private: System::Void InstruccionesMundo3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Space) {
			this->Hide();
			Frase3^ frase = gcnew Frase3();
			frase->ShowDialog();
			this->Close();
		}

	}

	};
}
