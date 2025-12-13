#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);

    for(int i = 0; i < n; i++) {
        cout << i << ": ";
        for(int v : adj[i]) cout << v << " ";
        cout << endl;
    }
}

