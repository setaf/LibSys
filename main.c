#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "functions.h"

void del_mem(void);
void menu(void);
void add_book(void);
void addmem(void);
void delete_book(void);
void borrow_book(int a);
void search_book(void);
void admin (void);
void user (int id);
void overdue(void);
void popular_book (void);
void ret_book(int id);
void new_cpy(void);
void check_id(void);
void new_save(void);
void del_save(void);
void curr_mem(void);

int main()
{
    curr_mem();
    menu();
    return 0;
}

void menu (void)
{
    system("cls");
    printf("1-admin\n");
    printf("2-user\n");
    printf("3-exit\n");
    switch(getch())
    {
    case '1':
        admin();
        break;
    case '2':
        addmem();
        break;
    case '3':
        exit(0);
        break;
    default:
        printf("Enter A valid Number:");
        menu();
    }
}
