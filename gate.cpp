# include <stdio.h>
# include <time.h>
# include "E101.h"


int main (){
   
   init();
   
   int quadrant = 1;
   
   char ip[15] = "130.195.6.196";
   
   while (quadrant == 1){
	   
	   
   
	   connect_to_server(ip, 1024);
	   char message[24] = {'P','l','e','a','s','e'};
	   printf("messasge is %s\n",message);
	   send_to_server(message);
	   char received_message[24];
	   receive_from_server(received_message); 
	   
	   send_to_server(received_message);

	   
	   
	   
	   
	   printf("%s", received_message);
	   printf("hello");
	   
	   quadrant =2;
   }

return 0;}
