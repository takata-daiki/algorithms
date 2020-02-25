#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C"
#include "../../data_structures/kd_tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    KdTree kd(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        kd.add_point(x, y, i);
    }
    kd.build();
    
    int q;
    cin >> q;
    while (q--) {
        int sx, tx, sy, ty;
        cin >> sx >> tx >> sy >> ty;
        vector<int> ans = kd.query(sx, tx, sy, ty);
        for (auto&& x : ans) cout << x << endl;
        cout << endl;
    }
}