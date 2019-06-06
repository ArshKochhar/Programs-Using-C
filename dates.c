//
//  dates.c
//  
//  compute the number of days between two dates
//
//   Gavin Anderson, 17GKA2, 20116948
//   Arsh Kochhar, 17AK126. 20104779 

#include <stdio.h>
#define MONTHS_IN_YEAR 12
#define DAYS_IN_MONTH 30

int main(int argc, char **argv)
{
    
    //define variables
    int days;
	int months;
	int years;
	
	//Day 1
    int day_1 = 6;
    int  mth_1 = 9;
	int yr_1 = 2018;
    //Day 2
   int  day_2 = 20;
   int mth_2 = 12;
   int yr_2 = 2018;
  //Stage 2
  int date_1;
  int date_2;
 int dayStage1;
 int monthStage1;
 int yearStage1;

int dayStage2;
 int monthStage2;
 int yearStage2; 
// Stage  3
int totalDays;
float percentOfYear;
    //Add an expression to determine the number of months between the dates
    //Add an expression to determine the number of years between the dates
    days = day_2 - day_1;
	months = mth_2 - mth_1;
	years = yr_2 -yr_1;
    
	
		
	
    
    if(day_1 > day_2){
		months= months - 1;
        //Add a statement to decrement the number of months by one
        days += DAYS_IN_MONTH; //Assuming 30 days in month
    }
    if(mth_1 > mth_2){
        //Add a statement to decrement the number of years by one
		years = years -1;
        months += MONTHS_IN_YEAR;
    }
	
    date_1 = 20180906;
	date_2 = 20181220;
	
	dayStage1 = date_1 % 100;
	monthStage1 =(date_1 / 100) %100;
	yearStage1 = date_1 / 10000;
	
	dayStage2 = date_2 % 100;
	monthStage2 = (date_2 / 100) %100;
	yearStage2 = date_2/ 10000;
   
   totalDays = 365*years + 30*months + days;
  percentOfYear = (float)totalDays/365;

   
   printf("Stage 1: Years is %d, Months is %d, Days is %d.\n",years,months,days);
    printf("Stage 2: Date 1: %d/%d/%d, Date 2: %d/%d/%d\n ", yearStage1, monthStage1, dayStage1,yearStage2,monthStage2,dayStage2);
   printf("Stage 3: Total Years %.2f", percentofYear);
  
}
    
