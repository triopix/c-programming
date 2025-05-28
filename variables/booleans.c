#include<stdio.h>
#include<stdbool.h>

int main() {

    // boolean variables, 1 = true, 0 = false, acc everything other than 0 is true
    // we tend to not display them externally
    // you would use them internally

    bool isOnline = false;   // value of 0
    bool isGreat = true;    // value of 1 or other #.
    bool isStudent = true;  // value of 1 or other #. 

    if(isOnline && isGreat) {
        printf("You are online and great\n");
    } else {
        printf("You aren't any lmao\n");
    }

    if(isStudent) {
        printf("You are a student\n");
    } else {
        printf("you aren't a student\n");
    }
    
    return 0;
}