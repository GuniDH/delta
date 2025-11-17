/*------------------------------------------------------
* Filename: [num.c]
* Description: [prints hanukia]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
// Let me know if you want me to use the standard library for booleans which i believe exists

int is_digit(int num){
    if (num >= 0 && num <= 9) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int main() {
    int sum, n_i;

    int is_first_iter = TRUE;
    // the instructions didnt mention need to print for input
    do { 
        scanf("%d", &n_i);
        sum = (is_first_iter) ? sum + n_i : sum - n_i;
        if (is_first_iter){
            is_first_iter = FALSE;
        }
    }  while(is_digit(n_i));
    // take in account for the last iteration
    
    sum += (2 * n_i); // n_i holds the last number
    if (sum){
        printf("The sum is not equal");
    }
    else{
        printf("The sum is equal");
    }
    return 0;
}
