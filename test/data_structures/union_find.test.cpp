#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>

#include "../../data_structures/union_find.hpp"
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << uf.same(u, v) << endl;
        } else {
            uf.unite(u, v);
        }
    }
}