#include<bits/stdc++.h>
using namespace std;

class student {
    public:
        string username;
        int regno, sem, card, amount, password;

        void get_details() {
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
        }

        void verify() {
            if (username == "Shyam" && password == 12345) {
                cout << "\nLogin Successful" << endl;
            }
            else {
                cout << "\nLogin failed" << endl;
                exit(0);
            }
        }

        void payment() {
            cout << "\nEnter the card details: ";
            cin >> card;
            cout << "Enter the amount: ";
            cin >> amount;
            cout << "Payment Successful" << endl;
        }

        void display() {
            cout << "\n---------- Details ----------" << endl;
            cout << "Name: " << username << endl;
            cout << "Registration Number: " << password << endl;
            cout << "Semester: 5" << endl;
            cout << "Payment: Done" << endl;
        }
};

int main() {

    student obj;
    obj.get_details();
    obj.verify();
    obj.payment();
    obj.display();

    return 0;
}