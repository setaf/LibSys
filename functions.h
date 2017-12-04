#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "struct.h"

FILE *fb, *fc, *temp; //34an el delete function
time_t borr_date,ret_date;
int mem_no; //# of  members
int newnumber=0; //# of new users
users new_user[100]; //lazem 34an tst5dmha fel save
users curr_user[100];

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
void admin ()
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
void addmem()
{
    system("cls");
    printf("1-Current Member\n");
    printf("2-New Member\n");
    printf("3-Save Changes\n");
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
            printf("Enter Your First Name:");
            gets(new_user[newnumber].f_name);
            printf("Enter Your Last Name:");
            gets(new_user[newnumber].l_name);
            printf("Enter Your ID:");
            scanf("%d",&new_user[newnumber].id);
            do
            {
                printf("Enter Your Street Number:");
                scanf("%d",&new_user[newnumber].adrs.street_no);
                if (new_user[newnumber].adrs.street_no<=0)
                    printf("Enter A positive number, Retry!!!\n\n\a");
            }
            while(new_user[newnumber].adrs.street_no<=0);
            printf("Enter Your Zone:");
            getchar();
            gets(new_user[newnumber].adrs.zone);
            printf("Enter Your City:");
            gets(new_user[newnumber].adrs.city);
            do
            {
                printf("Enter Your Phone(01##########):");
                scanf("%d",&new_user[newnumber].phone);
                if (new_user[newnumber].phone<01000000000 || new_user[newnumber].phone>0100000000000)
                    printf("Wrong Phone Number Retry!!!\n\n\a");
            }
            while(new_user[newnumber].phone<1000000000 || new_user[newnumber].phone>0100000000000);
            do
            {
                printf("Enter Your Age '7 years or older':");
                scanf("%d",&new_user[newnumber].age);
                if (new_user[newnumber].age<7)
                    printf("Wrong Age Retry!!!\n\n\a");
            }
            while(new_user[newnumber].age<7);
            printf("Enter Your E-mail:");
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
                    printf("the email is wrong Retry!!!\n\n\a");
                }
            }
            while(flag != 1);
            newnumber++;
            fclose(fb);
        }
        else
        {
            //newnumber variable ??? //
            system("cls");
            fb = fopen("members.txt","a");
            int i,flag=0;
            printf("Enter Your First Name:");
            gets(new_user[newnumber].f_name);
            printf("Enter Your Last Name:");
            gets(new_user[newnumber].l_name);

            do
            {
                printf("Enter Your ID:");
                scanf("%d",&new_user[newnumber].id);
                for(i=0;i<mem_no;i++)
                {
                    if(new_user[newnumber].id==curr_user[i].id)
                        break;

                        flag++;
                }
                if(flag!=mem_no)
                    printf("A User with the same ID already exist, Retry!!!\n\n\a");
                if(new_user[newnumber].id<0)
                    printf("Enter A positive number, Retry!!!\n\n\a");
            }
            while(new_user[newnumber].id<0||new_user[newnumber].id==curr_user[i].id);

            do
            {
                printf("Enter Your Street Number:");
                scanf("%d",&new_user[newnumber].adrs.street_no);
                if (new_user[newnumber].adrs.street_no<0)
                    printf("Enter A positive number, Retry!!!\n\n\a");
            }
            while(new_user[newnumber].adrs.street_no<0);
            printf("Enter Your Zone:");
            getchar();
            gets(new_user[newnumber].adrs.zone);
            printf("Enter Your City:");
            gets(new_user[newnumber].adrs.city);
            do
            {
                printf("Enter Your Phone:");
                scanf("%d",&new_user[newnumber].phone);
                if (new_user[newnumber].phone<1000000000 || new_user[newnumber].phone>100000000000)
                    printf("Wrong Phone Number Retry!!!\n\n\a");
            }
            while(new_user[newnumber].phone<1000000000 || new_user[newnumber].phone>100000000000);
            do
            {
                printf("Enter Your Age '7 years or older':");
                scanf("%d",&new_user[newnumber].age);
                if (new_user[newnumber].age<7)
                    printf("Wrong Age Retry!!!\n\n\a");
            }
            while(new_user[newnumber].age<7);
            printf("Enter Your E-mail:");
            getchar();
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
                    printf("the email is wrong Retry!!!\n\n\a");
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
void curr_mem(void)
{

    if(temp = fopen("members.txt","r")==NULL)
        return;
    else
    {
        temp = fopen("members.txt","r");
        while (!feof(temp))
        {
                fscanf(temp,"%[^,],%[^,],%d,%d,%[^,],%[^,],%d,%d,%s",curr_user[mem_no].f_name,curr_user[mem_no].l_name,&curr_user[mem_no].id,&curr_user[mem_no].adrs.street_no,
                curr_user[mem_no].adrs.zone,curr_user[mem_no].adrs.city,&curr_user[mem_no].phone,&curr_user[mem_no].age,curr_user[mem_no].email);
        mem_no++;
        }
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
        fprintf(fb,"%s,%s,%d,%d,%s,%s,%d,%d,%s\n",new_user[i].f_name,new_user[i].l_name,new_user[i].id,new_user[i].adrs.street_no,
                new_user[i].adrs.zone,new_user[i].adrs.city,new_user[i].phone,new_user[i].age,new_user[i].email);
    fclose(fb);
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

#endif // FUNCTIONS_H_INCLUDED
