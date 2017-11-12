#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

void draw_rectangle(int top, int left, int height, int width) {
    for(int x = top; x <= top+height; x++){
      if(left >= 0 && x >= 0 && left < 256 && x < 256){
        image[x][left] = 0;
      }
      if((left+width) >= 0 && x >= 0 && (left+width) < 256 && x < 256){
        image[x][left+width] = 0;
      }
    }
    for(int y = left; y <= left+width; y++){
      if(top >= 0 && y >= 0 && top < 256 && y < 256){
        image[top][y] = 0;
    }
      if((top+height) >= 0 && y >= 0 && (top + height) < 256 && y < 256){
      image[top+height][y] = 0;
    }
  }
}

void draw_ellipse(int cy, int cx, int height, int width) {
    for (double theta=0.0; theta < 2*M_PI; theta += .01) {
       int x = (height/2)*cos(theta);
       int y = (width/2)*sin(theta);
       x += cx;
       y += cy;
         if((x >= 0 && x < 256) && (y >= 0 && y < 256)){
           image[(int)x][(int)y] = 0;
         }
    }
}



int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }

   // Main program loop here

   int input = 1;
   int xcoor, ycoor, h, w;
   while(input <= 2 && input >= 0){
    //  cout << "Test" << endl;
      cout << "To draw a rectangle, enter: 0 top left height width" << endl;
      cout << "To draw an eclipse, enter: 1 cy cx height width" << endl;
      cout << "To save your drawing as \"output.bmp\" and quit, enter:  2" << endl;
      cin >> input;
        if(input == 2){
          break;
        }
      cin >> ycoor >> xcoor >> h >> w;
        if(input == 0){
          draw_rectangle(ycoor, xcoor, h, w);
        }
        if(input == 1){
          draw_ellipse(ycoor, xcoor, h, w);
        }
   }

   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);

   return 0;
}
