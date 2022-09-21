#include<bits/stdc++.h>
using namespace std;

#define a1 3.6
#define a2 1.2
#define b1 2.5
#define b2 0.32

int main() {

    double kloc;
    cout << "Enter kloc: ";
    cin >> kloc;
    double effort = a1 * pow(kloc, a2);
    double tdev = b1 * pow(effort, b2);
    cout << "Effort = " << effort << endl;
    cout << "Time of development = " << tdev << endl;
    cout << "Cost = " << effort * tdev << endl;

    return 0;
}