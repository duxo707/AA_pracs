#include <bits/stdc++.h>
using namespace std;

// ekzlib code
const int INF = 1 << 30;
struct graph {
  struct edge {
    int src, dst;
    int capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst, int capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  int max_flow(int s, int t) {
    vector<bool> visited(n);
    function<int(int,int)> augment = [&](int u, int cur) {
      if (u == t) return cur;
      visited[u] = true;
      for (auto &e: adj[u]) {
        if (!visited[e.dst] && e.capacity > e.flow) {
          int f = augment(e.dst, min(e.capacity - e.flow, cur));
          if (f > 0) {
            e.flow += f;
            adj[e.dst][e.rev].flow -= f;
            return f;
          }
        }
      }
      return 0;
    }; // lamba function for augmented edges
    for (int u = 0; u < n; ++u)
      for (auto &e: adj[u]) e.flow = 0;

    int flow = 0;
    while (1) {
      fill(visited.begin(), visited.end(), false); // reinitialise visited array
      int f = augment(s, INF);
      if (f == 0) break;
      flow += f;
    }
    return flow;
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