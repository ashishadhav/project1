/* client */


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include<string.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[])
{
    int sockfd = 0;
    int i=1;
char sendBuff[1025];
    struct sockaddr_in serv_addr; 

  /*  if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } */

    memset(sendBuff, '0',sizeof(sendBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7000); 

    if(inet_pton(AF_INET, "1.23.114.11", &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
      return 1;
    } 

 while(i<=20)
   {
      snprintf(sendBuff, sizeof(sendBuff), "\nclient saying hiiii...");
      fputs(sendBuff, stdout);
     if(send(sockfd,sendBuff,strlen(sendBuff),0)<0)
     {
       printf("sending failed..");
     }
  i++;
   }

return 0;
}



