---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/maths/prime.sieve_of_eratosthenes.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/maths/prime.sieve_of_eratosthenes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-24 17:58:17+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1276">https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1276</a>


## Depends on

* :x: <a href="../../../library/maths/prime.hpp.html">maths/prime.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1276"
#include "../../maths/prime.hpp"

#include <bits/stdc++.h>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/maths/prime.sieve_of_eratosthenes.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1276"
#line 2 "test/maths/../../maths/prime.hpp"
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
#line 3 "test/maths/prime.sieve_of_eratosthenes.test.cpp"

#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

