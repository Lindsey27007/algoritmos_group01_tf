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
        if (direccion == 1) {
            //los enemigs se mueven de izquierda a derecha
            if (x + W > gr->VisibleClipBounds.Width || x < 0)dx *= -1;
            if (dx > 0) {
                indiceH = 2;
            }
            else indiceH = 1;
            x += dx;
        }
        else {//de arriba hacia abajo
            if (y + H > gr->VisibleClipBounds.Height || y < 0)dy *= -1;

            if (dy > 0) {
                indiceH = 0;
            }
            else indiceH = 3;
            y += dy;
        }
        indiceW++;
        if (indiceW > 3)indiceW = 0;
    }

    // ? HITBOX ULTRA REDUCIDA (20%) PARA EVITAR COLISIONES FALSAS
    Rectangle getRectangle() {
        int ancho = W * 0.2;   // 20% del tama?o original
        int alto = H * 0.2;
        int offsetX = W * 0.4; // centrado
        int offsetY = H * 0.4;

        return Rectangle(x + offsetX, y + offsetY, ancho, alto);
    }

    void setVisibilidad(bool v) { visibilidad = v; }
    bool getVisibilidad() { return visibilidad; }
};