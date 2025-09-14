#include <stdio.h>
#include <stdbool.h>
int main()
{
  FILE *fp;
  char buf[1024];
  fp = fopen("Writing.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file");
    return 1;
  }
fprintf(fp,"Aaditya is the best !\n");
fprintf(fp,"Square of %d id %d.\n",5,5*5);
fprintf(fp,"Who's the best ?, I'm the best, Oh ya.\n");

  int con = fclose(fp);
  if (con == 0)
    fp = NULL;
  else
  {
    printf("File wasn't closed properly");
    return 1;
  }
  fp = fopen("Writing.txt", "a"); 
  if (fp == NULL)
  {
    printf("Error opening file");
    return 1;
  }
  fprintf(fp,"Aaditya is the best !\n");
  fp = fopen("Writing.txt", "r"); 
  if (fp == NULL)
  {
    printf("Error opening file");
    return 1;
  }
  int ch;
  do
  {
    ch = fgetc(fp);
    printf("%c", ch);
  } while (ch != EOF);
  
  fclose(fp);
  return 0;
}