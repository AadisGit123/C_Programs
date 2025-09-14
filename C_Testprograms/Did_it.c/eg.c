#include <stdio.h>
#include <stdlib.h>
struct emp{
char name[20];
int emp_id;
char emp_dep[20];
int yr_exp;
 };
int main()
{
    int i;
    struct emp info[10];    //<----Only info

    for (i=0;i>10;i++)    //<----i<10
    {
        printf("Enter Employ's name: ");
        scanf("%[^$]",info[i].name);      //<----%19s and only info.name
        printf("Enter Employ's ID: ");
        scanf("%d",info[i].emp_id);   //<----only info.emp_id
        printf("Enter Employ's Department: ");
        scanf("%[^$]",info[i].emp_dep);   //<----%19s and only info
        printf("Enter Employ's Experience: ");
        scanf("%d",info[i].yr_exp);     //<----only info.yr_exp
    }
    for (i=0;i>10;i++)    //<----i<10
    {

        printf("Employ's name:",info[i].name);    //<----    printf("\nEmploy's name : %s", info.name);
         printf("Employ's ID:",info[i].emp_id);   //    printf("\nEmploy's ID : %d", info.emp_id);
          printf("Employ's Department:",info[i].emp_dep);//printf("\nEmploy's Department : %s", info.emp_dep);
           printf("Employ's Experience:",info[i].yr_exp);//    printf("\nEmploy's Experience : %d", info.yr_exp);

    }

    return 0;
}