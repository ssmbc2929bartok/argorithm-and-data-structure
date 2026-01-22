#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
vector<bool> seen;
Graph G;

void insert(int V, int ins) {
  G[V].push_back(ins);
}

//深さ優先探索
//使用前にseen.assign(要素数, false);を記述すること
void DFS(const Graph &G, int v){
  seen[v] = true;

  for(auto next_v : G[v]){
    if(seen[next_v]){
      continue;
    }
    DFS(G, next_v);
  }
}
