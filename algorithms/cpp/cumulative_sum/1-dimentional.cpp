#include <cmath>
#include <iostream>
#include <vector>
// 競プロ用
// #include <bits/stdc++.h>

/*１次元累積和を計算するためのファイルだよ*/
/*    様々なことに活用してくださいな     */
/*   質問・訂正などはXまでお願いします   */
/*       アカウントなどはGithubに       */

using namespace std;
using sumType = int;  // 状況に応じて変更してね

vector<sumType> gCmlSum;  // 累積和を保存するvector

// 累積和を計算するフィールドを作る関数
void initCumulativeSum(sumType size) {
  gCmlSum.assign(size + 1, 0);
}

// 値を入れるための関数
void input(sumType index, sumType inp) {
  gCmlSum[index] = gCmlSum[index - 1] + inp;
}

// 全区間累積和を計算する関数
void calcAllSum() {
  for (int i = 1; i <= gCmlSum.size(); i++) {
    gCmlSum[i] = gCmlSum[i] + gCmlSum[i - 1];
  }
}

// 区間[a, b]の累積和を計算する関数
void calcSecSum(int a, int b, bool isUp) {  // isUp = 1:aからbまで昇順, 2:bからaまで降順
  if (isUp) {
    for (int i = a + 1; i <= b; i++) {
      gCmlSum[i] = gCmlSum[i] + gCmlSum[i - 1];
    }
  } else {
    for (int i = b - 1; i >= a; i--) {
      gCmlSum[i] = gCmlSum[i] + gCmlSum[i + 1];
    }
  }
}
