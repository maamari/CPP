#include "draw.h"
#ifndef TURTLE_H
#define TURTLE_H

class Turtle {
	public:
		Turtle(double x, double y, double dir);
		void move(double dist);
		void turn(double deg);
		void setColor(Color c);
		void off();
		void on();

	private:
		double x1, y1, dir;
		bool show;
		Color col;
};

#endif