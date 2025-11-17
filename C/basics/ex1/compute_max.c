/*------------------------------------------------------
* Filename: [compute_max.c]
* Description: [find max out of variables]
* Author: guni deyo haness
-------------------------------------------------------*/


/*------------------------------------------------------
* Function Name - compute_max
*
* Function Purpose - [find max out of 2 variables and print] 
*
* Parameters –  None
*
* Return Values - None
*
* Author - Guni Deyo Haness
-------------------------------------------------------*/

#include <stdio.h>


void compute_max() {
    int x = 9;
    int y = 7;
    int z = (y>=x) * y + (y<x) * x;
    printf("%d",z);
}


int main() {
    compute_max();
    return 0;
}
