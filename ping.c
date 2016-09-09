#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<netinet/ip_icmp.h>
#include<sys/socket.h>
#include<netdb.h>

#define PACKAGE_LENGTH 64 //the length of icmp package
#define SEND_PACKAGE_COUNT 3 //the mount of sent packge

u_int16_t f_checksum(struct icmphdr* icmp);
u_int32_t sockfd;
struct sockaddr_in hostsockaddr;//IPv4 protocol structure
char icmp[PACKAGE_LENGTH];

//initial the icmp package
void init_icmp(u_int16_t sequence){
	memset(icmp,'a',PACKAGE_LENGTH);
	struct icmphdr* p_icmp = (struct icmphdr*) icmp;
	p_icmp->type = ICMP_ECHO;
	p_icmp->code = 0;
	p_icmp->checksum = 0;
	p_icmp->un.echo.id = getpid();
	p_icmp->un.echo.sequence = sequence;
	
	u_int16_t checksum = f_checksum((struct icmphdr*)icmp);
	p_icmp->checksum = checksum;
}

//check the sum
u_int16_t f_checksum(struct icmphdr* icmp){
	u_int32_t sum=0;
	u_int16_t * p_int=(u_int16_t *)icmp;
	u_int16_t index = PACKAGE_LENGTH;
	while(index > 0){
		sum+=*p_int++;
		index-=2;				//lack of this line will case segmentation fault
	}
	while(sum >> 16){
		sum=(sum>>16) + (sum & 0xffff);
	}
	sum = ~sum;
	return sum;
}
//send the icmp package
void send_icmp(){
	int i;	
	for(i=0;i<SEND_PACKAGE_COUNT;i++){
		init_icmp(i);
		sendto(sockfd,icmp,PACKAGE_LENGTH,0,(struct sockaddr*)&hostsockaddr,sizeof(struct sockaddr));
	}
}

void main(int argc,char *args[]){
	struct protoent * protocol;
	if((protocol = getprotobyname("icmp")) == NULL){
		perror("Fail to call getprotobyanme");
		exit(EXIT_FAILURE);
	}
	sockfd = socket(AF_INET,SOCK_RAW,protocol->p_proto);
	if(sockfd < 0){
		perror("Fail to open socket");
		exit(EXIT_FAILURE);
	}

	//initial the sockaddr
	bzero(&hostsockaddr,sizeof(hostsockaddr));
	hostsockaddr.sin_family = AF_INET;
	u_int64_t net = inet_addr(args[1]);
	hostsockaddr.sin_addr.s_addr = net;
	send_icmp();
	
}


