#include <bits/stdc++.h>
using namespace std;

// hoare pivot used, for lomuto, swap pivot element with high instead of low
int pivot(int low, int high) {
  return low + (rand() % (high - low + 1));
}
int partition(vector<int>& a, int low, int high) {
  int p = pivot(low, high), i = low, j = high;
  swap(a[low], a[p]);
  int pivot = a[low];
  while (i < j) {
    while (a[i] <= pivot && i < high) i++;
    while (a[j] >= pivot && j > low) j--;
    if (i < j)
      swap(a[i], a[j]);
  }
  swap(a[low], a[j]);
  return j;
}
void rqs(vector<int>& a, int low, int high) {
  if (low < high) {
    int mid = partition(a, low, high);
    rqs(a, low, mid);
    rqs(a, mid + 1, high);
  }
}
int main() {
  vector<int> a = {4, 2, 9, 5, 6, 1, 8, 0, 3};
  rqs(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); i++)
  cout<<a[i]<<" ";
  return 0;
}