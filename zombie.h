/*
 * @file zombie.h
 * @author Drew Purvis
 * @date 10/13/2016
 * Assignment: Lab 5
 * @brief header file for zombie.c
 * @details see zombie.c
 * @bugs none
 */
#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#define SIZE 5

#include <stdlib.h>

struct zombie_t {
         enum {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;
         float blood;
         int toes;
         int hour;
         int min;
         int sec;
         char dead;
};

void menu();
void input_time(struct zombie_t data[], int i);
void input_day(struct zombie_t data[], int i);
void input_toes(struct zombie_t data[], int i);
void input_blood(struct zombie_t data[], int i);
void print_zombies(struct zombie_t data[], int count);

#endif
