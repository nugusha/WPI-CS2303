/*
    PA1.c
    Nugzar Chkhaidze nchkhaidze
*/

#include<stdio.h>
int dayoftheweek;
int year=2017;
int n_year;
void printweekdays(){
     printf("Sun Mon Tue Wed Thu Fri Sat\n");     
} // void printweekdays();
int isleap(int x){
    if(x%4)return 0;
    if(x%400==0)return 1;
    if(x%100==0)return 0;
    return 1;
} // isleap(int year);
void input(){
    printf("MONTHLY CALENDAR\n");
    printf("Please enter year for this calendar:- ");
    scanf("%d",&n_year);
    printf("*** CALENDAR for %d ***\n",n_year);
} // void input();
int firstday(){

    int dayoftheweek=0;
    while(n_year<year){
     dayoftheweek-=1+isleap(--year);
     dayoftheweek=(dayoftheweek+7)%7;
    } 
/*
	year=2017 is the starting year
	and the first january is Sunday (dayoftheweek=0)
	while loop works while input year (n_year) is less than year.
	each time dayoftheweek is decreased by one because (365%7==1)
	and decreased by one more if (year-1) is leap year
*/
    while(n_year>year){
     dayoftheweek+=1+isleap(year++);
     dayoftheweek=(dayoftheweek+7)%7;
    }

/*
	this while loop works for the input years greater than year=2017
	it increments year during each iteration while n_year>year
	and finds first day of the week of year n_year at the end.
*/

    return dayoftheweek;
    
} // void firstday();
int getmonthdays(int i,int year){

	switch (i){
		case 0:case 2:case 4:case 6:
	        case 7:case 9:case 11:
			return 31;
		case 3:case 5:case 8:case 10:
			return 30;
	}
	if(isleap(year) && i==1)return 29;
	return 28;
}
int printmonth(int year,int i,int dayoftheweek){

        for(int j=0;j<dayoftheweek;j++){
                printf("   ");
		if(j)printf(" ");	
	}
/*
		it prints the blank spaces dayoftheweek times
	        e.g if dayoftheweek=2 (Tuesday) it will print
		blanks for sunday and monday.
		and additional blank between those (when j is more than 0)

*/


        int monthdays=getmonthdays(i,year);

        for(int j=1;j<=monthdays;j++){
/*
		it iterates form one to monthdays
		prints j, and a newline '\n' if all 7 days are
		already printed.
*/
		if(dayoftheweek)printf(" ");
                printf("%3d",j);
                
                
                dayoftheweek++;
                if(dayoftheweek==7){
                      printf("\n");
                      dayoftheweek=0;
                }
        }
        
        printf("\n");
        printf("\n");

	return dayoftheweek;
} // int printmonth(int year,int i,int dayoftheweek);
void printMonthName(int i){

	switch(i){
	case 0:
	    printf("January");
	    break;
	case 1:
 	    printf("February");
            break;
	case 2:	
	    printf("March");
	    break;
	case 3:
	    printf("April");
	    break;
	case 4:
	    printf("May");
	    break;
	case 5:
	    printf("June");
	    break;
	case 6:
	    printf("July");
	    break;
	case 7:
	    printf("August");
	    break;
	case 8:
	    printf("September");
	    break;
	case 9:
	    printf("October");
	    break;
	case 10:
	    printf("November");
	    break;
	case 11:
	    printf("December");
	    break;
	}
	printf(" %d\n",year);

} // void printMonthName(int i);
void printCalendar(int year,int dayoftheweek){
/*
 This for loop iterates form zero to 11 (from january to december)
	and calls functions for printing name of the month, week days 
	and month (numbers)
*/
    for(int i=0;i<12;i++){

	printMonthName(i);
        printweekdays();
	dayoftheweek=printmonth(year,i,dayoftheweek);
    }
} // void printCalendar(int year,int dayoftheweek);
int main(){  
    input();
    dayoftheweek=firstday();
    printCalendar(n_year,dayoftheweek);
    return 0;  
} // int main();
