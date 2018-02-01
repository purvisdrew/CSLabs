/*
 * @file lab5.c
 * @author Drew Purvis
 * @date 10/13/2016
 * Assignment: Lab 5
 * @brief asks user to input zombie data, and then prints zombie data
 * @details calls functions from zombie.c to have user input data for
 * their zombie encounters. Then gives option for user to view previously encountered
 * logs
 * @bugs none
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "zombie.h"

int main(void)
{
        struct zombie_t data[5];
        int m;
        int i;
        int count;/* count is used to only print encounters that the user has entered */
        char buf[32];
        i = 0;
        count = 0;
        /* While statement to run program until user wants to quit */
        while(i < SIZE){
                menu();
                fgets(buf, 32, stdin);
                sscanf(buf, "%d", &m);
                /* If else statment to exit program, or to input or print data */
                if (m == 3){
                        printf("\nStay alert! Keep a watch out for zombies!!\n");
                        printf("Goodbye and good luck!\n");
                        return 1;
                } else{
                        /* Switch to determine if user wants to input or print encounter */
                        switch (m){
                        case 1:
                                printf("Was the zombie found dead? (Y or N) ");
                                fgets(buf, 32, stdin);
                                sscanf(buf, "%c", &data[i].dead);
                                data[i].dead = tolower(data[i].dead);
                                if (data[i].dead == 'y'){
                                        input_toes(data, i);
                                } else{
                                        input_blood(data, i);
                                }
                                input_time(data, i);
                                input_day(data, i);
                                i++;
                                break;
                        case 2:

                                print_zombies(data, count);
                                count--;
                                break;
                        }
                        count++;
                }

                /* sets i at zero so that the while loop runs till user exits */
                if(i == SIZE){
                        i=0;
                }
                /*prevents more than 5 encounters to be printed*/
                if(count>SIZE){
                        count = 5;
                }
        }


        return 0;
}

/* menu to display the users options
*/
void menu()
{
        printf("\n1) Enter new zombie information\n");
        printf("2) Display zombie information\n");
        printf("3) Return to fighting zombies(exit)\n");
        printf("Enter choice: ");
}
/* Asks user to input the time the zombie was encountered
 * @param zombie_t data[] an array of structs used to store zombie data
 * @param int i used as a index value for the array
 */
void input_time(struct zombie_t data[], int i)
{
        char buf[32];
        printf("Enter time when this zombie was encountered.\n");
        printf("Seperate hours, minutes, and seconds by colons.\n");
        printf("HH:MM:SS\n");
        fgets(buf, 32, stdin);
        sscanf(buf, "%d:%d:%d", &data[i].hour, &data[i].min, &data[i].sec);
}
/* user inputs day zombie was encountered
 * @param zombie_t data[] an array of structs used to store zombie data
 * @param int i used as a index value for the array
 */
void input_day(struct zombie_t data[], int i)
{

        char buf[32];
        printf("Please choose the day this zombie was encountered: \n");
        printf("1) Monday\n");
        printf("2) Tuesday\n");
        printf("3) Wednesday\n");
        printf("4) Thursday\n");
        printf("5) Friday\n");
        printf("6) Saturday\n");
        printf("7) Sunday\n");
        fgets(buf, 32, stdin);
        sscanf(buf, "%u", &data[i].day);


}
/* user inputs number of toes the zombie had
 * @param zombie_t data[] an array of structs used to store zombie data
 * @param int i used as a index value for the array
 */
void input_toes(struct zombie_t data[], int i)
{
        char buf[32];
        printf("Enter the number of toes the zombie has: ");
        fgets(buf, 32, stdin);
        sscanf(buf, "%d", &data[i].toes);
}
/* user inputs amount of blood drained from zombie_t
 * @param zombie_t data[] an array of structs used to store zombie data
 * @param int i used as a index value for the array
 */
void input_blood(struct zombie_t data[], int i)
{
        char buf[32];
        printf("Enter the amount of blood that oozed from its body\n");
        printf("after you killed it (in mL) ");
        fgets(buf, 32, stdin);
        sscanf(buf, "%f", &data[i].blood);
}
/* used to print previously entered data for a zombie encountered
 * @param zombie_t data[] an array of structs used to store zombie data
 * @param int count used to count how many zombie encounters have been logged
 */
void print_zombies(struct zombie_t data[], int count)
{

        int i;
        for(i = 0; i < count; i++){
                /* IF else to determine to print toes or blood depending
                   if the zombie was found alive or dead */
                if (data[i].dead == 'y'){
                        printf("\n%d. This zombie was found dead.\n", (i+1));
                        printf("This zombie had %d toes.\n", data[i].toes);
                } else{
                        printf("\n%d. This zombie was found ALIVE!\n", (i+1));
                        printf("It was drained of %.2f mL of blood once killed\n", data[i].blood);
                }
                printf("This zombie was sighted ");
                /*Switch statement to print day of week*/
                switch(data[i].day){
                case 1:
                        printf("Monday");
                        break;
                case 2:
                        printf("Tuesday");
                        break;
                case 3:
                        printf("Wednesday");
                        break;
                case 4:
                        printf("Thursday");
                        break;
                case 5:
                        printf("Friday");
                        break;
                case 6:
                        printf("Saturday");
                        break;
                case 7:
                        printf("Sunday");
                        break;
                }
                printf(" at %d:%d:%d.\n\n", data[i].hour, data[i].min, data[i].sec);
        }
        if (i==0){
             printf("\nNo zombie information has been recorded yet!\n");
       }

}
