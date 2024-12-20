#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

void removeLevel(TreeNode*& root, int level, int currentLevel = 0) {
    if (root == NULL) return;
    if (currentLevel == level) {
        root = NULL;
        return;
    }
    removeLevel(root->left, level, currentLevel + 1);
    removeLevel(root->right, level, currentLevel + 1);
}

void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int nodeCount = q.size();
        while (nodeCount > 0) {
            TreeNode* node = q.front();
            cout << node->val << " ";
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Original Tree (Level Order):" << endl;
    printLevelOrder(root);

    int level = 2;
    cout << "Tree after removing nodes at level " << level << ":" << endl;
    removeLevel(root, level);
    printLevelOrder(root);

    return 0;
}
