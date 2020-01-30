#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"
#include "../../maths/mod.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ModInt::build(2000);
    cout << ModInt::comb(n + k - 1, n) << endl;
}