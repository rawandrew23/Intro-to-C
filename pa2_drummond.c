#include <stdio.h>
#include <ctype.h>

int main(void) {
    double usage;
    double rate1 = 0;
    double rate2 = 0.10;
    double rate3 = 0.20;
    double rate4 = 0.30;

    double block_1 = 100;
    double block_2 = 200;
    double block_3 = 200;

    double remaining_usage1, remaining_usage2, remaining_usage3; // holds val the remaining usage within each block

    double block_usage1, block_usage2, block_usage3; // holds block values
    double result;
    double surcharge = 0.1;

    printf("Enter usage (kWh): ");
    scanf("%lf", &usage);

    //user inputs negative num
    if (usage<0) {
        printf("\nInvalid Input\n");
    }
    //user input is [0, 100]
    else if (usage>=0 && usage<=100) {
       printf("\nBase bill: $%.2lf", rate1);
       printf("\nFinal bill: $%.2lf\n", rate1);
    }
    //user input is [101, 300]
    else if (usage>=101 && usage<=300) {
        remaining_usage1 = usage-block_1;
        if (remaining_usage1<=200) {
            result =remaining_usage1 * rate2;
        }
        printf("\nBase bill: $%.2lf", result);
        printf("\nFinal bill: $%.2lf\n", result);
    }
    //user input is [301-500]
    else if (usage>=301 && usage<=500) {
        remaining_usage1 = usage - block_1;
        block_usage1 = usage - remaining_usage1;

        remaining_usage2 = remaining_usage1 - block_2;
        block_usage2 = remaining_usage1 - remaining_usage2;

        if (remaining_usage2<=200) {
            result = (block_usage1*rate1)+(block_usage2*rate2)+(remaining_usage2*rate3);
        }
        printf("\nBase bill: $%.2lf", result);
        printf("\nFinal bill: $%.2lf\n", result);

    }
    //user input>=501
    else if (usage>=501) {
        remaining_usage1 = usage-block_1;
        block_usage1 = usage-remaining_usage1;

        remaining_usage2 = remaining_usage1-block_2;
        block_usage2 = remaining_usage1 - remaining_usage2;

        remaining_usage3 = remaining_usage2-block_3;
        block_usage3 = remaining_usage2-remaining_usage3;

        result = (block_usage1*rate1)+(block_usage2*rate2)+(block_usage3*rate3)+(remaining_usage3*rate4);
        printf("Base bill: $%.2lf\n", result);
        if (result>100) {
            surcharge = surcharge*result;
            result += surcharge;
            printf("Surcharge (10%%): $%.2lf\n", surcharge);
            printf("Final bill: $%.2lf\n", result);
        }
    }
    return 0;
}