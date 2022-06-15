#include <string.h>
#include <stdlib.h>
#include "fscrypt.h"
#include <stdio.h>
// Ali Mert Doganay


void *fs_encrypt(void* plaintext, int bufsize, char *keystr, int *resultlen){
  
  int buftemp = bufsize;
  //printf("%d",buftemp);
  BF_KEY key;
  
  char *ptr;                          
  ptr = (char*)malloc(bufsize);
  ptr = (char*)plaintext;
  
  size_t size = ((buftemp + 7)/8) * 8; //xoring, real value = (buftemp+7) & (~7); , 7 is 000..0000111
  char *outbuf = (char*)malloc(size);
  char *outtemp = outbuf;

  BF_set_key(&key,strlen(keystr), (const unsigned char*)keystr);  

  while(buftemp > 7){ //8
    
    BF_ecb_encrypt(ptr,outtemp,&key,BF_ENCRYPT);
    printf("\n");
    
    buftemp -= 8; 
    //printf("%d", buftemp);
    //printf("\n");
    outtemp += 8;
    //printf("%d", *outtemp);
    //printf("\n");
    ptr += 8;
    //printf("%d", *ptr);
    //printf("\n");    
    }
    
  int i;
  if (buftemp > 0){ // 8-8
    char buff_octal[8];
    memcpy(buff_octal,ptr,buftemp);
    for(i = buftemp; i <= 7; i++){    //padding 8 bytes 0x08, using BLOCKSIZE 8
      buff_octal[i] = rand();
    }
    BF_ecb_encrypt(buff_octal,outtemp,&key,BF_ENCRYPT);
    
  //for (int i = 0; i < 16; i++)
  //printf("%02x", (unsigned char)outbuf[i]);      //printing outbuf to check
  //printf("\n");

  }
  *resultlen = (int)strlen(outbuf);
   
  return outbuf;
}


void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen){
  
  int buftemp = bufsize;
  BF_KEY key;
  
  char *ptr;                          
  ptr = (char*)malloc(bufsize);
  ptr = (char*)ciphertext;
  
  size_t size = ((buftemp + 7)/8) * 8; //xoring, real value = (buftemp+7) & (~7); 7 is 000..0000111

  char *outbuf2 = malloc(size);
  char *outtemp = outbuf2;
  
  
  BF_set_key(&key,strlen(keystr), (const unsigned char*)keystr);  

  while(size){
    
    BF_ecb_encrypt(ptr,outtemp,&key,BF_DECRYPT);
 
    size -= 8; 
    outtemp += 8;
    ptr += 8;
    
    }
  int new_len = strlen(outbuf2) + 1; // '\0'
  
  *resultlen = new_len;
   
  return outbuf2;

}

