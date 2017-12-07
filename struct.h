#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct
{
    int street_no;
    char zone[20];
    char city[20];

} address;              //talb el adress lwa7do howa

typedef struct
{
    char f_name[10];
    char l_name[10];
    int id;
    int age;
    char email[64];
    address adrs;
    int phone;
} users;

typedef struct
{
    int day, month, year;
} date;

typedef struct
{
    char catg[32];
    char title[32];
    char author[32];
    char ISBN [32];
    int no_cpy;
    int curr_copy;
    int no_borr;
    char publisher[32];
    date publish;

} books;
typedef struct
{
    int book_isbn;
    int user_id;
    int borr_no;
    date ret_date;        //m4 3arf azay bst5dm el time.h lw 7t3rf tta3ml ams7 dool w el function ele ana zwdtha
    date borrow_date;
    date duedate;
} borrow;

#endif // STRUCT_H_INCLUDED
