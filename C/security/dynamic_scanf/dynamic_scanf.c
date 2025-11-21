/*------------------------------------------------------
* Filename: [dynamic_scanf.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 64
#define MAX_UINT 0xFFFFFFFF

// in order to be more efficient (not quadratic) we wont allocate every iteration

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

int main() {
    char* res = dyn_scanf();
    if (res != NULL) {
        printf("%s", res);
        free(res);
        return 0;
    }
    return 1;
}