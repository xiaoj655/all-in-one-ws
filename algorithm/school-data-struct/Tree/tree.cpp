#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef struct treeNode {
  int val;
  treeNode *left, *right;
  treeNode() : val(0), left(nullptr), right(nullptr) {}
  treeNode(int val) : val(val), left(nullptr), right(nullptr) {}
} treeNode;

vector<int> primaryTraversal(treeNode* root) {
  stack<treeNode*> st;
  vector<int> res;
  st.push(root);
  while (!st.empty()) {
    treeNode* cur = st.top();
    st.pop();
    res.push_back(cur->val);
    if (cur->right) {
      st.push(cur->right);
    }
    if (cur->left) {
      st.push(cur->left);
    }
  }
  return res;
}

int getTreeDepth(treeNode* root) {
  stack<pair<treeNode*, int>> st;
  st.push({root, 1});
  int mx = 0;
  while (!st.empty()) {
    auto [cur, dep] = st.top();
    st.pop();
    mx = max(mx, dep);
    if (cur->right) {
      st.push({cur->right, dep + 1});
    }
    if (cur->left) {
      st.push({cur->left, dep + 1});
    }
  }
  return mx;
}

vector<int> BFS(treeNode* root) {
  queue<treeNode*> q;
  vector<int> v;
  q.push(root);
  while (!q.empty()) {
    treeNode* cur = q.front();
    q.pop();
    v.push_back(cur->val);
    if (cur->left) {
      q.push(cur->left);
    }
    if (cur->right) {
      q.push(cur->right);
    }
  }
  return v;
}

bool isBST(treeNode* root, int min, int max) {
  if (!root) return true;
  if (root->val >= max || root->val <= min) {
    return false;
  }
  return isBST(root->left, min, root->val) &&
         isBST(root->right, root->val, max);
}

treeNode* searchBST(treeNode* root, int tar) {
  stack<treeNode*> st;
  treeNode* cur = root;
  for (;;) {
    if (!cur) {
      return nullptr;
    } else if (cur->val == tar) {
      return cur;
    } else if (cur->val > tar) {
      cur = cur->left;
    } else if (cur->val < tar) {
      cur = cur->right;
    }
  }
}

// find the max node of the left sub-tree
treeNode* findMax(treeNode* root) {
  for (;;) {
    if (!root->right) {
      return root;
    }
    root = root->right;
  }
  return root;
}

treeNode* deleteBSTNode(treeNode* root, int tar) {
  if (!root) return root;

  if (root->val > tar) {
    root->left = deleteBSTNode(root->left, tar);
  } else if (root->val < tar) {
    root->right = deleteBSTNode(root->right, tar);
  } else {
    if (!root->left) {
      treeNode* temp = root->right;
      delete root;
      return temp;
    }
    if (!root->right) {
      treeNode* temp = root->left;
      delete root;
      return temp;
    }
    treeNode* temp = findMax(root->left);
    root->val = temp->val;
    root->left = deleteBSTNode(root->left, temp->val);
  }
  return root;
}

vector<int> stackPreOrder(treeNode* root) {
  stack<treeNode*> st;
  vector<int> res;
  st.push(root);
  while (!st.empty()) {
    treeNode* now = st.top();
    res.push_back(now->val);
    st.pop();
    if (now->right) {
      st.push(now->right);
    }
    if (now->left) {
      st.push(now->left);
    }
  }
  return res;
}
int main() {
  treeNode* root = new treeNode(4);
  root->right = new treeNode(5);
  root->left = new treeNode(2);
  root->left->right = new treeNode(3);
  root->left->left = new treeNode(1);

  // root = deleteBSTNode(root, 2);
  vector<int> v = stackPreOrder(root);
  for (int x : v) {
    cout << x << ' ';
  }
  return 0;
}