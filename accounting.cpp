#include <bits/stdc++.h>
using namespace std;

// dynamic tabe
int main() {
  int n, dc = 0, ic = 0, ca = 0, cursize = 1, sizelim = 1, bank = 0, cbank = 0;
  cout<<"enter number of elements: ";
  cin>>n;
  for (int i= 0; i < n; i++) {
    if (cursize <= sizelim)
      dc = 0, ic = 1;
    else
      dc = cursize - 1, ic = 1, sizelim += sizelim;
    cursize++;
    ca += ic + dc;
    cbank += 3 - dc - ic;
    bank += cbank;
    cout<<endl<<"for element "<<i + 1<<","<<endl;
    cout<<"doubling cost: "<<dc<<endl;
    cout<<"insertion cost: "<<ic<<endl;
    cout<<"total cost: "<<ic + dc<<endl;
    cout<<"amorphised cost: "<<3<<endl;
    cout<<"bank: "<<cbank<<endl;
  }
  cout<<endl<<"bank balance: "<<bank;
  return 0;
}