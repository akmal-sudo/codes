#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1,2});
    adj[1].push_back({2,3});
    adj[0].push_back({3,6});
    adj[1].push_back({3,8});

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);

    pq.push({0,0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto [v,w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << key[i] << " ";
}
