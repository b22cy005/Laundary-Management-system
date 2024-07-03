#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for customer and laundry details
struct Customer {
    char name[50];
    int age;
    char contact[15];
    int laundryID;
};

struct Laundry {
    int laundryID;
    char type[50];
    char instructions[100];
    char status[20];
};

// Function prototypes
void enrollcustomer(struct Customer *customer);
void enterlogLaundry(struct Laundry *laundry);
void pleasetrackProgress(int laundryID);
void generateBill(int laundryID);
void offerFeedbackconcerning(int laundryID);
void storetheorderinarchive(int laundryID);

// Global variables
struct Customer customers[100]; // Assuming a maximum of 100 customers
struct Laundry laundryOrders[100]; // Assuming a maximum of 100 laundry orders
int customerCount = 0;
int laundryCount = 0;

int main() {
    int choice;
    do {
        // Display menu
        printf("\nLaundry Management System\n");
        printf("1. enroll Customer\n");
        printf("2. enter Log Laundry\n");
        printf("3. please Track Progress\n");
        printf("4. Generate Bill\n");
        printf("5. offer Feedback concerning\n");
        printf("6. store the Order in archive\n");
        printf("7. Exit\n");

        // User input
        printf("please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCustomer(&customers[customerCount]);
                customerCount++;
                break;
            case 2:
                logLaundry(&laundryOrders[laundryCount]);
                laundryCount++;
                break;
            case 3:
                printf(" please Enter Laundry ID: ");
                int trackID;
                scanf("%d", &trackID);
                trackProgress(trackID);
                break;
            case 4:
                printf(" please Enter Laundry ID: ");
                int billID;
                scanf("%d", &billID);
                generateBill(billID);
                break;
            case 5:
                printf(" please Enter Laundry ID: ");
                int feedbackID;
                scanf("%d", &feedbackID);
                giveFeedback(feedbackID);
                break;
            case 6:
                printf("please Enter Laundry ID: ");
                int archiveID;
                scanf("%d", &archiveID);
                archiveOrder(archiveID);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to register a new customer
void registerCustomer(struct Customer *customer) {
    printf("kindly write the name of the customer: ");
    scanf("%s", customer->name);
    printf("please fill out the field of customer age: ");
    scanf("%d", &customer->age);
    printf("please provide the customer contact number: ");
    scanf("%s", customer->contact);
    customer->laundryID = rand(); // Assign a random unique Laundry ID
    printf("Customer registered successfully. Your Laundry ID is: %d\n", customer->laundryID);
}

// Function to log a new laundry order
void logLaundry(struct Laundry *laundry) {
    printf("please Enter Laundry ID: ");
    scanf("%d", &laundry->laundryID);
    printf(" please Enter type of clothes: ");
    scanf("%s", laundry->type);
    printf("please Enter washing instructions: ");
    scanf("%s", laundry->instructions);
    strcpy(laundry->status, "Pending"); // Initial status is set to Pending
    printf("Laundry logged successfully.\n");
}

// Function to track the progress of a laundry order
void trackProgress(int laundryID) {
    for (int i = 0; i < laundryCount; i++) {
        if (laundryOrders[i].laundryID == laundryID) {
            printf("Laundry ID: %d\n", laundryOrders[i].laundryID);
            printf("Status: %s\n", laundryOrders[i].status);
            return;
        }
    }
    printf("Laundry ID not found.\n");
}

// Function to generate a bill for a laundry order
void generateBill(int laundryID) {
    for (int i = 0; i < laundryCount; i++) {
        if (laundryOrders[i].laundryID == laundryID) {
            // Calculate bill based on service type and quantity (assuming a fixed rate for simplicity)
            int billAmount = 10; // Replace with actual calculation
            printf("Bill for Laundry ID %d: Rupees=%d\n", laundryOrders[i].laundryID, billAmount);
            return;
        }
    }
    printf("Laundry ID not found.\n");
}

// Function to record feedback for a laundry order
void giveFeedback(int laundryID) {
    for (int i = 0; i < laundryCount; i++) {
        if (laundryOrders[i].laundryID == laundryID) {
            // Assuming feedback is a simple text input
            printf(" please Enter feedback for Laundry ID %d: ", laundryOrders[i].laundryID);
            scanf("%s", laundryOrders[i].status); // Using the status field to store feedback for simplicity
            printf("Feedback recorded successfully.\n");
            return;
        }
    }
    printf("Laundry ID not found.\n");
}

// Function to archive a completed laundry order
void archiveOrder(int laundryID) {
    for (int i = 0; i < laundryCount; i++) {
        if (laundryOrders[i].laundryID == laundryID && strcmp(laundryOrders[i].status, "Completed") == 0) {
            // Move the order details to an archive or perform necessary actions for archiving
            printf("Laundry ID %d archived successfully.\n", laundryOrders[i].laundryID);
            return;
        }
    }
    printf("Laundry ID not found or not completed yet.\n");
}
