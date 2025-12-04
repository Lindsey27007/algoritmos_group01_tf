#pragma once
#include "Frase1.h"
namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InstruccionesMundo1
	/// </summary>
	public ref class InstruccionesMundo1 : public System::Windows::Forms::Form
	{
	public:
		InstruccionesMundo1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &InstruccionesMundo1::Instrucciones_KeyDown);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InstruccionesMundo1()
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
			this->StartPosition = FormStartPosition::CenterScreen;

			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InstruccionesMundo1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(829, 533);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InstruccionesMundo1::panelInstruccionesMundo1);
		
			// 
			// InstruccionesMundo1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 532);
			this->Controls->Add(this->panel1);
			this->Name = L"InstruccionesMundo1";
			this->Text = L"InstruccionesMundo1";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void panelInstruccionesMundo1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Instrucciones_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space)
		{
			this->Hide();
			Frase1^ frase = gcnew Frase1();
			frase->ShowDialog();
			this->Close();
		}
	}

	};
}
