//Anjana Kummetha 
//NETID: 117162837

#include <criterion/criterion.h>
#include "../cse_caesar.h"

Test(encryptCaesar, basic) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("abc", buf, 2);
    cr_expect_eq(r, 3);
    cr_expect_str_eq(buf, "ceg__EOM__");
}

Test(decryptCaesar, basic) {
    char buf[32] = "xxxxxxxx";
    int r = decryptCaesar("ceg__EOM__", buf, 2);
    cr_expect_eq(r, 3);
    cr_expect_str_eq(buf, "abc");
}

//testing encryptCaesar
 
//basic encrypt abc with key 2
Test(encryptCaesar, basic1) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("abc", buf, 2);
    cr_assert_eq(r, 3);
    cr_assert_str_eq(buf, "ceg__EOM__");
}
//encrypt with key 0
Test(encryptCaesar, keyZero) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("CS", buf, 0);
    cr_assert_eq(r, 2);
    cr_assert_str_eq(buf, "CT__EOM__");
}
//encrypt mixed case with key 3
Test(encryptCaesar, mixedCase) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("Ayb", buf, 3);
    cr_assert_eq(r, 3);
    cr_assert_str_eq(buf, "Dcg__EOM__");
}
//encrypt with digits
Test(encryptCaesar, withDigits) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("Cse220", buf, 1);
    cr_assert_eq(r, 6);
    cr_assert_str_eq(buf, "Duh911__EOM__");
}
//NULL plaintext returns -2
Test(encryptCaesar, nullPlaintext) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar(NULL, buf, 1);
    cr_assert_eq(r, -2);
}
//NULL ciphertext returns -2
Test(encryptCaesar, nullCiphertext) {
    int r = encryptCaesar("hello", NULL, 1);
    cr_assert_eq(r, -2);
}
//buffer too small so returns -1
Test(encryptCaesar, bufferTooSmall) {
    char buf[4] = "abc";
    int r = encryptCaesar("hello", buf, 1);
    cr_assert_eq(r, -1);
}
//empty plaintext returns 0 and writes EOM
Test(encryptCaesar, emptyPlaintext) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("", buf, 1);
    cr_assert_eq(r, 0);
    cr_assert_str_eq(buf, "__EOM__");
}
//wrap around z to a with key 1
Test(encryptCaesar, wrapAround) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("z", buf, 1);
    cr_assert_eq(r, 1);
    cr_assert_str_eq(buf, "a__EOM__");
}
//spaces are copied unchanged
Test(encryptCaesar, spacesUnchanged) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("a b", buf, 1);
    cr_assert_eq(r, 2);
    cr_assert_str_eq(buf, "b e__EOM__");
}
//negative key wraps correctly for encrypt
Test(encryptCaesar, negative_key) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = encryptCaesar("a", buf, -1);
    cr_assert_eq(r, 1);
    cr_assert_str_eq(buf, "z__EOM__");
}
 
//testing decryptCaesar 
 
//basic decrypt with key 2
Test(decryptCaesar, basic1) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("ceg__EOM__", buf, 2);
    cr_assert_eq(r, 3);
    cr_assert_str_eq(buf, "abc");
}
//decrypt with key 0
Test(decryptCaesar, keyZero) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("CT__EOM__", buf, 0);
    cr_assert_eq(r, 2);
    cr_assert_str_eq(buf, "CS");
}
//decrypt mixed case with key 3
Test(decryptCaesar, mixedCase) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("Dcg__EOM__", buf, 3);
    cr_assert_eq(r, 3);
    cr_assert_str_eq(buf, "Ayb");
}
//decrypt with digits
Test(decryptCaesar, withDigits) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("Duh911__EOM__", buf, 1);
    cr_assert_eq(r, 6);
    cr_assert_str_eq(buf, "Cse220");
}
//NULL ciphertext returns -2
Test(decryptCaesar, nullCiphertext) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar(NULL, buf, 1);
    cr_assert_eq(r, -2);
}
//NULL plaintext returns -2
Test(decryptCaesar, nullPlaintext) {
    int r = decryptCaesar("ceg__EOM__", NULL, 1);
    cr_assert_eq(r, -2);
}
//missing EOM returns -1
Test(decryptCaesar, missingEOM) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("ceg", buf, 1);
    cr_assert_eq(r, -1);
}
//plaintext length 0 returns 0
Test(decryptCaesar, plaintextLengthZero) {
    char buf[1] = "";
    int r = decryptCaesar("ceg__EOM__", buf, 1);
    cr_assert_eq(r, 0);
}
//wrap around decryption
Test(decryptCaesar, wrapAround) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("a__EOM__", buf, 1);
    cr_assert_eq(r, 1);
    cr_assert_str_eq(buf, "z");
}
//spaces are copied without being changed 
Test(decryptCaesar, spacesUnchanged) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("b e__EOM__", buf, 1);
    cr_assert_eq(r, 2);
    cr_assert_str_eq(buf, "a b");
}
//negative key wraps correctly for decrypt
Test(decryptCaesar, negative_key) {
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    int r = decryptCaesar("z__EOM__", buf, -1);
    cr_assert_eq(r, 1);
    cr_assert_str_eq(buf, "a");
}