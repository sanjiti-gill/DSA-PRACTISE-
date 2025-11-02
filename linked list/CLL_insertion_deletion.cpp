#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

void insertbeg(int data){
    node* newnode=new node;
    newnode->data=data;

    if(head==NULL){
        head=newnode;
        newnode->next=head;
        return;
    }

    else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }

        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
}

void insertend(int data){
    node* newnode=new node;
    newnode->data=data;

    if(head==NULL){
        head=newnode;
        newnode->next=head;
        return;
    }

    else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }

        temp->next=newnode;
        newnode->next=head;
    }
}

void insertpos(int data,int pos){
    node* newnode=new node;
    newnode->data=data;

    if(head==NULL){
        if(pos!=1){
            cout << "list empty, invalid position";
            return;
        }
        else{
            head=newnode;
            newnode->next=head;
            return;
        }
    }

    if(pos==1){
        insertbeg(data);
        return;
    }

    node* temp=head;
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }

    newnode->next=temp->next;
    temp->next=newnode;
}

void deletebeg(){
    if(head==NULL){
        return;
    }

    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }

    node* temp=head;
    node* last=head;

    while(last->next!=head){
        last=last->next;
    }

    head=head->next;
    last->next=head;
    delete temp;
}

void deleteend(){
    if(head==NULL){
        return;
    }

    if(head->next==head){
        delete head;
        head=NULL;
        return;
    }

    node* temp=head;
    node* prev=NULL;

    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }

    prev->next=head;
    delete temp;
}

void deletepos(int pos){
    if(head==NULL){
        return;
    }

    if(head->next==head){
        if(pos!=1){
            cout << "invalid position";
            return;
        }
        else{
            delete head;
            head=NULL;
            return;
        }
    }

    if(pos==1){
        deletebeg();
        return;
    }

    node* temp=head;
    node* prev=NULL;

    for(int i=1;i<pos && temp->next!=head;i++){
        prev=temp;
        temp=temp->next;
    }

    if(temp==head){
        cout << "invalid position" ;
        return;
    }

    prev->next=temp->next;
    delete temp;
}

void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    node* temp = head;
    while (temp->next != head) {   
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << temp->data << " -> (back to head)\n";
}


int main(){
    int ch,data,pos;
    do{
    cout << "---MENU---" << endl;
    cout << "1. insert node at beginning" << endl;
    cout << "2. insert at end" << endl;
    cout << "3. insert at a position" << endl;
    cout << "4. display linked list" << endl;
    cout << "5. delete at beginning" << endl;
    cout << "6. delete at end" << endl;
    cout << "7. delete at a position" << endl;
    cout << "8. EXIT" << endl;
    cout << "enter your choice: " ;
    cin >> ch;

    switch(ch){
        case 1:
        cout << "enter data for node: " ;
        cin >> data;
        insertbeg(data);
        break;

        case 2:
        cout << "enter data for node: " ;
        cin >> data;
        insertend(data);
        break;

        case 3:
        cout << "enter data for node: " ;
        cin >> data;
        cout << "enter which position: " ;
        cin >> pos;
        insertpos(data,pos);
        break;

        case 4:
        display();
        break;

        case 5:
        deletebeg();
        break;

        case 6:
        deleteend();
        break;

        case 7:
        cout << "delete at which position? : " ;
        cin >> pos;
        deletepos(pos);
        break;

        case 8:
        cout << "exiting program..." ;
        break;

        default:
        cout << "invalid input" << endl;
        }
    }while(ch!=8);
    
    return 0;  
}
