//Anjana Kummetha 
//NETID: 117162837

#include "cse_caesar.h"
#include "strgPtr.h"
/* DO NOT use <string.h> or <ctype.h> */
// check if a character is a letter
#define EOM_LEN 7
#define EOM "__EOM__"




//check if the char is a letter 
int letterCheck(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    else if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    else{
        return 0;
    }
}
 
// check if a char is a digit
int digitCheck(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    else{
        return 0; 
    }
}

//check if EOM + \0 would fit in the buffer
int EOMCheck(int finalPosition, int bufferSize) {
    if (finalPosition + 7 + 1 <= bufferSize) {
        return 1;
    }
    else{
        return 0;
    }
}

//find where EOM starts and that it has all characters 
int findEOM(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '_' && s[i+1] == '_' && s[i+2] == 'E' && s[i+3] == 'O' && s[i+4] == 'M' && s[i+5] == '_' && s[i+6] == '_') {
            return i;
        }
        else {
            i++;
        }
    }
    return -1;
}


int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    if (plaintext == NULL || ciphertext == NULL) {
        return -2;
    }
    key = ((key % 26) + 26) % 26;
 
    //get buffer size 
    int bufferSize = strgLen(ciphertext) + 1;
 
    //check that EOM will fit 
    if (EOMCheck(0, bufferSize) == 0) {
        return -1;
    }
 
    int i = 0;  
    int encodedCount = 0;  
    int outPosition = 0; 
 
    while (plaintext[i] != '\0') {
        char current = plaintext[i];
 
        //check that you can fit this char and EOM before proceeding 
        if (EOMCheck
        (outPosition + 1, bufferSize) == 0) {
            break;
        }
 
        if (letterCheck(current)) {
            //shift -> (key + i) % 26)
            //uppercase 
            if (current >= 'A' && current <= 'Z') {
                ciphertext[outPosition] = 'A' + (current - 65 + ((key + i) % 26)) % 26;
            }
            //lowercase
            if (current >= 'a' && current <= 'z') {
                ciphertext[outPosition] = 'a' + (current - 97 + ((key + i) % 26)) % 26;
            }
            outPosition++;
            encodedCount++;
        } else if (digitCheck(current)) {
            //shift -> (key + 2*index) % 10
            ciphertext[outPosition] = '0' + (current - '0' +  ((key + 2 * i) % 10)) % 10;
            outPosition++;          
            encodedCount++;
        } else {
            //keep spaces/punctuation the same 
            ciphertext[outPosition] = current;
            outPosition++;
        }

        i++;
    }

    //add EOM and \0
    ciphertext[outPosition]     = '_';
    ciphertext[outPosition + 1] = '_';
    ciphertext[outPosition + 2] = 'E';
    ciphertext[outPosition + 3] = 'O';
    ciphertext[outPosition + 4] = 'M';
    ciphertext[outPosition + 5] = '_';
    ciphertext[outPosition + 6] = '_';
    ciphertext[outPosition + 7] = '\0';
 
    return encodedCount;
}
 



int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    if (ciphertext == NULL || plaintext == NULL) {
        return -2;
    }
    key = ((key % 26) + 26) % 26;
 
    //check size of plaintext and find EOM
    int plainLen = strgLen(plaintext);
    if (plainLen == 0) {
        return 0;
    }
    int eomPos = findEOM(ciphertext);
    if (eomPos == -1) {
        return -1;
    }
 
    int i  = 0; 
    int outPosition = 0; 
    int decodedCount = 0; 
 

    while (i < eomPos) {
        //check that plaintext isn't full 
        if (outPosition >= plainLen) {
            break;
        }
 
        char current = ciphertext[i];
        if (letterCheck(current)) {
            // shift is ((key + i) % 26)
            //uppercase
            if (current >= 'A' && current <= 'Z') {
                plaintext[outPosition] = 'A' + (current - 65 - ((key + i) % 26) + 26) % 26;
            }
             //lowercase
            if (current >= 'a' && current <= 'z') {
                plaintext[outPosition] = 'a' + (current - 97 - ((key + i) % 26) + 26) % 26;
            }
            outPosition++;
            decodedCount++;
 

        } 
        else if (digitCheck(current)) {
            // shift -> (key + 2 * i) % 10
            plaintext[outPosition] = '0' + (current - '0' - ((key + 2 * i) % 10) + 10) % 10;
            outPosition++;
            decodedCount++;
        } else {
            //copy spaces/punctuation 
            plaintext[outPosition] = current;
            outPosition++;
        }

        i++;
    }
 
    plaintext[outPosition] = '\0';
    return decodedCount;
}
