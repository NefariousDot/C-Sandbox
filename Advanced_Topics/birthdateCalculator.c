/******************************************************************************************************
 * @file: sbirthdayCalculator.c
 * @topic: stdlib.h miscellaneous functions
 * @description: This program takes a user's name and date of birth as input and determines the day of the week they were born.
 * @conversion:  It leverages the C standard library's time manipulation functions, including struct tm and mktime(), 
 * to perform the calculation. The program also formats the output using ordinal suffixes (st, nd, rd, th) for the date 
 * and prints the result in a user-friendly format.
 * 
 *
 * The members of structure tm
 * struct tm {
 *      int tm_sec;     //0-60
 *      int tm_min;     //0-59
 *      int tm_hour;    //0-23
 *      int tm_mday;    //1-31
 *      int tm_mon;     //0-11
 *      int tm_year;    //Current Year - 1900
 *      int tm_wday;    // sun=0, mon=1,...,sat=6
 *      int tm_yday;    //0-365
 *      int tm_isdst;   //day light savings flag..
 *                          >0 ;  if Daylight Saving Time is in effect
 *                          0  ;  if Daylight Saving Time is not in effect
 *                          <0 ;  if the information is not available
 * }
 * 
 * time manipulation functions
 * mktime()     ==> converts tm structure to time_t
 * localtime()  ==> converts time_t to tm structure as local time
 * gmtime()     ==> converts time_t to tm structure as UTC time
 * 
 ******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <time.h>


int main(){
    const char *day[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char *months[12] = {"January", "February", "March", "April", "may", "June", "July", "August", 
                                "September", "October", "November", "December"};
    const char *suffix[] = {"st", "nd", "rd", "th"};

    enum suffixIndex { st, nd, rd, th} suffixSet = th;

    struct tm bday= {0};
    // memset(&bday, 0, sizeof(bday));

    char name[30]={'\0'};
    printf("Enter name : ");
    scanf("%s",name);

    printf("Enter birthday of %s as DAY MONTH YEAR format seperated by space..\n",name);
    scanf("%d %d %d",&bday.tm_mday, &bday.tm_mon, &bday.tm_year);

    bday.tm_mon -= 1;  // Adjust month to 0-based
    bday.tm_year -= 1900;  // Adjust year to years since 1900
    // bday.tm_isdst = -1;  // Let mktime determine DST

    if(mktime(&bday) == -1){
        fprintf(stderr,"Operation Failed to Perform..\n");
        return -1;
    }

    switch (bday.tm_mday){
    case 1: case 21: case 31:
        suffixSet = st;
        break;
    
    case 2: case 22:
        suffixSet = nd;
        break;        
    
    case 3: case 23:
        suffixSet = rd;
        break;

    default:
        suffixSet = th;
        break;
    }

    printf("%s was born on the %d%s %s %d , which was a %s.\n", 
                        name, 
                        bday.tm_mday, 
                        suffix[suffixSet], 
                        months[bday.tm_mon], 
                        bday.tm_year+1900, 
                        day[bday.tm_wday]);

    return 0;


}