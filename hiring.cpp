#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> c = {4, 2, 5, 1, 3, 7, 8, 0}, ci = {1, 2, 3, 4, 5, 6, 7, 8}, hc;
  vector<pair<int, int>> ic;
  int fc = 0, n = c.size(), max = -1;
  for (int i = 0; i < n; i++) {
    int idx = rand() % c.size();
    ic.push_back({c[idx], ci[idx]});
    c.erase(c.begin() + idx);
    ci.erase(ci.begin() + idx);
  }
  for (int i = 0; i < n; i++) {
      if (ic[i].first > max) {
        max = ic[i].first;
        hc.push_back(ic[i].second);
      }
  }
  cout<<endl<<"Firing cost: "<<hc.size() - 1<<endl;
  cout<<endl<<"Interviewed candidates:"<<endl;
  for (int i = 0; i < n; i++)
  cout<<ic[i].second<<" ";
  cout<<endl<<"Hired candidates:"<<endl;
  for (int i = 0; i < hc.size(); i++)
  cout<<hc[i]<<" ";
  cout<<endl<<"Number of candidates hired: "<<hc.size();
  return 0;
}