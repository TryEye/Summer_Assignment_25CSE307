#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book 
{
    int  bookId;
    char title[100];
    char author[80];
    int  isIssued;
};

int main()
{
    struct Book library[MAX_BOOKS];
    int count = 0, choice;

    do
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Search Book by Title\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_BOOKS)
            {
                printf("Library full!\n");
            } 
            else
            {
                printf("Enter Book ID: ");
                scanf("%d", &library[count].bookId);
                getchar();
                printf("Enter Title: ");
                fgets(library[count].title, 100, stdin);
                int len = 0;
                while (library[count].title[len] != '\0' && library[count].title[len] != '\n') len++;
                library[count].title[len] = '\0';
                printf("Enter Author: ");
                fgets(library[count].author, 80, stdin);
                len = 0;
                while (library[count].author[len] != '\0' && library[count].author[len] != '\n') len++;
                library[count].author[len] = '\0';
                library[count].isIssued = 0;
                count++;
                printf("Book added successfully!\n");
            }

        } 
        else if (choice == 2)
        {
            if (count == 0)
            { 
                printf("No books available.\n"); 
            }
            else
            {
                printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
                printf("----------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++)
                {
                    printf("%-5d %-30s %-20s %-10s\n", library[i].bookId,
                           library[i].title, library[i].author,
                           library[i].isIssued ? "Issued" : "Available");
                }
            }

        } 
        else if (choice == 3)
        {
            int id; printf("Enter Book ID to issue: "); scanf("%d", &id); getchar();
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (library[i].bookId == id)
                {
                    found = 1;
                    if (library[i].isIssued) printf("Book already issued!\n");
                    else
                    { 
                        library[i].isIssued = 1; printf("Book issued successfully!\n"); 
                    }
                    break;
                }
            }
            if (!found) printf("Book ID %d not found.\n", id);

        } 
        else if (choice == 4)
        {
            int id; printf("Enter Book ID to return: "); scanf("%d", &id); getchar();
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (library[i].bookId == id)
                {
                    found = 1;
                    if (!library[i].isIssued) printf("Book was not issued!\n");
                    else
                    { 
                        library[i].isIssued = 0; printf("Book returned successfully!\n"); 
                    }
                    break;
                }
            }
            if (!found) printf("Book ID %d not found.\n", id);

        } 
        else if (choice == 5)
        {
            char search[100];
            printf("Enter title to search: ");
            fgets(search, 100, stdin);
            int len = 0;
            while (search[len] != '\0' && search[len] != '\n') len++;
            search[len] = '\0';
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (strstr(library[i].title, search) != NULL)
                {
                    printf("Found: ID=%d, Title=%s, Author=%s, Status=%s\n",
                           library[i].bookId, library[i].title, library[i].author,
                           library[i].isIssued ? "Issued" : "Available");
                    found = 1;
                }
            }
            if (!found) printf("No book with that title found.\n");

        } 
        else if (choice == 6)
        {
            printf("Exiting Library Management System.\n");
        } 
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
