#include <bits/stdc++.h>
using namespace std;

// dynamic table
int main() {
  int n, dc = 0, ic = 1, ps = 1, cs = 1, p = 1, pp = 0, ac = dc + ic + p;
  cout<<"enter number of elements: ";
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cout<<endl<<"for element "<<i<<","<<endl;
    cout<<"previous size: "<<ps<<endl;
    cout<<"current size: "<<cs<<endl;
    cout<<"doubling cost: "<<dc<<endl;
    cout<<"insertion cost: "<<ic<<endl;
    cout<<"total cost: "<<ic + dc<<endl;
    cout<<"potential: "<<p<<endl;
    cout<<"amorphised cost: "<<ac<<endl;
    ps = cs;
    if (i == cs) {
      cs += cs;
      dc = cs - ps;
    } else
      dc = 0;
    pp = p;
    p = 2 * i - cs;
    ac = dc + ic + p - pp;
  }
  return 0;
}