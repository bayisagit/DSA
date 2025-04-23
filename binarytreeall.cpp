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

    int findMax(Node* node) {
        if (node->right == nullptr) {
            return node->data;
        }
        return findMax(node->right);
    }

    int findMin(Node* node) {
        if (node->left == nullptr) {
            return node->data;
        }
        return findMin(node->left);
    }

    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    Node* deleteByMerging(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->data) {
            root->left = deleteByMerging(root->left, value);
        } else if (value > root->data) {
            root->right = deleteByMerging(root->right, value);
        } else {
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            }
            root->data = findMax(root->left);
            root->left = deleteByMerging(root->left, root->data);
        }
        return root;
    }

    Node* deleteByCopying(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->data) {
            root->left = deleteByCopying(root->left, value);
        } else if (value > root->data) {
            root->right = deleteByCopying(root->right, value);
        } else {
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            }
            root->data = findMin(root->right);
            root->right = deleteByCopying(root->right, root->data);
        }
        return root;
    }

    int findHeight(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        return 1 + max(findHeight(node->left), findHeight(node->right));
    }

    int findLevel(Node* node, int value, int level) {
        if (node == nullptr) {
            return 0;
        }
        if (node->data == value) {
            return level;
        }
        int downLevel = findLevel(node->left, value, level + 1);
        if (downLevel != 0) {
            return downLevel;
        }
        return findLevel(node->right, value, level + 1);
    }
};

int main() {
    Binarytree bintre;
    bintre.adds(3);
    bintre.adds(4);
    bintre.adds(1);
    bintre.adds(8);

    int choice, value;
    int level; // Declare level here

    do {
        cout << "\nMenu:\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Find Maximum\n";
        cout << "3. Find Minimum\n";
        cout << "4. Search\n";
        cout << "5. Delete by Merging\n";
        cout << "6. Delete by Copying\n";
        cout << "7. Find Height\n";
        cout << "8. Find Level\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder traversal: ";
                bintre.inorder();
                break;
            case 2:
                cout << "Maximum value: " << bintre.findMax(bintre.root) << endl;
                break;
            case 3:
                cout << "Minimum value: " << bintre.findMin(bintre.root) << endl;
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (bintre.search(bintre.root, value)) {
                    cout << value << " found in the tree." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;
            case 5:
                cout << "Enter value to delete (merge): ";
                cin >> value;
                bintre.root = bintre.deleteByMerging(bintre.root, value);
                break;
            case 6:
                cout << "Enter value to delete (copy): ";
                cin >> value;
                bintre.root = bintre.deleteByCopying(bintre.root, value);
                break;
            case 7:
                cout << "Height of tree: " << bintre.findHeight(bintre.root) << endl;
                break;
            case 8:
                cout << "Enter value to find level: ";
                cin >> value;
                level = bintre.findLevel(bintre.root, value, 1); // Use the already declared level
                if (level != 0) {
                    cout << value << " is at level " << level << "." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 9);
    
    return 0;
}