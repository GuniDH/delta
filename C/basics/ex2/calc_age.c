/*------------------------------------------------------
* Filename: [calc_age.c]
* Description: [find max out of variables]
* Author: guni deyo haness
-------------------------------------------------------*/


/*------------------------------------------------------
* Function Name - calc_age
*
* Function Purpose - [calc age based on birthday] 
*
* Parameters –  None
*
* Return Values - None
*
* Author - Guni Deyo Haness
-------------------------------------------------------*/

#include <stdio.h>
#define MONTH_DAYS 30
#define YEAR_DAYS 365

void calc_age() {
    int current_day, current_month, current_year;
    int birthday_day, birthday_month, birthday_year;
    int age_in_days;
    double age_in_months, age_in_years;
    printf("Enter current date:\n");
    scanf("%d/%d/%d", &current_day, &current_month, &current_year);
    printf("Enter Gary's Birthday:\n");
    scanf("%d/%d/%d", &birthday_day, &birthday_month, &birthday_year);
    int current_total_days = current_year * YEAR_DAYS + current_month * MONTH_DAYS + current_day;
    int birthday_total_days = birthday_year * YEAR_DAYS + birthday_month * MONTH_DAYS + birthday_day;
    age_in_days = current_total_days - birthday_total_days;
    age_in_months = (double)age_in_days / MONTH_DAYS;
    age_in_years = (double)age_in_days / YEAR_DAYS;
    printf("Gary's age in days:%d\n", age_in_days);
    printf("Gary's age in months:%f\n", age_in_months);
    printf("Gary's age in years:%f\n", age_in_years);
}


int main() {
    calc_age();
    return 0;
}
