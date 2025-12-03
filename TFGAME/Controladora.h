#pragma once
#include <vector>
using namespace System::Drawing;
using namespace std;

class Controladora {
private:
    vector<Enemigo*> enemigos;
    vector<Bala*> balas;
    vector<Recurso*> recursos;

    int puntos = 0;   // contador de tuercas recolectadas

public:

    // ================
    //   ENEMIGOS
    // ================
    void agregarEnemigo(Enemigo* e) {
        enemigos.push_back(e);
    }

    void moverEnemigos(Graphics^ g) {
        for (int i = 0; i < enemigos.size(); i++)
            enemigos[i]->moverE(g);
    }

    void dibujarEnemigos(Graphics^ g, Bitmap^ bmp) {
        for (auto e : enemigos)
            e->dibujar(g, bmp);
    }

    // ================
    //     BALAS
    // ================
    void agregarBala(Bala* b) {
        balas.push_back(b);
    }

    void moverBalas(Graphics^ g) {
        for (auto b : balas)
            b->mover(g);
    }

    void dibujarBalas(Graphics^ g, Bitmap^ bmp) {
        for (auto b : balas)
            b->dibujarB(g, bmp);
    }

    // ======================
    //   RECURSOS
    // ======================
    void crearRecursos(Bitmap^ bmp) {
        recursos.push_back(new Recurso(150, 200, bmp->Width, bmp->Height));
        recursos.push_back(new Recurso(350, 150, bmp->Width, bmp->Height));
        recursos.push_back(new Recurso(550, 260, bmp->Width, bmp->Height));
    }

    void dibujarRecursos(Graphics^ g, Bitmap^ bmp) {
        for (auto r : recursos)
            r->dibujar(g, bmp);
    }

    void colisionRecurso(Personaje* jugador) {
        for (auto r : recursos) {
            if (r->getVisible() &&
                jugador->getRectangle().IntersectsWith(r->getRectangle()))
            {
                r->setVisible(false);
                puntos++; // suma 1 punto
            }
        }
    }

    int getPuntos() { return puntos; }

    // ======================
    //   CONTROL GENERAL
    // ======================
    void moverTodo(Graphics^ g) {
        moverEnemigos(g);
        moverBalas(g);
    }

    void dibujarTodo(Graphics^ g, Bitmap^ bmpEnemigo, Bitmap^ bmpBala, Bitmap^ bmpRecurso) {
        dibujarEnemigos(g, bmpEnemigo);
        dibujarBalas(g, bmpBala);
        dibujarRecursos(g, bmpRecurso);
    }
};
