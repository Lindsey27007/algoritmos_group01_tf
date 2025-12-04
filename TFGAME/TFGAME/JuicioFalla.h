#pragma once
#include "GameOver.h"

namespace TFGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for JuicioFalla
	/// </summary>
	public ref class JuicioFalla : public System::Windows::Forms::Form
	{
	public:
		JuicioFalla(void)
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
		~JuicioFalla()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(JuicioFalla::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(826, 531);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &JuicioFalla::panel1_Paint);
			// 
			// JuicioFalla
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(825, 531);
			this->Controls->Add(this->panel1);
			this->Name = L"JuicioFalla";
			this->Text = L"JuicioFalla";
			this->KeyDown += gcnew KeyEventHandler(this, &JuicioFalla::JuicioFalla_KeyDown);
			this->Load += gcnew System::EventHandler(this, &JuicioFalla::JuicioFalla_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void JuicioFalla_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void JuicioFalla_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space) {
			this->Hide();
			GameOver^ go = gcnew GameOver();
			go->ShowDialog();
			this->Close();
		}
	}

	};
}
