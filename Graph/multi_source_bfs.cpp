#include <bits/stdc++.h>
using namespace std;

vector<int> multiSourceBFS(int n, vector<vector<int>> &adj, vector<int> &sources) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    for(int src : sources) {
        dist[src] = 0;
        q.push(src);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
