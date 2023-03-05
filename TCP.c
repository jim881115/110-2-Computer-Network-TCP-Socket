#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

struct Msgbuf{
    int mtype;
    char context[20];
};

int main(int argc , char *argv[])
{
	//socket的建立
    int sockfd;
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    printf("------------\nconstruct socket\n");
    if(sockfd < 0)
        printf("socket error\n");
    else
        printf("socket success\n");
    printf("------------\n\n");

    //socket的設定(IPv4、port)
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(9999);
    sa.sin_addr.s_addr = inet_addr("134.208.2.60");

    int sta = connect(sockfd, (struct sockaddr *) &sa, sizeof(sa));
    printf("------------\nconnect socket\n");
    if(sta < 0)
        printf("connect error\n");
    else
        printf("connect success\n");
    printf("------------\n\n");

    struct Msgbuf sM; //傳送的封包
    struct Msgbuf rM; //接收的封包
    sM.mtype = 101;
    strcpy(sM.context, "410714203");
	
    //第一次傳送
    printf("First send    mtype: %d     context: %s\n", sM.mtype, sM.context);
    send(sockfd, &sM, sizeof(struct Msgbuf), 0);
    //第一次接收
    recv(sockfd, &rM, sizeof(struct Msgbuf), 0);
    printf("First recv    mtype: %d     context: %s\n", rM.mtype, rM.context);
	
    //學號後八碼與context做xor
    int stu_id = atoi(sM.context) - 400000000;
    int res = stu_id ^ atoi(rM.context);
    char tmp[8];
    sprintf(tmp, "%d", res);

    sM.mtype = 300;
    strcpy(sM.context, tmp);
    //第二次傳送
    printf("Second send    mtype: %d     context: %s\n", sM.mtype, sM.context);
    send(sockfd, &sM, sizeof(struct Msgbuf), 0);
    //第二次接收
    recv(sockfd, &rM, sizeof(struct Msgbuf), 0);
    printf("Second recv    mtype: %d     context: %s\n", rM.mtype, rM.context);

    printf("------------\n");
    if(rM.mtype == 203)
        printf("pass\n");
    else
        printf("fail\n");
    printf("------------\n\n");

    printf("close socket\n");
    close(sockfd); //關閉socket
    return 0;
}
