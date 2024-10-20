#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;
    vector<string> transactionHistory;  // Stores history of transactions

public:
    // Constructor
    BankAccount(const string& accNum, const string& holder, double initialBalance) 
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {
        transactionHistory.push_back("Account created with balance: $" + to_string(initialBalance));
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
        transactionHistory.push_back("Deposited: $" + to_string(amount));
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            transactionHistory.push_back("Attempted withdrawal of: $" + to_string(amount) + " (Failed: Insufficient balance)");
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
            transactionHistory.push_back("Withdrew: $" + to_string(amount));
        }
    }

    // Display account balance
    void displayBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    // View transaction history
    void viewTransactionHistory() const {
        cout << "Transaction History for " << accountHolder << " (" << accountNumber << "):" << endl;
        for (const string& transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }
};

// Main function with user input
int main() {
    string accountNumber, accountHolder;
    double initialBalance;

    // Get user input for account details
    cout << "Enter account number: ";
    getline(cin, accountNumber);  // Use getline for string input to handle spaces
    cout << "Enter account holder name: ";
    getline(cin, accountHolder);
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    // Create a bank account using user input
    BankAccount myAccount(accountNumber, accountHolder, initialBalance);

    // Perform operations
    int choice;
    do {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. View Balance\n2. Deposit\n3. Withdraw\n4. View Transaction History\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                myAccount.displayBalance();
                break;
            }
            case 2: {
                double depositAmount;
                cout << "Enter deposit amount: $";
                cin >> depositAmount;
                myAccount.deposit(depositAmount);
                break;
            }
            case 3: {
                double withdrawalAmount;
                cout << "Enter withdrawal amount: $";
                cin >> withdrawalAmount;
                myAccount.withdraw(withdrawalAmount);
                break;
            }
            case 4: {
                myAccount.viewTransactionHistory();
                break;
            }
            case 5: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    } while (choice != 5);

    return 0;
}

