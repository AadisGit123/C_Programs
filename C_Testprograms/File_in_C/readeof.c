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
  int ch;
  // while ((ch = fgetc(fp)) != EOF)
  // putchar(ch);
  do
  {
    ch = fgetc(fp);
    printf("%c", ch);
  } while (ch != EOF);

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