#pragma once
#include <ctime>

#include "Entidad.h"
#include "Jugador.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Controladora.h"

namespace TFGAME {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            srand((unsigned)time(NULL));

            gr = panel1->CreateGraphics();
            buffer = BufferedGraphicsManager::Current->Allocate(gr, panel1->ClientRectangle);

            personaje = gcnew Bitmap("Imagenes\\Personaje1.png");
            enemigo = gcnew Bitmap("Imagenes\\enemigoRobot.png");
            bala = gcnew Bitmap("Imagenes\\efectos1.png");
            mapa = gcnew Bitmap("Imagenes\\Mundo1.png");
            recurso = gcnew Bitmap("Imagenes\\recursotuerca.png");

            p1 = new Personaje(personaje->Width / 4, personaje->Height / 4);

            control = new Controladora();

            control->agregarEnemigo(new Enemigo(enemigo->Width / 4, enemigo->Height / 4, 'D'));
            control->agregarEnemigo(new Enemigo(enemigo->Width / 4, enemigo->Height / 4, 'D'));

            control->crearRecursos(recurso);

            this->KeyPreview = true;
        }

    protected:
        ~MyForm()
        {
            if (components)
                delete components;
        }

    private:
        Graphics^ gr;
        BufferedGraphics^ buffer;

        Bitmap^ personaje;
        Bitmap^ enemigo;
        Bitmap^ mapa;
        Bitmap^ bala;
        Bitmap^ recurso;

        Personaje* p1;
        Controladora* control;

        System::Windows::Forms::Timer^ timer1;
        System::Windows::Forms::Panel^ panel1;
        System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();

            this->timer1->Enabled = true;
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);

            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(620, 436);
            this->panel1->TabIndex = 0;

            this->ClientSize = System::Drawing::Size(619, 436);
            this->Controls->Add(this->panel1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);

            this->ResumeLayout(false);
        }
#pragma endregion


    private:
        System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

            buffer->Graphics->DrawImage(mapa, 0, 0, panel1->Width, panel1->Height);

            control->moverTodo(buffer->Graphics);
            control->colisionRecurso(p1);

            control->dibujarTodo(buffer->Graphics, enemigo, bala, recurso);

            p1->dibujar(buffer->Graphics, personaje);

            // DIBUJAR CONTADOR EN PANTALLA
            buffer->Graphics->DrawString(
                "Puntos: " + control->getPuntos(),
                gcnew System::Drawing::Font("Arial", 16),
                Brushes::Yellow,
                10, 10
            );

            buffer->Render(gr);
        }


    private:
        System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

            switch (e->KeyCode)
            {
            case Keys::A:
                p1->mover(buffer->Graphics, 'A');
                break;

            case Keys::D:
                p1->mover(buffer->Graphics, 'D');
                break;

            case Keys::W:
                p1->mover(buffer->Graphics, 'W');
                break;

            case Keys::S:
                p1->mover(buffer->Graphics, 'S');
                break;

            case Keys::Space:
            {
                Bala* b1 = new Bala(
                    p1->getX(),
                    p1->getY(),
                    bala->Width,
                    bala->Height,
                    p1->getDireccion()
                );

                control->agregarBala(b1);
            }
            break;
            }
        }
    };
}
