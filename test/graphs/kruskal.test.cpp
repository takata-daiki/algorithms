#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"
#include "../../graphs/kruskal.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    Kruskal<int> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        g.add_edge(s, t, w);
    }
    cout << g.build() << endl;
}