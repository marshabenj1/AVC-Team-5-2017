#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {
	
	init();

	int quadrant = 1;
	char ip[15] = "130.195.6.196";
	
	while (quadrant == 1){
	   
	   connect_to_server(ip, 1024);
	   char message[24] = {'P','l','e','a','s','e'};
	   send_to_server(message);
	   char received_message[24];
	   receive_from_server(received_message); 
	   
	   send_to_server(received_message);
	   
	   printf("Entering Quadrant 2 \n");
	   quadrant =2;
   }
	
	int leftSpeed = 60;
	int rightSpeed = 60;
	
	int previousSum = 0;
	float kp = 0.2;// proportional constant. Value is placeholder.
	float kd = 0.2;// derivative constant. Value is placeholder.
	int threshold = 100;// this is the number used to determine if a pixel is black or white.
	char wh[320];
	char vertwh[240];
	
	
	while (quadrant == 2) {
		
		int whitepixels = 0;
		int sum = 0;

		take_picture();
		
		//Creates an array of 320 pixel values, horizontal line halfway up the picture. Pushes each pixel to either entirely black or entirely white.
		int i;
		char PIX[320];
		
		for (i=0; i<320; i++) {
			 PIX[i] = get_pixel(120,i,3);
			
			if (PIX[i] < threshold) {
				wh[i] = 0;
			} else {
				wh[i] = 1;
				whitepixels++;
			}
			sum += (wh[i]*(i-160));// this is the sum error
		}
		int proportional_signal_error = sum * kp;
		int derivative_signal_error = (sum - previousSum)*kd;
		previousSum = sum;
		
		
		int final_signal = proportional_signal_error + derivative_signal_error;
		
		int scalefactor = 40;
		
		final_signal /= scalefactor;
		
		if (whitepixels > 250) {
			printf("Entering Quadrant 3 \n");
			quadrant = 3;
		}
		else if (whitepixels > 5) {
			set_motor(1, (leftSpeed - final_signal));
			set_motor(2, (rightSpeed + final_signal));
		}
		else {
			set_motor(1, -60);
			set_motor(2, -60);
			sleep1(0,200000);
		}
		
	}
	
	
	while (quadrant == 3) {
		int whitepixels = 0;
		int sum = 0;
		int vertSum = 0;
		take_picture();
		
		int i;
		char horizontal[320];
		char vertical[240];
		
		for (i=0; i<320; i++) {
			 horizontal[i] = get_pixel(120,i,3);
			
			if (horizontal[i] < threshold) {
				wh[i] = 0;
			} else {
				wh[i] = 1;
				whitepixels++;
			}
			sum += (wh[i]*(i-160));// this is the sum error
		}
		
		for (i=0; i<240; i++) {
			vertical[i] = get_pixel(i,160,3);
			
			if (vertical[i] < threshold) {
				vertwh[i] = 0;
			} else {
				vertwh[i] = 1;
			}
			vertSum += (vertwh[i]);// 	(vertwh[i])
		}
		int proportional_signal_error = sum * kp;
		int derivative_signal_error = (sum - previousSum)*kd;
		previousSum = sum;
		
		
		int final_signal = proportional_signal_error + derivative_signal_error;
		
		int scalefactor = 40;
		
		final_signal /= scalefactor;
		//printf("VertSum = %d \n", vertSum);
		
		int leftwhite = 0;
		int rightwhite = 0;
		
		for (int i = 0; i <160; i++) {
			rightwhite += wh[i];
			leftwhite += wh[(i+160)];
		}
		
		
		if (vertSum > 40){ //(vertSum > 60)
			if (!(wh[320] == 1) && !(wh[0] == 1) ) {// &&	(!(wh[320] == 1) && !(wh[0] == 1) ) 	if(sum < 1000 && sum > -1000)
				set_motor(1, (leftSpeed - final_signal));
				set_motor(2, (rightSpeed + final_signal));
			} else {
				set_motor(1, (leftSpeed));
				set_motor(2, (rightSpeed));
			}
		} else if (vertSum <= 40 &&  vertSum >0) {
			//printf("Sum = %d \n", sum);
			
			if (leftwhite >= 40) {
				set_motor(1,-70);
				set_motor(2,70);
				sleep1(0,250000);
			} else {
				set_motor(1,70);
				set_motor(2,-70);
				sleep1(0,250000);
			}
			
			//else{
			//	set_motor(1, (-50));
				//set_motor(2, (-100));
				//sleep1(0,100000);
			//}
			
			
		}
		else{
			//if (sum >= 0) {
				//set_motor(1,-70);
				//set_motor(2,70);
				//sleep1(0,100000);
			//}
			//else {//if (sum < 0) 
			//	set_motor(1,70);
				//set_motor(2,-70);
			//	sleep1(0,100000);
			//}
			printf("REVERSE! \n");
			set_motor(1, (-50));
			set_motor(2, (-50));
			sleep1(0,100000);
			
				//set_motor(1, (-100));  //Should this have some sort of 'else' beside it, Sion?
				//set_motor(2, (-50));
				//sleep1(0,100000);
		}

		
	}
		
	
return 0;}
