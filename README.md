# OpenSSL-Blowfish-Algorithm

Blowfish is a symmetric-key block cipher that provides good encryption rate with no disclosed effective cryptanalysis. Blowfish uses 64-bit blocks and typically 128-bit keys; you can find a description of the Blowfish algorithm at https://www.schneier.com/academic/blowfish/ and http://www.counterpane.com/blowfish.html.

In this project I used OpenSSL's libcrypto to implement the Blowfish block cipher. You can find a current description of all the OpenSSL functions at https://www.openssl.org/docs/man1.1.1/man3/.

In this project BF_cbc_encrypt, BF_ecb_encrypt, and BF_set_key functions were used which are described at https://www.openssl.org/docs/man1.1.1/man3/BF_encrypt.html.

# It contains;

**Makefile to compile the driver executables.**

**main.c, which contains a driver program.**

**fscrypt.h, which contains a block size definition, and the two function prototypes**

**fscrypt.c and fscrypt2.c, which are CBC-mode Encryption/Decryption**

# Assumptions of the project:

**Use CBC mode of encryption and decryption.**

**Pad the buffer with null bytes so that the input is always a multiple of the block size.**

**The initialization vector must be comprised of all null characters.**

**Both functions must allocate the result buffer of at least the required size (using malloc() or new).**

**Both functions also return the number of valid bytes in the result buffer pointed to by resultlen.**

**The application “caller” code is responsible for subsequently freeing the buffer pointed to by plaintext or ciphertext**
