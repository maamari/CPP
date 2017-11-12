#include <iostream>
#include <cmath>
#include "turtle.h"
using namespace std;

Turtle::Turtle(double x0, double y0, double dir0)
{
	x1 = x0;
	y1 = y0;
	dir = dir0;
	setColor(draw::BLACK);
	show = true;
}

void Turtle::turn(double deg)
{
	dir += deg;
}

void Turtle::move(double dist)
{
	double x2, y2;

	x2 = x1 + (dist * cos(dir*M_PI/180));
	y2 = y1 + (dist * sin(dir*M_PI/180));

	draw::setcolor(col);

	if(show) {
	draw::line(x1, y1, x2, y2);
	}

	x1 = x2;
	y1 = y2;
}

void Turtle::setColor(Color c) 
{
  col = c;
}

void Turtle::off() 
{
  show = false;
}

void Turtle::on() 
{
  show = true;
}
