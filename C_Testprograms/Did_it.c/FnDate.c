#include <stdio.h>
#include <time.h>

int main()
{
  time_t t = time(NULL);
  struct tm *currentTime = localtime(&t);

  printf("Date: %02d/%02d/%04d \nTime: %02d:%02d:%02d ",
         currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900,
         currentTime->tm_hour - 12, currentTime->tm_min, currentTime->tm_sec);
  if (currentTime->tm_hour > 12)
    printf("PM");
  else
    printf("AM");
  return 0;
}
