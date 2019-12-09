#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"
#include <bits/stdc++.h>

#include "../../maths/prime.hpp"
using namespace std;

int main() {
    auto prime = sieve_of_eratosthenes(1e7);
    for (int n; cin >> n, n;) {
        int l = n, r = n;
        while (!prime[l]) l--;
        while (!prime[r]) r++;
        cout << r - l << endl;
    }
}