#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float gpa;
    int id;
    char name[50];
}Student;
Student *read_student(int n);


int main()
{
int i,n;
   Student *ptr;
   printf("Enter The Number of Student:");
   scanf("%d",&n);
   ptr=read_student(n);
   for(i=0;i<n;i++)
   printf("Name of %d Student:%s\tID:%d\tGPA:%.2f\n",i+1,ptr[i].name,ptr[i].id,ptr[i].gpa);
    return 0;
}
Student *read_student(int n)
{ int i;
    Student *ptr;
    ptr=(Student*)malloc(n*sizeof(Student));
    for(i=0;i<n;i++)
    {
        printf("Enter The GPA---ID---Name of Student %d:",i+1);
        scanf("%f%d ",&ptr[i].gpa,&ptr[i].id);
        gets(ptr[i].name);
    }
    return ptr;
}
