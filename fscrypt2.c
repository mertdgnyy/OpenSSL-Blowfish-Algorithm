#include <string.h>
#include <stdlib.h>
#include "fscrypt.h"
#include <stdio.h>
// Ali Mert Doganay

void *fs_encrypt(void* plaintext, int bufsize, char *keystr, int *resultlen){
  
  unsigned char iv[BLOCKSIZE]; //BLOCKSIZE = 8 given in fscrypt.h

  BF_KEY key;
 
  char *outbuf = (char*)malloc(bufsize);
  
  memset(iv,0,8);
  int i;
  /////////////////////////////////////////
  //char *ptr;                          // Creating a ptr that holds the address of plain text
  //ptr = (char*)malloc(bufsize);
  //ptr = (char*)plaintext;
  //                                    // Not used since plaintext value can be used standalone.
  //for(i = 0; i < bufsize ; i++){         
  //  printf("%c", ptr[i]);              
  //}                                    //I used it for testing the values. 
  //////////////////////////////////////////
  
  printf("\n");
  printf("Value of plaintext:");    // Printing plaintext value to check
  printf("%s", plaintext);
  printf("\n");
  ///////////////////////////////////////////////////
  printf("Value of bufsize: ");                    //Printing bufsize value to check 
  printf("%d",bufsize);
  ///////////////////////////////////////////////////
  printf("\n");
  printf("Value of keystr: ");
  for(i = 0; i < strlen(keystr) ; i++){            //Printing keystr value to check
    printf("%c", keystr[i]);
  }
  printf("\n");
  ////////////////////////////////////////////////////
  
  printf("First value of resultlen: %d ",*resultlen);
  printf("\n");

  //printf("%d", strlen((const char*)keystr));  10

  BF_set_key(&key,strlen(keystr), (const unsigned char*)keystr);  

  BF_cbc_encrypt(plaintext,(unsigned char*)outbuf,bufsize,&key,iv,BF_ENCRYPT);
  
  *resultlen = strlen(outbuf);
  
  return outbuf;
  

}

void *fs_decrypt(void *ciphertext, int bufsize, char *keystr, int *resultlen){

  unsigned char iv[BLOCKSIZE];
  
  //printf("%d",bufsize); //16
  BF_KEY key;
  
  char *outbuf = (char*)malloc(bufsize);
  
  memset(iv,0,8);

  BF_set_key(&key,strlen(keystr), (const unsigned char*)keystr);

  BF_cbc_encrypt(ciphertext,(unsigned char*)outbuf,bufsize,&key,iv,BF_DECRYPT);
  
  int new_len = strlen(outbuf) + 1; // '\0'
  
  *resultlen = new_len; //12

  return outbuf;
  
}


