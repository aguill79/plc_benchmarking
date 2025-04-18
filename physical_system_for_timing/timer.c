#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]){

    int run_flag_port = 10000;
    int run_status_port = 10100;

    int value=1;
    int status = 0;

    int sockfd;
    struct sockaddr_in servaddr, plcaddr;
    int plc_struct_length = sizeof(plcaddr);

    char plc_data[1024];

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.56.1");

    // Set port to recieve from output coil
    servaddr.sin_port = htons(run_status_port);

   
    if(bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr))<0){
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    clock_t diff;

    memset(&servaddr, 0, sizeof(servaddr));

    // Set port to send on input coil port
    servaddr.sin_port = htons(run_flag_port);

    sendto(sockfd, &value, 2, 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    //printf("Message sent.\n");
    
    servaddr.sin_port = htons(run_status_port);

    //status = atoi(plc_data[0]);
    printf("received... \n");

    while(status == 0){
        diff = clock()-start;
        
        if(recvfrom(sockfd, plc_data, sizeof(plc_data), 0, (struct sockaddr*)&plcaddr, &plc_struct_length) <0)
        {
            printf("Failed to connect to output port");
            return -1;
        }
        status = (int)plc_data[0];
        printf("Recieved %d\n", plc_data[0]);
    }

    while(status != 0){
        diff = clock()-start;
        
        if(recvfrom(sockfd, plc_data, sizeof(plc_data), 0, (struct sockaddr*)&plcaddr, &plc_struct_length) <0)
        {
            printf("Failed to connect to output port");
            return -1;
        }
        status = (int)plc_data[0];
        printf("Recieved %d\n", plc_data[0]);
    }
    int msec = (int) (diff * 1000 / CLOCKS_PER_SEC);

    printf("diff: %ld clocks/sec %ld\n", diff, CLOCKS_PER_SEC);
    printf("duation: %d seconds %d milliseconds\n", msec/1000, msec%1000); 


    printf("close socket\n");
    close(sockfd);

    return 0;

}
