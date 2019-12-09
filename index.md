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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# ライブラリの HTML ビルドテスト

ここに書いた内容がトップページに足されます

* this unordered seed list will be replaced by toc as unordered list
{:toc}

## Library Files
### data_structures
* :heavy_check_mark: [data_structures/union_find.hpp](library/data_structures/union_find.hpp.html)


### maths
* :heavy_check_mark: [maths/prime.hpp](library/maths/prime.hpp.html)


## Verify Files
* :heavy_check_mark: [test/data_structures/union_find.test.cpp](verify/test/data_structures/union_find.test.cpp.html)
* :heavy_check_mark: [test/maths/prime.test.cpp](verify/test/maths/prime.test.cpp.html)


