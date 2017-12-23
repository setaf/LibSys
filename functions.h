#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "struct.h"

FILE *fb, *fc, *temp,*fd;
time_t borr_date,ret_date;
int mem_no=0,book_no=0,borrow_no=0,newnumber=0,newbook=0,newborrow=0,newreturn=0;
users new_user[100]; //lazem 34an tst5dmha fel save
users curr_user[100];
books book_new[100];
books book_curr[100];
borrow borrows[100];
borrow borrows_curr[100];
date overd[100];
date comparedate[1];
char password[10]={"test"};

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void pass_word()
{
        int j;
    char pass[10];
    system("cls");
    printf("\n\n\n\n\n\t\t");
    for(j=0;j<10;j++)
    {
    delay(50);
    printf("\xB2");
    }
    printf(" Administrator Password ");
    for(j=0;j<10;j++)
    {
    delay(50);
    printf("\xB2");
    }
    printf("\n\n\n\n\n\t\t");
    printf("Enter Password:");
    gets(pass);
    if(strcmp(pass,password)!=0)
    {
        printf("\n\n\t\t Wrong Password \a");
        printf("\n\n\t\tYou Want To Back to Main Menu (Y/N):");
        switch(getch())
        {
        case 'y': case'Y':
            main();
            break;
        case 'N':case'n':
            pass_word();
            break;
        default:
            printf("\n\n\t\tWrong Input you will be back To Main Menu\a");
            delay(1500);
            main();
        }
    }
    else
    {
        printf("\n\n\t\t Correct Password ");
        delay(500);
        admin();
    }
}

void menu (void)
{
    system("cls");
    system("color 71");
    //popular Books
    printf("\n\n\n\n\n\n\t\t\t\xDB\xDB\xDB\xDb\xB2 Welcome To Main Menu \xB2\xDB\xDB\xDB\xDb\n\n\n");
    delay(500);
    printf("\t\t\t\xDB 1-Administrator Menu\n\t\t\t\xDB\n\t\t\t\xDB\n");
    delay(150);
    printf("\t\t\t\xDB 2-Members Menu\n\t\t\t\xDB\n\t\t\t\xDB\n");
    delay(150);
    printf("\t\t\t\xDB 3-Exit\n\t\t\t\xDB\n");
    delay(150);
    printf("\t\t\t\xDB Enter You Choice:");
    switch(getch())
    {
    case '1':
        pass_word();
        break;
    case '2':
        addmem();
        break;
    case '3':
        system("color F0");
        printf(" \n\n\t\t\tYou Want To Save Before Leaving (Y/N):");
        char in;
        scanf("%c",&in);
        switch(in)
        {
        case 'y': case'Y':
            del_save();
            new_save();
            printf("\n\t\t Saved Successfully");
            printf("\n\t\t ** The Program will Close After 5 Second **");
            delay(5000);
            exit(0);
            break;
        case 'N':case'n':
            printf("\n\t\t ** The Program will Close After 5 Second **");
            delay(5000);
            exit(0);
            break;
        default:
            system("color FC");
            printf("\n\t\t\tWrong Input\a");
            delay(1500);
            main();
        }
        break;

    default:
        printf("(Enter A valid Input\a)");
        delay(700);
        menu();
    }
}
void admin ()
{
    system("cls");
    system("color F1");
    printf("\t\t\t\xDB\xDB\xDB Welcome To Administrator Menu  \xDB\xDB\xDB\n\n");
    printf("\t\t\t\xDB 1-Add Book\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 2-Delete Book\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 3-Delete Member\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 4-Overdue Books\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 5-Show List Menu\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 6-Save Changes\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 7-Main Menu\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 8-Exit \n\t\t\t\xDB\n");
    printf("\t\t\t\xDB Enter Your Choice:");
    switch (getch())
    {
    case '1':
        add_book();
        break;
    case '2':
        delete_book();
        break;
    case '3':
        del_mem();
        break;
    case '4':
        overdue();
        break;
    case '5':
        show_list(4);
        break;
    case '6' :
        del_save();
        new_save();
        curr_mem();
        printf("\n\n\t\t\t *Save Successfully*");
        delay(1500);
        admin();
        break;
    case '7':
        printf("\n\n\t\t\t *You Will Return To Main Menu*");
        delay(900);
        menu();
        break;
    case '8':
        system("color F0");
         printf(" \n\n\t\t\tYou Want To Save Before Leaving (Y/N):");
        char in;
        scanf("%c",&in);
        switch(in)
        {
        case 'y': case'Y':
            del_save();
            new_save();
            printf("\n\t\t Saved Successfully");
            printf("\n\t\t ** The Program will Close After 5 Second **");
            delay(5000);
            exit(0);
            break;
        case 'N':case'n':
            printf("\n\t\t ** The Program will Close After 5 Second **");
            delay(5000);
            exit(0);
            break;
        default:
            system("color FC");
            printf("\n\t\t\t \a Wrong Input");
            delay(1500);
            admin();
        }
        break;

    default:
        system("color FC");
        printf("\n\n\t\t\t Enter A valid Input");
        delay(1000);
        admin();

    }
}

