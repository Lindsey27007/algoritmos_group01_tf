#pragma once
#include <iostream>
using namespace System::Drawing;

class Entidad {
public:
    Entidad() {}

    Entidad(int x, int y, int W, int H) {
        this->x = x;
        this->y = y;
        this->W = W;
        this->H = H;
        dx = dy = 0;
        indiceW = indiceH = 0;
        direccion = 'D';
    }

    void dibujar(Graphics^ gr, Bitmap^ bmp) {
        Rectangle porcion = Rectangle(indiceW * W, indiceH * H, W, H);
        Rectangle destino = Rectangle(x, y, W, H);
        gr->DrawImage(bmp, destino, porcion, GraphicsUnit::Pixel);
    }

protected:
    int x, y;
    int dx, dy;
    int indiceW, indiceH;
    int W, H;
    char direccion;
};


// ============================
//     RECURSO (RECOLECCIÓN)
// ============================
class Recurso : public Entidad {
private:
    bool visible;

public:
    Recurso(int x, int y, int W, int H)
        : Entidad(x, y, W, H)
    {
        visible = true;
    }

    void dibujar(Graphics^ g, Bitmap^ bmp) {
        if (visible)
            g->DrawImage(bmp, x, y, 30, 30); // tamaño ajustado
    }

    Rectangle getRectangle() { return Rectangle(x, y, 30, 30); }
    void setVisible(bool v) { visible = v; }
    bool getVisible() { return visible; }
};
