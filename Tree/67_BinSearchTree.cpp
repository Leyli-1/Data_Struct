#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    string data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k, string d) : key(k), data(d), left(nullptr), right(nullptr) {}
};

class BinSearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int key, string data) {
        if (node == nullptr) {
            return new TreeNode(key, data);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, data);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, data);
        }

        return node;
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "Key: " << node->key << ", Data: " << node->data << endl;
        inorder(node->right);
    }

public:
    BinSearchTree() : root(nullptr) {}

    void insert(int key, string data) {
        root = insert(root, key, data);
    }

    void printInOrder() {
        inorder(root);
    }

    TreeNode* search(int key) {
        TreeNode* node = root;
        while (node != nullptr) {
            if (key == node->key) {
                return node;
            }
            else if (key < node->key) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return nullptr;
    }
};

int main() {
    BinSearchTree tree;

    tree.insert(50, "Data for 50");
    tree.insert(30, "Data for 30");
    tree.insert(20, "Data for 20");
    tree.insert(40, "Data for 40");
    tree.insert(70, "Data for 70");
    tree.insert(60, "Data for 60");
    tree.insert(80, "Data for 80");

    cout << "In-order Traversal:" << endl;
    tree.printInOrder();

    int keyToSearch = 40;
    TreeNode* foundNode = tree.search(keyToSearch);
    if (foundNode != nullptr) {
        cout << "\nFound Node - Key: " << foundNode->key << ", Data: " << foundNode->data << endl;
    }
    else {
        cout << "\nNode with key " << keyToSearch << " not found." << endl;
    }

    return 0;
}
