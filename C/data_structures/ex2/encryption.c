/*------------------------------------------------------
* Filename: [encryption.c]
* Description: [encryptes]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define ARRAY_LEN (15)
#define INCREASING (0)
#define DECREASING (1)
#define CONSTANT (2)

int main() {
    int arr[ARRAY_LEN];
    int state;
    int prev;
    printf("Give me an array of %d characters\n",ARRAY_LEN);
    if(scanf("%d", &arr[0])!=1){
        printf("The array is constant");
        return 0;
    }
    if(scanf("%d", &arr[1])!=1){
        printf("The array is constant");
        return 0;
    }
    // we have 2 already
    if (arr[0]<arr[1]){
        state=INCREASING;
    }
    else if(arr[0]>arr[1]){
        state=DECREASING;
    }
    else{
        state=CONSTANT;
    }
    prev= arr[1];
    for (int i=2;i<ARRAY_LEN;i++){
        if(scanf("%d", &arr[i])!=1){
            break;
        }
        if (state==DECREASING && prev<=arr[i] || state==INCREASING && prev>=arr[i] || state==CONSTANT && prev!=arr[i]){
            printf("The array is messed up");
            return 0;
        }
        prev=arr[i];
    }
    if(state==INCREASING){ // we could use a dictionary to do the prints without any ifs to be shorter
        printf("The array is increasing");
    }
    else if(state==DECREASING){
        printf("The array is decreasing");
    }
    else {
        printf("The array is constant");
    }
    return 0;
}