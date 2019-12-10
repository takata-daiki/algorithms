#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
    vector<T> bit;
    BinaryIndexedTree(int n) : bit(n + 1, 0) {}
    T sum(int k) {
        k++;
        T s = 0;
        for (; k > 0; k -= k & -k) s += bit[k];
        return s;
    }
    void add(int k, T x) {
        k++;
        for (; k <= bit.size(); k += k & -k) bit[k] += x;
    }
};