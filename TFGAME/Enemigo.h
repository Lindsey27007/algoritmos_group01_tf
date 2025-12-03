#pragma once
#include "Entidad.h"

class Enemigo : public Entidad
{
private:
    bool visible;

public:

    // Constructor: recibe tamaño del sprite y dirección inicial
    Enemigo(int W, int H, char direccion)
    {
        this->W = W;
        this->H = H;

        this->direccion = direccion;   // 'A', 'D', 'W', 'S'
        dx = 20;
        dy = 20;

        // Posición inicial aleatoria
        x = rand() % 700;
        y = rand() % 400;

        indiceW = 0;
        indiceH = 0;

        visible = true;
    }

    ~Enemigo() {}

    // Movimiento del enemigo
    void moverE(Graphics^ gr)
    {
        // Movimiento horizontal izquierda-derecha
        if (direccion == 'D' || direccion == 'A')
        {
            if (x + W >= gr->VisibleClipBounds.Width || x <= 0)
                dx *= -1;

            // Cambiar sprite según dirección
            if (dx > 0)
                indiceH = 2;     // mirando derecha
            else
                indiceH = 1;     // mirando izquierda

            x += dx;
        }

        // Animación de frames
        indiceW++;
        if (indiceW > 3) indiceW = 0;
    }

    // Colisiones
    Rectangle getRectangle() { return Rectangle(x, y, W, H); }

    // Visibilidad (para eliminar enemigos)
    void setVisible(bool v) { visible = v; }
    bool getVisible() { return visible; }
};
