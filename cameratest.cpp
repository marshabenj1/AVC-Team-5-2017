#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
  init();
  
  
  int i;
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
  //for (i=0, i <320, i++){
    //w = get_pixel(i, 120, 3);
    //sum = sum + i*w;}
    // if the sum of the numbers is positive turn a distance to the right depending on how large the number is
    // if the sum of the number sis negative turn left
    // if the sum = 0 travel straight forward
}
