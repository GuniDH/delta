/*------------------------------------------------------
* Filename: [median.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>


// Helper for the sort function
// Swaps values using pointers
void swap(int*pointer1, int*pointer2){
    int tmp=*pointer1;
    *pointer1=*pointer2;
    *pointer2=tmp;
}


// Sort an array nums with length len naively
void sort(int* nums, int len){
    for(int i=0;i<len;i++){ 
        for(int j=i+1;j<len;j++){
            if(nums[i]>nums[j]){ // we want accending order
                swap(nums+i, nums+j);
            }
        }
    }
}


// Computes the median
// If length is even we will take the average of the middle 2 elements in sorted order
// if odd we will return the mid value in sorted order
int compute_median(int*nums, int len){
    return (len%2==0) ? (nums[len/2-1]+nums[len/2])/2 : nums[len/2];
}

int main() {
    
    int*nums=NULL;
    int count=0; // Count is the current number of numbers that the user provided
    int tmp;
    printf("Give me numbers so i can compute their median, in order to stop give a non number input\n");
    while(scanf("%d", &tmp)==1){
        count++;
        int *tmp_p=(int*)realloc(nums,sizeof(int)*count);
        if(!tmp_p){ // memory allocation might fail
            printf("allocation failed");
            free(nums);
            return 1;
        }
        nums=tmp_p;
        nums[count-1]=tmp;
    }
    if(count){
        printf("Here is your median!\n");
        sort(nums,count);
        printf("%d", compute_median(nums,count));
        free(nums);
    }
    else{
        printf("You didnt give me any numbers so no median for you today!\n");
        return 1;
    }
    return 0;
}