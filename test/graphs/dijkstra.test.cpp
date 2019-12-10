#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../graphs/dijkstra.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    Dijkstra<int> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    auto dist = g.build(r);
    for (int i = 0; i < v; i++) {
        if (dist[i] == -1) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}