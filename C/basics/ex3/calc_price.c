/*------------------------------------------------------
* Filename: [calc_price.c]
* Description: [find max out of variables]
* Author: guni deyo haness
-------------------------------------------------------*/


/*------------------------------------------------------
* Function Name - calc_price
*
* Function Purpose - [calc package delivery fee] 
*
* Parameters –  None
*
* Return Values - None
*
* Author - Guni Deyo Haness
-------------------------------------------------------*/

#include <stdio.h>
#define BASE_FEE 5.5
#define KILO_FEE 11
#define CM_FEE 0.03
#define SIZE_WEIGHT_FEE 0.01
#define MM_TO_CM_FACTOR 10
#define GRAM_TO_KG_FACTOR 1000

void calc_price() {
    // weight in grams, width and and length in mm
    int length, width;
    float weight, size, price;
    printf("Enter package length,width (mm) and weight (grams) one by one:\n");
    scanf("%d\n%d\n%f", &length, &width, &weight);
    size = ((length / MM_TO_CM_FACTOR) * (width / MM_TO_CM_FACTOR)); // convert to cm before squared cm calculation
    weight /= GRAM_TO_KG_FACTOR; // convert to kg
    price = BASE_FEE + weight * KILO_FEE + size * CM_FEE + (size/weight) * SIZE_WEIGHT_FEE;
    printf("Package size in squared cm:%.2f\n", size);
    printf("Package weight in kg:%.3f\n", weight);
    printf("Package price in ILS:%.2f\n", price);
}


int main() {
    calc_price();
    return 0;
}
