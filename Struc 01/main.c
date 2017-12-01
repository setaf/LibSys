#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    float real_r;
    float img_r;
} complex;
complex add_complex(complex a,complex b);
void print_complex(complex c);
complex read_complex();
void add_real(complex *a,float r);
int compare_complex(complex a,complex b);
int main()
{
    complex c,a,b,*z;
    int x;
    float r;
    a=read_complex();
    b=read_complex();
    c= add_complex(a,b);
    print_complex(c);
    z=&a;
    add_real(z,0.6);
     print_complex(a);
     x=compare_complex(a,b);
     if(x==1)
     printf("Complex A bigger Than Complex B");
     else if(x==-1)
        printf("Complex A Less Than Complex B");
        else  printf("Complex A Equal Complex B");
    return 0;
}
complex add_complex(complex a,complex b)
{
    complex c;
    c.real_r=a.real_r+b.real_r;
    c.img_r=a.img_r+b.img_r;
    return c;
}
void print_complex(complex c)
{
    printf("The real part =%.2f the img part =%.2fi\n",c.real_r,c.img_r);
}
complex read_complex()
{
    complex a;
    printf("Enter The Complex Number of X+Y i:");
    scanf("%f%f",&a.real_r,&a.img_r);
    return a;
}
void add_real(complex *a,float r)
{
    a->real_r+=r;
}
int compare_complex(complex a,complex b)
{
    float x,y;
    x=sqrt(pow(a.real_r,2)+pow(a.img_r,2));
    y=sqrt(pow(b.real_r,2)+pow(b.img_r,2));
    if(x<y) return -1;
    if(x>y) return 1;
    if(x=y) return 0;
}

