/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

/*
   source-address    |  Dest source-address
   2 bits | 6bits len| if-index
   data

*/

/*
  extract_pkt(char *buffer, int len)
*/

#define ADDRESS_LEN 2

void
extract_pkt(char *buffer, int pkt_len){
    
    uint8_t *data;
    uint8_t bits = 0x03, len=0x3F;  /*0011 1111  3F*/
    uint32_t if_idx = 0xFFFFFF00;
    int data_len;
    int i;
    if(!buffer){
        return;
    }

    printf("Src: %x", *(uint16_t *)buffer);
    printf("\nDst: %x", *(uint16_t *)(buffer+ADDRESS_LEN));
    printf("\nbits %x", ((*(uint8_t*)(buffer+4) & bits)));
    printf("\nlen %x", ((*(uint8_t*)(buffer+4) & len)));
    
    data_len = (pkt_len*sizeof(int)) - 8;
    
    printf("\nif-index %x",htonl((*(uint32_t*)(buffer+5)) & if_idx));

    
    //data = (char *) calloc(data_len, sizeof(char));
    
    //memcpy(data, buffer+8, data_len);
    data = buffer+8;
  
    printf("\ndata-len: %d\n", data_len);

    //printf("\ndata: %x", *(uint8_t *)data);
    for(i=0;i<data_len;i++){
        printf("%x ", *((uint8_t *)(data+i)));
    }
    printf("\n");
    
    return;
}





int main()
{
    int buff[5] = {0x02020303,0xbfaeaeae,0x0c0c0c0c, 0x0d0d0d0d, 0x0e0e0e0e};
    //char buff[] = {0x02, 0x02, 0x03, 0x03, 0xbf, 0xae, 0xae, 0xae,0x0c, 0x0c, 0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e};
   
    int i, size = sizeof(buff)/sizeof(int);
    for(i=0;i<size;i++)
       printf("%x ", buff[i]);
    printf("\n");
    extract_pkt((char *)buff, size);

    return 0;
}

