#include<iostream>
using namespace std;

struct Node{
    int data; //linked ka aage jo hota hai
    struct Node *next; //basically a pointer pointing to next node so datatype is node 
};

struct Node* head = NULL; //globally declared

void insert_begin(int new_data){
    struct Node *new_node = new Node; //insert karna hai toh new data dalne ki ke liye node ki need hai so phele new node banaige
    new_node->data = new_data; //new_node jo name diya usko data diya
    new_node->next = head; //new_node mai jo nextptr hoga vo head ke ptr ko point karega...kyuki yeh begining mai lag raha hai
    head = new_node; //jo aage lagaya vahi ab head ho jaiga toh uska head bol denge
} 

void insert_begin(int new_data){
    struct Node *new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = head; 
    head = new_node; 
} 

void insert_last(int new_data){
    if(head==NULL){
        return insert_begin(new_data);
    }
    
    struct Node *new_node = new Node; //insert karna hai toh new data dalne ki ke liye node ki need hai so phele new node banaige
    new_node->data = new_data; //new_node jo name diya usko data diya
    new_node->next = NULL; //new_node mai jo nextptr hoga vo null ko point karega...kyuki yeh last mai lag raha hai
    struct Node* ptr = head;
    while(ptr->next!=NULL){ //null ke ek phele tak chalega
        ptr=ptr->next;
    }
    ptr->next = new_node; //jo new node hai uska address jo phele null tha usme daldenge
} 

void insert_middle(int new_data,int position){
    if(head==NULL){
        return insert_begin(new_data);
    }

    struct Node *new_node = new Node; //insert karna hai toh new data dalne ki ke liye node ki need hai so phele new node banaige
    new_node->data = new_data; //new_node jo name diya usko data diya
    struct Node* ptr = head;
    for(int i = 1; i<position; i++){
        if(ptr->next!=NULL){
            ptr=ptr->next;
        }
    }
    new_node->next = ptr->next;
    ptr->next=new_node;
}

void delete_begin(){
    head = head->next;
}

void delete_end(){
    struct Node* ptr = head;
    while(ptr->next->next!=NULL){ //null ke ek phele tak chalega
        ptr=ptr->next;
    }
    ptr->next = NULL;
}

void delete_middle(int position){
   struct Node* ptr = head;
    for(int i = 1; i<position; i++){
        if(ptr->next!=NULL){
            ptr=ptr->next;
        }
    }
    ptr->next = ptr->next->next;
}

void search(int data){
    struct Node* ptr = head;
    while(ptr!=NULL){ //null ke ek phele tak chalega
    if(ptr->data == data){
        cout<<data<<endl;
        return;
    }else{
        ptr=ptr->next;
    }
}
cout<<"Item not present"<<endl;
}

void display(){
    if(head==NULL){
        cout<<"No elments in the list"<<endl;;
    }
    struct Node* ptr = head; //head pe point kiya ptr ko
    while(ptr!=NULL){  //ptr tab tak chalna hai jab tak vo null ko point na kare that means last
        cout<<ptr->data<<endl; //jaha hai vaha ka data print kiya
        ptr=ptr->next; // now print karne ke baad vo aage gaya tab tak jaiga jab tak vo null ko point na kare
    }
}

int main(){
    
    // insert_begin(4); //4
    insert_last(5);
    insert_begin(6); //6 4
    insert_last(5);
    insert_middle(3,2);
    display();
    cout<<"After Deletaion"<<endl;
    // delete_begin();
    // delete_end();
    // delete_middle(3);
    search(2);
    // display(); // 6 4



}
