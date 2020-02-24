#pragma once
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind(int n) : data(n, -1) {}

    inline int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
    inline int size(int x) { return -data[root(x)]; }
    inline bool same(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
};