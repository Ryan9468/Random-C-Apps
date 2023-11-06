#ifndef C_MAIN_H
#define C_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SIZE 6

struct Player{
    char name[15];
    int score;
};

void Game(struct Player P1, struct Player P2, int number);
void Calculator();
int random_number(int min, int max);
void Bubble_Sort();
void Guessing_Game(int number);
void Say_Hi();
void Password();

#endif //C_MAIN_H
