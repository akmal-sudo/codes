#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> lookup;
    lookup[101] = "Ambulance - Medical Emergency";
    lookup[102] = "Police Department";
    lookup[103] = "Fire Brigade";
    lookup[104] = "Disaster Response Team";

    int code;
    cout << "Enter emergency code: ";
    cin >> code;

    if (lookup.count(code))
        cout << lookup[code] << endl;
    else
        cout << "Invalid Code!" << endl;

    return 0;
}
