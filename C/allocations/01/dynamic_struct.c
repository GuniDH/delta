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
    scanf("%d", &t->hrs);
    if(!(t->hrs>=0 && t->hrs<=MAX_HRS)){
        return 0;
    }
    printf("Give minutes max %d\n", MAX_MINS);
    scanf("%d", &t->mins);
    if(!(t->mins>=0 && t->mins<=MAX_MINS)){
        return 0;
    }
    printf("Give seconds max %d\n", MAX_SECS);
    scanf("%d", &t->secs);
    if(!(t->secs>=0 && t->secs<=MAX_SECS)){
        return 0;
    }
    return 1;
}

Time * add_times(Time *t1, Time *t2){
    Time *res = (Time*) malloc(sizeof(Time));
    if(res==NULL){
        return NULL;
    }
    res->secs=(t1->secs+t2->secs)%(MAX_SECS+1); // we need to start from the smallest unit to accumalte overflow to the next unit
    res->mins=((t1->secs+t2->secs)/(MAX_SECS+1) + (t1->mins+t2->mins))%(MAX_MINS+1);
    res->hrs=((t1->mins+t2->mins)/(MAX_MINS+1) + (t1->hrs+t2->hrs))%(MAX_HRS+1);
    res->hrs = (t1->hrs + t2->hrs)%(MAX_HRS+1); // there is no day field
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
    // we werent told to print t3 or do anything with it
    free(t1);
    free(t2);
    free(res);
    return 0;
}