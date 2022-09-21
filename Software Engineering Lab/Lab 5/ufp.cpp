#include<bits/stdc++.h>
using namespace std;

int main() {

    int low[] = {3, 4, 3, 7, 5};
    int average[] = {4, 5, 4, 10, 7};
    int high[] = {6, 7, 6, 15, 10};
    int EI, EO, res1, res2, UFP;
    char type1, type2;

    cout << "Enter the value of EI: ";
    cin >> EI;
    cout << "Enter the type of EI: ";
    cin >> type1;
    getchar();

    if (type1 == 'low')
        res1 = EI * low[0];
    else if (type1 == 'average')
        res1 = EI * average[0];
    else
        res1 = EI * high[0];

    cout << "Enter the value of EO: ";
    cin >> EO;
    cout << "Enter the type of EO: ";
    cin >> type2;

    if (type1 == 'low')
        res2 = EO * low[1];
    else if (type2 == 'average')
        res1 = EO * average[1];
    else
        res1 = EO * high[1];

    UFP = res1 + res2;
    cout << "UFP = " << UFP << endl;

    return 0;
}