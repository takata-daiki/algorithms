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
* category: maths


[Back to top page](../../index.html)



## Verified
* :heavy_check_mark: [test/maths/prime.test.cpp](../../verify/test/maths/prime.test.cpp.html)


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

[Back to top page](../../index.html)

