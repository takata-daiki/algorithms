#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
    vector<int> prime(n + 1, 0);
    for (int i = 2; i <= n; ++i) prime[i] = i;
    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) prime[j] = 0;
        }
    }
    // prime.erase(remove(begin(prime), end(prime), 0), end(prime));
    return prime;
}