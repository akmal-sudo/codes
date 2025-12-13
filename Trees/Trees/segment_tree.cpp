#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int size) {
        n = size;
        tree.resize(4*n, 0);
    }

    void build(vector<int> &arr, int idx, int l, int r) {
        if(l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, idx*2, l, mid);
        build(arr, idx*2+1, mid+1, r);
        tree[idx] = tree[idx*2] + tree[idx*2+1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if(qr < l || ql > r) return 0;
        if(ql <= l && r <= qr) return tree[idx];
        int mid = (l+r)/2;
        return query(idx*2, l, mid, ql, qr) +
               query(idx*2+1, mid+1, r, ql, qr);
    }
};
