#pragma once
#include<iostream>
using namespace System::Drawing;
class Bala
{
private:
    int x, y;//posición del personaje
    int dx, dy;//velocidades del personaje en x, y
    int indiceW, indiceH;
    int W, H;
    char direccion;
    bool visibilidad;
public:
    // Constructor
    Bala(int x, int y, int W, int H, char tecla) {
        this->x = x;
        this->y = y;
        this->W = W;
        this->H = H;
        this->direccion = tecla;
        this->dx = 30;
        this->dy = 30;
        this->visibilidad = true;
        this->indiceW = 0;
        this->indiceH = 0;
    }

    // Destructor
    ~Bala() {}

    // Dibuja la bala en la pantalla
    void dibujarB(Graphics^ gr, Bitmap^ bmp) {
        gr->DrawImage(bmp, x, y, (W * 0.03), (H * 0.03));
    }

    // Mueve la bala según su dirección
    void mover(Graphics^ gr) {
        if (direccion == 'S' && y + H * 0.03 <= gr->VisibleClipBounds.Height)
            y += dy;
        else if (direccion == 'W' && y >= 0)
            y -= dy;
        else if (direccion == 'A' && x >= 0)
            x -= dx;
        else if (direccion == 'D' && x + W * 0.03 < gr->VisibleClipBounds.Width)
            x += dx;
    }

    // Devuelve el rectángulo de colisión (ajustado en tamaño)
    Rectangle getRectangle() {
        return Rectangle(x, y, (int)(W * 0.03), (int)(H * 0.06));
    }

    // Getters y setters
    int getX() { return x; }
    int getY() { return y; }
    int getW() { return (int)(W * 0.03); }
    int getH() { return (int)(H * 0.03); }

    void setVisibilidad(bool visi) { visibilidad = visi; }
    bool getVisibilidad() { return visibilidad; }
};