/*------------------------------------------------------
* Filename: [remove_dup.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN (10)

// removes duplicatates , returns arr updates len
int* remove_dup_v1(int* arr, int* len){
    int count=1; // length of the result array
    int* dupless_arr=NULL;
    int *tmp; // we need it so we can free after failed allocation the prev memo
    int j;
    for(int i=0; i<*len;){
        tmp = dupless_arr = (int*)(realloc(dupless_arr, count*(sizeof(int))));
        if(tmp==NULL){
            free(dupless_arr);
            return NULL;
        }
        dupless_arr=tmp;
        dupless_arr[(count++)-1]=arr[i];
        j=i+1;
        while(j<*len && arr[i] == arr[j]){
            j++;
        }
        i=j;
    }
    *len=count-1;
    return dupless_arr;
}

// removes duplicatates , returns len updates arr
int remove_dup_v2(int* arr, int len){
    int count=1; // length of the result array
    int* dupless_arr=NULL;
    int *tmp; // we need it so we can free after failed allocation the prev memo
    int j;
    for(int i=0; i<len;){
        tmp = dupless_arr = (int*)(realloc(dupless_arr, count*(sizeof(int))));
        if(tmp==NULL){
            free(dupless_arr);
            return -1;
        }
        dupless_arr=tmp;
        dupless_arr[(count++)-1]=arr[i];
        j=i+1;
        while(j<len && arr[i] == arr[j]){
            j++;
        }
        i=j;
    }
    arr = dupless_arr;
    return count-1;
}

// removes duplicates and updates both len and arr
void remove_dup_v3(int* arr, int* len){
    int count=1; // length of the result array
    int* dupless_arr=NULL;
    int *tmp; // we need it so we can free after failed allocation the prev memo
    int j;
    for(int i=0; i<*len;){
        tmp = dupless_arr = (int*)(realloc(dupless_arr, count*(sizeof(int))));
        if(tmp==NULL){
            free(dupless_arr);
        }
        dupless_arr=tmp;
        dupless_arr[(count++)-1]=arr[i];
        j=i+1;
        while(j<*len && arr[i] == arr[j]){
            j++;
        }
        i=j;
    }
    arr = dupless_arr;
    *len = count-1;
}

void print_arr(int * arr, int len){
    printf("Printed array: ");
    for(int i = 0; i < len;i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

// currently running v1
int main() {
    int arr[ARR_LEN]={1,1,1,2,2,6,7,87,87,99};
    int *dupless_arr;
    int*len;
    *len=ARR_LEN;
    print_arr(arr,*len);
    if((dupless_arr=(remove_dup_v1(arr,len)))==NULL){
        printf("Memory Allocation failed");
        return 1;
    }
    print_arr(dupless_arr, *len);
    free(dupless_arr); 
    return 0;
}