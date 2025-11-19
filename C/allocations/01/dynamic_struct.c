/*------------------------------------------------------
* Filename: [dynamic_struct.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HRS (23)
#define MAX_MINS (59)
#define MAX_SECS (59)

typedef struct {
    int hrs;
    int mins;
    int secs;
} Time;

void deallocate(Time *t1, Time *t2){
    printf("Bad input");
    free(t1);
    free(t2);
}


// return true if no error in input
int get_input(Time *t){
    printf("Give hours max %d\n", MAX_HRS);
    if((scanf("%d", &t->hrs)) != 1 || !(t->hrs>=0 && t->hrs<=MAX_HRS)){
        printf("Input has to be an integer in the specified range I noted\n");
        return 0;
    }
    printf("Give minutes max %d\n", MAX_MINS);
    if((scanf("%d", &t->mins)) != 1 || !(t->mins>=0 && t->mins<=MAX_MINS)){
        printf("Input has to be an integer in the specified range I noted\n");
        return 0;
    }
    printf("Give seconds max %d\n", MAX_SECS);
    if((scanf("%d", &t->secs)) != 1 || !(t->secs>=0 && t->secs<=MAX_SECS)){
        printf("Input has to be an integer in the specified range I noted\n");
        return 0;
    }
    return 1;
}

Time * add_times(Time *t1, Time *t2){
    Time *res = (Time*) malloc(sizeof(Time));
    if(res==NULL){
        return NULL;
    }

    int sec_limit = MAX_SECS+1;
    int total_secs=t1->secs+t2->secs;
    res->secs=total_secs%sec_limit; //the remainder is the actual seconds
    int carry_mins = total_secs / sec_limit; // carry to minutes

    int min_limit = MAX_MINS+1;
    int total_mins=t1->mins+t2->mins+carry_mins;
    res->mins=total_mins%min_limit;
    int carry_hrs = total_mins / min_limit;

    int hrs_limit= MAX_HRS+1;
    int total_hours=t1->hrs+t2->hrs+carry_hrs;
    res->hrs=total_hours%hrs_limit;
    // no carry for days 
    return res;
}

int main() {
    Time *t1 = (Time*) malloc(sizeof(Time));
    Time *t2 = (Time*) malloc(sizeof(Time));
    Time *res;
    if (t1==NULL || t2==NULL){
        printf("Get yourself a new ram my friend, its 2025.");
        return 1;
    }
    printf("Fields for first time:\n");
    if(!get_input(t1)){
        deallocate(t1,t2);
        return 1;
    }
    printf("Fields for second time:\n");
     if(!get_input(t2)){
        deallocate(t1,t2);
        return 1;
    }
    if((res = add_times(t1,t2))==NULL){
        printf("Get yourself a new ram my friend, its 2025.");
        deallocate(t1,t2);
        return 1;
    }
    printf("%d:%d:%d", res->hrs, res->mins, res->secs);
    free(t1);
    free(t2);
    free(res);
    return 0;
}