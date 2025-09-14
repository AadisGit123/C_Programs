#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,i;
  printf("Entert he Number of elements : ");
  scanf("%d", &n);
  float *arr = (float *)malloc(n * sizeof(float *));
  printf("Enter the Elments : ");
  for(i=0;i<n;i++)
  {
    scanf("%f",&arr[i]);
  }
  printf("Elements : ");
  for(i=0;i<n;i++)
  printf(" %.3f",arr[i]);
}