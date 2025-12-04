#pragma once
#include <vector>
#include <algorithm>
using namespace System::Drawing;
using namespace std;

class Controladora {

private:
    vector<Enemigo*> enemigos;
    vector<Bala*> balas;
    vector<Recurso*> recursos;

    int puntos = 0;
    int vidas = 3;

public:

    void agregarEnemigo(Enemigo* e) { enemigos.push_back(e); }

    void moverEnemigos(Graphics^ g) {
        for (auto e : enemigos)
            e->moverE(g);
    }

    void dibujarEnemigos(Graphics^ g, Bitmap^ bmp) {
        for (auto e : enemigos)
            if (e->getVisibilidad()) e->dibujar(g, bmp);
    }

    void agregarBala(Bala* b) { balas.push_back(b); }

    void moverBalas(Graphics^ g) {
        for (auto b : balas)
            b->mover(g);
    }

    void dibujarBalas(Graphics^ g, Bitmap^ bmp) {
        for (auto b : balas)
            if (b->getVisibilidad()) b->dibujarB(g, bmp);
    }

    void crearRecursos(Bitmap^ bmp) {
        recursos.push_back(new Recurso(150, 200, bmp->Width, bmp->Height));
        recursos.push_back(new Recurso(350, 150, bmp->Width, bmp->Height));
        recursos.push_back(new Recurso(550, 260, bmp->Width, bmp->Height));
    }

    void dibujarRecursos(Graphics^ g, Bitmap^ bmp) {
        for (auto r : recursos)
            if (r->getVisible()) r->dibujar(g, bmp);
    }

    void colisionRecurso(Personaje* jugador) {
        for (auto r : recursos) {
            if (r->getVisible() &&
                jugador->getRectangle().IntersectsWith(r->getRectangle()))
            {
                r->setVisible(false);
                puntos++;
            }
        }
    }
    int getRecursosRestantes() {
        int c = 0;
        for (auto r : recursos)
            if (r->getVisible()) c++;
        return c;
    }

    // bala elimina enemigo
    void colisionBalasEnemigos() {
        for (auto b : balas)
        {
            if (!b->getVisibilidad()) continue;

            for (auto e : enemigos)
            {
                if (!e->getVisibilidad()) continue;

                if (b->getRectangle().IntersectsWith(e->getRectangle())) {
                    b->setVisibilidad(false);
                    e->setVisibilidad(false);
                    puntos += 5;
                }
            }
        }
    }

    bool colisionEnemigo(Personaje* jugador) {
        for (auto e : enemigos) {
            if (e->getVisibilidad() &&
                jugador->getRectangle().IntersectsWith(e->getRectangle()))
            {
                vidas--;
                return true;
            }
        }
        return false;
    }

    int getPuntos() { return puntos; }
    int getVidas() { return vidas; }

    void moverTodo(Graphics^ g) {

        moverEnemigos(g);
        moverBalas(g);

        colisionBalasEnemigos(); // ?? IMPACTO BALA?ENEMIGO

        // limpiar balas invisibles (con delete REAL)
        balas.erase(remove_if(balas.begin(), balas.end(),
            [](Bala* b) {
                if (!b->getVisibilidad()) {
                    delete b;      // ? MATAR OBJETO REAL
                    return true;   // ? BORRAR PUNTERO DEL VECTOR
                }
                return false;
            }),
            balas.end());


        // limpiar enemigos muertos
        enemigos.erase(remove_if(enemigos.begin(), enemigos.end(),
            [](Enemigo* e) { return !e->getVisibilidad(); }),
            enemigos.end());
    }

    void dibujarTodo(Graphics^ g, Bitmap^ bmpEnemigo, Bitmap^ bmpBala, Bitmap^ bmpRecurso) {
        dibujarEnemigos(g, bmpEnemigo);
        dibujarBalas(g, bmpBala);
        dibujarRecursos(g, bmpRecurso);
    }
};