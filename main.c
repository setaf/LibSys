#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//GLOBAL DECLERTAION//
FILE *fb *fa;
time_t borr_date,ret_date;
int k;

void del_mem(void);
void menu (void);
void add_book (void);
void exit_prog (void);
void addmem (void);
void delete_book (void);
void borrow_book (void);
void search_book (void);
void admin (void);
void user (void);
void overdue(void);
void popular_book (void);
void ret_book(void);
void save();


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
    int borr_no;
    char ret_date [3][12];

}*users;

int main()
{
    menu();
    return 0;
}

void menu (void)
{
    system("cls");
    print("1-admin\n");
    print("2-user\n");
    switch(getch())
    {
        case '1':admin();break;
        case '2': addmem();break;
        default:
            printf("Enter A valid Number");
            menu();
    }
}
void user()
{
    system("cls");
    printf("1-Borrow Book\n");
    printf("2-Return Book\n");
    printf("3-Search Book\n");
    printf("4-Save||Exit");
    printf("5-Menu\n");

    switch(getch())
    {
        case '1': borrow_book();break;
        case '2': ret_book();break;
        case '3': search();break;
        case '5':
            printf("You Want to Save Before Back to Main Menu(Y/N)");
            switch(getch())
            {
                case 'y''Y': save(); /*without break */
                case 'n''N': menu();break;
                }

        default:
            printf("Enter A valid Number");
            user();
    }
}
void borrow_book()
{
    fb=fopen("file.txt", "w+"); //check//
    system("cls");
    if(users.borr_no==3)
        {
        printf("You Can't Borrow in This Moment");
        user();
    }
    else
    {
    fa=fopen("file.txt", "w+");
    time(&borr_date);
    fprintf(fb,"%s",ctime(&borr_date));
    printf("Enter ISBN");
    users.borr_no++;
    time(&borr_date);
    ctime(&borr_date);
    printf("Enter The Return Date YYYY-MM-DD:");
    scanf("%s",users.ret_date[users.borr_no]);
    books.no_cpy--;//error//
    fprintf();
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
    case 'n' 'N': user();
    }
}

void admin(void)
{
    print("1-add\n");
    print("2-delete\n");
    print("3-search\n");
    print("4-overdue\n");
    printf("5-delete mem\n");
    printf("6-Save Changes\n");
    print("7-menu\n");
    switch(getch())
    {
   case '1': add_book();break;
   case '2':delete_book();break;
   case '3':search();break;
   case '4':overdue();break;
   case '5':del_mem();break;
   case '6':save();break;
   case '7':printf("You Want to Save Before Back to Main Menu(Y/N)");
            switch(getch())
            {
                case 'y' 'Y': save(); /*without break */
                case 'n' 'N': menu();break;
            }
    }
}

void addmem(void)
{
    printf("1-Current Member");
    printf("2-New Member");
    fp=fopen("members.txt","w");
    switch(getch())
    {
        system("cls");
        case '1': user(); break;
        case '2':
            system("cls");
            printf("Welcome\n");
            printf("Enter First Name:\n");
            scanf("%s",&users.f_name);
            printf("Enter Last Name:\n");
            scanf("%s",&users.l_name);
            printf("Enter Your Age:\n");
            scanf("%d",&users.age);
            printf("Enter Your Email:\n");
            scanf("%s",&users.email);
            printf("Enter Your Address (St.no/Zone/City):\n");
            scanf("%d%s%s",&users.street_no,&users.zone,&users.city);
            users.borr_no=0;
            fprintf(fb,"");
            break;
        default :printf("Enter A valid Number"); addmem();
    }

}
