//Anjana Kummetha 
//NETID: 117162837
#include "strgPtr.h"

/* DO NOT use <string.h> or <ctype.h> */
//return len of a string 
int strgLen(const char *s) {
    if (s == NULL) {
        return -1;
    }
    int x = 0;
    while (*s++) {
        x++;
    }
    return x;
}


//copy a string and truncate if needed 
void strgCopy(const char *source, char *destination, size_t size) {
    if (source == NULL || size == 0 || destination == NULL) {
        return;
    }
    else if (size == 1) {
        *destination = '\0';
        return;
    }
    //copy the string 
    size_t x = 0;
    while (x < size - 1 && *source != '\0') {
        *destination++ = *source++;
        x++;
    }
    *destination = '\0';
}



//flips capital and lowercase letters if it doesn't have a digit to its left and right, if its not a letter don't change it
void strgChangeCase(char *s) {
    if (s == NULL) {
        return;
    }
    int len = strgLen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        // check if its not a letter 
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            continue;
        }
        // check for digits on the left and right 
        int left  = (i > 0) && (s[i - 1] >= '0' && s[i - 1] <= '9');
        int right = (i < len - 1) && (s[i + 1] >= '0' && s[i + 1] <= '9');
        if (left || right) {
            continue;
        }
        // flip the letter 
        if (c >= 'A' && c <= 'Z') {
            s[i] = c + 32;} 
            else {
            s[i] = c - 32; 
        }
    }
}

//returns index where there is a difference between both strings
int strgDiff(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        return -2;
    }


    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return i;
           }
        i++;
    }
    //return -1 if they are equal 
    if (s1[i] == '\0' && s2[i] == '\0') {
        return -1;
    }
    // return idex if one string ended first 
    return i;
}



//interleave two strings into each other 
void strgInterleave(const char *s1, const char *s2, char *d, size_t size) {
    if (size == 0 || s1 == NULL || s2 == NULL || d == NULL) {
        return;
    }

    //copy chars from s1 and s2 and move the pointers 
    size_t di = 0;
    while (*s1 != '\0' && *s2 != '\0' && di < size - 1) {
        d[di++] = *s1++;
        if (di < size - 1) {
            d[di++] = *s2++;
        } else {
            s2++;
        }
    }
 
    // copying leftover characters from longer string if needed 
    while (*s1 != '\0' && di < size - 1) {
        d[di++] = *s1++;
    }
    while (*s2 != '\0' && di < size - 1) {
        d[di++] = *s2++;
    }
 
    d[di] = '\0';
}



//reverse letters in the string, if its not a letter then keep it at the same position
void strgReverseLetters(char *s) {
    if (s == NULL) {
        return;
    }
    int left  = 0;
    int right = strgLen(s) - 1;
 
    while (left < right) {
        //look for a letter from the elft 
        while (left < right && !((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z'))) {
            left++;
        }
        //look for a letter from the right 
        while (left < right && !((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z')) ) {
            right--;
        }

        if (left < right) {
            char temp = s[left];
            s[left]   = s[right];
            s[right]  = temp;
            right--;
            left++;
        }
    }
}
