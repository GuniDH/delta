/*------------------------------------------------------
* Filename: [dynamic_scanf.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRINGS (5)

char* dyn_scanf(void) {
    char* res = NULL;
    int length = 0; // length of res
    char c;
    while (1) {
        c = fgetc(stdin);
        char* tmp = (char*)realloc(res, sizeof(char) * (++length)); // we use a temp in order to be able to free our allocated memory in case of failure
        if (tmp == NULL) {
            printf("Memo allocation failed. get yourself a new ram dear friend\n");
            free(res);
            return NULL;
        }
        res = tmp;
        if (c == '\n' || c==EOF) { //this way our function is suitable both for normal stdin and also if the user gives input as file and doenst place \n
            res[length - 1] = '\0';
            return res;
        }
        res[length - 1] = c;
    }
    return NULL;
}

int compare(void *n1, void* n2){
    n1 = (double*)n1;
    n2 = (double*)n2;

}

void sort(void* arr, int len, void (*compare)(void*, void*)){
    for(int i =0;i<len;i++){
        for(int j=i+1;j<len;j++){
           if(compare(arr[i], arr[j])){
                
           }
        }
    }
}

int cmp_len(char* s1, char*s2){
    return (strlen(s1) > strlen(s2));
}

int cmp_alpha(char*s1, char*s2){
    int l1 = strlen(s1), l2=strlen(s2);
    int min_len=(l1<l2)?l1:l2;
    for(int i =0;i<min_len;){
        while(s1[i]==s2[i]){i++;}
        if (s1[i]>s2[i]){
            return 1;
        }
    }
    return 0;
}

void print_strings(char**strings){
    for (int i = 0; i < NUM_STRINGS; i++){
        printf("%s", strings[i]);
        if (i!=NUM_STRINGS-1)
            putchar(',');
    }
}

int main() {
    char**strings;
    for (int i = 0; i < NUM_STRINGS; i++){
        printf("Enter %d string: ", i+1);
        strings[i]=dyn_scanf();
        putchar('\n');
    }
    print_strings(strings);
    sort(strings, NUM_STRINGS, cmp_alpha);
    print_strings(strings);
    return 1;
}