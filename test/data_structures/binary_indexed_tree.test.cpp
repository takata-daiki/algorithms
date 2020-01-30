#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
#include "../../data_structures/binary_indexed_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    BinaryIndexedTree<long long> bit(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << bit.sum(y) - bit.sum(x - 1) << endl;
        } else {
            bit.add(x - 1, y);
        }
    }
}