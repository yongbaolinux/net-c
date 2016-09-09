#include<memory.h>
#include<netinet/ip_icmp.h>

#define PACKAGE_LENGTH 64 //the length of icmp package
#define SEND_PACKAGE_COUNT 3 //the mount of sent packge

u_int16_t f_checksum(struct icmphdr* icmp);
u_int32_t sockfd;


//initial the icmp package
void init_icmp(u_int16_t sequence){
	char icmp[PACKAGE_LENGTH];
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
	}
	while(sum >> 16){
		sum=(sum>>16) + (sum & 0xffff);
	}
	sum = ~sum;
	return sum;
}
//send the icmp package
void send_icmp(){
	for(int i=0;i<SEND_PACKAGE_COUNT;i++){
		init_icmp(i);
	}
}

void main(char** args,int argc){
	sockfd = sock


}
