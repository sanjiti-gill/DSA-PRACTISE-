#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

void insertbeg(int val){
    node* newnode= new node;
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void insertend(int val){
    node* temp=head;
    node* newnode= new node;
    newnode->data=val;
    newnode->next=NULL;
    
    if(head==NULL){
        head=newnode;
        return;
    }
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertpos(int val, int pos){
    node* newnode= new node;
    newnode->data=val;
    newnode->next=NULL;
    node* temp=head;
    
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    
    for(int i=1;i<pos-1 && temp; i++){
        temp=temp->next;
        if(temp==NULL)
            cout << "invalid position" << endl;
        
    }
    temp->next=newnode;
    newnode->next=temp->next;
}

void display(){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL \n" << endl;
}

int main(){
    int val,ch,pos;
    do{
        cout << "--- MENU ---" << endl;
        cout << "1. insert at beginning" << endl;
        cout << "2. insert at end" << endl;
        cout << "3. insert at a position " << endl;
        cout << "4. display" << endl;
        
        cout << "enter your choice";
        cin >> ch;
        
        switch(ch){
            case 1:
                cout << "enter data" << endl;
                cin >> val;
                insertbeg(val);
                break;
                
            case 2:
                cout << "Enter value: "; cin >> val;
                insertend(val); break;
            case 3:
                cout << "Enter value: "; cin >> val;
                cout << "Enter position: "; cin >> pos;
                insertpos(val, pos); break;
            case 4:
                display(); break;
            case 5:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice\n";
        }
    }while(ch != 5);
    return 0;
}
