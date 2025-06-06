#include<stdio.h>
#include<string.h>

int main() {

    int age = 0;
    float gpa = 0.0f;
    char grade = '\0'; // Initialize to null character

    char name[30]; // This is a character array to store a string, with a maximum of 29 bytes + null terminator '\0'

    /*
    Terminal always sends a newline character ('\n') to the input buffer (when enter pressed).

    The newline character is not consumed by scanf() when reading integers or floats,
    so it remains in the input buffer. When you subsequently try to read a character with scanf("%c", &grade), it reads the newline character instead of waiting for new input, which can lead to unexpected behavior. To avoid this, you can use a space before the format specifier to ignore any whitespace characters, including the newline character left in the input buffer.
    
   
    fgets():
    - allows for spaces and handles buffer sizes correctly
    - consumes the newline character
    - reads a line of text from the input, including spaces
    - stops when it encounters a newline character or reaches the specified size limit.
    - automatically appends a null terminator ('\0') at the end of the string
    - prevents buffer overflow by limit # of chars read
    - is safer than scanf() for reading strings 
    - faster than scanf() for reading strings
    */
    
    // & is the (address-of) operator
    // store input in address of variable
    // scanf() reads formatted input from stdin (standard input)
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    printf("Enter your grade: ");
    scanf(" %c", &grade); // Note the space

    // input buffer is NOT cleared after reading integers or floats
    // The space before %c in scanf will ignore any whitespace characters, including newlines.  Check timestamp (1:00:30 to 1:01:10)

    getchar(); // consume any newline character

    /*IMPORTANT POINT:
    
    Important Caveat: If the input buffer is empty when getchar() is called, it will block (wait) for the user to type a character and press Enter. This can be a source of confusion. If this getchar() call blocks, the character it consumes will be the first character the user types in response to the "Enter your name:" prompt, which is usually not the desired effect. The \n after that input would then be left in the buffer.
    */

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // Use fgets to read a string with spaces
    name[strcspn(name, "\n")] = '\0'; // remove the \n from string

    // strlen() is used for deterimining length of string without null terminator
    // fgets() reads up to (n-1) characters from stdin, where n is the size of the buffer
    // last char is reserved for null terminator '\0'

    // Output the values to verify input
    printf("%s\n", name); 
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);

    /*
    1. scanf() cannot read ANY WHITESPACES
    2. this is because scanf() stops reading input when it encounters a whitespace character (space, tab, or newline). 
    */

}

