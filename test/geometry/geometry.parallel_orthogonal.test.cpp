#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"
#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        vector<Point> p(4);
        for (int i = 0; i < 4; i++) cin >> p[i];
        Point s1 = p[0] - p[1];
        Point s2 = p[2] - p[3];
        int ans = 0;
        if (s1.is_orthogonal(s2)) ans = 1;
        if (s1.is_parallel(s2)) ans = 2;
        cout << ans << endl;
    }
}