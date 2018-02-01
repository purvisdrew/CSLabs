/*
 * @file lab8.c
 * @author Drew Purvis
 * @date 11/13/2016
 * Assignment: Lab 8
 * @brief creates a linked list where the user inputs the data
 * @details multiple functions created to insert at head, middle, or tail of a list
 * also to delete a value, or search for a value in a linked list.
 * @bugs none
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
#define SIZE 100
#define FAIL 1000
 
struct node_t {
        double x;
        struct node_t *next;
};
 
struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t *insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, double n);
struct node_t *delete_node(struct node_t *head, double n);
void delete_list(struct node_t *head);
 
 
int main()
{
        int menu;
        int sub;
        double sub1;
        int count;
        int pos;
        double n;
        char buf[SIZE];
 
        struct node_t *head;
        struct node_t *new_node;
 
        head = NULL;
        new_node = NULL;
        /*loop to continue to bring up menu until user wants to quit*/
        do{
                printf("1) Add a number to list\n");
                printf("2) Delete a number from list\n");
                printf("3) Print all numbers in the list\n");
                printf("4) Print how many items are in the list\n");
                printf("5) Search the list for a number\n");
                printf("6) Exit\n");
                fgets(buf, SIZE, stdin);
                sscanf(buf, "%d", &menu);
                switch(menu){
                case 1:
                        printf("Would you like to add this number to the head, tail, or middle of the list?\n");
                        printf("1) Head\n");
                        printf("2) Tail\n");
                        printf("3) Middle\n");
                        fgets(buf, SIZE, stdin);
                        sscanf(buf, "%d", &sub);
                        if (sub == 1){
                                printf("Enter Number: ");
                                fgets(buf, SIZE, stdin);
                                sscanf(buf, "%lf", &n);
                                new_node = create_node(n);
                                head = insert_head(head, new_node);
 
 
                        }
                        if (sub == 2){
                                printf("Enter Number: ");
                                fgets(buf, SIZE, stdin);
                                sscanf(buf, "%lf", &n);
                                if(head == NULL){
                                        new_node = create_node(n);
                                        head = insert_head(head, new_node);
                                } else{
                                        new_node = create_node(n);
                                        head = insert_tail(head, new_node);
                                }
 
                        }
                        if (sub == 3){
                                printf("Enter Number: ");
                                fgets(buf, SIZE, stdin);
                                sscanf(buf, "%lf", &n);
                                printf("Enter postion in list for number to be inserted: ");
                                fgets(buf, SIZE, stdin);
                                sscanf(buf, "%d", &pos);
                                if (pos == 1){
                                        new_node = create_node(n);
                                        head = insert_head(head, new_node);
                                } else if (head == NULL){
                                        new_node = create_node(n);
                                        head = insert_head(head, new_node);
                                } else{
                                        new_node = create_node(n);
                                        head = insert_middle(head, new_node, pos);
                                }
 
                        }
                        break;
                case 2:
                        printf("1) Delete entire list.\n");
                        printf("2) Enter a number to delete from the list: \n");
                        fgets(buf, SIZE, stdin);
                        sscanf(buf, "%d", &sub);
                        if(sub == 1){
                                if (head == NULL){
                                        printf("List is empty.\n");
                                }else{
                                        delete_list(head);
                                        printf("List deleted.\n");
                                        head = NULL;
                                }
                        }else{
                                printf("Enter the value you would like to delete: ");
                                fgets(buf, SIZE, stdin);
                                sscanf(buf, "%lf", &sub1);
                                head = delete_node(head, sub1);
                        }
                        break;
                case 3:
                        if(head == NULL){
                              printf("\nThe list is empty!!\n\n");
                        }
                        print_list(head);
                        break;
                case 4:
                        count = count_nodes(head);
                        printf("The number of items in the list is: %d\n", count);
                        break;
                case 5:
                        printf("Enter the value you would like to search for: ");
                        fgets(buf, SIZE, stdin);
                        sscanf(buf, "%lf", &sub1);
                        head = find_node(head, sub1);
                        break;
                }
 
 
 
        }while(menu!=6);
/* used to free all memory */
delete_list(head);
return 0;
}
 
/* creates a node with value of n
 * @param n the value to store in the node
 * returns the node
 */