void addmem(void)
{
    int i;
    system("cls");
    for(i=0; i<borrow_no; i++)
    {
        printf("%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
               borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
               borrows[i].ret_date.year);
    }
    printf("1-Current Member\n");
    printf("2-New Member\n");
    printf("3-Save Changes \n");
    printf("4-back to Main menu\n");
    switch (getch())
    {
    case '1':
        check_id();
        break;
    case '2':
        system("cls");
        printf("Enter Your First Name:\n");
        gets(new_user[newnumber].f_name);
        printf("Enter Your Last Name:\n");
        gets(new_user[newnumber].l_name);
        do
        {
            printf("Enter Your ID:\n");
            scanf("%d",&new_user[newnumber].id);
            for(i=0; i<mem_no; i++)
            {
                if(new_user[newnumber].id==curr_user[i].id)
                {
                    printf("A User with the same ID already exist, Retry!!!\n\n");
                }
            }
            if(new_user[newnumber].id<0)
                printf("Enter A positive number, Retry!!!\n\n");
        }
        while(new_user[newnumber].id<0);
        do
        {
            printf("Enter Your Street Number:\n");
            scanf("%d",&new_user[newnumber].adrs.street_no);
            if (new_user[newnumber].adrs.street_no<0)
                printf("Enter A positive number, Retry!!!\n\n");
        }
        while(new_user[newnumber].adrs.street_no<0);
        printf("Enter Your Zone:\n");
        getchar();
        gets(new_user[newnumber].adrs.zone);
        printf("Enter Your City:\n");
        gets(new_user[newnumber].adrs.city);
        do
        {
            printf("Enter Your Phone:\n");
            scanf("%d",&new_user[newnumber].phone);
            if (new_user[newnumber].phone<1000000000 || new_user[newnumber].phone>100000000000)
                printf("Wrong Phone Number Retry!!!\n\n");
        }
        while(new_user[newnumber].phone<1000000000 || new_user[newnumber].phone>100000000000);
        do
        {
            printf("Enter Your Age '7 years or older':\n");
            scanf("%d",&new_user[newnumber].age);
            if (new_user[newnumber].age<7)
                printf("Wrong Age Retry!!!\n\n");
        }
        while(new_user[newnumber].age<7);
        printf("Enter Your E-mail:\n");
        getchar();
        int flag=0;
        do
        {
            gets(new_user[newnumber].email);
            int elen=strlen(new_user[newnumber].email);
            if(new_user[newnumber].email[elen-1] ==  'm' || new_user[newnumber].email[elen-1] ==  'M')
            {
                if(new_user[newnumber].email[elen-2] ==  'o' || new_user[newnumber].email[elen-2] ==  'O')
                {
                    if(new_user[newnumber].email[elen-3] ==  'c' || new_user[newnumber].email[elen-3] ==  'C')
                        for (i=0; i<elen; i++)
                        {
                            if (new_user[newnumber].email[i]=='@')
                                flag++;
                        }
                }

            }
            else
            {
                printf("the email is wrong Retry!!!\n\n");
            }
        }
        while(flag != 1);
        new_user[newnumber].no_borru=0;
        newnumber++;

        printf("Welcome %s\n Your ID:%d\n",new_user[newnumber-1].f_name,new_user[newnumber-1].id);
        printf("Press Any Key To Continue....");
        switch(getch())
        default:
        addmem();
        break;
    case '3':
        del_save();
        new_save();
        curr_mem();
          printf("Saved successfully\n");
        printf("Enter any key to return to the menu!!");
        getch();
        addmem();
        break;
    case '4':
        menu();
        break;
    default:
        printf("Enter A valid Number");
        addmem();
    }
}
void curr_mem()          //btgyb 3dd el current user w t7thom fe array
{
    int i;
    if (temp = fopen("members.txt","r") == NULL)
    {
        temp = fopen("members.txt","w");//notes
    }
    else
    {
        temp = fopen("members.txt","r");
        while (!feof(temp))
        {
            fscanf(temp,"%[^,],%[^,],%d,%d,%[^,],%[^,],0%d,%d,%d,%s\n",curr_user[mem_no].f_name,curr_user[mem_no].l_name,&curr_user[mem_no].id,&curr_user[mem_no].adrs.street_no,
                   curr_user[mem_no].adrs.zone,curr_user[mem_no].adrs.city,&curr_user[mem_no].phone,&curr_user[mem_no].age,&curr_user[mem_no].no_borru,curr_user[mem_no].email);
            for(i=0; i<mem_no; i++)
                if(curr_user[i].id == curr_user[mem_no].id)//notess
                {
                    break;
                }
            if(i == mem_no)
            {

                if(strcmp(curr_user[mem_no].f_name,curr_user[mem_no+1].f_name)!=0)//notes
                    mem_no++;
            }
        }
    }
    fclose(temp);
    if (temp = fopen("books.txt","r")== NULL)
    {
        temp = fopen("books.txt","w");//notes
    }
    else
    {
        temp = fopen("books.txt","r");
        while (!feof(temp))
        {
            fscanf(temp,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d\n",book_curr[book_no].ISBN,book_curr[book_no].catg,book_curr[book_no].title,book_curr[book_no].author,book_curr[book_no].publisher,
                   &book_curr[book_no].publish.day,&book_curr[book_no].publish.month,&book_curr[book_no].publish.year,&book_curr[book_no].no_cpy,&book_curr[book_no].curr_copy,&book_curr[book_no].no_borr);

            for(i=0; i<book_no; i++)
            {
                if(strcmp(book_curr[i].ISBN,book_curr[book_no].ISBN)==0)
                    break;
            }
            if(i==book_no)
            {
                if(strcmp(book_curr[book_no].ISBN,book_curr[book_no+1].ISBN)!=0)//notes
                    book_no++;
            }
        }
    }
    fclose(temp);

    if (temp = fopen("borrow.txt","r")== NULL)
    {
        temp = fopen("borrow.txt","w");//notes
    }
    else
    {
        temp = fopen("borrow.txt","r");
        while (!feof(temp))
        {
            fscanf(temp,"%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[newborrow].book_isbn,&borrows[newborrow].user_id,&borrows[newborrow].borrow_date.day,
                   &borrows[newborrow].borrow_date.month,&borrows[newborrow].borrow_date.year,&borrows[newborrow].duedate.day,&borrows[newborrow].duedate.month,
                   &borrows[newborrow].duedate.year,&borrows[newborrow].ret_date.day,&borrows[newborrow].ret_date.month,&borrows[newborrow].ret_date.year);
            if(borrows[newborrow].user_id!=0)
                newborrow++;
        }
    }
    fclose(temp);
}
void del_mem()
{
    int i,id,flag=0;
    system("cls");
    system("color 0C");
    printf("\n\t\t\t\t** Member List **\n\n");
    printf("Memeber Name   ID   Address \t Phone\t   Age #Borrow  Email \n\n");
    for(i=0; i<mem_no; i++)
        {
            if(curr_user[i].id==0)
                continue;
            else
            printf("%s %s %d  %d-%s-%s %0d %d  %d   %s\n\n",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no
                   ,curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].no_borru,curr_user[i].email);
        }
    printf("================================================================================\n");
    printf("Enter the User's ID you want to Remove");
    scanf("%d",&id);
    for(i=0; i<mem_no; i++)
    {
        if(curr_user[i].id==id)
            break;
    }
    if(i==mem_no)
    {
        system("color CF");
        printf("\nUser Not Found \a");
        printf("\nPress Any Key To Continue...");
        getch();
        admin();
    }
    else
    {
    if(curr_user[i].no_borru>0)
    {
        system("color CF");
        printf("\aThe User Can't Be Delete At This Moment ");
        printf("\nPress Any Key To Continue...");
        getch();
        admin();
    }
   else
   {
       curr_user[i].id=0;
    printf("You Want To Delete Another Member(Y/N)");
    do
    {
    switch(getch())
    {
    case'y':case'Y':
        del_mem();
        break;
    case'n':case'N':
        admin();
        break;
    default:
        flag=0;
        system("color FC");
        printf("\a\n*Invalid Input*");
        flag++;
    }
    }while(flag!=0);
   }
    }
}


