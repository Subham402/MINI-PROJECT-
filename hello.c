#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 5  // Maximum confirmed tickets

// Structure for storing passenger information
struct Passenger {
    char name[50];
    int age;
    char gender[10];
};

// Global arrays for confirmed tickets and waiting list
struct Passenger confirmedList[MAX_TICKETS];
struct Passenger waitingList[100];
int confirmedCount = 0;
int waitingCount = 0;

// Function to book a ticket
void bookTicket() {
    struct Passenger p;
    
    printf("\nEnter Passenger Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf("%s", p.gender);

    if (confirmedCount < MAX_TICKETS) {
        confirmedList[confirmedCount++] = p;
        printf("Ticket confirmed for %s!\n", p.name);
    } else {
        waitingList[waitingCount++] = p;
        printf("No confirmed seats available. %s added to the waiting list.\n", p.name);
    }
}

// Function to cancel a ticket
void cancelTicket() {
    if (confirmedCount == 0) {
        printf("\nNo bookings to cancel.\n");
        return;
    }

    char name[50];
    printf("\nEnter the name of the passenger to cancel: ");
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < confirmedCount; ++i) {
        if (strcmp(confirmedList[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < confirmedCount - 1; ++j) {
                confirmedList[j] = confirmedList[j + 1];
            }
            confirmedCount--;
            printf("%s's ticket has been canceled.\n", name);

            // Move a passenger from the waiting list to confirmed list if available
            if (waitingCount > 0) {
                confirmedList[confirmedCount++] = waitingList[0];
                for (int k = 0; k < waitingCount - 1; ++k) {
                    waitingList[k] = waitingList[k + 1];
                }
                waitingCount--;
                printf("%s moved from waiting list to confirmed list.\n", confirmedList[confirmedCount - 1].name);
            }
            break;
        }
    }

    if (!found) {
        printf("Passenger not found in confirmed bookings.\n");
    }
}

// Function to view confirmed bookings
void viewConfirmed() {
    printf("\nConfirmed Bookings:\n");
    if (confirmedCount == 0) {
        printf("No confirmed tickets.\n");
        return;
    }
    for (int i = 0; i < confirmedCount; ++i) {
        printf("%d. %s | Age: %d | Gender: %s\n", i + 1, confirmedList[i].name, confirmedList[i].age, confirmedList[i].gender);
    }
}

// Function to view waiting list
void viewWaitingList() {
    printf("\nWaiting List:\n");
    if (waitingCount == 0) {
        printf("No passengers in waiting list.\n");
        return;
    }
    for (int i = 0; i < waitingCount; ++i) {
        printf("%d. %s | Age: %d | Gender: %s\n", i + 1, waitingList[i].name, waitingList[i].age, waitingList[i].gender);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n===== Railway Reservation System =====");
        printf("\n1. Book Ticket\n2. Cancel Ticket\n3. View Confirmed Bookings\n4. View Waiting List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                viewConfirmed();
                break;
            case 4:
                viewWaitingList();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 5  // Maximum confirmed tickets

// Structure for storing passenger information
struct Passenger {
    char name[50];
    int age;
    char gender[10];
};

// Global arrays for confirmed tickets and waiting list
struct Passenger confirmedList[MAX_TICKETS];
struct Passenger waitingList[100];
int confirmedCount = 0;
int waitingCount = 0;

// Function to book a ticket
void bookTicket() {
    struct Passenger p;
    
    printf("\nEnter Passenger Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf("%s", p.gender);

    if (confirmedCount < MAX_TICKETS) {
        confirmedList[confirmedCount++] = p;
        printf("Ticket confirmed for %s!\n", p.name);
    } else {
        waitingList[waitingCount++] = p;
        printf("No confirmed seats available. %s added to the waiting list.\n", p.name);
    }
}

// Function to cancel a ticket
void cancelTicket() {
    if (confirmedCount == 0) {
        printf("\nNo bookings to cancel.\n");
        return;
    }

    char name[50];
    printf("\nEnter the name of the passenger to cancel: ");
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < confirmedCount; ++i) {
        if (strcmp(confirmedList[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < confirmedCount - 1; ++j) {
                confirmedList[j] = confirmedList[j + 1];
            }
            confirmedCount--;
            printf("%s's ticket has been canceled.\n", name);

            // Move a passenger from the waiting list to confirmed list if available
            if (waitingCount > 0) {
                confirmedList[confirmedCount++] = waitingList[0];
                for (int k = 0; k < waitingCount - 1; ++k) {
                    waitingList[k] = waitingList[k + 1];
                }
                waitingCount--;
                printf("%s moved from waiting list to confirmed list.\n", confirmedList[confirmedCount - 1].name);
            }
            break;
        }
    }

    if (!found) {
        printf("Passenger not found in confirmed bookings.\n");
    }
}

// Function to view confirmed bookings
void viewConfirmed() {
    printf("\nConfirmed Bookings:\n");
    if (confirmedCount == 0) {
        printf("No confirmed tickets.\n");
        return;
    }
    for (int i = 0; i < confirmedCount; ++i) {
        printf("%d. %s | Age: %d | Gender: %s\n", i + 1, confirmedList[i].name, confirmedList[i].age, confirmedList[i].gender);
    }
}

// Function to view waiting list
void viewWaitingList() {
    printf("\nWaiting List:\n");
    if (waitingCount == 0) {
        printf("No passengers in waiting list.\n");
        return;
    }
    for (int i = 0; i < waitingCount; ++i) {
        printf("%d. %s | Age: %d | Gender: %s\n", i + 1, waitingList[i].name, waitingList[i].age, waitingList[i].gender);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n===== Railway Reservation System =====");
        printf("\n1. Book Ticket\n2. Cancel Ticket\n3. View Confirmed Bookings\n4. View Waiting List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                viewConfirmed();
                break;
            case 4:
                viewWaitingList();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}