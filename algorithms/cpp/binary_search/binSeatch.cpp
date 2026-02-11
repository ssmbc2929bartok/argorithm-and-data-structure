#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<ll> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  int l = 1;
  int r = a.size();
  while (a[ans] != x) {
    ans = (l + r) / 2;  // 現在の区間の中央値
    if (a[ans] < x) {   // 真ん中より右
      l = ans + 1;
    } else if (a[ans] > x) {  // 真ん中より左
      r = ans - 1;
    }
  }

  cout << ans << endl;
  return 0;
}
