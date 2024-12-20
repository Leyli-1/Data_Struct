#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void longestPath(TreeNode* root, vector<int>& path, vector<int>& result) {
    if (root == NULL) return;
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        if (path.size() > result.size()) {
            result = path;
        }
    }
    else {
        longestPath(root->left, path, result);
        longestPath(root->right, path, result);
    }
    path.pop_back();
}

void printLongestPath(TreeNode* root) {
    vector<int> path, result;
    longestPath(root, path, result);
    cout << "Longest path from root to leaf: ";
    for (int val : result) {
        cout << val << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    printLongestPath(root);

    return 0;
}
