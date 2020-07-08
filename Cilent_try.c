#include "head.h"

int main(int argc, char *argv[])
{
    char ip[20] = {0};
    int port = 0, sockfd;
    char buff[512] = {0};
    struct sockaddr_in server;

    /*if (argc != 3)
    {
        fprintf(stderr, "Usage :%s ip port!\n", argv[0]);
    }*/

    //strcpy(ip, argv[1]);
    //port = atoi(argv[2]);
    //strcpy(ip, "49.222.141.40");
    //port = atoi("445");
    strcpy(ip, "123.57.102.65");
    port = atoi("8888");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket()\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()\n");
        exit(1);
    }

    while (1) {
        recv(sockfd, buff, sizeof(buff), 0);

        if (buff[0] == 1) {
            sprintf(buff, "2019302180299");
        } else if (buff[0] == 2) {
            sprintf(buff, "Áº¿¤");
        } else if (buff[0] == 3 ) {
            break;
        }



        send(sockfd, buff, strlen(buff), 0);
    }
    close(sockfd);

    return 0;
}
