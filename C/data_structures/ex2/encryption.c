/*------------------------------------------------------
* Filename: [encryption.c]
* Description: [encryptes]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define ARR_LEN (26)

// moves n forward cyclicly
void reverse(int*arr, int n){
    int i=0, j=n-1;
    while(i<j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
        i++;
        j--;
    }
}

void encrypt(int*arr){
    int tmp[ARR_LEN];
    int mid = ARR_LEN/2; // switch halfs
    memcpy(tmp,arr,mid);
    memcpy(arr,&arr[mid],mid);
    memcpy(&arr[mid],tmp,mid);

    //reverse step 6
    for(int i = ARR_LEN-1;i>0;i--){
        arr[i]-=arr[i-1];
    }

    // its a known interview question to move forward by 3 reverses
    int num_steps=5;
    num_steps %= ARR_LEN;
    int split_idx = ARR_LEN-num_steps;
    reverse(arr,split_idx);
    reverse(&arr[split_idx],ARR_LEN-split_idx);
    reverse(arr,ARR_LEN);

    for(int i =1;i<ARR_LEN;i*=2){
        // we can access 1 because the messages are always 26 nums
        arr[i]/=7;
    }

    num_steps=4;
    split_idx=num_steps;
    reverse(arr,split_idx);
    reverse(&arr[split_idx],ARR_LEN-split_idx);
    reverse(arr,ARR_LEN);

    int to_lower=5; //print result decrypted
    for(int i =0;i<ARR_LEN;i++){
        putchar((char)(arr[i]-to_lower));
    }
}

int main() {
    int arr[ARR_LEN];
    for(int i = 0;i<ARR_LEN;i++){ 
        if(scanf("%d", &arr[i])!=1){
            printf("ARR_LEN should be 26!");
            return 1;
        }
    }
    encrypt(arr);
    return 0;
}