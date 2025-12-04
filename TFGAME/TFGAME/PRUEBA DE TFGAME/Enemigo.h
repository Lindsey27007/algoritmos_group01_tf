#pragma once
#include "Entidad.h"

class Enemigo : public Entidad
{
private:
    bool visibilidad;

public:
    Enemigo(int W, int H, char d)
    {
        this->W = W;
        this->H = H;
        direccion = d;

        dx = 8;
        dy = 8;

        x = rand() % 600;
        y = rand() % 300;

        indiceW = 0;
        indiceH = 0;

        visibilidad = true;
    }

    ~Enemigo() {}

    void moverE(Graphics^ gr)
    {
        if (x + W >= gr->VisibleClipBounds.Width || x <= 0)
            dx *= -1;

        x += dx;

        indiceW++;
        if (indiceW > 3) indiceW = 0;
    }

    // ? HITBOX ULTRA REDUCIDA (20%) PARA EVITAR COLISIONES FALSAS
    Rectangle getRectangle() {
        int ancho = W * 0.2;   // 20% del tamaño original
        int alto = H * 0.2;
        int offsetX = W * 0.4; // centrado
        int offsetY = H * 0.4;

        return Rectangle(x + offsetX, y + offsetY, ancho, alto);
    }

    void setVisibilidad(bool v) { visibilidad = v; }
    bool getVisibilidad() { return visibilidad; }
};
