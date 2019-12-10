#pragma once
#include <bits/stdc++.h>
using namespace std;

map<int, int> compress(vector<int>& unzip) {
    map<int, int> zip;
    for (auto x : unzip) zip[x] = -1;
    int idx = 0;
    unzip = vector<int>();
    for (auto& p : zip) {
        unzip.push_back(p.first);
        p.second = idx;
        idx++;
    }
    return zip;
}