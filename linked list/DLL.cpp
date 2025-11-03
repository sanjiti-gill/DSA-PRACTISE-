#include <iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* head = NULL;

// ------------------ INSERT AT BEGINNING ------------------
void insertbeg(int data) {
    node* newnode = new node;
    newnode->data = data;
    newnode->prev = NULL;

    if (head == NULL) {
        newnode->next = NULL;
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

// ------------------ INSERT AT END ------------------
void insertend(int data) {
    node* newnode = new node;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

// ------------------ INSERT AT POSITION ------------------
void insertpos(int data, int pos) {
    node* newnode = new node;
    newnode->data = data;

    // Case 1: Empty list
    if (head == NULL) {
        if (pos != 1) {
            cout << "Invalid position\n";
            delete newnode;
            return;
        }
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        return;
    }

    // Case 2: Insert at beginning
    if (pos == 1) {
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    // Case 3: Insert in middle or end
    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position\n";
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

// ------------------ DELETE AT BEGINNING ------------------
void deletebeg() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

// ------------------ DELETE AT END ------------------
void deleteend() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

// ------------------ DELETE AT POSITION ------------------
void deletepos(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 1) {
        deletebeg();
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    if (temp->next == NULL) { // last node
        temp->prev->next = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// ------------------ DISPLAY FUNCTION ------------------
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* temp = head;
    cout << "List elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ------------------ MAIN FUNCTION WITH MENU ------------------
int main() {
    int ch, data, pos;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertbeg(data);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> data;
                insertend(data);
                break;

            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> pos;
                insertpos(data, pos);
                break;

            case 4:
                deletebeg();
                break;

            case 5:
                deleteend();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletepos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (ch != 8);

    return 0;
}
