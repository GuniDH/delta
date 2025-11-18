/*------------------------------------------------------
* Filename: [print_val_addr.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

#define LEN (8)

int main() {
    int nums[LEN];
    char chars[LEN];
    printf("give array of nums");
    for(int i = 0; i<LEN;i++){
        scanf(" %d",&nums[i]);
    }
    printf("give array of chars");
    for(int i = 0; i<LEN;i++){
        scanf(" %c",&chars[i]);
    }
    for(int i = 0; i<LEN;i++){
        printf("\nFIRST WAY\narray of chars\nval: %c addr: %p\narray of nums\nval: %d addr: %p\n", chars[i], &chars[i], nums[i], &nums[i]);
        printf("\nSECOND WAY\narray of chars\nval: %c addr: %p\narray of nums\nval: %d addr: %p\n", *(chars+i), chars+i, *(nums+i), nums+i);
    }
    return 0;
}