//Anjana Kummetha 
//NETID: 117162837

#include <criterion/criterion.h>
#include "../strgPtr.h"

Test(strgLen, basic) {
    cr_expect_eq(strgLen("Stony Brook"), 11);
    cr_expect_eq(strgLen(""), 0);
    cr_expect_eq(strgLen(NULL), -1);
}

Test(strgCopy, truncation) {
    char d[5];
    strgCopy("Computer Science", d, 5);
    cr_expect_str_eq(d, "Comp");
}

Test(strgChangeCase, adjacency) {
    char s[] = "Stony Brook";
    strgChangeCase(s);
    cr_expect_str_eq(s, "sTONY bROOK");
}

Test(strgInterleave, priority) {
    char d[6];
    strgInterleave("abcdef", "12", d, 6);
    cr_expect_str_eq(d, "a1b2c");
}




//testing strgLen
 
//basic string
Test(strgLen, normal_string) {
    cr_assert_eq(strgLen("Stony Brook"), 11);
}
//empty string returns 0
Test(strgLen, empty_string) {
    cr_assert_eq(strgLen(""), 0);
}
//NULL returns -1
Test(strgLen, null_pointer) {
    cr_assert_eq(strgLen(NULL), -1);
}
//single character
Test(strgLen, single_char) {
    cr_assert_eq(strgLen("a"), 1);
}
//string with spaces
Test(strgLen, string_with_spaces) {
    cr_assert_eq(strgLen("CSE 220"), 7);
}

//string with digits
Test(strgLen, string_with_digits) {
    cr_assert_eq(strgLen("abc123"), 6);
}
//longer string
Test(strgLen, longer_string) {
    cr_assert_eq(strgLen("System Fundamental"), 18);
}
//single digit
Test(strgLen, single_digit) {
    cr_assert_eq(strgLen("1"), 1);
}
//string with punctuation
Test(strgLen, punctuation) {
    cr_assert_eq(strgLen("CSE-220"), 7);
}
//string with only spaces
Test(strgLen, only_spaces) {
    cr_assert_eq(strgLen("   "), 3);
}
 
 
//testing strgCopy
 
//basic copy when destination is large enough
Test(strgCopy, basic_copy) {
    char d[20];
    strgCopy("hello", d, 20);
    cr_assert_str_eq(d, "hello");
}
//truncation when destination is too small
Test(strgCopy, truncation2) {
    char d[5];
    strgCopy("Computer Science", d, 5);
    cr_assert_str_eq(d, "Comp");
}
//size 1 stores only null terminator
Test(strgCopy, size_one) {
    char d[1];
    strgCopy("hello", d, 1);
    cr_assert_str_eq(d, "");
}
//empty source copies empty string
Test(strgCopy, empty_source) {
    char d[10] = "xxxxxxxx";
    strgCopy("", d, 10);
    cr_assert_str_eq(d, "");
}
//NULL source does nothing
Test(strgCopy, null_source) {
    char d[10] = "original";
    strgCopy(NULL, d, 10);
    cr_assert_str_eq(d, "original");
}
//NULL destination does nothing
Test(strgCopy, null_destination) {
    strgCopy("hello", NULL, 10);
    cr_assert(1);
}
//size 0 does nothing
Test(strgCopy, size_zero) {
    char d[10] = "original";
    strgCopy("hello", d, 0);
    cr_assert_str_eq(d, "original");
}
//exact fit
Test(strgCopy, exact_fit) {
    char d[6];
    strgCopy("hello", d, 6);
    cr_assert_str_eq(d, "hello");
}
//copy with digits
Test(strgCopy, copy_with_digits) {
    char d[10];
    strgCopy("CSE-220", d, 10);
    cr_assert_str_eq(d, "CSE-220");
}
//copy single character
Test(strgCopy, single_char) {
    char d[5];
    strgCopy("A", d, 5);
    cr_assert_str_eq(d, "A");
}
 
 
//testing strgChangeCase
 
//basic flip
Test(strgChangeCase, basic_flip) {
    char s[] = "Stony Brook";
    strgChangeCase(s);
    cr_assert_str_eq(s, "sTONY bROOK");
}
//letter next to digit on right does not flip
Test(strgChangeCase, digit_on_right) {
    char s[] = "a1b";
    strgChangeCase(s);
    cr_assert_str_eq(s, "a1b");
}
//letter next to digit on left does not flip
Test(strgChangeCase, digit_on_left) {
    char s[] = "1a";
    strgChangeCase(s);
    cr_assert_str_eq(s, "1a");
}
//NULL does nothing
Test(strgChangeCase, null_pointer) {
    strgChangeCase(NULL);
    cr_assert(1);
}
//empty string does nothing
Test(strgChangeCase, empty_string) {
    char s[] = "";
    strgChangeCase(s);
    cr_assert_str_eq(s, "");
}
//mixed digits and letters
Test(strgChangeCase, mixed_digits) {
    char s[] = "CSE220";
    strgChangeCase(s);
    cr_assert_str_eq(s, "csE220");
}
//only digits no change
Test(strgChangeCase, only_digits) {
    char s[] = "12345";
    strgChangeCase(s);
    cr_assert_str_eq(s, "12345");
}
//all uppercase flips to lowercase
Test(strgChangeCase, all_uppercase) {
    char s[] = "HELLO";
    strgChangeCase(s);
    cr_assert_str_eq(s, "hello");
}
//all lowercase flips to uppercase
Test(strgChangeCase, all_lowercase) {
    char s[] = "hello";
    strgChangeCase(s);
    cr_assert_str_eq(s, "HELLO");
}
//letter sandwiched between digits does not flip
Test(strgChangeCase, sandwiched_by_digits) {
    char s[] = "1a2";
    strgChangeCase(s);
    cr_assert_str_eq(s, "1a2");
}
 
 
//testing strgDiff
 
