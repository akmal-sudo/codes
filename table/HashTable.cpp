#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, string> mp;

    mp["AMB101"] = "Available";
    mp["FIRE11"] = "Busy";
    mp["POL05"]  = "Patrolling";

    cout << mp["AMB101"];
}
