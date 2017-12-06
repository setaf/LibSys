#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "struct.h"

FILE *fb, *fc, *temp; //34an el delete function
time_t borr_date,ret_date;
int mem_no,book_no; //# of  members
int newnumber=0;
int newbook=0;
users new_user[100]; //lazem 34an tst5dmha fel save
users curr_user[100];
books book_new[100];
books book_curr[100];

void menu (void)
{
    system("cls");
    printf("1-admin\n");
    printf("2-user\n");
    printf("3-exit\n");
    printf("%d",mem_no);
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
void admin ()
{
    system("cls");
    printf("1-add\n");
    printf("2-delete\n");
    printf("3-search\n");
    printf("4-overdue\n");
    printf("5-delete mem\n");
    printf("6-show list\n");
    printf("7-Save Changes \n");
    printf("8-menu\n");
    printf("9-popular");
    switch (getch())
    {
    case '1':
        add_book();
        break;
    case '2':
        delete_book();
        break;
    case '3':
        search_book();
        break;
    case '4':
        overdue();
        break;
    case '5':
        del_mem();
    case '6' :
        show_list();
    case '7':
    new_save();
        break;
    case '8':
        menu();
        break;
    case '9':
        popular_book();
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
    printf("3-Save Changes \n");
    printf("4-back to Main menu\n");
    switch (getch())
    {
    case '1':
        check_id();
        break;
    case '2':
        if ((fb = fopen("members.txt","r")) == NULL)
        {
            fb = fopen("members.txt","w");
            system("cls");
            printf("Enter Your First Name:\n");
            gets(new_user[newnumber].f_name);
            printf("Enter Your Last Name:\n");
            gets(new_user[newnumber].l_name);
            printf("Enter Your ID:\n");
            scanf("%d",&new_user[newnumber].id);
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
            int i,flag=0;
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
            newnumber++;
            fclose(fb);
        }
        else
        {
            system("cls");
            fb = fopen("members.txt","a");
            int i;
            printf("Enter Your First Name:\n");
            gets(new_user[newnumber].f_name);
            printf("Enter Your Last Name:\n");
            gets(new_user[newnumber].l_name);
            do
            {
                printf("Enter Your ID:\n");
                scanf("%d",&new_user[newnumber].id);
                for(i=0;i<mem_no;i++)
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
            newnumber++;
            fclose(fb);
        }
        printf("Welcome %s\n Your ID:%d\n",new_user[newnumber-1].f_name,new_user[newnumber-1].id);
        printf("Press Any Key To Continue....");
        switch(getch())
        default:
        addmem();
        break;
        case '3':new_save();break;
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
    if (temp = fopen("members.txt","r")== NULL)
    {
        return;
    }
     temp = fopen("members.txt","r");
     while (!feof(temp))
    {
        fscanf(temp,"%[^,],%[^,],%d,%d,%[^,],%[^,],%d,%d,%s",curr_user[mem_no].f_name,curr_user[mem_no].l_name,&curr_user[mem_no].id,&curr_user[mem_no].adrs.street_no,
                curr_user[mem_no].adrs.zone,curr_user[mem_no].adrs.city,&curr_user[mem_no].phone,&curr_user[mem_no].age,curr_user[mem_no].email);

            mem_no++;
    }
    fclose(temp);

    if (temp = fopen("books.txt","r")== NULL)
    {
        return;
    }
     temp = fopen("books.txt","r");
     while (!feof(temp))
    {
        fscanf(temp,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d\n",book_curr[book_no].ISBN,book_curr[book_no].catg,book_curr[book_no].title,book_curr[book_no].author,book_curr[book_no].publisher,
               &book_curr[book_no].publish.day,&book_curr[book_no].publish.month,&book_curr[book_no].publish.year,&book_curr[book_no].no_cpy,&book_curr[book_no].curr_copy,&book_curr[book_no].no_borr);

            book_no++;
    }
    fclose(temp);

}
void del_mem()
{
    int i,position,id;
    printf("Enter the User's ID you want to remove");
    scanf("%d",&id);
    for(i=0;i<mem_no;i++)
    {
        if(curr_user[i].id==id)
            position=i;
    }
    for(i=position;i<mem_no-2;i++)
    {
     strcpy(curr_user[i+1].f_name,curr_user[i].f_name);
     strcpy(curr_user[i+1].l_name,curr_user[i].l_name);
     curr_user[i].id=curr_user[i+1].id;
     curr_user[i].adrs.street_no=curr_user[i+1].adrs.street_no;
     strcpy(curr_user[i+1].adrs.zone,curr_user[i].adrs.zone);
     strcpy(curr_user[i+1].adrs.city,curr_user[i].adrs.city);
     curr_user[i].phone=curr_user[i+1].phone;
     curr_user[i].age=curr_user[i+1].age;
     strcpy(curr_user[i+1].email,curr_user[i].email);

}
}

void add_book()
{
   int i,addcop,flag=0;
   if(fc=fopen("books.txt","r") == NULL)
        {
            fc=fopen("books.txt","w");
            system("cls");
            printf("ente isbn");
            scanf("%s",book_new[newbook].ISBN);
            printf("enter catg");
            scanf("%s",book_new[newbook].catg);
            getchar();
            printf("enter tittle");
            gets(book_new[newbook].title);
            printf("enter author");
            gets(book_new[newbook].author);
            printf("enter pulisher");
            gets(book_new[newbook].publisher);
            printf("enter date of publish DD/MM/YYYY");
            scanf("%d%d%d",&book_new[newbook].publish.day,&book_new[newbook].publish.month,&book_new[newbook].publish.year);
            printf("enter the No.copies");
            do{
            scanf("%d",&book_new[newbook].no_cpy);
            if(book_new[newbook].no_cpy<0)
                printf("Enter a Postive Number of Copy \a \n: ");
            }while(book_new[newbook].no_cpy<0);
            book_new[newbook].curr_copy=book_new[newbook].no_cpy;
            newbook++;
            book_new[newbook].no_borr=0;
            fclose(fc);
            admin();

        }
        else
        {
            fc=fopen("books.txt","a");
            system("cls");
            printf("ente isbn");
            scanf("%s",book_new[newbook].ISBN);
            for(i=0;i<book_no;i++)
            {
                if(book_new[newbook].ISBN==book_curr[i].ISBN)
                {
                    printf("This book is Already Exist Enter the No of Copies:");
                    scanf("%d",&addcop);
                    book_curr[i].no_cpy+=addcop;
                    book_curr[i].curr_copy+=addcop;
                    flag++;

                }
            }
            if(flag==1)
            {
                newbook--;
                fclose(fc);
                admin();
            }
            else
            {
            printf("enter catg");
            scanf("%s",book_new[newbook].catg);
            getchar();
            printf("enter tittle");
            gets(book_new[newbook].title);
            printf("enter author");
            gets(book_new[newbook].author);
            printf("enter pulisher");
            gets(book_new[newbook].publisher);
            printf("enter date of publish DD/MM/YYYY");
            scanf("%d%d%d",&book_new[newbook].publish.day,&book_new[newbook].publish.month,&book_new[newbook].publish.year);
            printf("enter the No.copies");
            scanf("%d",&book_new[newbook].no_cpy);
            book_new[newbook].curr_copy=book_new[newbook].no_cpy;
            newbook++;
            book_new[newbook].no_borr=0;
            fclose(fc);
            admin();
        }
        }

}


void delete_book()
{

}
void borrow_book(int a)
{

}
void search_book()
{

}

void user (int id)
{
    system("cls");
    printf("1-Borrow Book\n");
    printf("2-Return Book\n");
    printf("3-Search Book\n");
    printf("4-menu\n");
    switch(getch())
    {
    case '1':
        borrow_book(1);
        break;
    case '2':
        ret_book(2);
        break;
    case '3':
        search_book();
        break;
    case '4':
        menu();
        break;
    default:
        printf("Enter A valid Number");
        user(id);
    }

}
void overdue()
{

}
void popular_book()
{
    int i,j,k;
    books *min,*high;
    high = malloc(sizeof(books)*5);
    min = malloc(sizeof(books));
    system("cls");

        for(j=0;j<5;j++)
            {
                high[j]=book_curr[j];
                strcpy(high[j].author,book_curr[j].author);
                strcpy(high[j].catg,book_curr[j].catg);
                strcpy(high[j].ISBN,book_curr[j].ISBN);
                strcpy(high[j].publisher,book_curr[j].publisher);
                strcpy(high[j].title,book_curr[j].title);
            }

     for(i=5;i<book_no;i++)
     {
         k=0;
         *min=high[0];
         strcpy(min->author,high[0].author);
         strcpy(min->catg,high[0].catg);
         strcpy(min->ISBN,high[0].ISBN);
         strcpy(min->publisher,high[0].publisher);
         strcpy(min->title,high[0].title);

         for(j=0;j<5;j++)
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
            high[k].no_borr=book_curr[i].no_borr;
            strcpy(high[k].author,book_curr[i].author);
            strcpy(high[k].catg,book_curr[i].catg);
            strcpy(high[k].ISBN,book_curr[i].ISBN);
            strcpy(high[k].publisher,book_curr[i].publisher);
            strcpy(high[k].title,book_curr[i].title);
        }

     }
     printf("\t \t \t Popluar books\n\n");
     for(j=0;j<5;j++)
     {
         printf("%s %s %s %s %s %d %d,%d %d %d %d \n",high[j].ISBN,high[j].catg,high[j].title,high[j].author,high[j].publisher,
               high[j].publish.day,high[j].publish.month,high[j].publish.year,high[j].no_cpy,high[j].curr_copy,high[j].no_borr);

     }
     free(high);
     free(min);
}
void ret_book(int id)
{

}
void new_cpy()
{

}
void check_id()
{
    int id,i,flag=0;
    system("cls");
    printf("Enter You ID :");
    scanf("%d",&id);
    fb = fopen("members.txt","r");
    for(i=0;i<mem_no;i++)
    {
        if(id==curr_user[i].id)
        break;
        flag++;
    }
    if(flag!=mem_no)
    user(id);
    else
        {
            printf("Wrong ID Please Enter Valid One:");
            check_id();
        }
    fclose(fb);

}
void new_save()
{
    int i;
    fb = fopen("members.txt","a");
    for(i=0; i<newnumber; i++)
        {
            if(mem_no==0&&i==0)
                fprintf(fb,"%s,%s,%d,%d,%s,%s,%d,%d,%s",new_user[i].f_name,new_user[i].l_name,new_user[i].id,new_user[i].adrs.street_no,
                new_user[i].adrs.zone,new_user[i].adrs.city,new_user[i].phone,new_user[i].age,new_user[i].email);
               else
               fprintf(fb,"\n%s,%s,%d,%d,%s,%s,%d,%d,%s",new_user[i].f_name,new_user[i].l_name,new_user[i].id,new_user[i].adrs.street_no,
                new_user[i].adrs.zone,new_user[i].adrs.city,new_user[i].phone,new_user[i].age,new_user[i].email);
        }
    fclose(fb);

    fc=fopen("books.txt","a");
    for(i=0;i<newbook;i++)
   {
        if(book_no==0&&i==0)
            fprintf(fc,"%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d",book_new[i].ISBN,book_new[i].catg,book_new[i].title,book_new[i].author,book_new[i].publisher,
               book_new[i].publish.day,book_new[i].publish.month,book_new[i].publish.year,book_new[i].no_cpy,book_new[i].curr_copy,book_new[i].no_borr);
              else
                fprintf(fc,"\n%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d",book_new[i].ISBN,book_new[i].catg,book_new[i].title,book_new[i].author,book_new[i].publisher,
               book_new[i].publish.day,book_new[i].publish.month,book_new[i].publish.year,book_new[i].no_cpy,book_new[i].curr_copy,book_new[i].no_borr); // 3lshn mynzlsh str
   }
    fclose(fc);

}


void del_save()
{
    int i;
    temp = fopen("members.txt","w");
    for(i=0; i<mem_no-1; i++)
    fprintf(temp,"%s,%s,%d,%d,%s,%s,%d,%d,%s",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no,
            curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].email);
    fclose(temp);

}
void show_list()
{
    int i;
    system("cls");
    printf("1-Show All Memebers:\n");
    printf("2-Show All Books\n");
    switch(getch())
    {

    case '1':
        system("cls");
        printf("\t member list \n");
        for(i=0;i<mem_no;i++)
    {
        printf("%s ,%s ,%d ,%d ,%s ,%s ,%d ,%d ,%s\n",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no
               ,curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].email);
    }
    break;
    case '2':
        system("cls");
        printf("%d\n\n",book_no);
        printf("\t books list \n");
        for(i=0;i<book_no;i++)
        printf("%s  ,%s ,%s ,%s ,%s ,%d ,%d,%d ,%d,%d,%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);

        break;
        default:
        printf("ente Valid input:");
        show_list();
    }

}

#endif // FUNCTIONS_H_INCLUDED
