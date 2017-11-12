/*********************************************************************
 File:     chromakey.cpp

 Author:   Karime Maamari

 Email address: maamari@usc.edu

 Usage: program_name in.bmp background.bmp dist_threshold out1.bmp out2.bmp

 Notes:

 This program performs the chroma key operation on an input 
 using two different methods.

 Method 1 Utilize a user-defined distance threshold from the
          chromakey value as a discriminator

 Method 2 Devise a method that to determine the chromakey mask
          that doesn't require a user-input threshold

********************************************************************/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"

using namespace std;

void method1(unsigned char inImage[][SIZE][RGB], bool mask[][SIZE], 
  double threshold);

void method2(unsigned char inImage[][SIZE][RGB], bool mask[][SIZE]);

void replace(bool mask[][SIZE], unsigned char inImage[][SIZE][RGB], 
  unsigned char bgImage[][SIZE][RGB], unsigned char outImage[][SIZE][RGB]);

int main(int argc, char *argv[])
{

  static unsigned char inputImage[SIZE][SIZE][RGB];
  static unsigned char bgrndImage[SIZE][SIZE][RGB];
  static unsigned char outputImage[SIZE][SIZE][RGB];
  static bool chromaMask[SIZE][SIZE];

  double threshold;

  if (argc < 6) {
    cerr << "usage: program_name in.bmp background.bmp dist_threshold " 
         << "out1.bmp out2.bmp" << endl;
    return 0;
  }
  
  if (readRGBBMP(argv[1], inputImage)) {
    cerr << "Error reading file: " << argv[1] << endl;
    return 1;
  }

  if (readRGBBMP(argv[2], bgrndImage)) {
    cout << "Error reading file: " << argv[2] << endl;
    return 1;
  }
  
  threshold = atof(argv[3]);

  method1(inputImage, chromaMask, threshold);

  replace(chromaMask, inputImage, bgrndImage, outputImage);

  if (writeRGBBMP(argv[4], outputImage)) {
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  } 
}

void method1(unsigned char inImage[][SIZE][RGB], bool mask[][SIZE], 
  double threshold)
{ 

   int count = 0;
   double rTot = 0, gTot = 0, bTot = 0;
   
   //find first corner
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //find second corner
   for (int i = SIZE - 3; i < SIZE; i++) {
      for (int j = SIZE - 3; j < SIZE; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //find third corner
   for (int i = SIZE - 3; i < SIZE; i++) {
      for (int j = 0; j < 3; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //find fourth corner
   for (int i = 0; i < 3; i++) {
      for (int j = SIZE - 3; j < SIZE; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //find average of the corners
   rTot /= count;
   gTot /= count;
   bTot /= count;
   
   //make the mask
   for (int r = 0; r < SIZE; r++) {
      for (int c = 0; c < SIZE; c++) {
         double rDiff = inImage[r][c][0] - rTot;
         double gDiff = inImage[r][c][1] - gTot;
         double bDiff = inImage[r][c][2] - bTot;
         double dist = sqrt(pow(rDiff, 2) + pow(gDiff, 2) + pow(bDiff, 2));
         
         if (dist <= threshold) {
            //color is within threshold
            mask[r][c] = false;
         } else {
            //goes to foreground
            mask[r][c] = true;
         }
      }
   }
}

void method2(unsigned char inImage[][SIZE][RGB], bool mask[][SIZE])  
{

   int count = 0;
   double rTot = 0, gTot = 0, bTot = 0;
   
   //first corner
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //second corner
   for (int i = SIZE - 3; i < SIZE; i++) {
      for (int j = SIZE - 3; j < SIZE; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //third corner
   for (int i = SIZE - 3; i < SIZE; i++) {
      for (int j = 0; j < 3; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //fourth corner
   for (int i = 0; i < 3; i++) {
      for (int j = SIZE - 3; j < SIZE; j++) {
         rTot += inImage[i][j][0];
         gTot += inImage[i][j][1];
         bTot += inImage[i][j][2];
         
         count++;
      }
   }
   
   //averages
   rTot /= count;
   gTot /= count;
   bTot /= count;  
   
   int run_thru = 0;
   double difArr[16 * 256];
   
   for (int r = 0; r < SIZE; r++) {
      for (int c = 0; c < SIZE; c++) {
         if (r == 0 && c == 0) {
            //find distance
            double rDiff = inImage[r][c][0] - rTot;
            double gDiff = inImage[r][c][1] - gTot;
            double bDiff = inImage[r][c][2] - bTot;
            double dist = sqrt(pow(rDiff, 2) + pow(gDiff, 2) 
               + pow(bDiff, 2));
            difArr[run_thru] = dist;
            //set mask to 0 or false
            mask[r][c] = false;
         } else {
            //find distance
            double rDiff = inImage[r][c][0] - rTot;
            double gDiff = inImage[r][c][1] - gTot;
            double bDiff = inImage[r][c][2] - bTot;
            double dist = sqrt(pow(rDiff, 2) + pow(gDiff, 2) 
               + pow(bDiff, 2));
            double prevDiff = abs(dist - difArr[run_thru]);
         
            if(prevDiff <= 14) {
               mask[r][c] = false;
               if (run_thru < 4096) {
                  run_thru++;
                  difArr[run_thru] = dist;
               }
            } else {
               //set mask to 1 or true
               mask[r][c] = true;
            }            
         }
      }
   }      
}

void replace(bool mask[SIZE][SIZE], unsigned char inImage[SIZE][SIZE][RGB], 
  unsigned char bgImage[SIZE][SIZE][RGB], unsigned char outImage[SIZE][SIZE][RGB])
{
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         if (mask[i][j] == false) {
            //pixel = chromakey, so it's background
            outImage[i][j][0] = bgImage[i][j][0];
            outImage[i][j][1] = bgImage[i][j][1];
            outImage[i][j][2] = bgImage[i][j][2];
         } else {
            //pixel != chromakey, so it's foreground
            outImage[i][j][0] = inImage[i][j][0];
            outImage[i][j][1] = inImage[i][j][1];
            outImage[i][j][2] = inImage[i][j][2];
         }
      }
   }
}