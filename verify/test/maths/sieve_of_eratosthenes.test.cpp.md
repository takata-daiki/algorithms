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


# :warning: test/maths/sieve_of_eratosthenes.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/maths/sieve_of_eratosthenes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 01:50:18 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276</a>


## Depends On
* :warning: <a href="../../../library/maths/prime.hpp.html">maths/prime.hpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1276"
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

<a href="../../../index.html">Back to top page</a>

