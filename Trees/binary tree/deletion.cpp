#include <iostream>
using namespace std;

class node {
    node *left;
    int data;
    node *right;

public:
    node(int n) {              
        data = n;
        left = right = NULL;
    }
    friend class tree;
};

class tree {
    node *root;

    // helper for deletion
    node* deleteNode(node* root, int key);

public:
    tree() { root = NULL; }

    void create();
    void deleteValue(int key);     
};

void tree::create() {
    node *temp, *newnode;
    int n;
    char ans, choice;

    do {
        cout << "Enter the element to be attached: ";
        cin >> n;

        newnode = new node(n);

        if (root == NULL) {
            root = newnode;
        }
        else {
            temp = root;

            while (1) {
                cout << "Left or Right (l/r) of " << temp->data << "? ";
                cin >> ans;

                if (ans == 'l' || ans == 'L') {
                    if (temp->left == NULL) {
                        temp->left = newnode;
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else {
                    if (temp->right == NULL) {
                        temp->right = newnode;
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
            }
        }

        cout << "Any more nodes (y/n)? ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}

/* ---------------- DELETE WRAPPER ---------------- */
void tree::deleteValue(int key) {
    root = deleteNode(root, key);
}

/* ---------------- DELETE FUNCTION ---------------- */
node* tree::deleteNode(node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // Case 1: no left child
        if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: no right child
        else if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: two children: find inorder successor
        node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    tree t;

    t.create();

    int x;
    cout << "Enter value to delete: ";
    cin >> x;

    t.deleteValue(x);

    cout << "Value deleted.\n";
}
