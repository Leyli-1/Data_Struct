#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printLevelMax(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            maxVal = max(maxVal, node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout << "Max at this level: " << maxVal << endl;
    }
}

TreeNode* buildTree() {
    cout << "Enter the value of root node (-1 for no node): ";
    int val;
    cin >> val;

    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << "Enter the left child of " << current->val << " (-1 for no node): ";
        cin >> val;
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        cout << "Enter the right child of " << current->val << " (-1 for no node): ";
        cin >> val;
        if (val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    TreeNode* root = buildTree();
    printLevelMax(root);
    return 0;
}
