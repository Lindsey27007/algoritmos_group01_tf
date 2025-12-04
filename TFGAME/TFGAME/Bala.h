#pragma once
#include <iostream>
using namespace System::Drawing;

class Bala
{
private:
    int x, y;
    int dx, dy;
    int W, H;
    int indiceW, indiceH;
    char direccion;
    bool visibilidad;

public:
    Bala(int x, int y, int W, int H, char tecla) {
        this->x = x + 20;
        this->y = y + 20;
        this->W = W;
        this->H = H;
        direccion = tecla;
        dx = 30;
        dy = 30;
        visibilidad = true;
        indiceW = indiceH = 0;
    }

    ~Bala() {}

    void dibujarB(Graphics^ gr, Bitmap^ bmp) {
        int w = (int)(W * 0.03f);
        int h = (int)(H * 0.03f);
        gr->DrawImage(bmp, x, y, w, h);
    }

    void mover(Graphics^ gr) {
        int limiteW = (int)gr->VisibleClipBounds.Width;
        int limiteH = (int)gr->VisibleClipBounds.Height;

        // movnormal
        if (direccion == 'S') y += dy;
        if (direccion == 'W') y -= dy;
        if (direccion == 'A') x -= dx;
        if (direccion == 'D') x += dx;

        // desactivamos la bala
        if (x < 0 || y < 0 ||
            x + (int)(W * 0.03f) > limiteW ||
            y + (int)(H * 0.03f) > limiteH)
        {
            visibilidad = false;
        }
    }


    Rectangle getRectangle() {
        return Rectangle(x, y, (int)(W * 0.03f), (int)(H * 0.03f));
    }

    int getX() { return x; }
    int getY() { return y; }

    void setVisibilidad(bool v) { visibilidad = v; }
    bool getVisibilidad() { return visibilidad; }
};