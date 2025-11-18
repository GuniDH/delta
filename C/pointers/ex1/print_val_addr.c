/*------------------------------------------------------
* Filename: [print_val_addr.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

#define LEN (8)

int main() {
    int nums[LEN];
    char chars[LEN];
    printf("give array of %d nums", LEN);
    for(int i = 0; i<LEN;i++){
        if(scanf(" %d",&nums[i])!=1){
            printf("Bad input!");
            return 1; // We werent told whether we should give another opportunity to the user or not
            // also let me know if you prefer that ill print errors into stderr
        }
    }
    printf("give array of %d chars", LEN);
    for(int i = 0; i<LEN;i++){
        if(scanf(" %c",&chars[i])!=1){
            printf("Bad input!");
            return 1;
        }
    }
    for(int i = 0; i<LEN;i++){
        printf("first way\n");
        printf("array of chars\nval: %c addr: %p\n", chars[i], &chars[i]);
        printf("array of nums\nval: %c addr: %p\n", nums[i], &nums[i]);
        printf("second way\n");
        printf("array of chars\nval: %c addr: %p\n",  *(chars+i), chars+i);
        printf("array of nums\nval: %c addr: %p\n", *(nums+i), nums+i);
    }
    return 0;
}