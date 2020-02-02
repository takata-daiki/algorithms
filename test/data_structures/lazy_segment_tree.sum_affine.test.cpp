#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../data_structures/lazy_segment_tree.hpp"
#include "../../monoids/sum.hpp"
#include "../../monoids/affine.hpp"
#include "../../monoids/sum_affine_action.hpp"
#include "../../maths/mod.hpp"

#include <bits/stdc++.h>
using namespace std;
using P = pair<ModInt, int>;

ModInt operator*(int x, ModInt m) { return ModInt(x) * m; }

int main() {
    ModInt::MOD = 998244353;
    int n, q;
    cin >> n >> q;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = P(x, 1);
    }
    
    LazySegmentTree<sum_monoid<ModInt>, affine_monoid<ModInt>, sum_affine_action<ModInt>> seg(begin(a), end(a));
    while (q--) {
        int com, l, r;
        cin >> com >> l >> r;
        if (com) {
            cout << seg.query(l, r).first << endl;
        } else {
            int b, c;
            cin >> b >> c;
            seg.update(l, r, P(b, c));
        }
    }
}