/*------------------------------------------------------
* Filename: [print_hanukia.c]
* Description: [prints hanukia]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

void print_candle_fire(int day_number, char candle_char) {
    printf("\n\n\n ");
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    printf("%c    ", ((day_number--)>0)*candle_char);
    putchar('\n');
}

void print_candle_base() {
    // let me know if you wanted the candle structure dimensions to be modular 
    // (given the fact we arent allowed to use if statements and loops)

    // let me know if you would prefer just 4 prints instead
    printf("###  ###  ###  ###  ###  ###  ###  ###\n###  ###  ###  ###  ###  ###  ###  ###\n###  ###  ###  ###  ###  ###  ###  ###\n###  ###  ###  ###  ###  ###  ###  ###\n");
}

void print_structure_base() {
    printf("######################################\n");
}

void print_vertical_structure() {
    printf("                  ::                  \n                  ::                  \n                  ::                  \n                  ::                  \n");
}

void print_base() {
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
}

int main() {
    int day_number;
    char candle_char = '#';
    printf("enter the day number\n");
    scanf("%d", &day_number);

    print_candle_fire(day_number, candle_char);
    print_candle_base();
    print_structure_base();
    print_vertical_structure();
    print_base();

    return 0;
}
