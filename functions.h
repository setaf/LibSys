#include "structs.h"

//GLOBAL DECLERTAION//
FILE *fb, *fc, *temp; //34an el delete function
time_t borr_date,ret_date;
int mem_no; //# of  members
int newnumber=0; //# of new users
users new_user[100]; //lazem 34an tst5dmha fel save
users curr_user[100];

void user(int id)
{
    system("cls");
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
        search_book();
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
            printf("Enter Your First Name:\n");
            gets(new_user[newnumber].f_name);
            printf("Enter Your Last Name:\n");
            gets(new_user[newnumber].l_name);
            do
            {
                printf("Enter Your ID:\n");
                scanf("%d",&new_user[newnumber].id);
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
        printf("Welcome %s\n Your ID:%d\n",new_user[newnumber-1].f_name,new_user[newnumber-1].id);
        printf("Press Any Key To Continue....");
        switch(getch())
        default:
        addmem();
        break;
    case '3':
        menu();
        break;
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


void borrow_book(int a)
{

    fb = fopen("members.txt","r");
    if()
    }

void check_id()
{
    count_lines(fb);
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

void curr_mem()          //btgyb 3dd el current user w t7thom fe array
{
    temp = fopen("members.txt","r");
while (!feof(temp))
    {
        if(curr_user[mem_no].id==id)
        fscanf(temp,"%[^,],%[^,],%d,%d,%[^,],%[^,],%d,%d,%s",curr_user[mem_no].f_name,curr_user[mem_no].l_name,&curr_user[mem_no].id,&curr_user[mem_no].adrs.street_no,
                curr_user[mem_no].adrs.zone,curr_user[mem_no].adrs.city,&curr_user[mem_no].phone,&curr_user[mem_no].age,curr_user[mem_no].email);

            mem_no++;
    }
    fclose(temp);
    }
}
void del_mem()
{
    int i,position;
    printf("Enter the User's ID you want to remove");
    scanf("%d",&position);
    for(i=0;i<mem_no;i++)
    {
        if(curr_user[i].id==id)
            position=i;
    }
    for(i=position;i<mem_no-2;i++)
    {
     curr_user[i].f_name=curr_user[i+1].f_name;
     curr_user[i].l_name=curr_user[i+1].l_name;
     curr_user[i].id=curr_user[i+1].id;
     curr_user[i].adrs.street_no=curr_user[i+1].adrs.street_no;
     curr_user[i].adrs.zone=curr_user[i+1].adrs.zone;
     curr_user[i].adrs.city=curr_user[i+1].adrs.city;
     curr_user[i].phone=curr_user[i+1].phone;
     curr_user[i].age=curr_user[i+1].age;
     curr_user[i].email=curr_user[i+1].email;
    }
}
void new_save()         //save lel new users bs
{
    int i;
    fb = fopen("members.txt","a");
    for(i=0; i<newnumber; i++)
        fprintf(fb,"%s,%s,%d,%d,%s,%s,%d,%d,%s\n",new_user[i].f_name,new_user[i].l_name,new_user[i].id,new_user[i].adrs.street_no,
                new_user[i].adrs.zone,new_user[i].adrs.city,new_user[i].phone,new_user[i].age,new_user[i].email);
    fclose(fb);

}
void del_save()   //btms7 el file w t3yd ktbto mn gdydx lel current users bs
{
    temp = fopen("members.txt","w");
    for(i=0; i<mem_no-1; i++)
    fprintf(temp,"%s,%s,%d,%d,%s,%s,%d,%d,%s",curr_user[i].f_name,curr_user[i].l_name,curr_user[i].id,curr_user[i].adrs.street_no,
            curr_user[i].adrs.zone,curr_user[i].adrs.city,curr_user[i].phone,curr_user[i].age,curr_user[i].email);
    fclose(temp);
}
