#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"
#include "../../graphs/ford_fulkerson.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    FordFulkerson ssp(n);
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        ssp.add_edge(u, v, c);
    }
    cout << ssp.build(0, n - 1) << endl;
}