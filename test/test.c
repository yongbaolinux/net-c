#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <assert.h>

int main(int argc,char *argv[]){
	/*while((ch=getopt(argc,argv,"b"))!= -1){
		switch(ch){
			case 'n':
					printf("the parameter is n");
					printf("%d",optind);
					printf("%s",optarg);
					break;
			case 'g':
					printf("the parameter is g");
					printf("%d",optind);
					printf("%s",optarg);
					break;
			case 'a':
					printf("the parameter is a");
					printf("%d",optind);
					printf("%s",optarg);
					break;
			case 'b':
					printf("the parameter is b");
					printf("%d",optind);
					printf("%s",optarg);
					break;
			case 'l':
				  printf("the parameter is l");
				  printf("%d",optind);
				  printf("%s",optarg);
					break;
			default:
					break;
		}
	}*/
	int sock_fd = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);	//sock句柄
	if(sock_fd < 0){
		fprintf(stderr,"the error:%s,ProcessID:%d",strerror(errno),getpid());
		exit(errno);
	}
	void getip(char *,char*);
	assert(argc == 2);

			char ip[100]={'\0'};				//存放点分制的ip地址
			getip(argv[1],ip);
			printf("%s",ip);
			return EXIT_SUCCESS;
}

/**
 * 根据域名获取IP地址
 * domain char* 域名
 * ip			char* 存放ip字符串
 */
void getip(char* domain,char* ip){
	  //printf("%s",domain);

	  struct addrinfo* res,*cur;
		struct addrinfo hints;
		memset(&hints,0,sizeof(hints));
	  hints.ai_family = AF_INET;
	  hints.ai_socktype = SOCK_STREAM;
	  hints.ai_protocol = 0;
	  hints.ai_flags = AI_PASSIVE;

	  int result = getaddrinfo(domain,NULL,&hints,&res);
	  if(result == 0){		//success
		  for(cur = res;cur!=NULL;cur=cur->ai_next){

				struct sockaddr_in* addr = (struct sockaddr_in *)cur->ai_addr;
				//struct in_addr dst;
				char temp[15] = {'\0'};
				inet_ntop(AF_INET,&addr->sin_addr,temp,16);
				if(strlen(ip) == 0){
					strcpy(ip,temp);
				} else {
					strcat(ip,",");
					strcat(ip,temp);
					}
			}
	  } else {	//failed
	  		fprintf(stderr,"get ip from host failed:%s",gai_strerror(result));
	  		exit(EXIT_FAILURE);
	  	}
}



