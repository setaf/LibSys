#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//GLOBAL DECLERTAION//
FILE *fb
time_t borr_date,ret_date;

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
void ret_book(void);

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
    int borr_no=0;
    char ret_date [3][12];

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
        case '1':admin();break;
        case '2': user();break;
        default:
            printf("Enter A valid Number");
            menu();
    }
}
void user()
{
    printf("1-Borrow Book\n2-Return Book");
    switch(getch())
    {
        case '1': borrow_book();break;
        case '2': ret_book();break;
        default:
            printf("Enter A valid Number");
            user();
    }
}
void borrow_book()
{
    //check//
    if(users.borr_no==3)
        {
        printf("You Can't Borrow in This Moment");
        user();
    }
    else{
    printf("Enter ISBN");
    users.borr_no++;
    time(&borr_date);
    ctime(&borr_date);
    printf("Enter The Return Date YYYY-MM-DD:");
    scanf("%s",users.ret_date[users.borr_no]);
    books.no_cpy--;//error//
    printf("You Want Save (Y/N):");
    switch(getchar())
    {
    case 'y' 'Y':
    case 'n' 'N': user();
    }
    }

}
void ret_book(void)
{
    printf("Enter ISBN");
    users.borr_no--;
    books.no_cpy++;//error//
    time(&ret_date);
    ctime(&ret_date);
    printf("You Want Save (Y/N):");
    switch(getchar())
    {
    case 'y' 'Y':
    case 'n' 'N': user();
    }
}
