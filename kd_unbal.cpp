#include <bits/stdc++.h>
using namespace std;


struct Node {
  int x, y;
  Node* left;
  Node* right;
  Node(int x, int y): x(x), y(y), left(NULL), right(NULL) {}
};

void insert(Node* root, pair<int, int> pt, int d) {
  if (d % 2 == 0) {
    if (root->x > pt.first) {
      if (!root->left) {
        Node* node = new Node(pt.first, pt.second);
        root->left = node;
        return;
      } else 
        insert(root->left, pt, d + 1);
    } else {
      if (!root->right) {
        Node* node = new Node(pt.first, pt.second);
        root->right = node;
        return;
      } else 
        insert(root->right, pt, d + 1);
    }
  } else {
    if (root->y > pt.second) {
      if (!root->left) {
        Node* node = new Node(pt.first, pt.second);
        root->left = node;
        return;
      } else 
        insert(root->left, pt, d + 1);
    } else {
      if (!root->right) {
        Node* node = new Node(pt.first, pt.second);
        root->right = node;
        return;
      } else 
        insert(root->right, pt, d + 1);
    }
  }
}
void inorder(Node* root) {
  if (root == NULL) 
    return;
  if (root->left)
    inorder(root->left);
  cout<<root->x<<", "<<root->y<<endl;
  if (root->right)
    inorder(root->right);
}
int main() {
  vector<pair<int, int>> pts =  {{3, 6}, {17, 15}, {13, 16}, {6, 12}, {9, 1}, {2, 7}, {10, 19}};
  Node* root = new Node(pts[0].first, pts[0].second);
  for (int i = 1; i < pts.size(); i++)
    insert(root, pts[i], 0);
  inorder(root);
  return 0;
}