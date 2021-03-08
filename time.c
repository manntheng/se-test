/*
This file includes some processes for time data.
Function: 
1.transform a string to time.
2.transform time to string.
********new function************
3.get current date and time from computer.
*/

// changes made by 2018380115

#include <stdio.h>                                         
#include <time.h>   
 
time_t str2time(const char *str_time){
  struct tm stm;  
  strptime(str_time, "%Y-%m-%d %H:%M:%S", &stm);
  long t = mktime(&stm);
  return t;
}

void time2str(time_t t, char *buf)
{
  strftime(buf, 30, "%Y-%m-%d %H:%M:%S", localtime(&t));
}

// function to get current date and time
void currentTime(time_t curtime)
{
   time(&curtime);
   printf("%s",ctime(&curtime));
}

int main()
{
  char szTime[30] = {0};
  sprintf(szTime, "2020-11-15 10:39:30");
  time_t start_t = str2time(szTime);
  printf("%ld\n", start_t);

  char szTime2[30];
  time2str(start_t, szTime2);
  printf("%s\n", szTime2);

  /* update */
  printf("\nCurrent date and time: ");
  time_t now;
  currentTime(now); //call the newly added function
 
  return 0;
}
