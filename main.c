#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/* el functions el 5lsana
-menu
-addmem
-user
-admin
-exit
*/

//GLOBAL DECLERTAION//
FILE *fb;
time_t borr_date,ret_date;
int k;

void del_mem(void);
void menu (void);
void add_book (void);
void addmem (void);
void delete_book (void);
void borrow_book (void);
void search_book (void);
void admin (void);
void user (void);
void overdue(void);
void popular_book (void);
void ret_book(void);
void new_cpy(void);

typedef struct
{
    char catg[32];
    char title[32];
    char author[32];
    int isbn;
    int no_cpy;
    char publisher[32];

} books;

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
    int phone[20];
} users;

int main()
{
    menu();
    return 0;
}

void menu (void)
{
    clrscr();
    print("1-admin\n");
    print("2-user\n");
    printf("3-exit\n")
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
        printf("Enter A valid Number");
        menu();
    }
}
void user()
{
    clrscr();
    printf("1-Borrow Book\n");
    printf("2-Return Book\n");
    printf("3-Search Book\n");
    printf("4-menu\n");
    switch(getch())
    {
    case '1':
        borrow_book();
        break;
    case '2':
        ret_book();
        break;
    case '3':
        search();
        break;
    case '4':
        menu();
        break;
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
    else
    {
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
        case 'n' 'N':
            user();
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
    case 'n' 'N':
        user();
    }
}

void admin(void)
{
    clrscr();
    printf("1-add\n");
    printf("2-delete\n");
    printf("3-search\n");
    printf("4-overdue\n");
    printf("5-delete mem\n");
    printf("6-menu\n");
    switch (getch())
    {
    case '1':
        add_book();
        break;
    case '2':
        delete_book();
        break;
    case '3':
        search();
        break;
    case '4':
        overdue();
        break;
    case '5':
        del_mem();
        break;
    case '6':
        menu();
        break;
    default:
        printf("Enter A valid Number");
        admin();
    }
}

void addmem(void)
{
    clrscr();
    printf("1-Current Member\n");
    printf("2-New Member\n");
    printf("3-back to Main menu\n");
    switch (getch())
    {
    case '1':
        user();
        break;
    case '2':
        if ((fb = fopen("members.txt","r")) == NULL)
        {
            fb = fopen("members.txt","w");
            users use;
            printf("Enter Your First Name:\n");
            scanf("%s",&use.f_name);
            printf("Enter Your Last Name:\n");
            scanf("%s",&use.l_name);
            printf("Enter Your ID:\n");
            scanf("%d",&use.id);
            printf("Enter Your Street Number:\n");
            scanf("%d",&use.street_no);
            printf("Enter Your Zone:\n");
            scanf("%s",&use.zone);
            printf("Enter Your City:\n");
            scanf("%s",&use.city);
            printf("Enter Your Phone:\n");
            scanf("%d",&use.phone);
            printf("Enter Your Age:\n");
            scanf("%d",&use.age);
            printf("Enter Your E-mail:\n");
            scanf("%s",&use.email);
            fprintf(fb,"%s, %s, %d, %d, %s, %s, %d, %d, %s \n",use.f_name,use.l_name,use.id,use.street_no,use.zone,use.city,use.phone,use.age,use.email);
            fclose(fb);
        }
        else
        {
            fb = fopen("members.txt","w");
            users use;
            printf("Enter Your First Name:\n");
            scanf("%s",&use.f_name);
            printf("Enter Your Last Name:\n");
            scanf("%s",&use.l_name);
            printf("Enter Your ID:\n");
            scanf("%d",&use.id);
            printf("Enter Your Street Number:\n");
            scanf("%d",&use.street_no);
            printf("Enter Your Zone:\n");
            scanf("%s",&use.zone);
            printf("Enter Your City:\n");
            scanf("%s",&use.city);
            printf("Enter Your Phone:\n");
            scanf("%d",&use.phone);
            printf("Enter Your Age:\n");
            scanf("%d",&use.age);
            printf("Enter Your E-mail:\n");
            scanf("%s",&use.email);
            fprintf(fb,"%s, %s, %d, %d, %s, %s, %d, %d, %s \n",use.f_name,use.l_name,use.id,use.street_no,use.zone,use.city,use.phone,use.age,use.email);
            fclose(fb);
        }
        break;
    case '3':
        menu();
        break;
    default:
        printf("Enter A valid Number");
        addmem();
    }
}