//equal strings return -1
Test(strgDiff, equal_strings) {
    cr_assert_eq(strgDiff("Hello", "Hello"), -1);
}
//difference at index 3
Test(strgDiff, diff_at_index_3) {
    cr_assert_eq(strgDiff("CSE-220", "CSE220"), 3);
}
//difference at index 0
Test(strgDiff, diff_at_index_0) {
    cr_assert_eq(strgDiff("CSE220", "SE220"), 0);
}
//both empty strings equal
Test(strgDiff, both_empty) {
    cr_assert_eq(strgDiff("", ""), -1);
}
//one string is prefix of the other
Test(strgDiff, prefix) {
    cr_assert_eq(strgDiff("abc", "abcd"), 3);
}
//NULL first argument returns -2
Test(strgDiff, null_first) {
    cr_assert_eq(strgDiff(NULL, "hello"), -2);
}
//NULL second argument returns -2
Test(strgDiff, null_second) {
    cr_assert_eq(strgDiff("hello", NULL), -2);
}
//both NULL returns -2
Test(strgDiff, both_null) {
    cr_assert_eq(strgDiff(NULL, NULL), -2);
}
//completely different strings
Test(strgDiff, completely_different) {
    cr_assert_eq(strgDiff("abc", "xyz"), 0);
}
//difference at last character
Test(strgDiff, diff_at_last_char) {
    cr_assert_eq(strgDiff("abcd", "abce"), 3);
}
 
 
//testing strgInterleave
 
//basic interleave equal length
Test(strgInterleave, equal_length) {
    char d[7];
    strgInterleave("abc", "123", d, 7);
    cr_assert_str_eq(d, "a1b2c3");
} 
//s1 longer than s2
Test(strgInterleave, s1_longer) {
    char d[10];
    strgInterleave("abcdef", "123", d, 10);
    cr_assert_str_eq(d, "a1b2c3def");
}
//s2 longer than s1
Test(strgInterleave, s2_longer) {
    char d[10];
    strgInterleave("cse", "12345", d, 10);
    cr_assert_str_eq(d, "c1s2e345");
}
//truncation when size is too small
Test(strgInterleave, truncation) {
    char d[6];
    strgInterleave("abcdef", "12", d, 6);
    cr_assert_str_eq(d, "a1b2c");
}
//empty s1
Test(strgInterleave, empty_s1) {
    char d[10];
    strgInterleave("", "123", d, 10);
    cr_assert_str_eq(d, "123");
}
//empty s2
Test(strgInterleave, empty_s2) {
    char d[10];
    strgInterleave("abc", "", d, 10);
    cr_assert_str_eq(d, "abc");
}
//both empty
Test(strgInterleave, both_empty) {
    char d[10];
    strgInterleave("", "", d, 10);
    cr_assert_str_eq(d, "");
}
//NULL s1 does nothing
Test(strgInterleave, null_s1) {
    char d[10] = "original";
    strgInterleave(NULL, "123", d, 10);
    cr_assert_str_eq(d, "original");
}
//size 1 stores only null terminator
Test(strgInterleave, size_one) {
    char d[1];
    strgInterleave("abc", "123", d, 1);
    cr_assert_str_eq(d, "");
}
//size 4 truncates correctly
Test(strgInterleave, size_four) {
    char d[4];
    strgInterleave("abc", "123", d, 4);
    cr_assert_str_eq(d, "a1b");
}
 
 
//testing strgReverseLetters
 
//basic reverse
Test(strgReverseLetters, basic) {
    char s[] = "Hello";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "olleH");
}
//non-letters stay in place
Test(strgReverseLetters, non_letters_stay) {
    char s[] = "ab-cd";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "dc-ba");
}
//digits stay in place
Test(strgReverseLetters, digits_stay) {
    char s[] = "a1b2c";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "c1b2a");
}
//NULL does nothing
Test(strgReverseLetters, null_pointer) {
    strgReverseLetters(NULL);
    cr_assert(1);
}
//empty string does nothing
Test(strgReverseLetters, empty_string) {
    char s[] = "";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "");
}
//single letter stays the same
Test(strgReverseLetters, single_letter) {
    char s[] = "a";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "a");
}
//only digits no change
Test(strgReverseLetters, only_digits) {
    char s[] = "12345";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "12345");
}
//spaces stay in place
Test(strgReverseLetters, spaces_stay) {
    char s[] = "ab cd";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "dc ba");
}
//all same letters
Test(strgReverseLetters, all_same) {
    char s[] = "aaaa";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "aaaa");
}
//mixed punctuation and letters
Test(strgReverseLetters, mixed_punctuation) {
    char s[] = "a!b@c";
    strgReverseLetters(s);
    cr_assert_str_eq(s, "c!b@a");
}

