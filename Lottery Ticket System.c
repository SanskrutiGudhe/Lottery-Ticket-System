#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
// Define constants
#define TICKET_LENGTH 6
#define MAX_NAME_LENGTH 100
// Function prototypes
void generateLotteryNumber(char* ticket);
void compareTickets(char* ticket1, char* ticket2);
void copyTicket(char* source, char* destination);
void displayTicketInfo(char* ticket, char* owner);
int isValidName(const char* name);
int isValidTicket(const char* ticket);
void concatenateTickets(char* ticket1, char* ticket2, char* result);
int main() {
    char lotteryTicket[TICKET_LENGTH + 1], userTicket[TICKET_LENGTH + 1];
    char userName[MAX_NAME_LENGTH], concatenatedTickets[MAX_NAME_LENGTH + TICKET_LENGTH + 1];
    // Seed random number generator
    srand(time(NULL));
    // Generate lottery ticket
    generateLotteryNumber(lotteryTicket);
    // Get user name
    while (1) {
        printf("Enter your name (letters only): ");
        fgets(userName, sizeof(userName), stdin);
        userName[strcspn(userName, "\n")] = 0; // Remove newline character
        if (isValidName(userName)) {
            break;
        } else {
            printf("Invalid name. Please use letters only.\n");
        }    }
    // Get user ticket
    while (1) {
        printf("Enter your lottery ticket (%d digits): ", TICKET_LENGTH);
        fgets(userTicket, sizeof(userTicket), stdin);
        userTicket[strcspn(userTicket, "\n")] = 0; // Remove newline character
        if (isValidTicket(userTicket)) {
            break;
        } else {
            printf("Invalid ticket. Please use numbers only.\n");
        }   }
  // Copy user ticket
    char winnerTicket[TICKET_LENGTH + 1];
    copyTicket(userTicket, winnerTicket);
    // Display ticket information
    displayTicketInfo(lotteryTicket, "Lottery");
    displayTicketInfo(userTicket, userName);
   // Compare tickets
    compareTickets(lotteryTicket, userTicket);
  // Concatenate user's name with ticket using strcat
    concatenatedTickets[0] = '\0'; // Initialize to empty string
    strcat(concatenatedTickets, userName);
    strcat(concatenatedTickets, userTicket);
      // Print the concatenated result
    printf("Concatenated ticket: %s\n", concatenatedTickets);
     // If not a winner, print the message
    if (strcmp(lotteryTicket, userTicket) != 0) {
        printf("Lottery not won.\n");
    }
    // Find length of tickets
    printf("Length of lottery ticket: %lu\n", strlen(lotteryTicket));
    printf("Length of user ticket: %lu\n", strlen(userTicket));
   return 0;
}// Function definitions
// Function to set a fixed winning lottery number
void generateLotteryNumber(char* ticket) {
    const char* fixedWinningNumber = "123456"; // Set your desired winning number here
    strcpy(ticket, fixedWinningNumber);
}
void compareTickets(char* ticket1, char* ticket2) {
    if (strcmp(ticket1, ticket2) == 0) {
        printf("You won! Your ticket matches the lottery ticket.\n");
    } else {
        printf("Sorry, your ticket does not match the lottery ticket.\n");
    }}
void copyTicket(char* source, char* destination) {
    strcpy(destination, source);
}
void displayTicketInfo(char* ticket, char* owner) {
    printf("%s's ticket: %s\n", owner, ticket);
}
int isValidName(const char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return 0; // Not a valid name
        }    }
    return 1; // Valid name
}
int isValidTicket(const char* ticket) {
    if (strlen(ticket) != TICKET_LENGTH) return 0; // Check length
    for (int i = 0; ticket[i] != '\0'; i++) {
        if (!isdigit(ticket[i])) {
            return 0; // Not a valid ticket
        }  }
    return 1; // Valid ticket
}
