#include <stdio.h>
#include<string.h>

int main()
{

    // MAD LIBS GAME

    char adj[20];
    char noun[50];
    char adj2[20];
    char verb[20];
    char adj3[20];

    printf("Enter an adjective(description): ");
    fgets(adj, sizeof(adj), stdin);

    /*
     * Remove the trailing newline character from 'item' if fgets stored one.
     *
     * How it works:
     * 1. strcspn(item, "\n"):
     *    - strcspn (string complement span) calculates the length of the initial
     *      segment of 'item' that consists entirely of characters NOT in the string "\n".
     *    - "\n" is a C string literal (an array {'\n', '\0'}). strcspn expects its
     *      second argument to be a const char* (a pointer to such a string) because
     *      it's designed to check for ANY character present in this second "reject set" string.
     *      Even though we are only looking for a single character ('\n'), it must be
     *      passed as a C string containing that character.
     *    - If a '\n' is found in 'item', strcspn returns the index of that '\n'.
     *    - If no '\n' is found (e.g., input filled the buffer before a newline),
     *      strcspn returns strlen(item), which is the index of the existing null terminator.
     *
     * 2. item[ strcspn(...) ] = '\0';
     *    - We use the index returned by strcspn to access an element of the 'item' array.
     *    - '\0' is a character literal representing the null character (integer value 0).
     *    - By assigning '\0' to item[index_of_newline_or_original_null], we are:
     *      a) Replacing the '\n' with a '\0' if a newline was found, effectively shortening
     *         the string and removing the newline.
     *      b) Overwriting the original '\0' with another '\0' if no newline was found,
     *         which is harmless and ensures the string remains correctly terminated.
     *
     * This method is generally preferred over `item[strlen(item) - 1] = '\0';` because it
     * correctly handles the case where the input buffer was filled by fgets *without*
     * a trailing newline, thus avoiding accidental truncation of the last valid character.
     */
    adj[strcspn(adj, "\n")] = '\0';

    printf("Enter a noun (animal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strcspn(noun, "\n")] = '\0';

    printf("Enter an adjective(description): ");
    fgets(adj2, sizeof(adj2), stdin);
    adj2[strcspn(adj2, "\n")] = '\0';

    printf("Enter a verb (ending w/ -ing): ");
    fgets(verb, sizeof(verb), stdin);   
    verb[strcspn(verb, "\n")] = '\0';

    printf("Enter an adjective(description): ");
    fgets(adj3, sizeof(adj3), stdin);
    adj3[strcspn(adj3, "\n")] = '\0';

    // printing madlibs output
    printf("\nToday I went to a %s zoo\n", adj);
    printf("In an exhibit, I saw a %s.\n", noun);
    printf("%s was %s and %s!\n", noun, adj2, verb);
    printf("I was %s!\n", adj3);

}