#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
  init();
  
  int row;
  int column;
  row = 120;
  column = 0;
  take_picture();// picture is 320*240 pixels
  char PIX[320]; this is an array where we will store the results of get_pixel
  
  while (column < 160){
    PIX[column] = get_pixel(row, column, 3);  //get_pixel third variable is 3 denotes that it is an rgb value
    column = column + 10;
  }
  
}
