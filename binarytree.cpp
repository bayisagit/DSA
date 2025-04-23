#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Binarytree {
public:
    Node* root;
    Binarytree() {
        root = nullptr;
    }

    Node* addss(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = addss(root->left, value);
        } else {
            root->right = addss(root->right, value);
        }
        return root;
    }

    void adds(int value) {
        root = addss(root, value);
    }

    void inoderr(Node* node) {
        if (node != nullptr) {
            inoderr(node->left);
            cout << node->data << " ";
            inoderr(node->right);
        }
    }

    void inorder() {
        inoderr(root);
        cout << endl;
    }
    
    void preorderr(Node* node) {
        if (node != nullptr) {
            cout << node->data << " "; // Print current node
            preorderr(node->left);      // Visit left child
            preorderr(node->right);     // Visit right child
        }
    }

    void preorder() {
        preorderr(root);
        cout << endl;
    }

    void postorderr(Node* node) {
        if (node != nullptr) {
            postorderr(node->left);     // Visit left child
            postorderr(node->right);    // Visit right child
            cout << node->data << " ";   // Print current node
        }
    }

    void postorder() {
        postorderr(root);
        cout << endl;
    }
};

int main() {
    Binarytree bintre;
    bintre.adds(3);
    bintre.adds(4);
    bintre.adds(1);
    bintre.adds(8);

    cout << "Inorder traversal: ";
    bintre.inorder();

    cout << "Preorder traversal: ";
    bintre.preorder();

    cout << "Postorder traversal: ";
    bintre.postorder();

    return 0;
}