#include <bits/stdc++.h>
using namespace std;

// multipop
int main() {
  int n, ct = 0;
  cout<<"Enter number of elements:";
  cin>>n;
  vector<int> v(n, 0);
  stack<int> st;
  cout<<"Enter elements: ";
  for (int i = 0; i < n; i++)
  cin>>v[i];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < st.size()) {
      cout<<"Pushed "<<v[i]<<endl;
      st.push(v[i]), ct++;
    } else {
      for (int j = 1; j <= v[i] && !st.empty(); j++) {
        cout<<"Popped "<<st.top()<<endl;
        st.pop(), ct++;
      }
      cout<<"Pushed "<<v[i]<<endl;
      st.push(v[i]), ct++;
    }
  }
  cout<<"Asymptotic: "<<ct<<endl;
  cout<<"Amortized: "<<ct / n<<endl;
  return 0;
}