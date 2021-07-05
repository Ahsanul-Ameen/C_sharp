// Note:
// For security reasons, only root processes and processes with the CAP_NET_RAW capabilities
// can create raw sockets. Therefore, we should use sudo to run our spoof program.

//------------------------------------------------------------------------------
// Code for constructing raw ICMP Echo request packet with a spoofed source IP address
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#define MAX_PAYLOAD_SIZE	47



/* ICMP Header */
struct icmpheader {
	unsigned char icmp_type;			// ICMP message type
	unsigned char icmp_code;			// Error code
	unsigned short int icmp_chksum;		// Checksum for ICMP Header and data
	unsigned short int icmp_id;			// Used for identifying request
	unsigned short int icmp_seq; 		// Sequence number
};

/* IP Header */
struct ipheader {
	unsigned char 		iph_ihl:4,		// IP header length
						iph_ver:4;		// IP version
	unsigned char 		iph_tos;		// Type of service
	unsigned short int 	iph_len;		// IP Packet length (data + header)
	unsigned short int  iph_ident;		// Identification
	unsigned short int 	iph_flag:3,		// Fragmentation flags
						iph_offset:13;	// Flags offset	
	unsigned char 		iph_ttl;		// Time to live
	unsigned char		iph_protocol;	// Protocol type
	unsigned short int 	iph_chksum;		// IP datagram checksum
	struct in_addr		iph_sourceip;	// Source IP address
	struct in_addr		iph_destip;		// Destination IP address
};



// Calculating Internet Checksum 
unsigned short in_cksum (unsigned short *buf, int length);
// Given an IP packet , send it out using a raw socket.
void send_raw_ip_packet	(struct ipheader *ip);
// Generate random alphanumeric string
const char *gen_payload(size_t length);


/*************************************************************************************
 * 		Spoof an ICMP echo request using an arbitrary source IP Address
**************************************************************************************/

int main(int argc, char **argv) {

	assert(argc == 4);		// pass the source_ip  dest_ip npackets
	srand(time(NULL));

	int npackets = atoi(argv[3]); // number of packets

	// Send n packets with random payloads
	for (int np = 1; np <= npackets; ++np) {

		const char *payload = gen_payload(rand() % MAX_PAYLOAD_SIZE);
		const size_t PAYLOAD_SIZE = strlen(payload);
		const size_t BUFF_SIZE = sizeof(struct ipheader) + sizeof(struct icmpheader) + PAYLOAD_SIZE;

		char *buffer = NULL;
		buffer = malloc(BUFF_SIZE);			// create a buffer of size BUFF_SIZE
		memset(buffer, 0, BUFF_SIZE);		// fill it with zeros
		memcpy(buffer + BUFF_SIZE - PAYLOAD_SIZE, payload, PAYLOAD_SIZE); // copy the payload

		
		/******************************************************
		 * 		Step 1: Fill in the ICMP header.
		 ******************************************************/

		{
			struct icmpheader *icmp = (struct icmpheader *)(buffer + sizeof(struct ipheader));
			icmp->icmp_type = 8;	// ICMP Type: 8 is request, 0 is reply.	

			// Calculate the checksum for integrity
			icmp->icmp_chksum = 0;
			icmp->icmp_chksum = in_cksum((unsigned short *)icmp, sizeof(struct icmpheader) + PAYLOAD_SIZE);
		}
	

	
		/******************************************************
		 * 		Step 2: Fill in the IP header
		 ******************************************************/
		const char *source_ip = "1.2.3.4";	source_ip = argv[1];
		const char *dest_ip = "10.0.2.69";	dest_ip = argv[2];
		

		struct ipheader *ip = (struct ipheader *) buffer; {
			ip->iph_ver = 4;
			ip->iph_ihl = 5;
			ip->iph_ttl = 20;
			ip->iph_sourceip.s_addr = inet_addr(source_ip);		// Source IP
			ip->iph_destip.s_addr = inet_addr(dest_ip);		// Destination IP
			ip->iph_protocol = IPPROTO_ICMP;
			ip->iph_len = htons(BUFF_SIZE);
		}
	


		/*******************************************************
		 * 		Step 3: Finally, send the spoofed packet
		 *******************************************************/

		printf("# ---- packet[%d] ----\n", np);
		printf("\t# --->> Sending a ICMP echo request packet to dest_ip <%s>....\n", dest_ip);
		send_raw_ip_packet(ip);		// Send out spoofed IP packet
		printf("\t# --->> Spoofed packet with source_ip <%s> sent....\n", source_ip);


		
		// free up memory
		if (buffer) free(buffer);
		buffer = NULL;

		if (payload) free(payload);
		payload = NULL;

	}
	

	return 0;
}


/*****************************************************************
	Given an IP packet , send it out using a raw socket.
	The ipheader structure is already defined above
******************************************************************/

void send_raw_ip_packet (struct ipheader *ip) {
	struct sockaddr_in dest_info;
	int enable = 1;

	// Step 1: Create a raw network socket.
	int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);

	// Step 2: Set socket option
	setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable));

	// Step 3: Provide needed information about destination.
	dest_info.sin_family = AF_INET;
	dest_info.sin_addr = ip->iph_destip;
	//dest_info.sin_addr = *(struct in_addr *) &ip->daddr;

	// Step 4: Send the packet out.
	sendto(sock, ip, ntohs(ip->iph_len), 0, 
			(struct sockaddr *)&dest_info, sizeof(dest_info));

	close(sock);
}


/*********************************************************
		Calculating Internet Checksum 
**********************************************************/
unsigned short in_cksum (unsigned short *buf, int length) {
	unsigned short *w = buf;
	int nleft = length;
	int sum = 0;
	unsigned short temp = 0;

	/**
	 * The algorithm uses a 32 bit accumulator (sum), adds
	 * sequential 16 bit words to it, and at the end, folds back all
	 * the carry bits from the top 16 bits into the lower 16 bits.
	 * */

	while (nleft > 1) {
		sum += *w++;
		nleft -= 2;
	}

	/* treat the odd byte at the end , if any */
	if (nleft == 1) {
		*(u_char *)(&temp) = *(u_char *)w;
		sum += temp;
	}


	/* add back carry outs from top 16 bits to low 16 bits */
	sum = (sum >> 16) + (sum & 0xffff);		// add hi 16 to low 16
	sum += (sum >> 16);						// add carry

	return (unsigned short)(~sum);
}



/*********************************************************
	Generate a random payload string of some length
**********************************************************/
const char *gen_payload(size_t length) {
    const static char charset[] = 
    	"abcdefghijklmnopqrstuvwxyz"
    	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789"
		",.-#'?!";        
		
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}