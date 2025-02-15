#include <bits/stdc++.h>
using namespace std;

// ekzlib code
const int INF = 1 << 30;
struct graph {
  int n;
  struct edge {
    int src, dst;
    int capacity, residue;
    size_t rev;
  };
  edge &rev(edge e) { return adj[e.dst][e.rev]; };

  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst, int capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  int max_flow(int s, int t) {
    for (int u = 0; u < n; ++u)
      for (auto &e: adj[u]) e.residue = e.capacity;
    int total = 0;
    while (1) {
      vector<int> prev(n, -1); prev[s] = -2;
      queue<int> que; que.push(s);
      while (!que.empty() && prev[t] == -1) {
        int u = que.front(); que.pop();
        for (edge &e: adj[u]) {
          if (prev[e.dst] == -1 && e.residue > 0) {
            prev[e.dst] = e.rev;
            que.push(e.dst);
          }
        }
      }
      if (prev[t] == -1) break;
      int inc = INF;
      for (int u = t; u != s; u = adj[u][prev[u]].dst) 
        inc = min(inc, rev(adj[u][prev[u]]).residue);
      for (int u = t; u != s; u = adj[u][prev[u]].dst) {
        adj[u][prev[u]].residue += inc;
        rev(adj[u][prev[u]]).residue -= inc;
      }
      total += inc;
    } // { u : visited[u] == true } is s-side
    return total;
  }
};

int main() {
  int n, m; // n = nodes, m = edges
  cin>>n>>m;
  graph g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin>>u>>v>>w;
    g.add_edge(u, v, w);
  }
  cout<<g.max_flow(0, n-1);
}
