#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, K;
  cin >> n >> K;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int z = K - i - j;
      if (z >= 1 && z <= n) {
        ++ans;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
