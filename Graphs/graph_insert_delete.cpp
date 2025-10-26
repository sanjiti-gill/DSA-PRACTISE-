#include <iostream>
using namespace std;

#define MAX 10

class graphnode {
    int vertex;
    graphnode *next;
public:
    graphnode(int n = 0) {  
        vertex = n;
        next = NULL;
    }
    friend class listgraph;
};

class listgraph {
    graphnode *list[MAX];  
    int n;                 
public:
    listgraph(int nov) {   
        n = nov;
        for (int j = 0; j < n; j++)
            list[j] = NULL;
    }

    void create();
    void display();
    void insertEdge(int src, int dest);
    void deleteEdge(int src, int dest);
};

// --------------------
// create()
// --------------------
void listgraph::create() {
    int i, j;
    char ans;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "\nIs there an edge between vertex " << i + 1 << " and " << j + 1 << "? (y/n): ";
            cin >> ans;
            if (ans == 'y' || ans == 'Y') {
                insertEdge(i, j);
            }
        }
    }
}

// --------------------
// insertEdge()
// --------------------
void listgraph::insertEdge(int src, int dest) {
    graphnode *newnode = new graphnode(dest + 1);  
    newnode->next = list[src];                     
    list[src] = newnode;                           
}


// --------------------
// deleteEdge()
// --------------------
void listgraph::deleteEdge(int src, int dest) {
    graphnode *temp = list[src];   
    graphnode *prev = NULL;       

    while (temp != NULL) {
        if (temp->vertex == dest + 1) {  
            if (prev == NULL) {
                // Node to delete is the first one (head)
                list[src] = temp->next;
            } else {
                // Node is in the middle or at the end
                prev->next = temp->next;
            }
            delete temp;  // free memory
            cout << "\nEdge between " << src + 1 << " and " << dest + 1 << " deleted successfully.";
            return;
        }
        // move ahead
        prev = temp;
        temp = temp->next;
    }

    cout << "\nEdge not found!";
}


// --------------------
// display()
// --------------------
void listgraph::display() {
    graphnode *temp;
    for (int i = 0; i < n; i++) {
        cout << "\nVertex " << i + 1 << " -> ";
        temp = list[i];
        while (temp != NULL) {
            cout << "v" << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    cout << endl;
}

// --------------------
// main()
// --------------------
int main() {
    int n, src, dest;
    cout << "Enter number of vertices: ";
    cin >> n;

    listgraph g(n);
    g.create();

    cout << "\nInitial Graph:\n";
    g.display();

    cout << "\nEnter edge to insert (src dest): ";
    cin >> src >> dest;
    g.insertEdge(src - 1, dest - 1);

    cout << "\nGraph after insertion:\n";
    g.display();

    cout << "\nEnter edge to delete (src dest): ";
    cin >> src >> dest;
    g.deleteEdge(src - 1, dest - 1);

    cout << "\nGraph after deletion:\n";
    g.display();

    return 0;
}
