#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;

void insert(int V, int ins) {
  G[V].push_back(ins);
}
