#include <algorithm>
#include <climits>
#include <functional>
#include <vector>

using namespace std;
using ll = long long;

struct SegmentTree {
  int n;
  vector<ll> tree;
  ll unit;                  // 単位元（初期値）
  function<ll(ll, ll)> op;  // 演算（min, max, sumなど）

  // コンストラクタ: サイズ、初期値、演算を指定
  SegmentTree(int _n, ll _unit, function<ll(ll, ll)> _op)
      : unit(_unit), op(_op) {
    n = 1;
    while (n < _n) n <<= 1;
    tree.assign(n * 2, unit);
  }

  // 値の更新: i番目をxに変更
  void update(int i, ll x) {
    i += n;
    tree[i] = x;
    while (i > 1) {
      i >>= 1;
      tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  // 区間クエリ: [l, r) の範囲を計算（半開区間）
  ll query(int l, int r) {
    ll res_l = unit;
    ll res_r = unit;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res_l = op(res_l, tree[l++]);
      if (r & 1) res_r = op(tree[--r], res_r);
    }
    return op(res_l, res_r);
  }
};
