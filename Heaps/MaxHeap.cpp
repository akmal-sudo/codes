#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxheap;

    maxheap.push(4);
    maxheap.push(10);
    maxheap.push(1);
    maxheap.push(15);

    while (!maxheap.empty()) {
        cout << maxheap.top() << " ";
        maxheap.pop();
    }
}
