/*------------------------------------------------------
* Filename: [dynamic_scanf.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRINGS (5)
#define INITIAL_SIZE 64
#define MAX_UINT 0xFFFFFFFF

// a safe implementation for scanf using dynamic allocation
char* dyn_scanf(void) {
    int size = INITIAL_SIZE;
    unsigned int length = 0;
    char* res = (char*)malloc(size);
    if (!res) return NULL;
    int c; // to handle EOF if we are given input from file
    while (1) {
        c = fgetc(stdin);
        if (c == '\n' || c == EOF) { //this way our function is suitable both for normal stdin and also if the user gives input as file and doenst place \n
            res[length] = '\0';
            return res;
        }
        if (length + 1 >= size) { // check if we need to resize
            size *= 2;
            if (size > MAX_UINT)
                size = MAX_UINT;
            char* tmp = (char*)realloc(res, size);
            if (tmp == NULL) {
                printf("Memo allocation failed. get yourself a new ram dear friend\n");
                free(res);
                return NULL;
            }
            res = tmp;
        }
        res[length] = (char)c; // because fgetc returns int and we need to handle EOF
        length++;
    }
}


void sort(void** arr, int len, int (*compare)(void*, void*)){
    void*tmp;
    for(int i =0;i<len;i++){
        for(int j=i+1;j<len;j++){
           if(compare(arr[i], arr[j]) > 0){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
           }
        }
    }
}

int cmp_len(void* s1, void* s2) {
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    // returns postive if str1 longer, negative if 2 and 0 if equale
    return (int)(strlen(str1) - strlen(str2));
}

int cmp_alpha(void* s1, void* s2) {
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            // asscii difference
            return str1[i] - str2[i];
        }
        i++;
    }
    // we finished scnanning the shorter one
    return str1[i] - str2[i];
}

void print_strings(char**strings){
    for (int i = 0; i < NUM_STRINGS; i++){
        printf("%s", strings[i]);
        if (i!=NUM_STRINGS-1)
            putchar(',');
    }
    putchar('\n');
}

int main() {
    char* strings[NUM_STRINGS]; 
    // get input (strings)
    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("Enter string #%d: ", i + 1);
        strings[i] = dyn_scanf();
        if (strings[i] == NULL) {
            printf("Error reading input.\n");
            return 1;
        }
    }
    // sort by length
    sort((void**)strings, NUM_STRINGS, cmp_len);
    print_strings(strings);

    // sort by abc
    sort((void**)strings, NUM_STRINGS, cmp_alpha);
    print_strings(strings);

    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }

    return 0;
}