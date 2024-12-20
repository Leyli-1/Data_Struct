#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> nums = { -10, -3, 0, 5, 9 };

    TreeNode* root = sortedArrayToBST(nums, 0, nums.size() - 1);

    cout << "In-order traversal of the BST: ";
    inorderTraversal(root);

    return 0;
}
