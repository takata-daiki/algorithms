#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"
#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    auto ch = Point::convex_hull(p);
    cout << ch.size() << endl;
    for (auto q : ch) {
        cout << q.x << ' ' << q.y << endl;
    }
}