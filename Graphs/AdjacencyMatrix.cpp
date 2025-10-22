#include<iostream>
using namespace std;

class graph{
    int n;
    int A[10][10];

    public:
    void create();
    void display();
};

void graph::create(){
    cout << "enter the number of vertices:" ;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=0;
        }
    }

    char ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "is there an edge between vertices " << i+1 << "and " << j+1 << "(y/n) " ;
            cin >> ans;

            if(ans=='y' || ans=='Y'){
                A[i][j]=1;
            }
        }
    }
}

void graph::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    graph g;
    g.create();
    g.display();
    return 0;
}
