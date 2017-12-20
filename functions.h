#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "struct.h"
int check_id();
FILE *fb, *fc, *temp,*fd; //34an el delete function
time_t borr_date,ret_date;
int mem_no=0,book_no=0,borrow_no=0; //# of  members
int newnumber=0;
int newbook=0;
int newborrow=0;
int newreturn=0;
users new_user[100]; //lazem 34an tst5dmha fel save
users curr_user[100];
books book_new[100];
books book_curr[100];
borrow borrows[100];
borrow borrows_curr[100];
date overd[100];
void menu (void)
{
    system("cls");
    printf("1-admin\n");
    printf("2-user\n");
    printf("3-exit\n");
    printf("%d,%d\n",mem_no,book_no);
    printf("%d,%d",newnumber,newbook);
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
            new_user[newnumber].no_borru=0;
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
            new_user[newnumber].no_borru=0;
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
    int i;
    if (temp = fopen("members.txt","r")!= NULL)
    {
     temp = fopen("members.txt","r");
     while (!feof(temp))
    {
        fscanf(temp,"%[^,],%[^,],%d,%d,%[^,],%[^,],0%d,%d,%d,%s",curr_user[mem_no].f_name,curr_user[mem_no].l_name,&curr_user[mem_no].id,&curr_user[mem_no].adrs.street_no,
                curr_user[mem_no].adrs.zone,curr_user[mem_no].adrs.city,&curr_user[mem_no].phone,&curr_user[mem_no].age,&curr_user[mem_no].no_borru,curr_user[mem_no].email);
          mem_no++;
    }
    fclose(temp);
    }
    if (temp = fopen("books.txt","r")!= NULL)
    {
     temp = fopen("books.txt","r");
     while (!feof(temp))
    {
        fscanf(temp,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d\n",book_curr[book_no].ISBN,book_curr[book_no].catg,book_curr[book_no].title,book_curr[book_no].author,book_curr[book_no].publisher,
               &book_curr[book_no].publish.day,&book_curr[book_no].publish.month,&book_curr[book_no].publish.year,&book_curr[book_no].no_cpy,&book_curr[book_no].curr_copy,&book_curr[book_no].no_borr);
        printf("%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d\n",book_curr[book_no].ISBN,book_curr[book_no].catg,book_curr[book_no].title,book_curr[book_no].author,book_curr[book_no].publisher,
               book_curr[book_no].publish.day,book_curr[book_no].publish.month,book_curr[book_no].publish.year,book_curr[book_no].no_cpy,book_curr[book_no].curr_copy,book_curr[book_no].no_borr);
            book_no++;
    }
    fclose(temp);
    }
    if (temp = fopen("borrow.txt","r")!= NULL)
    {
     temp = fopen("borrow.txt","r");
     while (!feof(temp))
    {
    fscanf(temp,"%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[newborrow].book_isbn,&borrows[newborrow].user_id,&borrows[newborrow].borrow_date.day,
           &borrows[newborrow].borrow_date.month,&borrows[newborrow].borrow_date.year,&borrows[newborrow].duedate.day,&borrows[newborrow].duedate.month,
           &borrows[newborrow].duedate.year,&borrows[newborrow].ret_date.day,&borrows[newborrow].ret_date.month,&borrows[newborrow].ret_date.year);
    printf("%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[newborrow].book_isbn,borrows[newborrow].user_id,borrows[newborrow].borrow_date.day,
           borrows[newborrow].borrow_date.month,borrows[newborrow].borrow_date.year,borrows[newborrow].duedate.day,borrows[newborrow].duedate.month,
           borrows[newborrow].duedate.year,borrows[newborrow].ret_date.day,borrows[newborrow].ret_date.month,borrows[newborrow].ret_date.year);
    newborrow++;
}
printf("%d",newborrow);
fclose(temp);
    }
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
            printf("enter isbn");
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
system("cls");
    printf("Books List:\n");
    char del_isbn [32];
    int i;
    for(i=0;i<book_no;i++)
        printf("%s  ,%s ,%s ,%s ,%s ,%d ,%d,%d ,%d,%d,%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
    printf("Enter The isbn you want to delete:");
    scanf("%s",del_isbn);
    for (i=0;i<book_no;i++)
    {
        if(strcmp(book_curr[i].ISBN,del_isbn)==0)
        break;
    }
    strcpy(book_curr[i].ISBN,"re");
}
void borrow_book(int id)
{
 system("cls");
 time_t currenttime;
 time(&currenttime);
 struct tm *mytime = localtime(&currenttime);
 char isbn[32];
 int i,x,indexmem,indexbook,indexborrow;
 if ((fd = fopen("borrow.txt","r")) == NULL)
  {
      fd = fopen("borrow.txt","w");
        printf("\t books list \n");
        for(i=0;i<book_no;i++)
        printf("%s  ,%s ,%s ,%s ,%s ,%d ,%d,%d ,%d,%d,%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
       printf("please enter the book ISBN you want to borrow:\n");
      fflush(stdin);
      gets(isbn);
     for(x=0;x<book_no;x++)
    {
        if(strcmp(isbn,book_curr[x].ISBN)==0)
        {
        indexborrow=x;
        strcpy(borrows[newborrow].book_isbn,isbn);
        }
        else
        {
            printf("please enter a valid ISBN!!!\n");
            printf("enter any key to return to the menu!");
            getch();
              fclose(fd);
            return addmem();
        }
    }
      for(x=0;x<newborrow;x++)
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
              printf("enter any key to return to the menu!");
              getch();
          newborrow++;
          fclose(fd);
         return addmem();
          }
          else{
            printf("Sorry there is no copies available for that book!!");
            printf("press any key to return to the menu!!");
            getch();
            fclose(fd);
          return addmem();
          }
  }
  }
  else{
      fd = fopen("borrow.txt","a");
      borrows[newborrow].user_id=id;
        printf("\t books list \n");
        for(i=0;i<book_no;i++)
        printf("%s  ,%s ,%s ,%s ,%s ,%d ,%d,%d ,%d,%d,%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
      printf("please enter the book ISBN you want to borrow:\n");
      fflush(stdin);
      gets(isbn);
     for(x=0;x<book_no;x++)
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
              fclose(fd);
            return addmem();
    }

      for(x=0;x<mem_no;x++)
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
              for(i=0;i<mem_no;i++)
                printf("%d",curr_user[i].no_borru);
              printf("enter any key to return to the menu!");
              getch();
          newborrow++;
          fclose(fd);
         return addmem();
          }
          else{
            printf("Sorry there is no copies available for that book!!");
            printf("press any key to return to the menu!!");
            getch();
            fclose(fd);
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
}
void search_book()
{
  search_double();
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
        borrow_book(id);
        break;
    case '2':
        ret_book(id);
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
  system("cls");
  int i;
  time_t currenttime;
  time(&currenttime);
  struct tm *mytime = localtime(&currenttime);
  if ((fd = fopen("borrow.txt","r")) == NULL)
 {
     printf("sorry they are no borrow books yet:\n");
 }
  else{
      fd = fopen("borrow.txt","a");
       for(i=0;i<newborrow;i++)
       {
         overd[i].day=mytime->tm_mday;
          overd[i].month=mytime->tm_mon+1;
          overd[i].year=mytime->tm_year+1900;
            if(borrows[i].duedate.day<overd[i].day || borrows[i].duedate.month<overd[i].month ||borrows[i].duedate.year<overd[i].year)
              break;
              }
       if(i==newborrow)
       {
              printf("there is no overdue books!!\n");
              printf("press any key to return to the menu!!");
              getch();
              return admin();
        }
       else
       {
      for(i=0;i<newborrow;i++)
      {
          overd[i].day=mytime->tm_mday;
          overd[i].month=mytime->tm_mon+1;
          overd[i].year=mytime->tm_year+1900;
           if(borrows[i].ret_date.day==0 && borrows[i].ret_date.month==0 && borrows[i].ret_date.year==0)
           {
        if(borrows[i].duedate.day<overd[i].day || borrows[i].duedate.month<overd[i].month ||borrows[i].duedate.year<overd[i].year)
        {
            printf("The over due book is:\n");
            printf("%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
        borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
        borrows[i].ret_date.year);
        }
      }
      }
      printf("press any key to return to the menu!!");
      getch();
      return admin();
  }
}
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
 system("cls");
 time_t currenttime;
 time(&currenttime);
 struct tm *mytime = localtime(&currenttime);
 char isbn[32];
 int i,x,indexmem,indexbook,indexreturn;
 if ((fd = fopen("borrow.txt","r")) == NULL)
 {
     printf("sorry you didn't borrow anything yet:\n");
     printf("press any key to return to the menu");
     getch();
     return addmem();
 }
  else{
      fd = fopen("borrow.txt","a");
      borrows[newborrow].user_id=id;
      printf("please enter the book ISBN you want to return:\n");
      fflush(stdin);
      gets(isbn);
for(x=0;x<book_no;x++)
    {
        if(strcmp(isbn,book_curr[x].ISBN)==0)
        {
        indexbook=x;
        }
    }

     for(x=0;x<newborrow;x++)
      {
          if(id==curr_user[x].id)
          {
            indexmem=x;
          }
      }
      for(x=0;x<newborrow;x++)
      {
          break;
      }
      if(x==newborrow)
      {
          printf("Enter a valid ISBN!!\n");
            printf("press any key to return to the menu!!");
            getch();
            fclose(fd);
            return addmem();
      }
      if(curr_user[indexmem].no_borru>0)
      {
     for(x=0;x<newborrow;x++)
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
        newborrow++;
        fclose(fd);
         return addmem();
        }
        }
    }
    }
            printf("you already returned the book!!!\n");
            printf("enter any key to return to the menu!");
            getch();
              fclose(fd);
            return addmem();
  }
}
void new_cpy()
{
 int no,i;
    system("cls");
    printf("Enter The ISBN Of Book:\n");
    scanf("%s",book_new[newbook].ISBN);
    for(i=0;i<book_no;i++)
        {
            if(strcmp(book_new[newbook].ISBN,book_curr[i].ISBN)==0)
                break;
        }
    if(i!=book_no)
    {
    printf("%d\n",i);
    printf("Enter The Number of Copies:\n");
    scanf("%d",&no);
    book_new[newbook]=book_curr[i];
    book_new[newbook].no_cpy+=no;
    book_new[newbook].curr_copy+=no;
    strcpy(book_new[newbook].catg,book_curr[i].catg);
    strcpy(book_new[newbook].author,book_curr[i].author);
    strcpy(book_new[newbook].publisher,book_curr[i].publisher);
    strcpy(book_new[newbook].title,book_curr[i].title);
    strcpy(book_curr[i].ISBN,"re");
    newbook++;
    }
    else
        printf("Not Found");

        admin();
}
int check_id()
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
    {
    user(id);
    return id;
    }
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
    if(newnumber!=0)
    {
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
    }
    else
    {
        fb = fopen("members.txt","w");
        for(i=0;i<mem_no;i++)
            fprintf(fb,"%s,%s,%d,%d,%s,%s,0%d,%d,%d,%s",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no,
                curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].no_borru,curr_user[i].email);
    }
    fclose(fb);
    if(newbook!=0)
    {
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
    }
   else
   {
      fc=fopen("books.txt","w");
   for(i=0;i<book_no;i++)
   {
        if(book_no==0&&i==0)
              fprintf(fc,"%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d\n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
       else
        fprintf(fc,"%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d\n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);
   }
   }
    fclose(fc);
    fd= fopen("borrow.txt","w");
    for(i=0;i<newborrow;i++)
    {
         if(newborrow==0&&i==0)
        fprintf(fd,"%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
        borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
        borrows[i].ret_date.year);
                else
                {
        fprintf(fd,"%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
        borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
        borrows[i].ret_date.year);
        printf("%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",borrows[i].book_isbn,borrows[i].user_id,borrows[i].borrow_date.day,borrows[i].borrow_date.month,
        borrows[i].borrow_date.year,borrows[i].duedate.day,borrows[i].duedate.month,borrows[i].duedate.year,borrows[i].ret_date.day,borrows[i].ret_date.month,
        borrows[i].ret_date.year);
                }

    }
    fclose(fd);
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
        printf("%s  ,%s ,%s ,%s ,%s ,%d ,%d,%d ,%d,%d \n",book_curr[i].ISBN,book_curr[i].catg,book_curr[i].title,book_curr[i].author,book_curr[i].publisher,
               book_curr[i].publish.day,book_curr[i].publish.month,book_curr[i].publish.year,book_curr[i].no_cpy,book_curr[i].curr_copy,book_curr[i].no_borr);

        break;
        default:
        printf("enter Valid input:");
        show_list();
    }
}
void search_double() //aldouble search albonus bs lsa ma7tathash fe al menu m3 alsearch 7azwedha k case 5 w asmha k function
{
    system("cls");
    char searchtarget[50];
    char *z;
    int x;
    int titlecounter=0;
    int authorcounter=0;
    int counter=0;
    printf("please search by book title or book author or both:\n");
    gets(searchtarget);
    for(x=0;x<book_no;x++)
    {
        z=strstr(book_curr[x].title,searchtarget);
        if(z!=NULL)
        titlecounter++;
          if(strcmp(searchtarget,book_curr[x].author)==0)
        authorcounter++;
    }
    if (titlecounter==0 && authorcounter==0)
        printf("there is no books matches the request!!");
    else
    {
        books searchdata[30];
        for(x=0;x<book_no;x++)
        {
            z=strstr(book_curr[x].title,searchtarget);
            if(z!=NULL ||strcmp(searchtarget,book_curr[x].author)==0)
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
        for(x=0;x<counter;x++)
            printf("%s, %s, %s, %s, %d, %d, %d, %d, %d, %s\n",searchdata[x].title,searchdata[x].author,searchdata[x].publisher,searchdata[x].ISBN,
                   searchdata[x].publish.day,searchdata[x].publish.month,searchdata[x].publish.year,searchdata[x].no_cpy,searchdata[x].curr_copy,searchdata[x].catg);
    }
}



#endif // FUNCTIONS_H_INCLUDED
