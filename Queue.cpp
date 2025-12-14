#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<string> q;
    q.push("Ambulance");
    q.push("Fire Truck");
    q.push("Police Van");

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
