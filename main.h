#ifndef C_MAIN_H
#define C_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 3

struct Player{
    char name[15];
    int score;
};
struct link_list{
    char Song_Name[10];
    int Song_No;
    struct link_list* next;
};
void Add_Song();
void Game(struct Player P1, struct Player P2, int number);
void Calculator();
int random_number(int min, int max);
void Bubble_Sort();
void Guessing_Game(struct Player P1, struct Player P2, int number, int lower_bound, int upper_bound);
void Say_Hi();
int Password();

#endif //C_MAIN_H
