/*------------------------------------------------------
* Filename: [print_chars.c]
* Description: [find max out of variables]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

/*------------------------------------------------------
* Function Name - determine_printed_char
*
* Function Purpose - [determines which characther to print ] 
*
* Parameters –  num_of_prints
*
* Return Values - determined char
*
* Author - Guni Deyo Haness
-------------------------------------------------------*/


char determine_printed_char(int num_of_prints){
    char printed_char = '@';
    if (!(num_of_prints % 2)){
        printed_char = '*';
    }
    else if (!(num_of_prints % 3)){
        printed_char = '^';
    }
    else if (!(num_of_prints % 5)){
        printed_char = '%';
    }
    return printed_char;
}

/*------------------------------------------------------
* Function Name - print_line
*
* Function Purpose - [prints the determined char based on num_of_prints] 
*
* Parameters –  num of prints
*
* Return Values - none
*
* Author - Guni Deyo Haness
-------------------------------------------------------*/

void print_line(unsigned int num_of_prints) {
    char printed_char = determine_printed_char(num_of_prints);
    for(int i = 0; i < num_of_prints; i++) {
        putchar(printed_char);
    }
    putchar('\n');
}

/*------------------------------------------------------
* Function Name - print_square
*
* Function Purpose - [prints the determined char based on num_of_prints as a square] 
*
* Parameters –  none
*
* Return Values - none
*
* Author - Guni Deyo Haness
-------------------------------------------------------*/

void print_square() {
    unsigned int num_of_prints; 
    // there was no requirement for printing and asking for the input
    scanf("%u", &num_of_prints);
    for(int i = 0; i < num_of_prints; i++) {
        print_line(num_of_prints);
    }
}

int main() {
    print_square();
    return 0;
}
