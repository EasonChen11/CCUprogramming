#include <stdio.h>
#define average_year 0
#define Leap_year 1
int days[]={0,31,0,31,30,31,30,31,31,30,31,30,31};

void calendar(int first_day, int month);
void printTitle(int month);
int leap_year(int year);

int what_day(int year);

int main() {
    int year;
    printf("please enter a year: ");
    scanf("%d",&year);
    printf("\n");
    if(leap_year(year))
        days[2]=29;
    else
        days[2]=28;
    int first_day=what_day(year);
    calendar(first_day, 1);
    return 0;
}

int what_day(int year) {
    int days=0;
    for (int i = 1950; i < year; ++i) {
        if(leap_year(i))
            days+=2;
        else
            days+=1;
        days%=7;
    }
    return days;
}

void calendar(int first_day, int month) {
    if(month==13)
        return;
    printTitle(month);
    for (int i = 0; i < first_day*4; ++i) {
        printf(" ");
    }
    for (int i = 1; i <= days[month]; ++i) {
        printf("%02d  ",i);
        if((i+first_day)%7==0)
            printf("\n");
    }
    printf("\n\n");
    calendar((first_day+days[month])%7,month+1);
}

void printTitle(int month) {
    switch (month) {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;

        case 3:
            printf("MAR");
            break;

        case 4:
            printf("APR");
            break;

        case 5:
            printf("MAY");
            break;

        case 6:
            printf("JUN");
            break;

        case 7:
            printf("JUL");
            break;

        case 8:
            printf("AUG");
            break;

        case 9:
            printf("SEP");
            break;

        case 10:
            printf("OCT");
            break;

        case 11:
            printf("NOV");
            break;

        case 12:
            printf("DEC");
            break;
    }
    printf("\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
}
int leap_year(int year){
    if(year%4)
        return average_year;
    if(year%100)
        return Leap_year;
    if(year%400)
        return average_year;
    return Leap_year;

}
