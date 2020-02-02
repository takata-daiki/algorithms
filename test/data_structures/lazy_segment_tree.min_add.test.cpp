#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/min.hpp"
#include "../../monoids/plus.hpp"
#include "../../monoids/min_plus_action.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    LazySegmentTree<min_monoid<int>, plus_monoid<int>, min_plus_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << seg.query(s, t) << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, x);
        }
    }
}