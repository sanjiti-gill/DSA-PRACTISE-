#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

void deletebeg(){
    if(head==NULL){
        cout << "list empty" << endl;
        return;
    }
    node* temp=head;
    head=temp->next;
    delete temp;
}

void deleteend(){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    node* temp=head;
    node* prev=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
        prev=temp;
    }
    prev->next=NULL;
    delete temp;
}

void deletepos(int pos) {
    if (head == NULL) {
        return;
    }

    if (pos == 1) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* temp = head;
    node* prev = NULL;

    for(int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}



void insertbeg(int data){
    node* newnode= new node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

void insertend(int data){
    node* newnode= new node;
    newnode->data=data;
    newnode->next=NULL;
    node* temp=head;
    if(head==NULL){
        head=newnode;
        return;
    }
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertpos(int data, int pos){
    node* newnode= new node;
    newnode->data=data;
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    
    node* temp=head;
    for(int i=1;i<pos-1 && temp; i++){
        temp=temp->next;
        if(temp == NULL){
            cout << "Invalid position\n";
            return;
        }

    }
    temp->next=newnode;
    newnode->next=temp->next;
}

void display(){
    node* temp=head;
    while(temp->next!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL \n" << endl;
}

int main(){
    int ch, data,pos;
    do{
        cout << "---MENU--- " << endl;
        cout << "1.insert at beginning \n" << endl;
        cout << "2. insert at end \n" << endl;
        cout << "3. insert at a position \n" << endl;
        cout << "4. delete at beginning \n" << endl;
        cout << "5. delete at end \n" << endl;
        cout << "6. delete at a position \n" << endl;
        cout << "7. display \n" << endl;
        cout << "8. EXIT \n" << endl;
        cout << "enter your choice: " ;
        cin >> ch;
        
        switch(ch){
            case 1:
                cout << "enter data for node: " ;
                cin >> data;
                insertbeg(data);
                break;
            case 2:
                cout << "enter data for node: ";
                cin >> data;
                insertend(data);
                break;
            case 3:
                cout << "enter data for node: ";
                cin >> data;
                cout << "enter position to insert";
                cin >> pos;
                insertpos(data,pos);
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                cout << "enter position : " ;
                cin >> pos;
                deletepos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "exiting program" << endl;
                break;
            default:
                cout << "invalid input" << endl;
        }
    }while(ch!=8);
    return 0;
}
