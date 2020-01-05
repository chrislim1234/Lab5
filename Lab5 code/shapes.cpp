#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
    int bottom = top + height;
    int right = left + width;
    for(int i=left; i<right+1; i++) {
        if (top>=0 && bottom<=255 && left>=0 && right<=255) {
        image[top][i]=0;
        image[bottom][i]=0;
        }
        }
    for(int i=top; i<bottom+1; i++) {
        if (top>=0 && bottom<=255 && left>=0 && right<=255) {
            image[top][i]=0;
            image[bottom][i]=0;
        image[i][left]=0;
        image[i][right]=0;
        }
    }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
    for (double theta=0.0; theta < 2*M_PI; theta += .01) {
        double x = width*cos(theta)-cx;
        double y = height*sin(theta)-cy;
        x += SIZE/2;
        y += SIZE/2;
        image[(int)y][(int)x] = 0;
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
    int input;
    int shape[4];
    while (input!=2) {
    cout << "Please input 0 for rectangle, 1 for ellipse and 2 to quit";
    cin >> input;
        if (input==0) {
            cout << "Please input TR, LC, H, W. TR stands for top row, LC stands for left column. H & W stands for height and width. ";
            cin >> input;
            for (int i=0; i<4; i++) {
                shape[i] = input;
            }
            draw_rectangle(shape[0],shape[1],shape[2],shape[3]);
        }
        if (input==1) {
            cout << "Please input CR, CC, H, W. CR & CC stands for Center Row and Column. H & W stands for height and width.";
            cin >> input;
            for (int i=0; i<4; i++) {
                shape[i] = input;
            }
            draw_ellipse(shape[0], shape[1], shape[2], shape[3]);
       }
    }
    
    // Write the resulting image to the .bmp file
    writeGSBMP("output.bmp", image);
    
    return 0;
}

