#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {
	
	init();
	
	//To let us swap to different logic easily.
	int quadrant = 1;
	
	int leftSpeed = 50;
	int rightSpeed = 50;
	
	bool skewLeft = false;
	bool skewRight = false;
	
	//motor 1 is on the left, 2 is on the right.
	set_motor(1,leftSpeed);
	set_motor(2,rightSpeed);
	
	while (quadrant == 1) {
		// we need a method for like a while loop that takes a picture every x milliseconds as the code runs.
		take_picture();
		int pictureSum = 0;
		int kp = 0.1;// proportional constant. Value is placeholder.
		int kd = 0.2;// derivative constant. Value is placeholder.
		int threshold = 128;// this is the number used to determine if a pixel is black or white.
		int sum = 0;
		int previousSum = 0;
		
		//Creates an array of 320 pixel values, horizontal line halfway up the picture. Pushes each pixel to either entirely black or entirely white.
		int i;
		int[320] horizontal;// examples had this as char PIX[320] im unsure if this is correct.
		for (i=0; i<320; i++) {
			horizontal[i] = get_pixel(i,120,3);
			
			if (horizontal[i] < threshold) {
				horizontal[i] = 0;
			} else {
				horizontal[i] = 255;
			}
			sum += (horizontal[i]*(i-160);// this is the sum error
		}
		int proportional_signal_error = sum * kp;
		int proportional_signal_error = (sum - previousSum)*kd;
		previousSum = sum;
		//Still need to add in the determination of skewleft/skewright here
		
		
		//If we're skewing either direction, increase speed in one motor. Otherwise, reset to standard speed.
		//if (skewLeft) {
			//rightSpeed += 5;
		//} else if (skewRight) {
			//leftSpeed += 5;
		//} else {
			//leftSpeed = 50;
			//rightSpeed = 50;
		//}
		final_signal = proportional_signal_error + proportional_signal_error;
		set_motor(1,leftSpeed * final_signal);
		set_motor(2,rightSpeed * final_signal);
		
	}
		
	
return 0;}
