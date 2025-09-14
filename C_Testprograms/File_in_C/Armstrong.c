#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digit()
{
  int i, num, dig, temp,arg,a;
  printf("Enter the Number  : ");
  scanf("%d", &num);
  a = num;
  while (num>0)
  {
    dig = num % 10;
    temp = dig*dig*dig;
    arg += temp;
    num/=10;
  }
  if(arg==a)
    printf("%d is an Armstrong Number",a);
  else
     printf("%d is not an Armstrong Number",a);
}
