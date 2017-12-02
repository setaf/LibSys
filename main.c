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
FILE *fb *fc;
time_t borr_date,ret_date;
int k;

void del_mem(void);
void menu(void);
void add_book(void);
void addmem(void);
void delete_book(void);
void borrow_book(int id);
void search_book(void);
void admin (void);
void user (int id);
void overdue(void);
void popular_book (void);
void ret_book(void);
void new_cpy(void);
void check_id(void);

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
    int borr_no;
    char ret_date [3][12];
    int phone;
} users;

int main()
{
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
void user()
{
   system("cls");
    printf("1-Borrow Book\n");
    printf("2-Return Book\n");
    printf("3-Search Book\n");
    printf("4-menu\n");
    switch(getch())
    {
    case '1':
        borrow_book(id);
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



void admin(void)
{
    system("cls");
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
    system("cls");
    printf("1-Current Member\n");
    printf("2-New Member\n");
    printf("3-back to Main menu\n");
    users use;
    switch (getch())
    {
        case '1':check_id()break;
        case '2':
            if ((fb = fopen("members.txt","r")) == NULL)
        {
            system("cls");
            fb = fopen("members.txt","w");
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
            use.borr_no=0;
            fprintf(fb,"%s,%s,%d,%d,%s,%s,%d,%d,%s,%d\n",use.f_name,use.l_name,use.id,use.street_no,use.zone,use.city,use.phone,use.age,use.email, use.borr_no);
            fclose(fb);
        }
        else
        {
            system("cls");
            fb = fopen("members.txt","a");
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
            printf("Welcome %s\n Your ID:%d\n",use.f_name,use.id);
            printf("Press Any Key To Continue....");
            switch(getch())
            default: addmem();
        break;
        case '3':menu();break;
        default:
        printf("Enter A valid Number");
        addmem();
    }
}
void add_book()
{
    books boo;
  if ((fc = fopen("books.txt","r")) == NULL)
  {
      system("cls");
      fc = fopen("books.txt","w");
      printf("Enter The Category:\n");
      scanf("%s",boo.catg);
      printf("Enter The Tittle of Book:\n");
      scanf("%s",boo.title);
      printf("Enter Author's Name:\n");
      scanf("%s",boo.author);
      printf("Enter The ISBN:\n");
      scanf("%d",&boo.isbn);
      printf("Enter Number Of Copies:\n");
      scanf("%d",&boo.no_cpy);
      printf("Enter Publisher:\n");
      scanf("%s",boo.publisher);
      fprintf(fc,"%s,%s,%s,%d,%d,%s",boo.catg,boo.title,boo.author,boo.isbn,boo.no_cpy,boo.publisher);
      fclose(fc);
  }
  else
  {
      system("cls");
     fc = fopen("books.txt","a");
      printf("Enter The Category:\n");
      scanf("%s",boo.catg);
      printf("Enter The Tittle of Book:\n");
      scanf("%s",boo.title);
      printf("Enter Author's Name:\n");
      scanf("%s",boo.author);
      printf("Enter The ISBN:\n");
      scanf("%d",&boo.isbn);
      printf("Enter Number Of Copies:\n");
      scanf("%d",&boo.no_cpy);
      printf("Enter Publisher:\n");
      scanf("%s",boo.publisher);
      fprintf(fc,"%s,%s,%s,%d,%d,%s",boo.catg,boo.title,boo.author,boo.isbn,boo.no_cpy,boo.publisher);
      fclose(fc);
  }

  printf("You Want to Add Another Book (Y/N):");
  switch(getch())
  {
      case 'Y':
      case 'y':
          add_book();
          break;
      case 'n':
      case 'N':
          admin();
          break ;
  }
  }
void borrow_book()
{

    fb = fopen("members.txt","r");
    if()
}
void check_id()
{
    int x;
    system("cls");
    printf("Enter You ID :");
    scanf("%d",&x);
    fb = fopen("members.txt","r");
    fscanf(fb,"%d",&x)
    while()
    if()
    user();
    else
    {
        printf("This ID Doesn't Exist Please Enter Valid One: ");
        getch();
        check_id();

    }
}
