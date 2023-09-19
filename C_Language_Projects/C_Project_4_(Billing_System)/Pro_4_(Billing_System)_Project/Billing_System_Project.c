

/* >>> Project 4 ( Billing System ) <<< */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Global Struct.
// 1 - Products
struct products
{
    char productName[50];
    int productNumber;
    int productPrice;
};
struct products sugar = {"sugar       ", 1, 15};
struct products rice = {"rice        ", 2, 25};
struct products oil = {"oil         ", 3, 40};
struct products spaghetti = {"spaghetti   ", 4, 20};
struct products juice = {"juice       ", 5, 10};
struct products apples = {"apples      ", 6, 15};
struct products bananas = {"bananas     ", 7, 20};
struct products strawberries = {"strawberries", 8, 25};
struct products pineapples = {"pineapples  ", 9, 35};
struct products mangos = {"mangos      ", 10, 50};

// ------------------------------------------------------------
// 2 - Billing
struct billing
{
    char userName[50];
    char userNumber[50];

    char productName[50][100];
    int productNumber[100];
    int productPrice[100];

    double total;
    double discount;
} bill;
// End Global Struct.

// Global Variable.
int productsCounter;
// End Global Variable.

// Functions ..
void welcomeMassageFun();
void productsViewScreenFun();
int buyingFun();
void userInfoFun();
void billingFun();

// End Functions ..

int main()
{
    welcomeMassageFun();

    productsViewScreenFun();
    buyingFun();
    userInfoFun();
    billingFun();

    return 0;
}

// Functions ..
// Welcome massage / Function.
void welcomeMassageFun()
{
    printf("\n\nYou welcome in Project 4 ( Billing System ) ..\n\n");
}

// Products view screen  / Function.
void productsViewScreenFun()
{
    printf("***************** Products *****************\n");
    printf("Pro-Number        Pro-Name         Pro-Price\n");
    printf("1)                  sugar               15 $\n");
    printf("2)                  rice                25 $\n");
    printf("3)                  oil                 40 $\n");
    printf("4)                  spaghetti           20 $\n");
    printf("5)                  juice               10 $\n");
    printf("6)                  apples              15 $\n");
    printf("7)                  bananas             20 $\n");
    printf("8)                  strawberries        25 $\n");
    printf("9)                  pineapples          35 $\n");
    printf("10)                 mangos              50 $\n");
    printf("********************************************\n");
}

// Buying / Function.
int buyingFun()
{
    int i = 0;
    productsCounter = 0;
    while (i <= 100)
    {
        int x = 0;
        printf("Please enter product number you need buying OR enter \"0\" for Exit: ");
        scanf("%d", &x);

        switch (x)
        {
        case 0:
            return 0;
            break;

        case 1:
            bill.productNumber[i] = sugar.productNumber;
            strcpy(bill.productName[i], sugar.productName);
            bill.productPrice[i] = sugar.productPrice;
            break;

        case 2:
            bill.productNumber[i] = rice.productNumber;
            strcpy(bill.productName[i], rice.productName);
            bill.productPrice[i] = rice.productPrice;
            break;

        case 3:
            bill.productNumber[i] = oil.productNumber;
            strcpy(bill.productName[i], oil.productName);
            bill.productPrice[i] = oil.productPrice;
            break;

        case 4:
            bill.productNumber[i] = spaghetti.productNumber;
            strcpy(bill.productName[i], spaghetti.productName);
            bill.productPrice[i] = spaghetti.productPrice;
            break;

        case 5:
            bill.productNumber[i] = juice.productNumber;
            strcpy(bill.productName[i], juice.productName);
            bill.productPrice[i] = juice.productPrice;
            break;

        case 6:
            bill.productNumber[i] = apples.productNumber;
            strcpy(bill.productName[i], apples.productName);
            bill.productPrice[i] = apples.productPrice;
            break;

        case 7:
            bill.productNumber[i] = bananas.productNumber;
            strcpy(bill.productName[i], bananas.productName);
            bill.productPrice[i] = bananas.productPrice;
            break;

        case 8:
            bill.productNumber[i] = strawberries.productNumber;
            strcpy(bill.productName[i], strawberries.productName);
            bill.productPrice[i] = strawberries.productPrice;
            break;

        case 9:
            bill.productNumber[i] = pineapples.productNumber;
            strcpy(bill.productName[i], pineapples.productName);
            bill.productPrice[i] = pineapples.productPrice;
            break;

        case 10:
            bill.productNumber[i] = mangos.productNumber;
            strcpy(bill.productName[i], mangos.productName);
            bill.productPrice[i] = mangos.productPrice;
            break;
        }
        productsCounter++;
        i++;
    }
}

// User info / Function.
void userInfoFun()
{
    printf("-----------------------\n");
    printf("Please enter your name: ");
    scanf("%s", bill.userName);
    printf("-----------------------\n");
    printf("Please enter your number: ");
    scanf("%s", bill.userNumber);
    printf("-----------------------\n\n");
}

// Billing / Function.
void billingFun()
{
    int total = 0;
    printf("********************* Billing *********************\n");
    printf("User-name                            User-number\n");
    printf("%s                                   %s\n", bill.userName, bill.userNumber);
    printf("---------------------------------------------------\n");
    printf("Pro-name         Pro-number               Pro-price\n");


    for (int i = 0; i < productsCounter; i++)
    {
        printf("%s          %d                          %d\n", bill.productName[i], bill.productNumber[i], bill.productPrice[i]);
        total += bill.productPrice[i];
    }

    
    printf("---------------------------------------------------\n");
    printf("Total                 =                         %d$\n", total);
    printf("---------------------------------------------------\n");
    printf("\n\n");
}

// End Functions ..
