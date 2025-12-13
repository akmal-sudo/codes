#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;

        for(auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
