#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next, adj, visited);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4};

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(0, adj, visited);
}
