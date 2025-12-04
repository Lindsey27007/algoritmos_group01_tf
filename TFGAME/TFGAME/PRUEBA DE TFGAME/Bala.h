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
        this->x = x;
        this->y = y;
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

        if (direccion == 'S' && y + dy < limiteH) y += dy;
        if (direccion == 'W' && y - dy > 0)      y -= dy;
        if (direccion == 'A' && x - dx > 0)      x -= dx;
        if (direccion == 'D' && x + dx < limiteW) x += dx;
    }

    Rectangle getRectangle() {
        return Rectangle(x, y, (int)(W * 0.03f), (int)(H * 0.03f));
    }

    int getX() { return x; }
    int getY() { return y; }

    void setVisibilidad(bool v) { visibilidad = v; }
    bool getVisibilidad() { return visibilidad; }
};
