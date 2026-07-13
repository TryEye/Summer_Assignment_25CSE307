#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 10

struct Ticket 
{
    int    seatNo;
    char   passengerName[100];
    char   destination[80];
    double price;
    int    isBooked;
};

int main()
{
    struct Ticket seats[TOTAL_SEATS];
    int choice;
    char destinations[3][30] = {"Delhi", "Mumbai", "Kolkata"};
    double prices[3]         = {800.0, 1200.0, 1500.0};

    
    for (int i = 0; i < TOTAL_SEATS; i++)
    {
        seats[i].seatNo   = i + 1;
        seats[i].isBooked = 0;
    }
    do
    {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Available Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View Booked Tickets\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            printf("\nAvailable Seats: ");
            int avail = 0;
            for (int i = 0; i < TOTAL_SEATS; i++)

            {
                if (!seats[i].isBooked)
                { 
                    printf("%d ", seats[i].seatNo); avail++; 
                }
            }
            if (!avail) printf("None");
            printf("\n");

        } 
        else if (choice == 2)
        {
            int seatNo;
            printf("Enter seat number (1-%d): ", TOTAL_SEATS);
            scanf("%d", &seatNo);
            getchar();
            if (seatNo < 1 || seatNo > TOTAL_SEATS)
            { 
                printf("Invalid seat number.\n"); 
            }
            else if (seats[seatNo - 1].isBooked)
            { 
                printf("Seat %d is already booked!\n", seatNo); 
            }
            else
            {
                printf("Enter Passenger Name: ");
                fgets(seats[seatNo - 1].passengerName, 100, stdin);
                int len = 0;
                while (seats[seatNo - 1].passengerName[len] != '\0' && seats[seatNo - 1].passengerName[len] != '\n') len++;
                seats[seatNo - 1].passengerName[len] = '\0';
                printf("Select Destination:\n");
                for (int i = 0; i < 3; i++) printf("%d. %s (Rs. %.0lf)\n", i + 1, destinations[i], prices[i]);
                int dest; scanf("%d", &dest); getchar();
                if (dest < 1 || dest > 3)
                { 
                    printf("Invalid destination.\n"); 
                }
                else
                {
                    strcpy(seats[seatNo - 1].destination, destinations[dest - 1]);
                    seats[seatNo - 1].price    = prices[dest - 1];
                    seats[seatNo - 1].isBooked = 1;
                    printf("Seat %d booked for %s to %s. Amount: Rs. %.0lf\n",
                           seatNo, seats[seatNo - 1].passengerName,
                           seats[seatNo - 1].destination, seats[seatNo - 1].price);
                }
            }

        } 
        else if (choice == 3)
        {
            int seatNo;
            printf("Enter seat number to cancel: ");
            scanf("%d", &seatNo);
            getchar();
            if (seatNo < 1 || seatNo > TOTAL_SEATS) printf("Invalid seat.\n");
            else if (!seats[seatNo - 1].isBooked) printf("Seat %d is not booked!\n", seatNo);
            else
            {
                seats[seatNo - 1].isBooked = 0;
                printf("Seat %d cancelled successfully.\n", seatNo);
            }

        } 
                else if (choice == 4)
        {
            printf("\n%-6s %-25s %-15s %-10s\n", "Seat", "Passenger", "Destination", "Price");
            printf("-------------------------------------------------------\n");
            int anyBooked = 0;
            for (int i = 0; i < TOTAL_SEATS; i++)
            {
                if (seats[i].isBooked)
                {
                    printf("%-6d %-25s %-15s Rs. %.0lf\n", seats[i].seatNo,
                           seats[i].passengerName, seats[i].destination, seats[i].price);
                    anyBooked = 1;
                }
            }
            if (!anyBooked) printf("No tickets booked.\n");

        } 
        else if (choice == 5)
        {
            printf("Thank you for using Ticket Booking System!\n");
        } 
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
