/*------------------------------------------------------
* Filename: [array_sort.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

#define LEN (4)

void swap(int**p1, int**p2){
    int* tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

void sort(int*pointers[]){
    for(int i=0;i<LEN;i++){ // sort
        for(int j=i+1;j<LEN;j++){
            if(*pointers[i] > *pointers[j]){
                swap(&pointers[i], &pointers[j]);
            }
        }
    }
}

void print(int*pointers[]){
    for (int i = 0;i<LEN;i++){ // init pointers array
        printf("%p ",pointers[i]);
    }
    putchar('\n');
}

int main() {
    int nums[LEN];
    int* pointers[LEN];
    printf("give me my array. %d values\n",LEN);
    for (int i = 0;i<LEN;i++){
        scanf("%d", &nums[i]);
    }
    for (int i = 0;i<LEN;i++){ // init pointers array
        pointers[i]=&nums[i];
    }
    print(pointers);
    sort(pointers);
    print(pointers);
    return 0;
}