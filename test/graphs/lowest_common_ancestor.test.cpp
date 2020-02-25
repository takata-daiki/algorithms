#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#include "../../graphs/lowest_common_ancestor.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    LowestCommonAncestor g(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int c;
            cin >> c;
            g.add_edge(i, c);
        }
    }
    g.build(0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << g.query(u, v) << endl;
    }
}