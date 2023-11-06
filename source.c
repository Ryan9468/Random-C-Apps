#include "main.h"
void Calculator(){
    printf("Please choose: Quotient(Q), Multiplication(M), Modulus(m), Addition(A), Subtraction(S) or (q) to quit.\n");
    char Calculator_Input;
    scanf(" %c", &Calculator_Input);
    if(Calculator_Input == 'Q'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 / num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'M'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 * num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'm'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 % num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'A'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 + num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'S'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 - num_2;
        printf("The result is: %f", result);
    }
    return;
}



int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

void Bubble_Sort(){
    int bubble[6];
    for (int i = 0; i < SIZE; ++i) {
        printf("Please chose number %d for the array:\n", i);
        scanf("%d", &bubble[i]);
    }
    int inner, outer, temp, x;
    for (outer = 0; outer < SIZE-1; outer++) {
        for (inner = outer+1;  inner < SIZE ; inner++) {
            if(bubble[outer] > bubble[inner]){
                temp = bubble[outer];
                bubble[outer] = bubble[inner];
                bubble[inner] = temp;
            }
        }
    }
    printf("Sorted Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", bubble[i]);
    }
    printf("\n");
}

void Guessing_Game(int number){
    int Guess_Won = 0;
    int P1_Guess;
    int P2_Guess;
    printf("Player 1, Enter Your Guess [0-10]:\n");
    scanf(" %d", &P1_Guess);
    printf("Player 2, Enter Your Guess [0-10]:\n");
    scanf(" %d", &P2_Guess);
    printf("%d\n", number);
    bool guess_TF = 1;
    while(guess_TF) {
        if (P1_Guess == number) {
            printf("Player one has won the game, Congrats!\n");
            break;
        }
        if (P2_Guess == number) {
            printf("Player two has won the game, Congrats!\n");
            break;
        }
        printf("Player 1, Enter Your Guess [0-10]:\n");
        scanf(" %d", &P1_Guess);
        printf("Player 2, Enter Your Guess [0-10]:\n");
        scanf(" %d", &P2_Guess);
    }
    return;
}
void Password(){
    char pass_guess[6];
    char password[] = "Stark";
    printf("Please input your password to continue the program:");
    int Guess_Limit = 3;
    int Guess_no = 0;
    scanf("%s", pass_guess);
    int truth = strcmp(pass_guess, password);
    while(truth){
        printf("Incorrect Guess, try again:\n");
        scanf("%s", pass_guess);
        Guess_no = Guess_Limit + 1;
        if(Guess_no == Guess_Limit){
            printf("Failed to input password, exiting...\n");
            break;
        }
        truth = strcmp(pass_guess, password);
    }
    return;
}

void Say_Hi(){
    char input[10];
    printf("Please print your name:\n");
    scanf("%s", input);
    input[10] = '\0';
    int i = 0;
    printf("Hello, ");
    int string_length = strlen(input)-1;
    while (i < string_length+1
    ){
        printf("%c", input[i]);
        i += 1;
    }
    printf("!\n");
    return;
}

void Game(struct Player P1, struct Player P2, int number){
    int P1_Guess;
    int P2_Guess;
    printf("Player 1, Enter Your Guess [0-10]:\n");
    scanf(" %d", &P1_Guess);
    printf("Player 2, Enter Your Guess [0-10]:\n");
    scanf(" %d", &P2_Guess);
    printf("%d\n", number);
    bool guess_TF = 1;
    char quit;
    while(guess_TF) {
        if (P1_Guess == number) {
            printf("Player one has won the game, Congrats!\n");
            P1.score = P1.score + 1;
            printf("\nPlayer one's score is now: %d\n", P1.score);
            printf("\nPress q if you would like to quit,\nother "
                   "wise press Enter Key:\n");
            scanf("%c", quit);
            quit = toupper(quit);
            if(quit == 'Q'){
                break;
            }
        }
        if (P2_Guess == number) {
            printf("Player two has won the game, Congrats!\n");
            P2.score = P2.score + 1;
            printf("\nPlayer two's score is now: %d\n", P2.score);
            printf("\nPress q if you would like to quit,\nother "
                   "wise press Enter Key:\n");
            scanf("%c", quit);
            quit = toupper(quit);
            if(quit == 'Q'){
                break;
            }
        }
        printf("\nPlayer 1, Enter Your Guess [0-10]:\n");
        scanf(" %d", &P1_Guess);
        printf("\nPlayer 2, Enter Your Guess [0-10]:\n");
        scanf(" %d", &P2_Guess);
    }
    return;
}
