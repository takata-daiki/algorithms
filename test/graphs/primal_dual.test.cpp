#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"
#include "../../graphs/primal_dual.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual ssp(n);
    while (m--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        ssp.add_edge(u, v, c, d);
    }
    cout << ssp.build(0, n - 1, f) << endl;
}