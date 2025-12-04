#pragma once

#include "Entidad.h"
#include "Jugador.h"
#include "Bala.h"
#include "Enemigo.h"
#include "Controladora.h"
#include"GameOver.h"
#include"InstruccionesMundo3.h"
namespace TFGAME {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class MyForm2 : public System::Windows::Forms::Form
    {
    public:


        bool invulnerable = false;
        int tiempoInvulnerable = 0;

        String^ obtenerCorazones(int vidas) {
            String^ c = "";
            for (int i = 0; i < vidas; i++)
                c += "O ";
            return c;
        }

        MyForm2(void)
        {
            //
            //TODO: Add the constructor code here
            //

            InitializeComponent();
            srand((unsigned)time(NULL));

            gr = panel1->CreateGraphics();
            buffer = BufferedGraphicsManager::Current->Allocate(gr, panel1->ClientRectangle);

            personaje = gcnew Bitmap("Imagenes\\Personaje1.png");
            enemigo = gcnew Bitmap("Imagenes\\Lucas.png");
            mapa = gcnew Bitmap("Imagenes\\Mundo2.png");
            bala = gcnew Bitmap("Imagenes\\efectos1.png");
            recurso = gcnew Bitmap("Imagenes\\hoja.png");

            p1 = new Personaje(personaje->Width / 4, personaje->Height / 4);
            control = new Controladora();

            // Enemigos
            control->agregarEnemigo(new Enemigo(enemigo->Width / 4, enemigo->Height / 4, 'D'));
            control->agregarEnemigo(new Enemigo(enemigo->Width / 4, enemigo->Height / 4, 'A'));

            // Recursos
            control->crearRecursos(recurso);

            this->KeyPreview = true;
        }

    protected:
        ~MyForm2()
        {
            if (components)
                delete components;
        }

    private:

        Graphics^ gr;
        BufferedGraphics^ buffer;

        Bitmap^ personaje;
        Bitmap^ enemigo;
        Bitmap^ bala;
        Bitmap^ mapa;
        Bitmap^ recurso;

        Personaje* p1;
        Controladora* control;

        System::Windows::Forms::Timer^ timer1;
        System::Windows::Forms::Panel^ panel1;
        System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->StartPosition = FormStartPosition::CenterScreen;
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();

            // TIMER
            this->timer1->Enabled = true;
            this->timer1->Interval = 50;
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);

            // PANEL
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(620, 436);
            this->panel1->TabIndex = 0;

            // FORM
            this->ClientSize = System::Drawing::Size(619, 436);
            this->Controls->Add(this->panel1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->KeyPreview = true;
            this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::MyForm_KeyDown);

            this->ResumeLayout(false);
        }

#pragma endregion


    private:
        System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
        {
            buffer->Graphics->DrawImage(mapa, 0, 0, panel1->Width, panel1->Height);

            // Mover enemigos + balas + eliminar muertos
            control->moverTodo(buffer->Graphics);

            // Recolecci�n de recursos
            control->colisionRecurso(p1);
            // ¿Ya recogió los 3 recursos?
            if (control->getRecursosRestantes() == 0)
            {
                timer1->Enabled = false;
                this->Hide();

                InstruccionesMundo3^ inst3 = gcnew InstruccionesMundo3();
                inst3->ShowDialog();

                this->Close();
                return;
            }

            if (!invulnerable && control->colisionEnemigo(p1))
            {
                invulnerable = true;
                tiempoInvulnerable = 20; // ~1 segundo

                // RESPAWN FIJO
                p1->setX(60);
                p1->setY(60);

                // �Se qued� sin vidas?
                if (control->getVidas() <= 0)
                {
                    timer1->Enabled = false;
                    this->Hide();

                    // Abrir pantalla GameOver
                    GameOver^ gameover = gcnew GameOver();

                    // Cuando GameOver cierre, cerramos MyForm también
                    gameover->ShowDialog();

                    this->Close();
                    return;
                }
            }

            // Contador de invulnerabilidad
            if (invulnerable)
            {
                tiempoInvulnerable--;
                if (tiempoInvulnerable <= 0)
                    invulnerable = false;
            }


            if (invulnerable)
            {
                if ((tiempoInvulnerable % 4) < 2)
                {
                    // No dibuja ? invisible
                }
                else
                {
                    p1->dibujar(buffer->Graphics, personaje);
                }
            }
            else
            {
                p1->dibujar(buffer->Graphics, personaje);
            }

            // Dibujar enemigos, recursos y balas
            control->dibujarTodo(buffer->Graphics, enemigo, bala, recurso);

            buffer->Graphics->DrawString(
                "Puntos: " + control->getPuntos() +
                "\nVidas: " + obtenerCorazones(control->getVidas()),
                gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold),
                Brushes::Yellow,
                10,
                10
            );

            buffer->Render(gr);
        }

        System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
        {
            switch (e->KeyCode)
            {
            case Keys::A: p1->mover(buffer->Graphics, 'A'); break;
            case Keys::D: p1->mover(buffer->Graphics, 'D'); break;
            case Keys::W: p1->mover(buffer->Graphics, 'W'); break;
            case Keys::S: p1->mover(buffer->Graphics, 'S'); break;

            break;
            }
        }
    };
}