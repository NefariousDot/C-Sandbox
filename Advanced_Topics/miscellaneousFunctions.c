/******************************************************************************************************
 * @file: miscellaneousFunctions.c
 * @topic: stdlib.h miscellaneous functions
 * @description: This program uses various stdlib.h funcions namely rand(), qsort(), time(), ctime(), localtime(),
 *                          difftime(), mktime(), exit()
 * @conversion:
 * 1. program which generate 50 random numbers between -0.5 and 0.5
 * 2. qsort()
 *          sort an array of doubles from lowest to highest 
 *          create a function that generate some random double values to fill up the array
 *          create a function that displays an array
 * 3. use time() & ctime()
 *          you should handle error with fprintf() and exit with correct failure code
 * 4. write a program to compute the #of seconds passed since the beginning of the current month
 *              using localtime(),difftime() and mktime()
 *              you should handle error with fprintf() and exit with correct failure code
 *              
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
#include <string.h>
#include <time.h>
#include <math.h>

#define ARRAY_MAX 100

void generateRandomNumber (float minValue, float maxValue){
    int i=50;
    printf("Random 50 numbers between -0.5 and 0.5\n");
    while(i){
        /**
         * General Formala : ((float)rand() / RAND_MAX) * (m - n) + n;
         * where    n is the minimum value 
         *          m is the maximum value 
         */
        float randomValue = ((float)rand() / RAND_MAX) * (maxValue - minValue) + minValue;
        printf("%.2f ",randomValue);// general 
        i--;
    }
    printf("\n");
}

void fillingArray(double array[], int arraySize){
    for(int i=0; i<arraySize; i++){
        array[i] = ((double)rand() / RAND_MAX) * 10.0;
    }
}

void displayArray(double array[], int arraySize){
    for(int i=0; i<arraySize; i++){
        printf("%.4lf ",array[i]);
    }
}
int compare (const void *a, const void *b){
    // return *(double *)a - *(double *)b;
    double diff = *(double *)a - *(double *)b;
    if (fabs(diff) < 1e-9) {  // Small tolerance for floating-point comparison
        return 0;
    }
    return (diff > 0) ? 1 : -1;
}

int main(){
    printf("===================================================================================\n");
    printf("                                CHALLENGE 1\n");
    printf("===================================================================================\n\n");
    srand(time(NULL));
    generateRandomNumber(-0.5,0.5);

    printf("\n===================================================================================\n");
    printf("                                CHALLENGE 2\n");
    printf("===================================================================================\n\n");
    double array[ARRAY_MAX];
    printf("Assigning array elements.....\n");
    fillingArray(array,10);
    printf("Array before sorting : \n");
    displayArray(array,10);
    qsort(array,10,sizeof(double),compare);
    printf("\nArray after sorting : \n");
    displayArray(array,10);

    printf("\n===================================================================================\n");
    printf("                                CHALLENGE 3\n");
    printf("===================================================================================\n\n");
    time_t currentTime;
    char *timeString;

    currentTime = time(NULL);
    if(currentTime == ((time_t)-1)){
        fprintf(stderr,"FAILED TO CAPTURE CURRENT TIME...\n");
        exit(EXIT_FAILURE);
    }

    timeString = ctime(&currentTime);

    if(!timeString){
        fprintf(stderr,"FAILED TO STORE TIME...\n");
        exit(EXIT_FAILURE);
    }

    printf("Time Captured : %s\n",timeString);
    

    printf("\n===================================================================================\n");
    printf("                                CHALLENGE 4\n");
    printf("===================================================================================\n\n");
    time_t startTime, endTime;
    double totalSec;
    const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", 
                                "September", "October", "November", "December"};

    endTime = time(NULL);
    if(endTime == ((time_t)-1)){
        fprintf(stderr,"Error : Operation Failed...\n");
        exit(EXIT_FAILURE);
    }

    struct tm *startingMonth;
    startingMonth = localtime(&endTime);

    startingMonth->tm_mday = 1;
    startingMonth->tm_hour = 0;
    startingMonth->tm_min = 0;
    startingMonth->tm_sec = 0;

    // startTime = mktime(startingMonth);
    if(startTime = mktime(startingMonth) == -1){
        fprintf(stderr,"Error : Operation Failed...\n");
        return -1;
    }

    totalSec = difftime(endTime, startTime);

    printf("Seconds Passed since the beginning of %s month  is : %lf",months[startingMonth->tm_mon],totalSec);    

    return 0;

}