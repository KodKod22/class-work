#include <stdio.h>
#include <string.h>
struct author {
char fName[12], lName[24];
};
struct date {
int month, year;
};
struct reprint {
int quantity;
struct date reprintDate;
};
struct book {
char title[80];
struct author *theAuthor;
float price;
int category;
int numberOfReprints;
struct reprint reprintList[20];
};
struct _AuthorDatabase
{
int numberOfAuthors;
struct author publisherAuthors[100];
} AuthorDatabase = { 3, {{"Amos", "Oz"}, {"Meir", "Shalev"}, {"Douglas", "Adams"}}
};
struct _BooksDatabase
{
int numberOfBooks;
struct book publisherBooks[1000];
} BooksDatabase = { 6, {{"black box", &AuthorDatabase.publisherAuthors[0], 75.25, 4, 0},
{"roman russi", &AuthorDatabase.publisherAuthors[1], 54.55, 4, 0},
{"fontenella", &AuthorDatabase.publisherAuthors[1], 72.00, 4, 0},
{"the hitch hikers guide to the universe", &AuthorDatabase.publisherAuthors[2], 35.50, 6, 0},
{"judas", &AuthorDatabase.publisherAuthors[0], 25.55, 4, 0},
{"thanks for all the fish", &AuthorDatabase.publisherAuthors[2], 52.00, 6, 0}
}
};
struct author inputAuthor(void)
{
struct author auth;
printf("First Name Last Name>");
scanf("%s %s", auth.fName, auth.lName);
return auth;
}
void addAuthor(void)
{
int nextAuth = AuthorDatabase.numberOfAuthors;
AuthorDatabase.publisherAuthors[nextAuth] = inputAuthor();
AuthorDatabase.numberOfAuthors++;
}
struct author *FindAuthor(void)
{
struct author auth;
auth = inputAuthor();
for (int i = 0; i < 100; ++i)
if ((strcmp(AuthorDatabase.publisherAuthors[i].fName, auth.fName) == 0) &&
(strcmp(AuthorDatabase.publisherAuthors[i].lName, auth.lName) == 0))
return &AuthorDatabase.publisherAuthors[i];
return NULL;
}
struct book inputBook(void)
{
struct book bk;
printf("Title>");
gets(bk.title);;
do
{
printf("\tAuthor :");
bk.theAuthor = FindAuthor();
if (bk.theAuthor == NULL)
printf("\tNo such Author\n");
} while (bk.theAuthor == NULL);
printf("\tPrice?>");
scanf("%f", &bk.price);
do
{
printf("\tCatagory (1-Suspense 2-Crime 3-Study 4-Novel 5-Mystery 6-SciFi)>");
scanf("%d", &bk.category);
} while (bk.category < 1 || bk.category > 6);
bk.numberOfReprints = 0;
return bk;
}
void addBook(void)
{
int nextBook = BooksDatabase.numberOfBooks;
BooksDatabase.publisherBooks[nextBook] = inputBook();
BooksDatabase.numberOfBooks++;
}
struct book *findBookByTitle(char *title)
{
for (int bkNum = 0; bkNum < BooksDatabase.numberOfBooks; ++bkNum)
if (strcmp(BooksDatabase.publisherBooks[bkNum].title, title) == 0)
return &BooksDatabase.publisherBooks[bkNum];
return NULL;
}
void addReprint(void)
{
char title[80];
int month, year, quant;
struct book *pBk;
do
{
printf("Book Title?>");
gets(title);
pBk = findBookByTitle(title);
} while (pBk == NULL);
printf("\tby %s %s\n", pBk->theAuthor->fName, pBk->theAuthor->lName);
printf("\tmm yyyy>");
scanf("%d %d", &month, &year);
printf("\tQuantity>");
scanf("%d", &quant);
int indx = pBk->numberOfReprints;
pBk->reprintList[indx].quantity = quant;
pBk->reprintList[indx].reprintDate.month = month;
pBk->reprintList[indx].reprintDate.year = year;
++pBk->numberOfReprints;
}
void ListAuthors(void)
{
for (int authNum = 0; authNum < AuthorDatabase.numberOfAuthors; ++authNum)
{
printf("%s %s\n", AuthorDatabase.publisherAuthors[authNum].fName,
AuthorDatabase.publisherAuthors[authNum].lName);
for (int bkNum = 0; bkNum < BooksDatabase.numberOfBooks; ++bkNum)
if (BooksDatabase.publisherBooks[bkNum].theAuthor == &AuthorDatabase.publisherAuthors[authNum])
printf("\t%s\n", BooksDatabase.publisherBooks[bkNum].title);
}
}
void ListBooks(void)
{
char *catagories[] = { "Suspense", "Crime", "Study", "Novel", "Mystery", "SciFi" };
for (int cat = 1; cat <= 6; ++cat)
{
printf("Catagory: %s\n", catagories[cat - 1]);
for (int bkNum = 0; bkNum < BooksDatabase.numberOfBooks; ++bkNum)
if (BooksDatabase.publisherBooks[bkNum].category == cat)
printf("\t%s\n", BooksDatabase.publisherBooks[bkNum].title);
printf("\n");
}
}
void ListReprints(void)
{
char *catagories[] = { "Suspense", "Crime", "Study", "Novel", "Mystery", "SciFi" };
for (int bkNum = 0; bkNum < BooksDatabase.numberOfBooks; ++bkNum)
{
struct book *pBk = &BooksDatabase.publisherBooks[bkNum];
printf("%s by %s %s [%s]\n", pBk->title, pBk->theAuthor->fName,pBk->theAuthor->lName,
catagories[pBk->category - 1]);
int totalSum = 0, totalBooks=0;
for (int reps = 0; reps < pBk->numberOfReprints; ++reps)
{
int turnaround = pBk->reprintList[reps].quantity*pBk->price;
printf("\t%02d/%04d %d books - Turnover:$%d\n", pBk->reprintList[reps].reprintDate.month,
pBk->reprintList[reps].reprintDate.year, pBk->reprintList[reps].quantity, turnaround);
totalSum += turnaround;
totalBooks += pBk->reprintList[reps].quantity;
}
printf("\t\tTotal: %d books $%d\n", totalBooks, totalSum);
}
}
int main(void)
{
int selection;
char c;
for (;;)
{
printf("\n\t\tMenu\n");
printf("1 - Add Author\t\t4 - List Authors\n2 - Add Book\t\t5 - List Books\n3 - Add Reprint\t\t6 - List Reprints\n");
printf("\t7 - End\tSelect==>");
scanf("%d", &selection);
c = getchar();
switch (selection)
{
case 1:
addAuthor();
break;
case 2:
addBook();
break;
case 3:
addReprint();
break;
case 4:
ListAuthors();
break;
case 5:
ListBooks();
break;
case 6:
ListReprints();
break;
case 7:
return 0;
}
}
} 
