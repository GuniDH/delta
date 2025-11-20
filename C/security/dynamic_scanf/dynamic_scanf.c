/*------------------------------------------------------
* Filename: [dynamic_scanf.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

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

int main() {
    char* res = dyn_scanf();
    if (res != NULL) {
        printf("%s", res);
        free(res);
        return 0;
    }
    return 1;
}