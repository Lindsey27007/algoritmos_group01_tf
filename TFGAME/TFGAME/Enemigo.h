#pragma once
#include"Entidad.h"

class Enemigo : public Entidad
{
private:

	bool visibilidad;
public:
	Enemigo(int W, int H, char d) {
		this->W = W;
		this->H = H;
		direccion = d;
		dx = 20;
		dy = 20;

		// posición aleatoria
		x = rand() % 20;
		y = rand() % 30;

		indiceW = 0;
		indiceH = 0;

		visibilidad = true;

		x = rand() % 700;  // ancho máximo
		y = rand() % 400;
	}
	~Enemigo() {}

	void moverE(Graphics^ gr) {
		if (direccion == 1) {
			//los enemigs se mueven de izquierda a derecha
			if (x + W > gr->VisibleClipBounds.Width || x < 0)dx *= -1;
			if (dx > 0) {
				indiceH = 2;
			}
			else indiceH = 1;
			x += dx;
		}
		//else {//de arriba hacia abajo
		//	if (y + H > gr->VisibleClipBounds.Height || y < 0)dy *= -1;

		//	if (dy > 0) {
		//		indiceH = 0;
		//	}
		//	else indiceH = 3;
		//	y += dy;
		//}
		indiceW++;
		if (indiceW > 3)indiceW = 0;
	}
	Rectangle getRectangle() { return Rectangle(x, y, W, H); }
	void setVisibilidad(bool v) { visibilidad = v; }
	bool getVisibilidad() { return visibilidad; }


};

