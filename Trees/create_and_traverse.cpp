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

    // private helpers
    void preorder(node *currentnode);
    void inorder(node *currentnode);
    void postorder(node *currentnode);

public:
    tree() {                   
        root = NULL;
    }

    void create();
    void preorder();           
    void inorder();
    void postorder();
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

/* ---------------- PREORDER ---------------- */
void tree::preorder() {
    preorder(root);
}

void tree::preorder(node *currentnode) {
    if (currentnode != NULL) {
        cout << currentnode->data << " ";   // D
        preorder(currentnode->left);        // L
        preorder(currentnode->right);       // R
    }
}

/* ---------------- INORDER ---------------- */
void tree::inorder() {
    inorder(root);
}

void tree::inorder(node *currentnode) {
    if (currentnode != NULL) {
        inorder(currentnode->left);         // L
        cout << currentnode->data << " ";   // D
        inorder(currentnode->right);        // R
    }
}

/* ---------------- POSTORDER ---------------- */
void tree::postorder() {
    postorder(root);
}

void tree::postorder(node *currentnode) {
    if (currentnode != NULL) {
        postorder(currentnode->left);       
        postorder(currentnode->right);      
        cout << currentnode->data << " ";   
    }
}

int main() {
    tree t;

    t.create();

    cout << "\nPreorder: ";
    t.preorder();

    cout << "\nInorder: ";
    t.inorder();

    cout << "\nPostorder: ";
    t.postorder();

    cout << endl;
    return 0;
}
