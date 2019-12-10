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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: maths/prime.hpp
<a href="../../index.html">Back to top page</a>

* category: maths
* <a href="{{ site.github.repository_url }}/blob/master/maths/prime.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 02:26:18 +0900




## Verified
* :heavy_check_mark: <a href="../../verify/test/maths/sieve_of_eratosthenes.test.cpp.html">test/maths/sieve_of_eratosthenes.test.cpp</a>


## Code
{% raw %}
```cpp
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
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

