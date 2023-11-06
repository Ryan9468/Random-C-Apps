#include "main.h"

int main() {
    srand(time(NULL));
    FILE *fh;
    fh = fopen("hi.txt", "w");

    fprintf(fh, "hi");
    Add_Song();
    fclose(fh);
    Password();
    Say_Hi();
    Bubble_Sort();
    int lower, upper;
    printf("Choose a number for guessing game [Lower Bounds]:\n");
    scanf("%d", &lower);
    printf("Choose a number for guessing game [Upper Bounds]:\n");
    scanf("%d", &upper);
    int alpha = random_number(lower, upper);
    struct Player P1;
    struct Player P2;
    printf("What is Player one's Name?:\n");
    scanf("%s", P1.name);
    P1.score = 0;

    printf("What is Player two's Name?:\n");
    scanf("%s", P2.name);
    P2.score = 0;
    Guessing_Game(P1, P2, alpha);
    //Guessing_Game(alpha);
    printf("Would you like to use the Calculator? {'Y', 'y', 'N', 'n'}:\n");
    char Calculator_Input;
    scanf(" %c", &Calculator_Input);
    Calculator_Input= toupper(Calculator_Input);
    if (Calculator_Input == 'Y'){
        Calculator();
    }
    else{
        printf("Invalid response received or 'n' key pressed, "
               "exiting...\n");
    }

    return 0;
}
