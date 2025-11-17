/*------------------------------------------------------
* Filename: [num_sum.c]
* Description: [checks if sum of first and last is same as rest]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

#define TRUE (1)
#define FALSE (0)


int main() {
    int n_i, first, last, mid_sum=0, count=0,prev=0;
    while(scanf("%d",&n_i)==1){
        if (count==0){
            first = n_i;
        }
        else if(count>1){
            mid_sum+=prev;
        }
        prev = n_i;
        count++;
    }
    last=prev;
    if (first+last == mid_sum){
        printf("The sum is equal");
    }
    else{
        printf("The sum is not equal");
    }
    return 0;
}
