#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account
typedef struct {
    char account_number[20];
    char name[100];
    double balance;
} BankAccount;

// Function to create a new bank account
void createAccount(BankAccount *account) {
    printf("Enter account number: ");
    scanf("%s", account->account_number);
    printf("Enter account holder name: ");
    scanf("%s", account->name);
    account->balance = 0.0;
    printf("Account created successfully.\n");
}

// Function to deposit money into an account
void deposit(BankAccount *account) {
    double amount;
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);
    
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited %.2f into account %s.\n", amount, account->account_number);
    } else {
        printf("Invalid amount for deposit.\n");
    }
}

// Function to withdraw money from an account
void withdraw(BankAccount *account) {
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);
    
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrew %.2f from account %s.\n", amount, account->account_number);
    } else {
        printf("Insufficient balance.\n");
    }
}

// Function to view the account balance
void viewBalance(BankAccount *account) {
    printf("Account %s balance: %.2f\n", account->account_number, account->balance);
}

int main() {
    BankAccount account;
    int choice;
    
    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                withdraw(&account);
                break;
            case 4:
                viewBalance(&account);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
