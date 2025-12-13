#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int g, h;
    bool operator>(const Node &other) const {
        return (g + h) > (other.g + other.h);
    }
};

int heuristic(int a, int b) {
    return abs(a - b);  // simple heuristic
}

vector<int> a_star(int start, int goal, vector<vector<pair<int,int>>> &adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX), parent(n, -1);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start] = 0;
    pq.push({start, 0, heuristic(start, goal)});

    while (!pq.empty()) {
        Node curr = pq.top(); 
        pq.pop();

        if (curr.id == goal) break;

        for (auto &[next, w] : adj[curr.id]) {
            int newCost = curr.g + w;
            if (newCost < dist[next]) {
                dist[next] = newCost;
                parent[next] = curr.id;
                pq.push({next, newCost, heuristic(next, goal)});
            }
        }
    }

    vector<int> path;
    for (int at = goal; at != -1; at = parent[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    int n = 6;
    vector<vector<pair<int,int>>> adj(n);

    adj[0] = {{1,2},{2,4}};
    adj[1] = {{3,7}};
    adj[2] = {{3,1}};
    adj[3] = {{4,3}};
    adj[4] = {{5,2}};

    vector<int> path = a_star(0, 5, adj);

    cout << "A* Path: ";
    for (int x : path) cout << x << " ";
}
