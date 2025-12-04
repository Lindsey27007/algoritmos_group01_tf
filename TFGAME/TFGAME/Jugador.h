#pragma once
#include "Entidad.h"

class Personaje : public Entidad
{
private:

public:

    Personaje(int W, int H)
    {
        this->W = W;
        this->H = H;

        dx = 15;
        dy = 15;

        // POSICI?N INICIAL FIJA (RESPAWN)
        x = 70;
        y = 70;

        indiceW = 0;
        indiceH = 0;
        direccion = 'S';
    }

    ~Personaje() {}

    // ============================
    //     MOVIMIENTO DEL JUGADOR
    // ============================
    void mover(Graphics^ gr, char tecla)
    {
        switch (tecla)
        {
        case 'A':
            if (x > 0)
            {
                indiceH = 1;
                x -= dx;
                direccion = 'A';
            }
            break;

        case 'D':
            if (x + W < gr->VisibleClipBounds.Width)
            {
                indiceH = 2;
                x += dx;
                direccion = 'D';
            }
            break;

        case 'W':
            if (y > 0)
            {
                indiceH = 3;
                y -= dy;
                direccion = 'W';
            }
            break;

        case 'S':
            if (y + H < gr->VisibleClipBounds.Height)
            {
                indiceH = 0;
                y += dy;
                direccion = 'S';
            }
            break;
        }

        // Animaci?n
        indiceW++;
        if (indiceW > 3) indiceW = 0;
    }

    // ============================
    //      GETTERS
    // ============================
    char getDireccion() { return direccion; }
    int getX() { return x; }
    int getY() { return y; }

    // ============================
    //    RECT?NGULO DE COLISI?N
    // ============================
    Rectangle getRectangle()
    {
        // HITBOX M?S PEQUE?A PARA COLISIONES JUSTAS
        int ancho = W * 0.6;
        int alto = H * 0.6;

        int offsetX = W * 0.2;
        int offsetY = H * 0.2;

        return Rectangle(x + offsetX, y + offsetY, ancho, alto);
    }

    // ============================
    //  SETTERS PARA RESPAWN
    // ============================
    void setX(int nuevoX) { x = nuevoX; }
    void setY(int nuevoY) { y = nuevoY; }

    void setPos(int nuevoX, int nuevoY)
    {
        x = nuevoX;
        y = nuevoY;
    }
};