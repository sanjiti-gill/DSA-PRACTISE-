#include<iostream>
using namespace std;

class graphnode{
    int vertex;
    graphnode* next;

    public:
    graphnode(int n=0){
        vertex=n;
        next=NULL;
    }

    friend class listgraph;
};

class listgraph{
    int n;
    graphnode* list[5];

    public:
    listgraph(int nov){
        n=nov;
        for(int i=0;i<n;i++){
            list[i]=NULL;
        }
    }
    void create();
    void display();

};

void listgraph::create(){
    graphnode* temp, *newnode;
    char ans;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "is there an edge between vertex" << i+1 << "and" << j+1<<"(y/n)";
            cin >> ans;
            if(ans=='y' || ans=='Y'){
                newnode= new graphnode(j+1);

                if(list[i]==NULL){
                    list[i]=temp=newnode;
                }
                else{
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}

void listgraph::display(){
    graphnode* temp;
    for(int i=0;i<n;i++){
        cout << "vertex" << i+1 << "->";
        temp=list[i];
        while(temp!=NULL){
            cout << "v" << temp->vertex << "->";
            temp=temp->next;
        }
        cout << "NULL" ;
    }
}

int main(){
    int n;
    cout << "enter the number of vertices: " ;
    cin >> n;

    listgraph g(n);
    g.create();
    g.display();
    return 0;
}
