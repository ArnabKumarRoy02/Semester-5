#include <bits/stdc++.h>
using namespace std;

class Bank {
    public:
        long accno, acno, pin, balance = 25000;
        string name, password, pwd;

        void create() {
            cout << "\nEnter the name: ";
            cin >> name;
            cout << "Enter the Account Number: ";
            cin >> accno;
            cout << "Enter the password: ";
            cin >> password;
            cout << "\nRegistered Succesfully\n" << endl;
        }

        void login() {
            cout << "Enter the account number: ";
            cin >> acno;
            cout << "Enter the password: ";
            cin >> pwd;
            if (acno != accno || pwd != password) {
                cout << "Incorrect details" << endl;
                cout << "!!!!Login Failed!!!!" << endl;
            }
            else {
                cout << "\nLogin Succesfull" << endl;
            }
        }

        void display() {
            cout << "Account Number: " << accno << endl;
            cout << "Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        }
};

class Transaction : public Bank {
    public:
        int amount;
        long transfer_accno;

        void deposit() {
            cout << "Enter the amount you want to deposit: ";
            cin >> amount;
            balance += amount;
            cout << "New balance: " << balance << endl;
        }

        void withdraw() {
            cout << "Enter the amount you want to withdraw: ";
            cin >> amount;
            if (amount > balance) {
                cout << "Insufficient balance" << endl;
            }
            else {
                balance -= amount;
                cout << "New balance: " << balance << endl;
            }
        }

        void fund_transfer() {
            cout << "Enter the account number you want to transfer: ";
            cin >> transfer_accno;
            cout << "Enter the amount to be transferred: ";
            cin >> amount;
            cout << "Enter the PIN: ";
            cin >> pin;
            if (pin == 1234) {
                if (amount > balance) {
                    cout << "Insufficient balance" << endl;
                }
                else {
                    balance -= amount;
                    cout << "New balance: " << balance << endl;
                }
            }
        }

        void check_balance() {
            cout << "Current balance: " << balance << endl;
        }
};

int main() {

    Transaction T;
    int choice;

    cout << "----------- BANKING SYSTEM ------------" << endl;
    cout << "Press 1 to Create a new account" << endl;
    cout << "Press 2 to Login" << endl;
    cout << "Press 3 to Display the details" << endl;
    cout << "Press 4 to Deposit money" << endl;
    cout << "Press 5 to Withdraw money" << endl;
    cout << "Press 6 to Transfer funds" << endl;
    cout << "Press 7 to Check Balance" << endl;
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                T.create();
                break;
            case 2: 
                T.login();
                break;
            case 3:
                T.display();
                break;
            case 4:
                T.deposit();
                break;
            case 5:
                T.withdraw();
                break;
            case 6:
                T.fund_transfer();
                break;
            case 7:
                T.check_balance();
                break;
            case 8: 
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
    } while(choice != 8);

    return 0;
}