#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item 
{
    int    itemId;
    char   itemName[100];
    int    quantity;
    double price;
};

int count = 0;
struct Item inventory[MAX_ITEMS];

void addItem() 
{
    if (count >= MAX_ITEMS)
    { 
        printf("Inventory full!\n"); return; 
    }
    printf("Enter Item ID: ");
    scanf("%d", &inventory[count].itemId);
    getchar();
    printf("Enter Item Name: ");
    fgets(inventory[count].itemName, 100, stdin);
    int len = 0;
    while (inventory[count].itemName[len] != '\0' && inventory[count].itemName[len] != '\n') len++;
    inventory[count].itemName[len] = '\0';
    printf("Enter Quantity: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter Price per unit: Rs. ");
    scanf("%lf", &inventory[count].price);
    getchar();
    count++;
    printf("Item added successfully!\n");
}

void displayAll() 
{
    if (count == 0)
    { 
        printf("Inventory is empty.\n"); return; 
    }
    printf("\n%-6s %-25s %-10s %-12s %-12s\n", "ID", "Name", "Quantity", "Price", "Total Value");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-6d %-25s %-10d Rs. %-8.2lf Rs. %.2lf\n",
               inventory[i].itemId, inventory[i].itemName, inventory[i].quantity,
               inventory[i].price, inventory[i].quantity * inventory[i].price);
    }
}

void updateQuantity() 
{
    int id; printf("Enter Item ID to update: "); scanf("%d", &id); getchar();
    for (int i = 0; i < count; i++)
    {
        if (inventory[i].itemId == id)
        {
            printf("Current quantity: %d\nEnter new quantity: ", inventory[i].quantity);
            scanf("%d", &inventory[i].quantity); getchar();
            printf("Quantity updated.\n");
            return;
        }
    }
    printf("Item ID %d not found.\n", id);
}

void searchItem() 
{
    char name[100];
    printf("Enter item name to search: ");
    fgets(name, 100, stdin);
    int len = 0;
    while (name[len] != '\0' && name[len] != '\n') len++;
    name[len] = '\0';
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strstr(inventory[i].itemName, name) != NULL)
        {
            printf("Found: ID=%d, Name=%s, Qty=%d, Price=Rs.%.2lf\n",
                   inventory[i].itemId, inventory[i].itemName,
                   inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) printf("Item not found.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Update Item Quantity\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addItem(); break;
            case 2: displayAll(); break;
            case 3: updateQuantity(); break;
            case 4: searchItem(); break;
            case 5: printf("Exiting Inventory System.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
