#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void menu (void);
void add_book (void);
void exit (void);
void addmem (void);
void delete_book (void);
void borrow_book (void);
void search_book (void);
void admin (void);
void user (void);
void overdue(void);
void popular_book (void);

typedef struct
{
    char catg[32];
    char title[32];
    char author[32];
    int isbn;
    int no_cpy;
    char publisher[32];
}books;

typedef struct
{
    char f_name[10];
    char l_name[10];
    int id;
    int age;
    char email[64];
    int street_no;
    char zone[20];
    char city[20];
}users;

int main()
{
    menu();
    return 0;
}

void menu (void)
{

    switch(getch())
    {
        case '1':break;
        default:
    }
}
