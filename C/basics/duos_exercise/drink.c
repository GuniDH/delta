/*------------------------------------------------------
* Filename: [num.c]
* Description: [prints hanukia]
* Author: Guni Deyo Haness and Tal Aviya Biton
-------------------------------------------------------*/

#include <stdio.h>

#define BAD_INPUT (-1)  // we could use any negative number for it since sum will never be negative
#define COKE_PRICE (5.20)
#define DIET_COKE_PRICE (7.20)
#define ORANJADA_PRICE (3.40)
#define SCHWEPPES_PRICE (4.50)
#define GRAPEFRUIT_PRICE (3.50)
#define MINERAL_WATER (2.50)
#define TRUE (1)
#define FALSE (0)

// we could obviously use the standard function but i dont know if we are allowed
char to_lower(char choice){
    switch(choice){
        case 'C': return 'c';
        case 'D': return 'd';
        case 'E': return 'e';
        case 'O': return 'o';
        case 'S': return 's';
        case 'G': return 'g';
        case 'W': return 'w';
        default: return choice; // so we could detect it and log accordingly
    }
}

int validate_input(double input){
    //checks that the input is a none negative integer => legal coin
    int int_input=(int)input;
    if(input >= 0 && input == (double)int_input){
        return TRUE;
    }
    printf("Invalid input for coin (has to none negative integer)\n");
    return FALSE;
}

void detect_agent(int tenths, int twos, int fives, int tens) {
    if (tenths==1 && twos==3 && fives==3 && tens==7) {
        printf("Special agent, please respond!!!\n");
    }
}

double compute_sum(int tenths, int halfs, int ones, int twos, int fives, int tens) {
    return tens*10.0+fives*5.0+twos*2.0+ones*1.0+halfs*0.5+tenths*0.1;
}

// Process coins: Computes their sum while detecting an agent if present
double process_coins(){
    double sum;
    double tenths=0, halfs=0, ones=0, twos=0, fives=0, tens=0; // counters
    printf("Enter amount of 0.1 NIS: ");
    scanf("%lf", &tenths);
    if (!validate_input(tenths)){
        return BAD_INPUT; 
    }
    printf("Enter amount of 0.5 NIS: ");
    scanf("%lf", &halfs);
    if (!validate_input(halfs)){
        return BAD_INPUT; 
    }
    printf("Enter amount of 1 NIS: ");
    scanf("%lf", &ones);
    if (!validate_input(ones)){
        return BAD_INPUT; 
    }
    printf("Enter amount of 2 NIS: ");
    scanf("%lf", &twos);
    if (!validate_input(twos)){
        return BAD_INPUT; 
    }
    printf("Enter amount of 5 NIS: ");
    scanf("%lf", &fives);
    if (!validate_input(fives)){
        return BAD_INPUT; 
    }
    printf("Enter amount of 10 NIS: ");
    scanf("%lf", &tens);
    if (!validate_input(tens)){
        return BAD_INPUT; 
    }
    putchar('\n');
    sum = compute_sum((int)tenths, (int)halfs, (int)ones, (int)twos, (int)fives, (int)tens);
    printf("The machine received payment of %.2lf NIS\n", sum);
    detect_agent((int)tenths, (int)twos, (int)fives, (int)tens);

    return sum;
}

void change_in_coins(double change){//prints the change by coins
    int agorot, coins;
    agorot = (int)(change*10+0.5); // round to nearest (and convert to agorot)

    coins = agorot / 100;
    printf("Machine returned %d coins of 10 NIS\n", coins);
    agorot %= 100;

    coins = agorot / 50;
    printf("Machine returned %d coins of 5 NIS\n", coins);
    agorot %= 50;

    coins = agorot / 20;
    printf("Machine returned %d coins of 2 NIS\n", coins);
    agorot %= 20;

    coins = agorot / 10;
    printf("Machine returned %d coins of 1 NIS\n", coins);
    agorot %= 10;

    coins = agorot / 5;
    printf("Machine returned %d coins of 0.5 NIS\n", coins);
    agorot %= 5;

    coins = agorot;
    printf("Machine returned %d coins of 0.1 NIS\n", coins);
}

// process drink and returns false if client cant buy
int process_drink(double price){
    printf("The price of the drink is %.2lf NIS\n", price);
    double sum = process_coins();
    double change = sum - price;
    if (!change){
        printf("Go get a loan and try again later"); // client doesnt have enough cash!
        return FALSE;
    }
    change_in_coins(change);
    printf("Your change is %.2lf NIS\n", change);
    return TRUE;
}

int main() {

    int running = TRUE;
    char drink_choice;
    while (running){
        double price;
        printf("*************** Welcome to the drinks machine ***************\n\n\n");
        printf("Please select the drink you would like to order:\n");
        printf("Press 'C' for Coca-Cola\n");
        printf("Press 'D' for Diet-Colaa\n");
        printf("Press 'O' for Orangeade\n");
        printf("Press 'S' for Schweppes\n");
        printf("Press 'G' for Grape juice\n");
        printf("Press 'W' for Mineral water\n");
        scanf(" %c", &drink_choice);

        switch(to_lower(drink_choice)){
            case 'c':
                if (!process_drink(COKE_PRICE)){
                    continue;
                }
                break;
            case 'd':
                if (!process_drink(DIET_COKE_PRICE)){
                    continue;
                }
                break;
            case 'o':
                if (!process_drink(ORANJADA_PRICE)){
                    continue;
                }
                break;
            case 's':
                if (!process_drink(SCHWEPPES_PRICE)){
                    continue;
                }
                break;
            case 'g':
                if (!process_drink(GRAPEFRUIT_PRICE)){
                    continue;
                }
                break;
            case 'w':
                if (!process_drink(MINERAL_WATER)){
                    continue;
                }
                break;
            case 'e':
                running = FALSE;
                break;
            default:
                printf("No such drink, try again!");
                continue;
        }
        printf("Enjoy your drink!\n");
    }
    return 0;
}
