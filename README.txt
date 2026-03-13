
//Anjana Kummetha 
//NETID: 117162837

README

Test Cases Explained 

PART 1 

strgLen
- tests basic string length and edge cases like empty string and NULL
- tests strings with spaces, digits, and punctuation

strgCopy
- tests basic copy, exact fit, and truncation when buffer is too small
- tests NULL source, NULL destination, and size 0 doing nothing

strgChangeCase
- tests basic case flip and letters adjacent to digits not flipping
- tests NULL, empty string, all uppercase, and all lowercase

strgDiff
- tests equal strings returning -1 and index of first difference
- tests NULL pointers returning -2 and one string ending before the other

strgInterleave
- tests basic interleaving and appending the remainder of the longer string
- tests truncation when buffer is too small and empty or NULL inputs

strgReverseLetters
- tests that only letters are reversed and non-letters stay in place
- tests NULL, empty string, single letter, and strings with digits and punctuation

PART 2 

encryptCaesar
- tests basic encryption, key 0, mixed case, digits, and wrap around
- tests NULL pointers returning -2 and buffer too small returning -1

decryptCaesar
- tests basic decryption, key 0, mixed case, digits, and wrap around
- tests NULL returning -2, missing EOM returning -1, and plaintext length 0 returning 0