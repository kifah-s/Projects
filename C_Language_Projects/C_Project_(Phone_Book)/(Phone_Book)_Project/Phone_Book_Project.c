

/* >>> Project 2 ( Phone Book ) <<< */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Functions ..
void welcomeMassageFun();
void titleFun();
void contactsCounterFun(FILE *contacts);
void readAllContactsFun(FILE *contacts);
void containerAddSearchUpdateDeleteFun(FILE *contacts, FILE *temporaryFile, char nameForSearch[50]);
void addContactFun(FILE *contacts);
void searchContactsFun(FILE *contacts, char nameForSearch[50]);
void updateContactsFun(FILE *contacts, FILE *temporaryFile, char nameForSearch[50]);
void deleteContactsFun(FILE *contacts, FILE *temporaryFile, char nameForSearch[50]);

int main()
{
    welcomeMassageFun();

    FILE *contacts, *temporaryFile;
    char nameForSearch[50];

    titleFun();
    contactsCounterFun(contacts);
    readAllContactsFun(contacts);
    containerAddSearchUpdateDeleteFun(contacts, temporaryFile, nameForSearch);

    return 0;
}

// Functions ..
// Welcome massage / Function.
void welcomeMassageFun()
{
    printf("\n\nYou welcome in Project 2 ( Phone Book ) ..\n\n");
}

// Title / Function.
void titleFun()
{
    printf(".. Phone Book ..\n\n");
}

// Contacts counter / Function.
void contactsCounterFun(FILE *contacts)
{
    char name[50], number[50];
    int contactsCounter = 0;
    contacts = fopen("contacts.txt", "r");
    for (; fscanf(contacts, "%s %*c %s", name, number) != EOF;)
    {
        // printf("%s : %s\n\n", name, number);
        contactsCounter++;
    }
    fclose(contacts);
    printf(".. %d contacts ..", contactsCounter);
    printf("\n\n");
}

// Read all contacts from file / Function.
void readAllContactsFun(FILE *contacts)
{
    printf("\n");
    char c;
    contacts = fopen("contacts.txt", "r");
    for (; fscanf(contacts, "%c", &c) != EOF;)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(contacts);

    /* contacts = fopen("contacts.txt", "r");
    while (fscanf(contacts, "%c", &c) != EOF)
    {
        printf("%c", c);
    }
    printf("\n\n");
    fclose(contacts); */
}

// Counter for Add, search, Update , and Delete / Function.
void containerAddSearchUpdateDeleteFun(FILE *contacts, FILE *temporaryFile, char nameForSearch[50])
{
    int select = 0;
    printf("---------------------------------------------------------------------\n");
    printf("( 1 / Add ) , ( 2 / Search ) , ( 3 / Update ) , ( 4 / Delete ) , ( Any Num / Just View)\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("Please select process number you need Implemented: ");
    scanf("%d", &select);

    if (select == 1) // Add contacts.
    {
        addContactFun(contacts);
        readAllContactsFun(contacts);
    }
    else if (select == 2) // Search contacts.
    {
        searchContactsFun(contacts, nameForSearch);
    }
    else if (select == 3) // Update contacts.
    {
        updateContactsFun(contacts, temporaryFile, nameForSearch);
        readAllContactsFun(contacts);
    }
    else if (select == 4) // Delete contacts.
    {
        deleteContactsFun(contacts, temporaryFile, nameForSearch);
        readAllContactsFun(contacts);
    }
    else // Just View
    {
        readAllContactsFun(contacts);
    }
}

// Add contact / Function.
void addContactFun(FILE *contacts)
{
    char name[50], number[50];
    printf("\nPlease enter name and number ( name - number ) : ");
    scanf("%s %s", name, number);

    contacts = fopen("contacts.txt", "a+");
    fprintf(contacts, "%s : %s\n", name, number);
    fclose(contacts);

    printf("\n");
}

// Search contacts / Function.
void searchContactsFun(FILE *contacts, char nameForSearch[50])
{
    char name[50], number[50];
    int counter = 0;
    printf("\nPlease enter name: ");
    scanf("%s", nameForSearch);

    contacts = fopen("contacts.txt", "r");

    for (; fscanf(contacts, "%s %*c %s", name, number) != EOF;)
    {
        if (strcmp(nameForSearch, name) == 0)
        {
            printf("\nFound: %s\n", name);
            printf("----------------------\n");
            printf("%s : %s\n", name, number);
            printf("----------------------\n");
            counter++;
            break;
        }
    }
    if (counter == 0)
    {
        printf("\nNot Found: %s\n\n", name);
    }
    fclose(contacts);
}

// Update contacts / Function.
void updateContactsFun(FILE *contacts, FILE *temporaryFile, char nameForSearch[50])
{
    searchContactsFun(contacts, nameForSearch);

    char name[50], number[50], updateName[50], updateNumber[50];

    printf("\nPlease enter the modifications you want to make on name and number: ");
    scanf("%s %s", updateName, updateNumber);

    contacts = fopen("contacts.txt", "r");
    temporaryFile = fopen("temporaryFile.txt", "w");
    for (; fscanf(contacts, "%s %*c %s", name, number) != EOF;)
    {
        if (strcmp(nameForSearch, name) == 0)
        {
            continue;
        }
        else
        {
            fprintf(temporaryFile, "%s : %s\n", name, number);
        }
    }
    fprintf(temporaryFile, "%s : %s\n", updateName, updateNumber);
    fclose(contacts);
    fclose(temporaryFile);

    remove("contacts.txt");
    rename("temporaryFile.txt", "contacts.txt");
}

// Delete contacts / Function.
void deleteContactsFun(FILE *contacts, FILE *temporaryFile, char nameForSearch[50])
{
    char name[50], number[50];

    printf("\nPlease enter the name you want to delete: ");
    scanf("%s", nameForSearch);

    contacts = fopen("contacts.txt", "r");
    temporaryFile = fopen("temporaryFile.txt", "w");
    for (; fscanf(contacts, "%s %*c %s", name, number) != EOF;)
    {
        if (strcmp(nameForSearch, name) == 0)
        {
            continue;
        }
        else
        {
            fprintf(temporaryFile, "%s : %s\n", name, number);
        }
    }
    fclose(contacts);
    fclose(temporaryFile);

    remove("contacts.txt");
    rename("temporaryFile.txt", "contacts.txt");

    printf("\n");
}