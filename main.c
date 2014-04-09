#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main()
{
    int age = 0;
    int avglife = 80;
    int remainingyears = 0;
    unsigned long int remsec = 0;
    int keypress = 0;
    char userinput[100];

    printf("How old are you?\n");
    //Trying out fgets and sscanf instaed of scanf to prevent buffer overflow.
    fgets(userinput, 4, stdin);
    /*fgets takes the input from stdin as a string and stores it in userinput, which
    is an array that holds chars. */
    sscanf(userinput, "%d", &age);
    /*sscanf here now reads from userinput and takes whatever is in it
    in the format of %d, a double, then stores it in age. There is an address-of
    operator in front of age because it takes a memory location of the variable, not
    the name of the variable.*/
    printf("You entered %d for your age.\n", age);
    //scanf("%d", &age); //This is the old code, vulnerable to buffer overflow.

    remainingyears = avglife - age;

    printf("The average human life expectancy is about 80 years.\n");
    printf("You have roughly %d years left to live.\n", remainingyears);

    remsec = remainingyears*31536000;

    printf("This is how many seconds you have remaining:\n");
    printf("%ld", remsec);

    do{
        printf("\r                             ");
        printf("\r%lu", remsec);
        Sleep(1000);
        keypress = kbhit();

    }while((!keypress)&&(remsec-- > 0));

    getchar();
    printf("\n\nYou have exited. Hit enter to end.\n");
    getchar();
    return 0;
}

    /*
    int year = 0;
    int month = 0;
    printf("Welcome to the countdown timer.");
    printf("What year were you born?");
    scanf("%d", year)
    printf("You entered %d. Is this correct? Y/N");

    printf("What month were you born? (Enter the number)");
    scanf("%d", month);
    */
