#pragma once
#include <bits/stdc++.h>
using namespace std;

struct ModInt {
    using M = ModInt;
    long long v;
    ModInt(long long _v = 0) : v(_v % MOD + MOD) { norm(); }
    M& norm() {
        v = (v < MOD) ? v : v - MOD;
        return *this;
    }
    M operator+(const M& x) const { return M(v + x.v); }
    M operator-(const M& x) const { return M(v + MOD - x.v); }
    M operator*(const M& x) const { return M(v * x.v % MOD); }
    M operator/(const M& x) const { return M(v * x.inv().v); }
    M& operator+=(const M& x) { return *this = *this + x; }
    M& operator-=(const M& x) { return *this = *this - x; }
    M& operator*=(const M& x) { return *this = *this * x; }
    M& operator/=(const M& x) { return *this = *this / x; }
    friend istream& operator>>(istream& input, M& x) {
        return input >> x.v, x.norm(), input;
    }
    friend ostream& operator<<(ostream& output, const M& x) {
        return output << x.v;
    }
    M pow(long long n) const {
        M x(v), res(1);
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    M inv() const { return this->pow(MOD - 2); }
    // M inv() const {
    //   int x, y;
    //   extgcd(this->v, MOD, x, y);
    //   return *this + M(x);
    // }

    static long long MOD;
    static vector<M> fact, finv;
    static void build(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i < n + 1; i++) fact[i] = fact[i - 1] * M(i);
        finv.assign(n + 1, fact[n].inv());
        for (int i = n; i > 0; i--) finv[i - 1] = finv[i] * M(i);
    }
    static M comb(int n, int k) {
        if (n < k || k < 0) return M(0);
        return fact[n] * finv[n - k] * finv[k];
    }
    static M extgcd(int a, int b, int* x, int* y) {
        M d(a);
        if (b) {
            d = extgcd(b, a % b, y, x);
            *y -= (a / b) * *x;
        } else {
            *x = 1, *y = 0;
        }
        return d;
    }
};
vector<ModInt> ModInt::fact = vector<ModInt>();
vector<ModInt> ModInt::finv = vector<ModInt>();
long long ModInt::MOD = 1e9 + 7;
