#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 50

struct Contact {
    char name[100];
    char phone[15];
    char email[100];
};

int main()
{
    struct Contact contacts[MAX_CONTACTS];
    int count = 0, choice;

    do
    {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_CONTACTS)
            { 
                printf("Contact list full!\n"); 
            }
            else
            {
                printf("Enter Name: ");
                fgets(contacts[count].name, 100, stdin);
                int len = 0;
                while (contacts[count].name[len] != '\0' && contacts[count].name[len] != '\n') len++;
                contacts[count].name[len] = '\0';
                printf("Enter Phone: ");
                fgets(contacts[count].phone, 15, stdin);
                len = 0;
                while (contacts[count].phone[len] != '\0' && contacts[count].phone[len] != '\n') len++;
                contacts[count].phone[len] = '\0';
                printf("Enter Email: ");
                fgets(contacts[count].email, 100, stdin);
                len = 0;
                while (contacts[count].email[len] != '\0' && contacts[count].email[len] != '\n') len++;
                contacts[count].email[len] = '\0';
                count++;
                printf("Contact added!\n");
            }

        } 
        else if (choice == 2)
        {
            if (count == 0)
            { 
                printf("No contacts found.\n"); 
            }
            else
            {
                printf("\n%-5s %-25s %-15s %-30s\n", "No.", "Name", "Phone", "Email");
                printf("------------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++)
                {
                    printf("%-5d %-25s %-15s %-30s\n", i + 1,
                           contacts[i].name, contacts[i].phone, contacts[i].email);
                }
            }

        } 
        else if (choice == 3)
        {
            char search[100];
            printf("Enter name to search: ");
            fgets(search, 100, stdin);
            int len = 0;
            while (search[len] != '\0' && search[len] != '\n') len++;
            search[len] = '\0';
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (strstr(contacts[i].name, search) != NULL)
                {
                    printf("Name: %s | Phone: %s | Email: %s\n",
                           contacts[i].name, contacts[i].phone, contacts[i].email);
                    found = 1;
                }
            }
            if (!found) printf("No contact found with that name.\n");

        } 
        else if (choice == 4)
        {
            char delName[100];
            printf("Enter name to delete: ");
            fgets(delName, 100, stdin);
            int len = 0;
            while (delName[len] != '\0' && delName[len] != '\n') len++;
            delName[len] = '\0';
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (strcmp(contacts[i].name, delName) == 0)
                {
                    for (int j = i; j < count - 1; j++) contacts[j] = contacts[j + 1];
                    count--;
                    printf("Contact deleted.\n");
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Contact not found.\n");

        } 
        else if (choice == 5)
        {
            printf("Exiting Contact Management System.\n");
        } 
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
