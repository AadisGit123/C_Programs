#include <stdio.h>
#include <stdbool.h>
int main()
{
  FILE *fp;
  char buf[1024];
  fp = fopen("Ccode.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file");
    return 1;
  }
  fgets(buf,sizeof(buf),fp);
  printf("File Contents : %s\n",buf);
  int con = fclose(fp);
  if (con == 0)
    fp = NULL;
  else
  {
    printf("File wasn't closed properly");
    return 1;
  }
  return 0;
}