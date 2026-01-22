#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;  // main関数内などで（全体の大きさ + 1）のサイズを確保すること
Graph G;

void insert(Graph& G, int V, int ins) {
  G[V].push_back(ins);
}

// 連結リストを表示する
//  頂点の表示順を昇順にしたいときはsort(G[i].begin(), G[i].end());などを先に実行すること
void show(const Graph& G, int V) {
  for (int next_v : G[V]) {
    cout << next_v << " ";
  }
  cout << endl;
}

vector<bool> seen;
// 深さ優先探索
// 使用前にseen.assign(要素数, false);を記述すること
void DFS(const Graph& G, int v) {
  seen[v] = true;

  for (auto next_v : G[v]) {
    if (seen[next_v]) {
      continue;
    }
    DFS(G, next_v);
  }
}
