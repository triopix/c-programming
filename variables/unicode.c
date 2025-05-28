#include <stdio.h>
// Make sure this source file is saved with UTF-8 encoding.
// Most modern editors (VS Code, Sublime Text, Xcode default) do this.

/*
    Understanding Characters, Unicode, and UTF-8 in C on Modern Systems (like macOS, Linux)

    1. ASCII (American Standard Code for Information Interchange):
       - A 7-bit character encoding standard (0-127).
       - Includes uppercase/lowercase English letters, digits, punctuation, control characters.
       - Example: 'A' is 65, 'a' is 97.

    2. Unicode:
       - A universal character set standard designed to represent (almost) all characters
         from all writing systems in the world, plus many symbols.
       - Assigns a unique number called a "code point" to each character.
         Code points are often written as U+XXXX (e.g., 'A' is U+0041, '°' is U+00B0, '€' is U+20AC).
       - The first 128 Unicode code points (U+0000 to U+007F) are IDENTICAL to ASCII.

    3. UTF-8 (Unicode Transformation Format - 8-bit):
       - An ENCODING scheme for Unicode code points. It translates Unicode code points
         into sequences of one to four bytes.
       - Your Mac's terminal (and most Linux terminals, modern Windows Terminal) uses UTF-8.
       - Key Features of UTF-8:
         a. Compatibility with ASCII:
            - Unicode code points U+0000 to U+007F (the ASCII range) are encoded
              as a SINGLE BYTE in UTF-8, and that byte has the same value as the
              ASCII code and the Unicode code point.
              Example: Unicode U+0041 ('A') -> UTF-8 byte: 0x41
         b. Multi-byte for other characters:
            - Unicode code points U+0080 and above are encoded using MULTIPLE BYTES
              (2, 3, or 4 bytes) in UTF-8.
              Example: Degree symbol '°' (Unicode U+00B0)
                       -> UTF-8 byte sequence: 0xC2 0xB0 (two bytes)
              Example: Euro symbol '€' (Unicode U+20AC)
                       -> UTF-8 byte sequence: 0xE2 0x82 0xAC (three bytes)

    4. The `char` type in C:
       - A `char` in C is typically 1 byte (8 bits).
       - It can hold a single ASCII character perfectly. `char c = 'A';`
       - It CANNOT meaningfully hold a multi-byte UTF-8 character like '°' or '€'
         if your goal is to then print it simply with `printf("%c", multi_byte_char_var);`.
         Assigning a multi-byte character literal like '°' to a char (e.g., `char x = '°';`)
         is implementation-defined and usually results in truncation or an integer value
         that isn't useful for printing as a single character.

    5. How to print special characters (like '°') in C on a UTF-8 system:

       METHOD 1: Directly embed the character in a string literal (Recommended & Easiest)
                 - Prerequisite: Your source code file MUST be saved as UTF-8.
                 - The C compiler (if modern and aware) will then embed the correct
                   UTF-8 byte sequence for that character into the compiled string.

       METHOD 2: Use UTF-8 Hex Escape Sequences in a string literal
                 - Useful if you can't type the character or need to be very explicit
                   about the bytes.
                 - Syntax: `\xHH` for each byte in the sequence.

       AVOID: `char sym = 176; printf("%c", sym);` for characters like '°'
              This sends a single byte (176, which is 0xB0) to the terminal.
              In UTF-8, 0xB0 by itself is an invalid/incomplete character sequence,
              so the terminal prints a placeholder (like '?' or '�').
              This method *might* work on older systems with specific single-byte
              "extended ASCII" code pages (like Windows-1252), but it's not
              portable to UTF-8 systems like macOS/Linux for these characters.

    6. Character Constants vs. String Literals:
       - `'A'` is a character constant (typically an `int` value).
       - `"A"` is a string literal (an array of characters, `{'A', '\0'}`).
       - `'°'` (if the file is UTF-8) is a multi-byte character constant. Its value is
         implementation-defined. Don't rely on it for portable `char` assignments.
       - `"°"` (if the file is UTF-8) is a string literal containing the UTF-8 bytes
         for `°` (i.e., `C2 B0`) followed by a null terminator (`00`).
*/

int main() {
    // Method 1: Direct embedding (Source file must be UTF-8)
    printf("Method 1 (Direct):\n");
    printf("Temperature: 25°C\n");
    printf("Price: €10.50\n");
    printf("Pi: π ≈ 3.14159\n");
    printf("Copyright: © 2024\n"); 
    printf("Omega: Ω\n");
    printf("你好 (Hello in Chinese)\n"); // Multi-byte, many characters
    printf("\n");

    // Method 2: UTF-8 Hex Escape Sequences
    printf("Method 2 (Hex Escapes):\n");
    // Degree '°' is U+00B0, which is C2 B0 in UTF-8
    printf("Temperature: 25\xc2\xb0\\C\n");
    // Euro '€' is U+20AC, which is E2 82 AC in UTF-8
    printf("Price: €10.50\n");
    // Pi 'π' is U+03C0, which is CF 80 in UTF-8
    printf("Pi: \xcf\x80 \xe2\x89\x88 3.14159\n"); // ≈ (U+2248) is E2 89 88 in UTF-8
    // Copyright '©' is U+00A9, which is C2 A9 in UTF-8
    printf("Copyright: \xc2\xa9 2024\n");
    printf("\n");

    // Demonstrating ASCII characters (single byte in UTF-8)
    char letter = 'A'; // ASCII 'A' is 65 (0x41). Unicode U+0041. UTF-8: 0x41.
    char digit = '7';  // ASCII '7' is 55 (0x37). Unicode U+0037. UTF-8: 0x37.
    printf("ASCII examples:\n");
    printf("Letter: %c, Digit: %c\n", letter, digit);
    printf("\n");

    // Why single `char` variable for '°' then printing with %c FAILS on UTF-8 terminals:
    unsigned char incorrect_deg_char_attempt1 = 176; // 0xB0 - an invalid UTF-8 standalone byte
    // '°' in a char constant is implementation-defined, usually a truncated int.
    // Let's say the compiler takes the first UTF-8 byte if '°' = C2 B0:
    // char incorrect_deg_char_attempt2 = '°'; // This will likely store 0xC2 or 0xB0 if it truncates
                                               // Or cause a multi-byte char constant warning/error.
                                               // Let's simulate storing just one byte for demonstration.

    // For illustration, let's assume we try to store one part of the UTF-8 sequence:
    unsigned char part_of_degree_utf8_seq = 0xC2; // The *first* byte of ° in UTF-8

    printf("Demonstrating incorrect attempts (will likely print '?'):\n");
    printf("Attempting to print byte 176 (0xB0) as char: %c\n", incorrect_deg_char_attempt1);
    printf("Attempting to print byte 0xC2 as char: %c\n", part_of_degree_utf8_seq);
    // printf("Attempting to print '°' stored in a char: %c\n", incorrect_deg_char_attempt2); // This is tricky to demo accurately cross-compiler
    printf("The above attempts fail because a single byte like 0xB0 or 0xC2 is not a complete/valid displayable character on its own in UTF-8.\n");


    // Storing a string (which IS an array of chars) is fine:
    char greeting[] = "Hello, world!"; // ASCII only, easy.
    char special_greeting[] = "Hello, 🌍!"; // Contains a multi-byte emoji. File must be UTF-8.

    printf("\nStrings work well:\n");
    printf("%s\n", greeting);
    printf("%s\n", special_greeting);


    return 0;
}