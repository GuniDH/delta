/*------------------------------------------------------
* Filename: [median.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void swap(int*n1, int*n2){
    int tmp=*n1;
    *n1=*n2;
    *n2=tmp;
}


void sort(int* nums, int len){
    for(int i=0;i<len;i++){ 
        for(int j=i+1;j<len;j++){
            if(nums[i]>nums[j]){
                swap(nums+i, nums+j);
            }
        }
    }
}

int compute_median(int*nums, int len){
    return (len%2==0) ? (nums[len/2-1]+nums[len/2])/2 : nums[len/2];
}

int main() {
    
    int*nums=NULL;
    int count=0;
    int tmp;
    while(scanf("%d", &tmp)==1){
        count++;
        int *tmp_p=(int*)realloc(nums,sizeof(int)*count);
        if(!tmp_p){
            printf("allocation failed");
            free(nums);
            return 1;
        }
        nums=tmp_p;
        nums[count-1]=tmp;
    }
    
    if(count){
        sort(nums,count);
        printf("%d", compute_median(nums,count));
        free(nums);
    }
    return 0;
}