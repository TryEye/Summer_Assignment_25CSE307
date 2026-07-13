#include <stdio.h>

#define MAX 100

int arr[MAX], n = 0;

void inputArray() 
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void displayArray() 
{
    if (n == 0)
    { 
        printf("Array is empty.\n"); return; 
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void findSumAverage() 
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    printf("Sum = %d, Average = %.2lf\n", sum, (double)sum / n);
}

void findLargestSmallest() 
{
    int large = arr[0], small = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > large) large = arr[i];
        if (arr[i] < small) small = arr[i];
    }
    printf("Largest = %d, Smallest = %d\n", large, small);
}

void reverseArray() 
{
    int l = 0, r = n - 1, temp;
    while (l < r)
    { 
        temp = arr[l]; arr[l] = arr[r]; arr[r] = temp; l++; r--; 
    }
    printf("Array reversed.\n");
    displayArray();
}

void bubbleSortArray() 
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            { 
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t; 
            }
    printf("Array sorted.\n");
    displayArray();
}

void linearSearch() 
{
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        { 
            printf("Found at index %d.\n", i); return; 
        }
    }
    printf("Element not found.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n===== Array Operations Menu =====\n");
        printf("1. Input Array\n");
        printf("2. Display Array\n");
        printf("3. Sum and Average\n");
        printf("4. Largest and Smallest\n");
        printf("5. Reverse Array\n");
        printf("6. Sort Array\n");
        printf("7. Linear Search\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: inputArray(); break;
            case 2: displayArray(); break;
            case 3: findSumAverage(); break;
            case 4: findLargestSmallest(); break;
            case 5: reverseArray(); break;
            case 6: bubbleSortArray(); break;
            case 7: linearSearch(); break;
            case 8: printf("Exiting Array Operations.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
