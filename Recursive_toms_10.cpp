#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findLevelMax(TreeNode* root, vector<int>& maxValues, int level) {
    if (!root) return;

    if (level == maxValues.size()) {
        maxValues.push_back(root->val);
    }
    else {
        maxValues[level] = max(maxValues[level], root->val);
    }

    findLevelMax(root->left, maxValues, level + 1);
    findLevelMax(root->right, maxValues, level + 1); 
}

void printLevelMax(TreeNode* root) {
    vector<int> maxValues;
    findLevelMax(root, maxValues, 0);

    for (int i = 0; i < maxValues.size(); ++i) {
        cout << "Max arjeq: " << maxValues[i] << endl;
    }
}

TreeNode* buildTree() {
    cout << "armat: ";
    int val;
    cin >> val;

    if (val == -1) return nullptr; 

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << "Mutq " << current->val << " dzaxi arjeqy: ";
        cin >> val;
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        cout << "Mutq " << current->val << " aji mutqy: ";
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
