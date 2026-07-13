#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

char bookTitles[MAX_BOOKS][100];
char bookAuthors[MAX_BOOKS][80];
int  bookIds[MAX_BOOKS];
int  isIssued[MAX_BOOKS];
char issuedTo[MAX_BOOKS][100];
int  bookCount = 0;

void addBook() 
{
    if (bookCount >= MAX_BOOKS)
    { 
        printf("Library full!\n"); return; 
    }
    int i = bookCount;
    printf("Enter Book ID: ");
    scanf("%d", &bookIds[i]);
    getchar();
    printf("Enter Title: ");
    fgets(bookTitles[i], 100, stdin);
    int len = 0;
    while (bookTitles[i][len] != '\0' && bookTitles[i][len] != '\n') len++;
    bookTitles[i][len] = '\0';
    printf("Enter Author: ");
    fgets(bookAuthors[i], 80, stdin);
    len = 0;
    while (bookAuthors[i][len] != '\0' && bookAuthors[i][len] != '\n') len++;
    bookAuthors[i][len] = '\0';
    isIssued[i] = 0;
    issuedTo[i][0] = '\0';
    bookCount++;
    printf("Book added!\n");
}

void listBooks() 
{
    if (bookCount == 0)
    { 
        printf("No books.\n"); return; 
    }
    printf("\n%-5s %-30s %-20s %-15s\n", "ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("%-5d %-30s %-20s %-15s\n", bookIds[i], bookTitles[i], bookAuthors[i],
               isIssued[i] ? "Issued" : "Available");
    }
}

void issueBook() 
{
    int id; printf("Enter Book ID: "); scanf("%d", &id); getchar();
    for (int i = 0; i < bookCount; i++)
    {
        if (bookIds[i] == id)
        {
            if (isIssued[i])
            { 
                printf("Book already issued to: %s\n", issuedTo[i]); return; 
            }
            printf("Enter borrower name: ");
            fgets(issuedTo[i], 100, stdin);
            int len = 0;
            while (issuedTo[i][len] != '\0' && issuedTo[i][len] != '\n') len++;
            issuedTo[i][len] = '\0';
            isIssued[i] = 1;
            printf("Book issued to %s.\n", issuedTo[i]);
            return;
        }
    }
    printf("Book ID not found.\n");
}

void returnBook() 
{
    int id; printf("Enter Book ID: "); scanf("%d", &id); getchar();
    for (int i = 0; i < bookCount; i++)

    {
        if (bookIds[i] == id)

        {
            if (!isIssued[i])
            { 
                printf("Book is already in library.\n"); return; 
            }
            printf("Book returned by %s.\n", issuedTo[i]);
            isIssued[i] = 0;
            issuedTo[i][0] = '\0';
            return;
        }
    }
    printf("Book ID not found.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n===== Mini Library System =====\n");
        printf("1. Add Book\n");
        printf("2. List All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: printf("Exiting Mini Library System.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