void add_book()
{
    time_t currenttime;
    time(&currenttime);
    struct tm *mytime = localtime(&currenttime);
    int i,addcop,flag=0;
    system("cls");
    system("color F3");
    printf("\n\n\n\n\n\n\t\t\t\xDB\xDB\xDB\xDb\xB2 Add Book Menu \xB2\xDB\xDB\xDB\xDb\n\n\n");
    printf("\t\t\t\xDB 1-Add New Book \n\t\t\t\xDB\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 2-Add Copies \n\t\t\t\xDB\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB 3-Back To Menu \n\t\t\t\xDB\n\t\t\t\xDB\n");
    printf("\t\t\t\xDB Enter You Choice:");
    switch(getch())
    {
    case '2':
        new_cpy();
        break;
    case '1':
        system("cls");
        printf("\n  \t\t\t\xdb\xdb\xdb\xb0 Add New Book \xb0\xdb\xdb\xdb");
        printf("\n================================================================================");
        printf("\tToday's Date:%s\n",ctime(&currenttime));
        printf("\n\t\xdb Enter Book's ISBN: ");
        scanf("%s",book_new[newbook].ISBN);
        for(i=0; i<book_no; i++)
        {
            if(strcmp(book_new[newbook].ISBN,book_curr[i].ISBN)==0)
                break;
        }
        if(i!=book_no)
            {
                system("color FC");
                printf("\n\t\a*This ISBN Is Already Exist*");
                printf("\n\tYou Want To Add Copies (Y/N): ");
                do
                {
                switch(getch())
                {
                case'y':case'Y':
                    new_cpy();
                    break;
                case 'n': case'N':
                    admin();
                    break;
                default:
                    flag=0;
                    system("color FC");
                    printf("\n\t\aInvalid Input");
                    flag++;
                }
                }
                while(flag!=0);
            }
        else
        {
            printf("\n\t\xdb Enter Category: ");
            scanf("%s",book_new[newbook].catg);
            getchar();
            printf("\n\t\xdb Enter Title: ");
            gets(book_new[newbook].title);
            printf("\n\t\xdb Enter Author: ");
            gets(book_new[newbook].author);
            printf("\n\t\xdb Enter Publisher: ");
            gets(book_new[newbook].publisher);
            printf("\n\t\xdb Enter Date Of Publisher");
            comparedate[0].day=mytime->tm_mday;
            comparedate[0].month=mytime->tm_mon+1;
            comparedate[0].year=mytime->tm_year+1900;
            do
            {
                flag=0;
                printf("\n\t\xb0 Enter Day:");
                scanf("%d",&book_new[newbook].publish.day);
                printf("\t\xb0 Enter Month:");
                scanf("%d",&book_new[newbook].publish.month);
                printf("\t\xb0 Enter Year:");
                scanf("%d",&book_new[newbook].publish.year);
                if(book_new[newbook].publish.day > 28 + fmod(book_new[newbook].publish.month + floor(book_new[newbook].publish.month/8),2) + (2 % book_new[newbook].publish.month) + 2 * floor(1/book_new[newbook].publish.month))
                {
                    system("color FC");
                    printf("\n\t\a Enter Valid Date");
                    flag++;
                }
                else if (book_new[newbook].publish.day<0 || book_new[newbook].publish.month<0)
                {
                    system("FC");
                    printf("\n\t\aEnter Valid Date");
                    flag++;
                }
                else if (book_new[newbook].publish.month>12)
                {
                    system("color FC");
                    printf("\n\t\aEnter Valid Date\a");
                    flag++;
                }
                else if(book_new[newbook].publish.day>comparedate[0].day || book_new[newbook].publish.month>comparedate[0].month || book_new[newbook].publish.year>comparedate[0].year)
                {
                    system("color FC");
                    printf("\n\t\aEnter Valid Date");
                    flag++;
                }
            }
            while(flag !=0);
            system("color 30");
            printf("\n\t\xdb Enter Number Of Copies: ");

            do
            {
                scanf("%d",&book_new[newbook].no_cpy);
                if(book_new[newbook].no_cpy < 0)
                    {
                        system("color FC");
                        printf("\n\t\xb0 \aEnter a Postive Number of Copy: ");
                    }
            }
            while(book_new[newbook].no_cpy < 0);

            book_new[newbook].curr_copy=book_new[newbook].no_cpy;
            newbook++;
            book_new[newbook].no_borr=0;
            system("color 30");
            printf("\n\t\xb0 Book Added Successfully");
            printf("\n\tPress any Key To Back To Menu:");
            getch();
            admin();
        } break;
        case '3':
            admin();
            break;
        default:
            system("color FC");
            printf("\n\t\t\t \aEnter a valid number!");
            delay(1500);
            add_book();
    }
}
void delete_book()
{
    system("cls");
    system("color 0C");
    printf("\n\t\t\t\t** Books List **\n\n");
    char del_isbn [32];
    int i,flag=0;
    printf("ISBN  Category  Title  Author  Publisher  Date of Publisher  #Copies  # Borrow\n");
    for(i=0; i<book_no; i++)
    {
        if(strcmp(book_curr[i].ISBN,"Removable")==0)
        continue;

        else
        printf("%s\t%s\t%s\t%s\t%s\t  %d/%d/%d\t     %d|%d\t%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);

    }
    printf("\n================================================================================");
    printf("\nEnter The ISBN You Want To Delete:");
    scanf("%s",del_isbn);
    for (i=0; i<book_no; i++)
    {
        if(strcmp(book_curr[i].ISBN,del_isbn)==0)
            break;
    }
    strcpy(book_curr[i].ISBN,"Removable");
    printf("You Want To Delete Another Book(Y/N)");
    do
    {
    switch(getch())
    {
    case'y':case'Y':
        delete_book();
        break;
    case'n':case'N':
        admin();
        break;
    default:
        flag=0;
        system("color FC");
        printf("\a\n*Invalid Input*");
        flag++;
    }
    }while(flag!=0);
}

void borrow_book(int id)
{
    system("cls");
    time_t currenttime;
    time(&currenttime);
    struct tm *mytime = localtime(&currenttime);
    char isbn[32];
    int i,x,indexmem,indexbook,indexborrow;
        borrows[newborrow].user_id=id;
        printf("\t books list \n");
        for(i=0; i<book_no; i++)
            printf("%s  ,%s ,%s ,%s ,%s ,%d ,%d,%d ,%d,%d,%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
                   book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
        printf("please enter the book ISBN you want to borrow:\n");
        fflush(stdin);
        gets(isbn);
        for(x=0; x<book_no; x++)
        {

            if(strcmp(isbn,book_curr[x].ISBN)==0)
            {
                indexbook=x;
                strcpy(borrows[newborrow].book_isbn,isbn);
                break;
            }
        }
        if(x==book_no)
        {
            printf("please enter a valid ISBN!!!\n");
            printf("enter any key to return to the menu!");
            getch();
            return addmem();
        }

        for(x=0; x<mem_no; x++)
        {
            if(id==curr_user[x].id)
            {
                indexmem=x;
                borrows[newborrow].user_id=id;
            }
        }
        if(curr_user[indexmem].no_borru<3)
        {
            if(book_curr[indexbook].curr_copy>0)
            {
                borrows[newborrow].borr_no++;
                curr_user[indexmem].no_borru++;
                book_curr[indexbook].curr_copy--;
                book_curr[indexbook].no_borr++;
                borrows[newborrow].borrow_date.month=mytime->tm_mon+1;
                borrows[newborrow].borrow_date.day=mytime->tm_mday;
                borrows[newborrow].borrow_date.year=mytime->tm_year+1900;
                borrows[newborrow].duedate.month=mytime->tm_mon+1;
                borrows[newborrow].duedate.day=mytime->tm_mday+5;
                borrows[newborrow].duedate.year=mytime->tm_year+1900;
                if(borrows[newborrow].duedate.day>31)
                {
                    borrows[newborrow].duedate.month++;
                    borrows[newborrow].duedate.day-=31;
                }
                if(borrows[newborrow].duedate.month>12)
                {
                    borrows[newborrow].duedate.year++;
                    borrows[newborrow].duedate.month-=12;
                }
                printf("you borrowed a book\n");
                for(i=0; i<mem_no; i++)
                    printf("%d",curr_user[i].no_borru);
                printf("enter any key to return to the menu!");
                getch();
                newborrow++;
                return addmem();
            }
            else
            {
                printf("Sorry there is no copies available for that book!!");
                printf("press any key to return to the menu!!");
                getch();
                return addmem();
            }
        }
        else
        {
            printf("you reached the maximium number of your borrows!\n");
            printf("enter any key to return to the menu!");
            getch();
            return addmem();
        }
    }
void search_book(int id)
{
    char searchtarget[50];
    char *z;
    int x;
    int titlecounter=0;
    int authorcounter=0;
    int isbncounter=0;
    int catgcounter=0;
    int counter=0;
    system("cls");
    printf("1-Search by book title:\n");
    printf("2-Search by book author:\n");
    printf("3-Search by book ISBN:\n");
    printf("4-Search by book category:\n");
    printf("5-search by book title or author or both\n");
    printf("6-return to the menu:");
    switch(getch())
    {
    case '1':
        search_booktitle(id);
        break;
    case '2':
        search_bookauthor(id);
        break;
    case '3':
        search_bookisbn(id);
        break;
    case '4':
        search_bookcatg(id);
        break;
    case '5':
        search_double(id);
        break;
    case '6':
        user(id);
        break;
    default:
        printf("\nenter a valid number!!");
        search_book(id);
    }
}
void user (int id)
{
    system("cls");
    printf("1-Borrow Book\n");
    printf("2-Return Book\n");
    printf("3-Search Book\n");
    printf("4-menu\n");
    popular_book();
    switch(getch())
    {
    case '1':
        borrow_book(id);
        break;
    case '2':
        ret_book(id);
        break;
    case '3':
        search_book(id);
        break;
    case '4':
        addmem();
        break;
    default:
        printf("Enter A valid Number");
        user(id);
    }

}
void overdue()
{
    system("cls");
    system("color F0");
    int i;
    time_t currenttime;
    time(&currenttime);
    struct tm *mytime = localtime(&currenttime);
    printf("\n\t\t\t\xDB\xDb\xB2 Overdue Books \xB2\xDB\xDb");
    printf("\n\nToday's Date :%s",ctime(&currenttime));
    printf("\n================================================================================");
        for(i=0; i<newborrow; i++)
        {
            overd[i].day=mytime->tm_mday;
            overd[i].month=mytime->tm_mon+1;
            overd[i].year=mytime->tm_year+1900;
            if(borrows[i].duedate.day<overd[i].day || borrows[i].duedate.month<overd[i].month ||borrows[i].duedate.year<overd[i].year)
                break;
        }
        if(i==newborrow)
        {
            printf("There Aren't Any Overdued Books At This Moment\n");
            printf("\n================================================================================");
            printf("\nPress Any Key To Continue...");
            getch();
            return admin();
        }
        else
        {
            for(i=0; i<newborrow; i++)
            {
                overd[i].day=mytime->tm_mday;
                overd[i].month=mytime->tm_mon+1;
                overd[i].year=mytime->tm_year+1900;
                if(borrows[i].ret_date.day==0 && borrows[i].ret_date.month==0 && borrows[i].ret_date.year==0)
                {
                    if(borrows[i].duedate.day<overd[i].day || borrows[i].duedate.month<overd[i].month ||borrows[i].duedate.year<overd[i].year)
                    {
                        printf("%s %d %d %d %d %d/%d/%d %d/%d/%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
                               borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
                               borrows[i].ret_date.year);
                    }
                }
            }
            printf("\n================================================================================");
            printf("press any key to return to the menu!!");
            getch();
            return admin();
        }
    }
void popular_book()
{
    int i,j,k;
    books *min,*high;
    high = malloc(sizeof(books)*5);
    min = malloc(sizeof(books));

    for(j=0; j<5; j++)
    {
        high[j]=book_curr[j];
        strcpy(high[j].author,book_curr[j].author);
        strcpy(high[j].catg,book_curr[j].catg);
        strcpy(high[j].ISBN,book_curr[j].ISBN);
        strcpy(high[j].publisher,book_curr[j].publisher);
        strcpy(high[j].title,book_curr[j].title);
    }

    for(i=5; i<book_no; i++)
    {
        k=0;
        *min=high[0];
        strcpy(min->author,high[0].author);
        strcpy(min->catg,high[0].catg);
        strcpy(min->ISBN,high[0].ISBN);
        strcpy(min->publisher,high[0].publisher);
        strcpy(min->title,high[0].title);

        for(j=0; j<5; j++)
        {
            if(high[j].no_borr< min->no_borr)
            {
                k=j;
                *min=high[j];
                strcpy(min->author,high[j].author);
                strcpy(min->catg,high[j].catg);
                strcpy(min->ISBN,high[j].ISBN);
                strcpy(min->publisher,high[j].publisher);
                strcpy(min->title,high[j].title);
            }
        }

        if(high[k].no_borr < book_curr[i].no_borr)
        {
            high[k]=book_curr[i];
            strcpy(high[k].author,book_curr[i].author);
            strcpy(high[k].catg,book_curr[i].catg);
            strcpy(high[k].ISBN,book_curr[i].ISBN);
            strcpy(high[k].publisher,book_curr[i].publisher);
            strcpy(high[k].title,book_curr[i].title);
        }

    }
    printf("\t \t \t Popluar books\n\n");
    for(j=0; j<5; j++)
    {
        printf("%s %s %s %s %s %d %d,%d %d %d %d \n",high[j].ISBN,high[j].catg,high[j].title,high[j].author,high[j].publisher,
               high[j].publish.day,high[j].publish.month,high[j].publish.year,high[j].no_cpy,high[j].curr_copy,high[j].no_borr);

    }
    free(high);
    free(min);

}
void ret_book(int id)
{
    system("cls");
    time_t currenttime;
    time(&currenttime);
    struct tm *mytime = localtime(&currenttime);
    char isbn[32];
    int i,x,indexmem,indexbook,indexreturn;
        borrows[newborrow].user_id=id;
        printf("please enter the book ISBN you want to return:\n");
        fflush(stdin);
        gets(isbn);
        for(x=0; x<book_no; x++)
        {
            if(strcmp(isbn,book_curr[x].ISBN)==0)
            {
                indexbook=x;
            }
        }

        for(x=0; x<newborrow; x++)
        {
            if(id==curr_user[x].id)
            {
                indexmem=x;
            }
        }
        for(x=0; x<newborrow; x++)
        {
            break;
        }
        if(x==newborrow)
        {
            printf("Enter a valid ISBN!!\n");
            printf("press any key to return to the menu!!");
            getch();
            return addmem();
        }
        if(curr_user[indexmem].no_borru>0)
        {
            for(x=0; x<newborrow; x++)
            {
                if(borrows[x].ret_date.day==0 && borrows[x].ret_date.month==0 && borrows[x].ret_date.year==0)
                {
                    printf("%s,%d\n",borrows[x].book_isbn,borrows[x].user_id);
                    if(strcmp(isbn,borrows[x].book_isbn)==0 && borrows[x].user_id==id)
                    {
                        curr_user[indexmem].no_borru--;
                        book_curr[indexbook].curr_copy++;
                        borrows[x].ret_date.month=mytime->tm_mon+1;
                        borrows[x].ret_date.day=mytime->tm_mday;
                        borrows[x].ret_date.year=mytime->tm_year+1900;
                        printf("you returned a book\n");
                        printf("%d,%d,%d,%d,%d",curr_user[indexmem].no_borru,book_curr[indexbook].curr_copy,borrows[x].ret_date.month,
                               borrows[x].ret_date.day,borrows[x].ret_date.year);
                        printf("enter any key to return to the menu!");
                        getch();
                        return addmem();
                    }
                }
            }
        }
        printf("you already returned the book!!!\n");
        printf("enter any key to return to the menu!");
        getch();
        return addmem();
    }

void new_cpy()
{
    int no,i;
    system("cls");
    system("color 30");
    printf("\n\n\n\n\n\n\t\t\t\xDB\xDB\xDB\xDb\xB2 Add Copies \xB2\xDB\xDB\xDB\xDb\n\n\n");
    printf("\t\t\t\xDB Enter Book's ISBN: ");
    scanf("%s",book_new[newbook].ISBN);
    for(i=0; i<book_no; i++)
    {
        if(strcmp(book_new[newbook].ISBN,book_curr[i].ISBN)==0)
            break;
    }
    if(i!=book_no)
    {
        printf("\n\t\t\t\xDB Enter The Number of Copies:");
        scanf("%d",&no);
        book_new[newbook]=book_curr[i];
        book_new[newbook].no_cpy+=no;
        book_new[newbook].curr_copy+=no;
        strcpy(book_new[newbook].catg,book_curr[i].catg);
        strcpy(book_new[newbook].author,book_curr[i].author);
        strcpy(book_new[newbook].publisher,book_curr[i].publisher);
        strcpy(book_new[newbook].title,book_curr[i].title);
        strcpy(book_curr[i].ISBN,"Removable");
        newbook++;
        printf("\n\t\t\t\xB2 Copies Added Successfully");
        printf("\n\t\t\t\xB2 Press Any Key To Continue....");
        getch();
        admin();
    }
    else
    {
        system("color FC");
        printf("\n\t\t\t\xB2 \aThis ISBN Isn't Exist");
        printf("\n\t\t\t\xB2 Press Any Key To Back...");
        getch();
        add_book();
}
}
int check_id()
{
    int id,i,flag=0;
    system("cls");
    printf("Enter Your ID :");
    scanf("%d",&id);
    for(i=0; i<mem_no; i++)
    {
        if(id==curr_user[i].id)
            break;
        flag++;
    }
    if(flag!=mem_no)
    {
        user(id);
        return id;
    }
    else
    {
        printf("Wrong ID Please Enter Valid One:");
        check_id();
    }

}

void new_save()
{
    int i;
    fb = fopen("members.txt","a");
    for(i=0; i<newnumber; i++)
    {
        if(mem_no==0&&i==0)
            fprintf(fb,"%s,%s,%d,%d,%s,%s,0%d,%d,%d,%s",new_user[i].f_name,new_user[i].l_name,new_user[i].id,new_user[i].adrs.street_no,
                    new_user[i].adrs.zone,new_user[i].adrs.city,new_user[i].phone,new_user[i].age,new_user[i].no_borru,new_user[i].email);
        else
            fprintf(fb,"\n%s,%s,%d,%d,%s,%s,0%d,%d,%d,%s",new_user[i].f_name,new_user[i].l_name,new_user[i].id,new_user[i].adrs.street_no,
                    new_user[i].adrs.zone,new_user[i].adrs.city,new_user[i].phone,new_user[i].age,new_user[i].no_borru,new_user[i].email);
    }
    fclose(fb);

    fc=fopen("books.txt","a");
    for(i=0; i<newbook; i++)
    {
        if(book_no==0&&i==0)
            fprintf(fc,"%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d",book_new[i].ISBN,book_new[i].catg,book_new[i].title,book_new[i].author,book_new[i].publisher,
                    book_new[i].publish.day,book_new[i].publish.month,book_new[i].publish.year,book_new[i].no_cpy,book_new[i].curr_copy,book_new[i].no_borr);
        else
            fprintf(fc,"\n%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d",book_new[i].ISBN,book_new[i].catg,book_new[i].title,book_new[i].author,book_new[i].publisher,
                    book_new[i].publish.day,book_new[i].publish.month,book_new[i].publish.year,book_new[i].no_cpy,book_new[i].curr_copy,book_new[i].no_borr); // 3lshn mynzlsh str
    }
    fclose(fc);

    fd= fopen("borrow.txt","a");
    for(i=0; i<newborrow; i++)
    {
        if(i==0)//notess
            fprintf(fd,"%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
                    borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
                    borrows[i].ret_date.year);
        else
        {
            fprintf(fd,"\n%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
                    borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
                    borrows[i].ret_date.year);
        }

    }
    fclose(fd);

    newbook=newborrow=newnumber=0;
}

void del_save()
{
    int i,flag=0;
    temp=fopen("books.txt","w");
    for(i=0; i<book_no; i++)
    {
        if(strcmp(book_curr[i].ISBN,"Removable")==0)
            continue;
        else
        {
            if(i==0||flag==0)
            {
                fprintf(temp,"%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
                        book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
                flag++;
            }
            else
                fprintf(temp,"\n%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
                        book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
        }

    }
    fclose(temp);

    temp=fopen("members.txt","w");
    flag=0;
    for(i=0; i<mem_no; i++)
    {
        if(curr_user[i].id==0)
            continue;
        else
        {
            if(i==0 || flag==0)
            {
                fprintf(temp,"%s,%s,%d,%d,%s,%s,0%d,%d,%d,%s",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no,
                        curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].no_borru,curr_user[i].email);
                flag++;
            }
            else
                fprintf(temp,"\n%s,%s,%d,%d,%s,%s,0%d,%d,%d,%s",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no,
                        curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].no_borru,curr_user[i].email);

        }
    }
    fclose(temp);

    temp=fopen("borrow.txt","w");
    for(i=0; i<borrow_no; i++)
    {
        if(i==0)
        {
            fprintf(temp,"%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",borrows_curr[i].book_isbn,borrows_curr[i].user_id,borrows_curr[i].borrow_date.day,borrows_curr[i].borrow_date.month,
                    borrows_curr[i].borrow_date.year,borrows_curr[i].duedate.day,borrows_curr[i].duedate.month,borrows_curr[i].duedate.year,borrows_curr[i].ret_date.day,borrows_curr[i].ret_date.month,
                    borrows_curr[i].ret_date.year);
            flag++;
        }
        else
            fprintf(temp,"\n%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",borrows_curr[i].book_isbn,borrows_curr[i].user_id,borrows_curr[i].borrow_date.day,borrows_curr[i].borrow_date.month,
                    borrows_curr[i].borrow_date.year,borrows_curr[i].duedate.day,borrows_curr[i].duedate.month,borrows_curr[i].duedate.year,borrows_curr[i].ret_date.day,borrows_curr[i].ret_date.month,
                    borrows_curr[i].ret_date.year);
    }
    fclose(temp);
    printf("Done");
    getch;
}
void show_list(int x)
{
    int i;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\xDB\xDB\xDB\xDb\xB2 Show List Menu \xB2\xDB\xDB\xDB\xDb\n\n\n");
    if(x == 0)
    {
        printf("\t\t\t\xDB 1-Book List \n\t\t\t\xDB\n\t\t\t\xDB\n");
        printf("\t\t\t\xDB 2-Member List ");
        printf("\n\t\t\t\xDB\n\t\t\t\xDB\n\t\t\t\xDB 3-All Borrow Logs");
        printf("\n\n\t\t\t\xB2 Enter Your Choice:");
    }
    else
    {
        printf("\t\t\t\xDB 1-Book List\n");
        printf("\n\t\t\t\xDB 2-All Borrow Logs");
        printf("\n\n\t\t\t\xB2 Enter Your Choice:");
    }
    switch(getch())
    {

    case '2':
        if(x ==0 )
        {
        system("cls");
         printf("\n\t\t\t\t** Member List **\n\n");
    printf("Memeber Name   ID   Address \t Phone\t   Age #Borrow  Email \n\n");
    if(mem_no==0)
    {
        printf("There is No Available Members At This Moment");
        printf("================================================================================\n");
        printf("Press Any Key To Back To Menu...");
        getch();
        admin();
    }
    else
    {
        for(i=0; i<mem_no; i++)
        {
            if(curr_user[i].id==0)
                continue;
            else
            printf("%s %s %d  %d-%s-%s %0d %d  %d   %s\n\n",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no
                   ,curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].no_borru,curr_user[i].email);
        }
    printf("================================================================================\n");
    printf("Press Any Key To Back To Menu...");
    getch();
    admin();
        }
        }
        else
        {
            if(newborrow==0)
            {
                system("cls");
                printf("There is No Available Borrows At This Moment");
                printf("================================================================================\n");
                printf("Press Any Key To Back To Menu...");
                getch();
                user(x);
            }
            else
            {
            int flag=0;
            system("cls");
            printf("\n\t\t\t\t** My Borrow List **\n\n");
            for(i=0;i<newborrow;i++)
            {
                if(x == borrows[i].user_id)
                {

                    printf("%s  %d  %d  %d  %d  %d/%d/%d  %d/%d/%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,
                   borrows[i].borrow_date.month,borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,
                   borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,borrows[i].ret_date.year);
                   flag++;
                   }
            }
                printf("Press Any Key To Back To Menu...");
                printf("================================================================================\n");
                getch();
                user(x);

            if(flag== 0)
            {
                system("cls");
                printf("There is No Available Borrows At This Moment");
                printf("================================================================================\n");
                printf("Press Any Key To Back To Menu...");
                getch();
                user(x);
            }
            }

        }
        break;
    case '1':
        system("cls");
        printf("\n\t\t\t\t** Book List **\n\n");
        printf("ISBN  Category  Title  Author  Publisher  Date of Publisher  #Copies  # Borrow\n");
        if(book_no==0)
        {
            printf("There is No Available Books At This Moment");
            printf("================================================================================\n");
            printf("Press Any Key To Back To Menu...");
            getch();
            admin();
        }
        else
        {
        for(i=0; i<book_no; i++)
        {
        if(strcmp(book_curr[i].ISBN,"Removable")==0)
        continue;

        else
        printf("%s\t%s\t%s\t%s\t%s\t  %d/%d/%d\t     %d|%d\t%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);

    }
            printf("\n================================================================================");
            printf("\nPress Any Key To Back To Menu...");
            getch();
            admin();

        }
        break;
    case '3':
        system("cls");
        printf("\n\t\t\t\t** Borrow List **\n\n");
            for(i=0;i<newborrow;i++)
            {
                printf("%s  %d  %d  %d  %d  %d/%d/%d  %d/%d/%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,
                   borrows[i].borrow_date.month,borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,
                   borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,borrows[i].ret_date.year);
            }

                printf("================================================================================\n");
                printf("Press Any Key To Back To Menu...");
                getch();
                admin();

        break;
        default:
        system("color F0");
        printf("Enter Valid input:");
        delay(1500);
        show_list(x);
    }
}
void search_double(int id)//notes bonus b3d alta3del
{
    system("cls");
    char searchtarget[30];
    char searchtargetauthor[30];
    char *z,*y;
    int x;
    int titlecounter=0;
    int authorcounter=0;
    int counter=0;
    fflush(stdin);
    printf("Enter the title of the book:\n");
    gets(searchtarget);
    printf("Enter the author of the book:\n");
    gets(searchtargetauthor);
    z=strstr(searchtarget,"\n");
    y=strstr(searchtargetauthor,"\n");
    if (z==NULL && y==NULL)
    {
        for(x=0; x<book_no; x++)
        {
            z=strstr(book_curr[x].title,searchtarget);
            y=strstr(book_curr[x].author,searchtargetauthor);
            if(z!=NULL)
                titlecounter++;
            if(y!=NULL)
                authorcounter++;
        }
        if (titlecounter==0 || authorcounter==0)
            printf("there is no books matches the request!!");
        else
        {
            books searchdata[30];
            for(x=0; x<book_no; x++)
            {
                z=strstr(book_curr[x].title,searchtarget);
                y=strstr(book_curr[x].author,searchtargetauthor);
                if(z!=NULL && y!=NULL)
                {
                    strcpy(searchdata[counter].title,book_curr[x].title);
                    strcpy(searchdata[counter].author,book_curr[x].author);
                    strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                    strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                    searchdata[counter].publish.day=book_curr[x].publish.day;
                    searchdata[counter].publish.month=book_curr[x].publish.month;
                    searchdata[counter].publish.year=book_curr[x].publish.year;
                    searchdata[counter].curr_copy=book_curr[x].curr_copy;
                    searchdata[counter].no_cpy=book_curr[x].no_cpy;
                    strcpy(searchdata[counter].catg,book_curr[x].catg);
                    counter++;
                }
            }
            printf("the list of books found %d books\n",counter);
            printf("------------------------------------\n");
            for(x=0; x<counter; x++)
                printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                       searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
            printf("\n press any key to return to the menu");
            getch();
            return user(id);
        }
    }
    else if(z==NULL && y!=NULL)
    {
        for(x=0; x<book_no; x++)
        {
            z=strstr(book_curr[x].title,searchtarget);
            if(z!=NULL)
                titlecounter++;
        }
        if (titlecounter==0)
            printf("there is no books matches the request!!");
        else
        {
            books searchdata[titlecounter];
            for(x=0; x<book_no; x++)
            {
                z=strstr(book_curr[x].title,searchtarget);
                if(z!=NULL)
                {
                    strcpy(searchdata[counter].title,book_curr[x].title);
                    strcpy(searchdata[counter].author,book_curr[x].author);
                    strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                    strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                    searchdata[counter].publish.day=book_curr[x].publish.day;
                    searchdata[counter].publish.month=book_curr[x].publish.month;
                    searchdata[counter].publish.year=book_curr[x].publish.year;
                    searchdata[counter].curr_copy=book_curr[x].curr_copy;
                    searchdata[counter].no_cpy=book_curr[x].no_cpy;
                    strcpy(searchdata[counter].catg,book_curr[x].catg);
                    counter++;
                }
            }
            printf("the list of books found %d books\n",counter);
            printf("------------------------------------\n");
            for(x=0; x<counter; x++)
                printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                       searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
            printf("\n press any key to return to the menu");
            getch();
            return user(id);
        }

    }
    else if(z!=NULL && y==NULL)
    {
        for(x=0; x<book_no; x++)
        {
            if(strcmp(searchtargetauthor,book_curr[x].author)==0)
                authorcounter++;
        }
        if (authorcounter==0)
            printf("\nthere is no books matches the request!!");
        else
        {
            books searchdata[authorcounter];
            for(x=0; x<book_no; x++)
            {
                if(strcmp(searchtarget,book_curr[x].author)==0)
                {
                    strcpy(searchdata[counter].title,book_curr[x].title);
                    strcpy(searchdata[counter].author,book_curr[x].author);
                    strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                    strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                    searchdata[counter].publish.day=book_curr[x].publish.day;
                    searchdata[counter].publish.month=book_curr[x].publish.month;
                    searchdata[counter].publish.year=book_curr[x].publish.year;
                    searchdata[counter].curr_copy=book_curr[x].curr_copy;
                    searchdata[counter].no_cpy=book_curr[x].no_cpy;
                    strcpy(searchdata[counter].catg,book_curr[x].catg);
                    counter++;
                }
            }
            printf("the list of books found %d books\n",counter);
            printf("------------------------------------\n");
            for(x=0; x<counter; x++)
                printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                       searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
            printf("\n press any key to return to the menu");
            getch();
            return user(id);
        }
    }
}
void search_booktitle(int id)
{
    system("cls");
    char searchtarget[50];
    char *z;
    int x;
    int titlecounter=0;
    int counter=0;
    fflush(stdin);
    printf("please search by book's title or a part of it:");
    gets(searchtarget);
    for(x=0; x<book_no; x++)
    {
        z=strstr(book_curr[x].title,searchtarget);
        if(z!=NULL)
            titlecounter++;
    }
    if (titlecounter==0)
        printf("there is no books matches the request!!");
    else
    {
        books searchdata[titlecounter];
        for(x=0; x<book_no; x++)
        {
            z=strstr(book_curr[x].title,searchtarget);
            if(z!=NULL)
            {
                strcpy(searchdata[counter].title,book_curr[x].title);
                strcpy(searchdata[counter].author,book_curr[x].author);
                strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                searchdata[counter].publish.day=book_curr[x].publish.day;
                searchdata[counter].publish.month=book_curr[x].publish.month;
                searchdata[counter].publish.year=book_curr[x].publish.year;
                searchdata[counter].curr_copy=book_curr[x].curr_copy;
                searchdata[counter].no_cpy=book_curr[x].no_cpy;
                strcpy(searchdata[counter].catg,book_curr[x].catg);
                counter++;
            }
        }
        printf("the list of books found %d books\n",counter);
        printf("------------------------------------\n");
        for(x=0; x<counter; x++)
            printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                   searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
        printf("\n press any key to return to the menu");
        getch();
        return user(id);
    }

}
void search_bookisbn(int id)
{
    system("cls");
    char searchtarget[50];
    int x;
    int isbncounter=0;
    int counter=0;
    fflush(stdin);
    printf("please search by book's ISBN:");
    gets(searchtarget);
    for(x=0; x<book_no; x++)
    {
        if(strcmp(searchtarget,book_curr[x].ISBN)==0)
            isbncounter++;
    }
    if (isbncounter==0)
        printf("there is no books matches the request!!");
    else
    {
        books searchdata[isbncounter];
        for(x=0; x<book_no; x++)
        {
            if(strcmp(searchtarget,book_curr[x].ISBN)==0)
            {
                strcpy(searchdata[counter].title,book_curr[x].title);
                strcpy(searchdata[counter].author,book_curr[x].author);
                strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                searchdata[counter].publish.day=book_curr[x].publish.day;
                searchdata[counter].publish.month=book_curr[x].publish.month;
                searchdata[counter].publish.year=book_curr[x].publish.year;
                searchdata[counter].curr_copy=book_curr[x].curr_copy;
                searchdata[counter].no_cpy=book_curr[x].no_cpy;
                strcpy(searchdata[counter].catg,book_curr[x].catg);
                counter++;
            }
        }
        printf("the list of books found %d books\n",counter);
        printf("------------------------------------\n");
        for(x=0; x<counter; x++)
            printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                   searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
        printf("\n press any key to return to the menu");
        getch();
        return user(id);
    }
}
void search_bookauthor(int id)
{
    system("cls");
    char searchtarget[50];
    int x;
    int authorcounter=0;
    int counter=0;
    fflush(stdin);
    printf("please search by book's author:");
    gets(searchtarget);
    for(x=0; x<book_no; x++)
    {
        if(strcmp(searchtarget,book_curr[x].author)==0)
            authorcounter++;
    }
    if (authorcounter==0)
        printf("\nthere is no books matches the request!!");
    else
    {
        books searchdata[authorcounter];
        for(x=0; x<book_no; x++)
        {
            if(strcmp(searchtarget,book_curr[x].author)==0)
            {
                strcpy(searchdata[counter].title,book_curr[x].title);
                strcpy(searchdata[counter].author,book_curr[x].author);
                strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                searchdata[counter].publish.day=book_curr[x].publish.day;
                searchdata[counter].publish.month=book_curr[x].publish.month;
                searchdata[counter].publish.year=book_curr[x].publish.year;
                searchdata[counter].curr_copy=book_curr[x].curr_copy;
                searchdata[counter].no_cpy=book_curr[x].no_cpy;
                strcpy(searchdata[counter].catg,book_curr[x].catg);
                counter++;
            }
        }
        printf("the list of books found %d books\n",counter);
        printf("------------------------------------\n");
        for(x=0; x<counter; x++)
            printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                   searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
        printf("\n press any key to return to the menu");
        getch();
        return user(id);
    }

}
void search_bookcatg(int id)
{
    system("cls");
    char searchtarget[50];
    int x;
    int catgcounter=0;
    int counter=0;
    fflush(stdin);
    printf("please search by book's category:");
    gets(searchtarget);
    for(x=0; x<book_no; x++)
    {
        if(strcmp(searchtarget,book_curr[x].catg)==0)
            catgcounter++;
    }
    if (catgcounter==0)
        printf("there is no books matches the request!!");
    else
    {
        books searchdata[catgcounter];
        for(x=0; x<book_no; x++)
        {
            if(strcmp(searchtarget,book_curr[x].catg)==0)
            {
                strcpy(searchdata[counter].title,book_curr[x].title);
                strcpy(searchdata[counter].author,book_curr[x].author);
                strcpy(searchdata[counter].publisher,book_curr[x].publisher);
                strcpy(searchdata[counter].ISBN,book_curr[x].ISBN);
                searchdata[counter].publish.day=book_curr[x].publish.day;
                searchdata[counter].publish.month=book_curr[x].publish.month;
                searchdata[counter].publish.year=book_curr[x].publish.year;
                searchdata[counter].curr_copy=book_curr[x].curr_copy;
                searchdata[counter].no_cpy=book_curr[x].no_cpy;
                strcpy(searchdata[counter].catg,book_curr[x].catg);
                counter++;
            }
        }
        printf("the list of books found %d books\n",counter);
        printf("------------------------------------\n");
        for(x=0; x<counter; x++)
            printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                   searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
        printf("\n press any key to return to the menu");
        getch();
        return user(id);
    }

}


#endif // FUNCTIONS_H_INCLUDED
