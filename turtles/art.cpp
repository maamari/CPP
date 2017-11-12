#include "turtle.h"
#include "draw.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  draw::setpenwidth(7); //pen widt
  draw::setrange(-100, 100);
  srand(time(0));
  double moveDist[4], turn[4];

  Turtle leonardo(0, 0, 0);
  Turtle donatelo(0, 0, 0);
  Turtle michaelangelo(0, 0, 0);
  Turtle raphael(0, 0, 0);

  leonardo.setColor(draw::RED);
  donatelo.setColor(draw::BLACK);
  michaelangelo.setColor(draw::AZURE);
  raphael.setColor(draw::CHARTREUSE);

  for(int i = 0; i < 4; i++)
  {
    turn[i] = rand()%360;
  }

  leonardo.turn(turn[0]);
  donatelo.turn(turn[1]);
  michaelangelo.turn(turn[2]);
  raphael.turn(turn[3]);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      moveDist[j] = rand() % 21;
    }

    for(int k = 0; k < 4; k++)
    {
      turn[k] = rand()%360;
    }

    leonardo.move(moveDist[0]);
    donatelo.move(moveDist[1]);
    michaelangelo.move(moveDist[2]);
    raphael.move(moveDist[3]);
    
    leonardo.turn(turn[0]);
    donatelo.turn(turn[1]);
    michaelangelo.turn(turn[2]);
    raphael.turn(turn[3]);

    for (int j = 0; j < 20; j++)
    {
      for(int l = 0; l < 4; l++)
      {
        turn[l] = rand()%360;
      }
    }

    draw::show(100);
  }
  return 0;
}