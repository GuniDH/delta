/*------------------------------------------------------
* Filename: [a.c]
* Description: [converts str to int]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT_LEN (10)
// well known but we can easiliy calculate using log 10 +1 of maxint(0xFFFFFFFF)
#define TO_ADD (36)


int is_number(char*arr,int len){
    if(arr[0]=='0'){
        printf("not a number");
        return 0;
    }
    for (int i=0;i<len;i++){
        if(!(arr[0]>='0' && arr[0]<='9')){
            printf("not a number");
            return 0;
        }
    }
    return 1;
}

int main() {
    char arr[MAX_INT_LEN];
    int res;
    int is_negative=0;
    printf("give me an integer!\n");
    scanf("%s", arr); // would be safer to use fgets to not allow the user perform rce etc
    if (arr[0]=='-'){
        if(strlen(arr)==1){
            printf("not a number");
            return 1;
        }
        is_negative=1;
    }

    // im not sure atoi handles none numbers so i will check myself
    if(! ((is_negative) ? is_number(arr+1,strlen(arr)-1) : is_number(arr,strlen(arr))))
        return 1;

    res=(is_negative) ? atoi(arr+1) : atoi(arr); // im not sure if atoi checks that its actually a number so i will 
    
    if(is_negative){
        res*=-1;
    }

    // I decided to not allow numeric overflow because its also vulnerable
    if(res> 0x7FFFFFFF-TO_ADD){
        printf("TOO BIG!\n");
        return 1;
    }

    printf("%d",res+TO_ADD);
    return 0;
}