struct node_t *create_node(double n)
{
        struct node_t *node;
        if (!(node = malloc(sizeof(struct node_t)))){
                printf("malloc failed\n");
                exit(FAIL);
        }
        node->x = n;
        node->next = NULL;
        return node;
}
 
/*inserts a node at the head of the linked list
 * @param *head a pointer to the current head of the node
 * @param *node a pointer to the node to be inserted
 * returns head, a pointer to the new head of the list
 */
struct node_t *insert_head(struct node_t *head, struct node_t *node)
{
        node->next = head;
        head = node;
        return head;
}
 
/*inserts a node at the tail of the linked list
 * @param *head a pointer to the current head of the node
 * @param *node a pointer to the node to be inserted
 * returns head, a pointer to the new head of the list
 */
struct node_t *insert_tail(struct node_t *head, struct node_t *node)
{
                struct node_t *tmp;
                tmp = head;
                while(tmp->next != NULL){
                        tmp = tmp->next;
                }
                tmp->next = node;
                node->next = NULL;
                return head;
}
/*inserts a node at the "pos" postion of the linked list
 * @param *head a pointer to the current head of the node
 * @param *node a pointer to the node to be inserted
 * @param pos the position for the node to be inserted
 * returns head, a pointer to the new head of the list
 */
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos)
{
        struct node_t *tmp;
        int i;
        int count;
        count = count_nodes(head);
        tmp = head;
        if (pos > count){
                insert_tail(head, node);
        }else {
                for(i=1;i<pos-1;i++){
                        tmp=tmp->next;
                }
 
                node->next=tmp->next;
                tmp->next = node;
        }
        return head;
 
 
 
}
/* deletes the node which contains the value n
 * @param *head a pointer to the current head of the node
 * @param n the value of the node to be deleted
 * returns head a pointer to the head of the list
 */
struct node_t *delete_node(struct node_t *head, double n)
{
        struct node_t *tmp;
        struct node_t *prev;
        tmp = head;
        prev = NULL;
        for(;tmp != NULL && !(isgreaterequal(tmp->x,n) && islessequal(tmp->x,n)); prev = tmp, tmp = tmp->next)
        ;
        if (tmp == NULL){
                printf("\nValue not found in list.\n");
                return head;
        }
        if (prev == NULL){
                head = head->next;
        } else {
                prev->next = tmp->next;
        }
        free(tmp);
        return head;
}
 
/* deletes all the nodes in a list
 * @param *head a pointer to the current head of the node
 */
void delete_list(struct node_t *head)
{
        struct node_t *tmp;
        struct node_t *tmp2;
        tmp = head;
        while(tmp != NULL){
                tmp2 = tmp->next;
                free(tmp);
                tmp = tmp2;
        }
        head = NULL;
}
/* prints the address, value, and address the node points to
*/
void print_node(struct node_t *node)
{
       printf("Address of node: %p Value of Node: %lf, Address next points to: %p\n", node, node->x, node->next);
}
/* prints the entire list
 * @param *head a pointer to the current head of the node
 */
void print_list(struct node_t *head)
{
        struct node_t *tmp;
        for(tmp = head; tmp!=NULL; tmp = tmp->next){
                print_node(tmp);
 
        }
 
}
 
/* searches the list for a node containing the value "n"
 * @param *head a pointer to the current head of the node
 * @param n the value to search the list for
 * returns head a pointer to the head of the list
 */
struct node_t *find_node(struct node_t *head, double n)
{
        struct node_t *tmp;
        struct node_t *prev;
        tmp = head;
        prev = NULL;
        for(;tmp != NULL && !(isgreaterequal(tmp->x,n) && islessequal(tmp->x,n)); prev = tmp, tmp = tmp->next)
        ;
        if (tmp == NULL){
                printf("\nValue not found in list.\n");
                return head;
        }
        if (prev == NULL){
                printf("Node found!\n");
                print_node(head);
        } else {
                printf("Node found!\n");
                print_node(tmp);
        }
        return head;
}
 
/* counts the number of nodes the list contains
 * @param *head a pointer to the current head of the node
 * returns count the number of nodes in the list
 */
int count_nodes(struct node_t *head)
{
        int count;
        struct node_t *tmp;
        tmp = head;
        for(count = 0; tmp!=NULL; tmp = tmp->next){
                count++;
        }
        return count;
}