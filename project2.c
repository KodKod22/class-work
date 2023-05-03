#include<stdio.h>
#include<string.h>
struct date{
    int day;
    int month;
    int year;
};
struct action
{
    struct date actiondate;
    float amount;
    char text[40];
    
};

struct bank
{
    struct customer *cust;
    int banknum;
    int numofhafkdot;
    int numofmshihot;
    float balance;
    struct action hafkdotlist[250];
    struct action mshihotlist[750];
};

struct customer
{
    char fname[30];
    char lname[30];
    int id;
    struct bank banklist[25];
};

struct _customerdatabase
{
    int numofcustomers;
    struct customer customerlist[100];
} customerdatabase = {2, {{"fawzi","noufal", 12345},{"wesam","yassin",54321}}};

struct _bankdatabase{
    int numberofbanks;
    struct bank banklist[2500];
} bankdatabase = {3,{
{&customerdatabase.customerlist[0] ,1,0,0,0},
{&customerdatabase.customerlist[0] ,2,0,0,0},
{&customerdatabase.customerlist[1] ,3,0,0,0}
}};

struct customer inputcustomer(void)
{
    struct customer newcustomer;
    printf("Enter First Name and last name");
    scanf("%s %s", &newcustomer.fname, &newcustomer.lname);
    printf("Enter ID:");
    scanf("%d",&newcustomer.id);
    return newcustomer;
}

void addcustomer(void){
    int nextcustomer= customerdatabase.numofcustomers;
    customerdatabase.customerlist[nextcustomer]=inputcustomer();
    customerdatabase.numofcustomers++;
}

struct customer* findcustomer(void)
{
struct customer cust;
cust=inputcustomer();
for(int i=0;i<100;++i)
    {
        if(customerdatabase.customerlist[i].id==cust.id)
        return &customerdatabase.customerlist[i];
    }
    return NULL;
}

struct bank inputbank(void)
{
    struct bank bk;
    do{
        printf("ID: ");
        scanf("%d",bk);
        bk.cust=findcustomer();
        if(bk.cust==NULL)
            printf("No such Customer");
    } while (bk.cust==NULL);
    bk.balance=0;
    bk.numofhafkdot=0;
    bk.numofmshihot=0;
    bk.banknum=bankdatabase.numberofbanks;
    return bk;
} 
void addbank(void){
    int nextbank=bankdatabase.numberofbanks;
    bankdatabase.banklist[nextbank]=inputbank();
    bankdatabase.numberofbanks++;
}

struct bank* findbankbynum(int banknum){
    for (int i = 0; i < bankdatabase.numberofbanks; i++)
    {
        if (banknum==bankdatabase.banklist[i].banknum)
        {
            return &bankdatabase.banklist[i];
        }
    }
return NULL;
    
}

void addaction(void){
    char atext[40];
    int day, month, year;
    float amount;
    int banknum;
    struct bank *pbk;
    do {
        printf("bank number:");
        scanf("%d",&banknum);
        pbk=findbankbynum(banknum);
        
    } while (pbk==NULL);
    printf("enter dd mm yyyy:");
    scanf("%d %d %d", &day,&month,&year);
    printf("amount: ");
    scanf("%f", &amount);
    if(amount>0){
        printf("enter your name:");
        scanf("%s",atext);
        int index=pbk->numofhafkdot;
        pbk->hafkdotlist[index].amount=amount;
        pbk->balance=pbk->balance+amount;
        pbk->hafkdotlist[index].actiondate.day=day;
        pbk->hafkdotlist[index].actiondate.month=month;
        pbk->hafkdotlist[index].actiondate.year=year;
        strcpy(pbk->hafkdotlist[index].text,atext);
        ++pbk-> numofhafkdot;
    }
    else
    {
        printf("enter mahot mishikha:");
        scanf("%s",atext);
        int index=pbk->numofmshihot;
        pbk->mshihotlist[index].amount=amount;
        pbk->balance=pbk->balance+amount;
        pbk->mshihotlist[index].actiondate.day=day;
        pbk->mshihotlist[index].actiondate.month=month;
        pbk->mshihotlist[index].actiondate.year=year;
        strcpy(pbk->mshihotlist[index].text,atext);
        ++pbk-> numofmshihot;

    }
}


void listcustomer(void){
    
    for (int  i= 0; i < customerdatabase.numofcustomers; ++i)
    {
        printf("%s %s \n", customerdatabase.customerlist[i].fname ,customerdatabase.customerlist[i].lname);
        for ( int j = 0; j < bankdatabase.numberofbanks; ++j)
        {
            if (bankdatabase.banklist[j].cust->fname==customerdatabase.customerlist[i].fname)
            {
                printf("%d %f \n",bankdatabase.banklist[j].banknum,bankdatabase.banklist[j].balance);
            }   
        }   
    }
}
int datecmp(int d1,int m1,int y1,int d2,int m2,int y2){
    if(y1<y2){
        return y1;
    }
    else if (y1>y2)
    {
        return y2;
    }
    else if (m1<m2)
    {
        return m1;
    }
    else if (m1>m2)
    {
        return m2;
    }
    else if (d1<d2)
    {
        return d1;
    }
    else if (d1>d2)
    {
        return d2;
    }
    else
    {
        return 0;
    }
}

void listaction(int banknum){
    struct bank* bk;
    bk=findbankbynum(banknum);
    int i=0;
    int j=0;
    while(i<bk->numofhafkdot)
    {
        while(j<bk->numofmshihot)
        {
            if(datecmp(bk->hafkdotlist[i].actiondate.day,bk->hafkdotlist[i].actiondate.month,bk->hafkdotlist[i].actiondate.year,bk->mshihotlist[j].actiondate.day,bk->mshihotlist[j].actiondate.month,bk->mshihotlist[j].actiondate.year)<0)
            {
            printf("%d %d %d %s %f\n ", bk->hafkdotlist[i].actiondate.day,bk->hafkdotlist[i].actiondate.month,bk->hafkdotlist[i].actiondate.year, bk->hafkdotlist[i].text,bk->hafkdotlist[i].amount);
            i++;
            }
            else
            {
             printf("%d %d %d %s %f\n ", bk->mshihotlist[i].actiondate.day,bk->mshihotlist[i].actiondate.month,bk->mshihotlist[i].actiondate.year, bk->mshihotlist[i].text,bk->mshihotlist[i].amount);
             j++;
            }
        }
    }
  
}


int main()    
{
    addaction();
    addaction();
    printf("----------\n");
    listcustomer();
    printf("----------\n");
    listaction(2);
    listaction(1);
    return 0;
}
