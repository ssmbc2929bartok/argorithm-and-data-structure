#include <cmath>
#include <iostream>
#include <vector>
// 競プロ用
// #include <bits/stdc++.h>
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
