#include<stdio.h>
#include<time.h>
#include<stdlib.h>  
#include<unistd.h>

void fill_time(char*, int);
void fill_date(char*);
int input_format();
void clear_screen();

int main() {

  char time[50], date[100];
  int format = input_format();

  while(1) {
    fill_time(time, format);
    fill_date(date);  
    clear_screen();
    printf("Current time: %s\n", time);
    printf("Date: %s\n", date);
    sleep(1); //sleep for 1 second
  }


  return 0;
}

void clear_screen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int input_format() {
  int format;
  printf("\nChoose the time format: ");
  printf("\n1. 24 Hours time format");
  printf("\n2. 12 Hours time format (default)");
  scanf("%d", &format);

  return format;
}
  
void fill_time(char* buffer, int format) {

  time_t rowtime;
  struct tm *currnet_time;
  time(&rowtime);
  currnet_time = localtime(&rowtime);

  if(format == 1) 
    strftime(buffer, 50, "%H:%M:%S", currnet_time); 
  else
    strftime(buffer, 50, "%I:%M:%S %p", currnet_time);

}

void fill_date(char* buffer) {
  time_t rowtime;
  struct tm *currnet_time;
  time(&rowtime);
  currnet_time = localtime(&rowtime);

  strftime(buffer, 100, "%A %B %d %Y", currnet_time); 
}