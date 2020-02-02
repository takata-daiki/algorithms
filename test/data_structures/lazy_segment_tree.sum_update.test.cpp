#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/sum.hpp"
#include "../../monoids/affine.hpp"
#include "../../monoids/sum_affine_action.hpp"

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = P(0, 1);
    }
    
    LazySegmentTree<sum_monoid<int>, affine_monoid<int>, sum_affine_action<int>> seg(begin(a), end(a));
    while (q--) {
        int com, s, t;
        cin >> com >> s >> t, t++;
        if (com) {
            cout << seg.query(s, t).first << endl;
        } else {
            int x;
            cin >> x;
            seg.update(s, t, P(0, x));
        }
    }
}