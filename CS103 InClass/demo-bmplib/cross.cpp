#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

int main() {
   unsigned char image[SIZE][SIZE];

   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }

   for(int i=0; i < SIZE; i++) {
      image[i][i] = 0;
      image[i][Size-i] = 0;
      // every 20 steps, display
      // if (i%20==0) showGSBMP(image);
   }


   writeGSBMP("cross.bmp", image);
   return 0;
}
