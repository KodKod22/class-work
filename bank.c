#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max_People 100
#define Max_Accounts 250
#define Max_Deposits 250
#define Max_Widthraws 750

struct person
{
    char firstName [40];
    char lastName [40];
    int ID;
};
struct account 
{
    struct person *owner;
    int accountNumber;
    float balance;

};
struct date
{
    int day, month, year;
};
struct deposit
{
    int accountNumber;
    struct date depositDate;
    float amount; // צריך בהדפסה לוודא דיוק של 2 מספרים אחרי הנק
    char depositorName[40];
};
struct widthraw
{
    int accountNumber;
    struct date widthrawDate ;
    float amount;
    char reason[40];
};
struct people *people [Max_People];
struct account *accounts[Max_Accounts];
struct deposit *deposits[Max_Deposits];
struct widthraw *widthraws[Max_Widthraws];

int numPeople = 0;
int numAccounts = 0;
int numDeposits = 0;
int numWidthraws = 0;
void addNewPerson ()
{
    int newID;
    char first[40];
    char last[40];
    struct person *people[Max_People];
    printf ("enter ID: ");
    scanf ("%d", &newID);
    if (newID > 999999999 )
    {
        printf ("ID should have less then 9 digits \n");
        return;
    }
    for (int i=0; i<numPeople ;i++)
    {
        if (people[i]->ID == newID)
        {
            printf ("ID already in use, enter new ID");
            scanf ("%d", &newID);
            i=-1;
        }
    }
    struct person *newOwner = malloc (sizeof(struct person));
    newOwner->ID = newID;
    printf ("enter first and last name: ");
    scanf ("%s %s", first, last);
    strcpy (newOwner->firstName, first);
    strcpy (newOwner->lastName, last);
    numPeople++;
}
void newAccount()
{
    int ID;
    printf("Enter your ID");
    scanf("%d", &ID);

    struct person *people = malloc(numPeople * sizeof(struct person));
    struct person *owner = NULL;

    for (int i=0; i<numPeople; i++)
    {
        if(people[i].ID == ID)
        {
            owner = &people[i];
            break;
        }
    }

    if (owner == NULL)
    {
        printf ("person not found with ID %d", ID);
        free(people);
        return;
    }

    accounts[numAccounts] = malloc(sizeof(struct account));
    accounts[numAccounts]->owner = owner;
    accounts[numAccounts]->accountNumber = numAccounts+1;
    accounts[numAccounts]->balance = 0.00;
    numAccounts++;

    free(people);
}

void addWidthraw()
{
    int accountNum;
    int i=0;
    printf("Enter your account number: ");
    scanf("%d",&accountNum);
    bool accountExists = false;
    while (!accountExists && i<numAccounts)
    {
        if (accounts[i]->accountNumber == accountNum)
        {
            accountExists = true;
        }
        else
        {   
            i++;
        }
    }
    if (!accountExists)
    {
        printf ("The Account doesn't exist\n");
        return;
    }
    struct widthraw *w = malloc(sizeof(struct widthraw));
    float amount;
    char reason [40];
    printf ("Enter amount of money: ");
    scanf ("%f", &amount);
    if (accounts[i]->balance < amount)
    {
        printf("not enough money\n");
        return;
    }
    printf ("Enter reason:");
    scanf ("%39s", reason);
    struct date widthrawDate;
    printf ("Enter date: dd.mm.yy ");
    scanf ("%d %d %d", &widthrawDate.day, &widthrawDate.month, &widthrawDate.year);
    w->accountNumber = accountNum;
    strcpy(w->reason, reason); 
    w->amount = amount;
    accounts[i]->balance -= amount ;
    numWidthraws++;
}
void addDeposit()
{
    int accountNum;
    int i=0;
    printf("Enter your account number");
    scanf("%d",&accountNum);
    bool accountExists = false;
    while (!accountExists && i<numAccounts)
    {
        if (accounts[i]->accountNumber == accountNum)
        {
            accountExists = true;
        }
        else
        {   
            i++;
        }
    }
    if (!accountExists)
    {
        printf ("The Account doesn't exist");
        return;
    }
    float amount;
    printf ("Enter amount of money: ");
    scanf ("%f", &amount);
    accounts[i]->balance += amount;
    struct date depositDate;
    printf ("Enter date: dd.mm.yy ");
    scanf ("%d %d %d", &depositDate.day, &depositDate.month, &depositDate.year);
    char depositor[40];
    printf ("Enter depositor name: ");
    scanf ("%39s", depositor);
    deposits[numDeposits] = malloc(sizeof(struct deposit));
    deposits[numDeposits]->accountNumber = accountNum;
    strcpy(deposits[numDeposits]->depositorName,depositor); 
    deposits[numDeposits]->amount = amount;
    deposits[numDeposits]->depositDate = depositDate;
    numDeposits++;
}
void listOfCustumers()
{
    if (numAccounts == 0)
    {
        printf ("No accounts found.\n");
        return;
    }
    for( int i=0; i<numPeople; i++) 
    {
        printf ("Account number: %d  First and Last Name of the owner: %s %s  Balance: %.2f\n", accounts[i]->accountNumber, accounts[i]->owner->firstName, accounts[i]->owner->lastName, accounts[i]->balance);
    }
}
void listOfAcc()
{
    if (numAccounts == 0)
    {
        printf ("No accounts found.\n");
        return;
    }
    for( int i=0; i<numPeople; i++) 
    {
        printf ("Account number: %d\n", accounts[i]->accountNumber);
        printf ("First and Last Name of the owner: %s %s\n",accounts[i]->owner->firstName, accounts[i]->owner->lastName);
        printf ("Balance: %.2f\n", accounts[i]->balance);
        printf ("Deposits: \n");
        for (int j=0; j<numDeposits; j++) 
        {
            if(deposits[j]->accountNumber == accounts[i]->accountNumber)
            {
                printf("\t Date: %02d.%02d.%02d, Amount: %.2f\n", deposits[j]->depositDate.day, deposits[j]->depositDate.month, deposits[j]->depositDate.year, deposits[j]->amount);
            }
        }
        printf ("Widhrawals:\n");
        for (int j=0; j<numWidthraws; j++)
        {
            if (widthraws[j]->accountNumber == accounts[i]->accountNumber)
            {
                printf ("\t Date: %02d.%02d.%02d, Amount: %.2f\n", widthraws[j]->widthrawDate.day, widthraws[j]->widthrawDate.month, widthraws[j]->widthrawDate.year, widthraws[j]->amount);
            }
        }
    
    printf ("\n");
    }
}
int main ()
{
    int selection;
    printf ("\t\t\tmenu\n");
    printf ("1- add new person\t\t\t 2- add a bank account\t\t\t\n");
    printf ("3- a widthraw\t\t\t\t 4- a deposit\t\t\t\n");
    printf ("5- produce list of bank costumer\t 6- Produce of an account sheet\t\t\t\n");
    printf ("\t\t selection: ");
    scanf("%d",&selection);
    switch (selection)
    {
        case 1:
            addNewPerson();
            break;
        case 2:
            newAccount();
            break;
        case 3:
            addWidthraw();
            break;
        case 4:
            addDeposit();
            break;
        case 5:
            listOfCustumers();
            break;
        case 6:
            listOfAcc();
            break;
        default:
            return 0;
    }
}


