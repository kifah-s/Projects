

/* >>> Project 3 ( ATM ) <<< */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Global Variables ..
int password = 1234;
int currentBalance = 1000;
// End Global Variables ..

// Functions ..
void welcomeMassageFun();
void screenViewFun();
void passwordFun();
void viewBalanceFun();
void depositFun();
void withdrawalFun();
void processesContainerFun();
// End Functions ..

int main()
{
    welcomeMassageFun();

    screenViewFun();
    passwordFun();
    processesContainerFun();

    return 0;
}

// Functions ..
// Welcome massage / Function.
void welcomeMassageFun()
{
    printf("\n\nYou welcome in Project 3 ( ATM ) ..\n\n");
}

// ATM screen view / Function.
void screenViewFun()
{
    printf("   .. ATM ..\n");
    printf("-------------------\n");
    printf("1 ) View Balance ..\n");
    printf("2 ) Deposit ..\n");
    printf("3 ) Withdraw ..\n");
    printf("4 ) Exit ..\n");
    printf("-------------------\n");
}

// Password / Function.
void passwordFun()
{
    int x = 0, i = 5;
    do
    {
        printf("Please enter your password: ");
        scanf("%d", &x);
        i--;

    } while (x != password && i > 0);
}

// View balance / Function.
void viewBalanceFun()
{
    printf("--------------------------\n");
    printf("your balance is: %d $\n", currentBalance);
    printf("--------------------------\n");
}

// Deposit / Function.
void depositFun()
{
    int x = 0;
    printf("\nPlease enter the amount you want to deposit: ");
    scanf("%d", &x);
    currentBalance += x;
    printf("\nThe deposit was successful.\n");
    viewBalanceFun();
}

// withdrawal / Function.
void withdrawalFun()
{
    int x = 0;
    printf("\nPlease enter the amount you want to withdrawal: ");
    scanf("%d", &x);
    if (x > currentBalance)
    {
        printf("\nMistake !!\n");
        viewBalanceFun();
    }
    else
    {
        currentBalance -= x;
        printf("\nThe withdrawal was successful.\n");
        viewBalanceFun();
    }
}

// processes container / Function.
void processesContainerFun()
{
    int x = 0;
    while (x != 4)
    {
        printf("\nPlease choose the operation you want to perform: ");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            viewBalanceFun();
            break;

        case 2:
            depositFun();
            break;

        case 3:
            withdrawalFun();
            break;
        }
    }
}

// End Functions ..
