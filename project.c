#include<stdio.h>
#include<string.h>
struct person
{
    char Fname[12],Lname[24];
    int id;
};
struct diposit
{
    int day1,mounth1,year1;
    double amount;
    char namedip[40];
};
struct widrowl
{
    int day2,mounth2,year2;
    double amount;
    char namewid[40];
};
struct bank_account
{
    char account_num[80];
    double balnce;
    struct person *owner;
    int numdiposit;
    int numwidrowl;
    struct diposit Dpositlis[250];
    struct widrowl widrowllist[750];
};
struct person_datebase
{
    int numofPerson;
    struct person owner_list[100];
}person_datebase= {3, {{"Amos", "Oz",123456789}, {"Meir", "Shalev",456789123}, {"Douglas", "Adams",987654321}} };
struct account_Database {
    int numberOfaccount;
    struct bank_account account_list[1000];
}account_Database= { 6,{
    {"123456",100.00, &person_datebase.owner_list[0],0, 0 , {}, {}},
    {"654321", 200.00, &person_datebase.owner_list[1], 0, 0, {}, {}},
    {"111111", 300.00, &person_datebase.owner_list[2], 0, 0, {}, {}},
    {"222222", 400.00, &person_datebase.owner_list[0], 0, 0, {}, {}},
    {"333333", 500.00, &person_datebase.owner_list[1], 0, 0, {}, {}},
    {"444444", 600.00, &person_datebase.owner_list[2], 0, 0, {}, {}},
}};
struct person inputperson(void)
{
    struct person auth;
    printf("enter first name last name id number>");
    scanf("%s %s %d", auth.Fname,auth.Lname,&auth.id);
    return auth;
};
void add_person(void){
    int nextauth = person_datebase.numofPerson;
    person_datebase.owner_list[nextauth]=inputperson();
    person_datebase.numofPerson++;
}
struct person *findperson(void)
{
    struct person auth;
    auth=inputperson();
    int i;
    for (i = 0; i < person_datebase.numofPerson; i++)
      if((strcmp(person_datebase.owner_list[i].Fname,auth.Fname)==0)&& (strcmp(person_datebase.owner_list[i].Lname,auth.Lname)==0))
        return &person_datebase.owner_list[i];
    return NULL;
};
struct bank_account inputaccount(void)
{
    struct bank_account ac;
    printf("account num>");
    scanf("%s",ac.account_num);
    do
    {
        printf("\tname person:");
        ac.owner=findperson();
        if (ac.owner==NULL)
        printf("\tno such person\n");
    } while (ac.owner==NULL);
        printf("\tbalnce?>");
        scanf("%lf",&ac.balnce);
        return ac;
};
void add_account(void){
    int nextaccount=account_Database.numberOfaccount;
    account_Database.account_list[nextaccount]=inputaccount();
    account_Database.numberOfaccount++;
}
struct bank_account* find_account(char* acct_num) {
for (int i = 0; i < account_Database.numberOfaccount; i++) {
if (strcmp(account_Database.account_list[i].account_num, acct_num) == 0) {
        return &account_Database.account_list[i];
    }
}
return NULL;
}
void make_diposit_or_widrol(void){
    struct bank_account *acct;
    char account_num[80];
    double new_balance;
    do
    {
        printf("enter account number:");
        scanf("%s",&account_num);
        acct=find_account(account_num);
        if (acct==NULL)
        printf("no such account exisit\n");
    } while (acct == NULL);
    int cohice;
    printf("1.deposits\n2.withdrawals\nEnter choice:");
    scanf("%d",&cohice);
    new_balance = acct->balnce;
    if (cohice == 1)
    {
        struct diposit diposit;
        printf("Enter deposit date (dd mm yyyy):");
        scanf("%d %d %d",&diposit.day1,&diposit.mounth1,&diposit.year1);
        printf("Enter deposit amount:");
        scanf("%lf", &diposit.amount);
        printf("enter diposit name:");
        scanf("%s",diposit.namedip);
        acct->Dpositlis[acct->numdiposit]=diposit;
        acct->numdiposit++;
        acct->balnce += diposit.amount;
        acct->balnce  = new_balance;
    }else if (cohice == 2)
    {
        struct widrowl widrowl;
        printf("Enter withdrawal date (dd mm yyyy):");
        scanf("%d %d %d",&widrowl.day2,&widrowl.mounth2,&widrowl.year2);
        printf("Enter withdrawal amount:");
        scanf("%lf",&widrowl.amount);
        printf("Enter withdrawer name:");
        scanf("%s",widrowl.namewid);
        acct->widrowllist[acct->numwidrowl] = widrowl;
        acct->numwidrowl++;
        acct->balnce -= widrowl.amount;
        acct->balnce  = new_balance;
    }
    
}
void list_account_bank(void){
for (int i = 0; i < account_Database.numberOfaccount; i++) {
printf("Account Number: %s\n", account_Database.account_list[i].account_num);
printf("\tOwner: %s %s", account_Database.account_list[i].owner->Fname,account_Database.account_list[i].owner->Lname);
printf("\tID:%d",account_Database.account_list[i].owner->id);
printf("\tBalance: $%.2lf\n", account_Database.account_list[i].balnce);
}
}
void list_diposit_or_widrol(void){
struct bank_account* acct;
char account_num[80];
do {
printf("Enter account number: ");
scanf("%s", account_num);
acct = find_account(account_num);
if (acct == NULL) printf("No such account exists\n");
} while (acct == NULL);
int choice;
printf("1. List deposits\n2. List withdrawals\nEnter choice: ");
scanf("%d", &choice);
if (choice == 1) {
    for (int i = 0; i < acct->numdiposit; i++) {
        printf("Deposit %d\n", i+1);
        printf("\tDate: %d/%d/%d\n", acct-> Dpositlis[i].day1, acct-> Dpositlis[i].mounth1, acct-> Dpositlis[i].year1);
        printf("\tAmount: $%.2lf\n", acct-> Dpositlis[i].amount);
        printf("\tDepositor: %s\n", acct-> Dpositlis[i].namedip);
    }
} else if (choice == 2) {
    for (int i = 0; i < acct->numwidrowl; i++) {
        printf("Withdrawal %d\n", i+1);
        printf("\tDate: %d/%d/%d\n", acct->widrowllist[i].day2, acct->widrowllist[i].mounth2, acct->widrowllist[i].year2);
        printf("\tAmount: $%.2lf\n", acct->widrowllist[i].amount);
        printf("\tWithdrawer: %s\n", acct->widrowllist[i].namewid);
    }
}
}
void print_bank_statement(void){
    char account_num[80];
    int start_day, start_month, start_year;
    int end_day, end_month, end_year;
    double new_balance;
    printf("Enter account number: ");
    scanf("%s", account_num);
    struct bank_account *acct = find_account(account_num);
    if (acct == NULL){
        printf("No such account found.\n");
        return;
    }
    printf("Enter start date (dd mm yyyy): ");
    scanf("%d %d %d", &start_day, &start_month, &start_year);
    printf("Enter end date (dd mm yyyy): ");
    scanf("%d %d %d", &end_day, &end_month, &end_year);
    printf("Account holder: %s %s %d\n", acct->owner->Fname, acct->owner->Lname,acct->owner->id);
    printf("Account number: %s\n", acct->account_num);
    printf("Period: %d/%d/%d to %d/%d/%d\n", start_day, start_month, start_year, end_day, end_month, end_year);
    printf("Opening balance as of %d/%d/%d: $%.2lf\n", start_day, start_month, start_year, acct->balnce);
    printf("\nDate\t\tDeposit\t\tWithdrawal\tClosing Balance\n");
    new_balance = acct->balnce;
for (int i = 0; i < acct->numdiposit; i++) {
    if (acct->Dpositlis[i].year1 < start_year || (acct->Dpositlis[i].year1 == start_year && acct->Dpositlis[i].mounth1 < start_month) || (acct->Dpositlis[i].year1 == start_year && acct->Dpositlis[i].mounth1 == start_month && acct->Dpositlis[i].day1 < start_day)) {
    continue;   
    }
    if (acct->Dpositlis[i].year1 > end_year || (acct->Dpositlis[i].year1 == end_year && acct->Dpositlis[i].mounth1 > end_month) || (acct->Dpositlis[i].year1 == end_year && acct->Dpositlis[i].mounth1 == end_month && acct->Dpositlis[i].day1 > end_day)) {
    continue;
    }
    printf("%d/%d/%d\t$%.2lf\t\t$%.2lf\n", acct->Dpositlis[i].day1, acct->Dpositlis[i].mounth1, acct->Dpositlis[i].year1, acct->Dpositlis[i].amount, new_balance);
    new_balance += acct->Dpositlis[i].amount;
}
    for (int i = 0; i < acct->numwidrowl; i++)
    {
     if(acct->widrowllist[i].year2<start_year||(acct->widrowllist[i].year2 == start_year && acct ->widrowllist[i].mounth2<start_month) || (acct->widrowllist[i].year2==start_year && acct->widrowllist[i].mounth2 == start_month && acct->widrowllist[i].day2<start_day)) {
        continue;
     }
     if(acct->widrowllist[i].year2 > end_year || (acct->widrowllist[i].year2 == end_year && acct->widrowllist[i].mounth2 > end_month) || (acct->widrowllist[i].year2 == end_year && acct->widrowllist[i].mounth2 == end_month && acct->widrowllist[i].day2 > end_day)) { 
        continue;
     }
     printf("%d/%d/%d\t\t\t$%.2lf\t\t\t$%.2lf\n", acct->widrowllist[i].day2, acct->widrowllist[i].mounth2, acct->widrowllist[i].year2, acct->widrowllist[i].amount, new_balance);
     new_balance -= acct->widrowllist[i].amount;
    }
}
int main(void){
    int selection;
    char c;
    for (;;)
    {
        printf("\n\t\t\tmenu\n");
        printf("1 - add person\t\t\t4 - list account bank\n2 - add account\t\t\t5 - list diposit or widrol\n3 - make diposit or widrol\t6 - print bank statement\n");
        printf("\t\t7-end\tselection==> ");
        printf("");
        scanf("%d",&selection);
        c=getchar();
        switch (selection)
        {
        case 1:
            add_person();
            break;
        case 2:
            add_account();
            break;
        case 3:
            make_diposit_or_widrol();
            break;
        case 4:
           list_account_bank();
            break;
        case 5:
            list_diposit_or_widrol();
        break;
        case 6:
            print_bank_statement();
        break;
        case 7:
        return 0;
        }
    }
}