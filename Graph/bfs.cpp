#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
