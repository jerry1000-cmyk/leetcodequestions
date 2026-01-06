#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
public:
   int data;
   Node* next;
   Node* prev;

   Node(int val){
    data = val;
    next = NULL;
    prev = NULL;
   }
};

class DoublyList{

   Node* head;
   Node* tail;
  
   public:
   DoublyList(){
      head = tail = NULL;
   }
   void push_front(int val){
      Node* newNode = new Node(val);
      if(head == NULL){
         head = tail =  newNode;
         return;
      }
      else{
         newNode->next = head;
         head->prev = newNode;
         head = newNode;
      }
   }
   void push_back(int val){
    Node* newNode = new Node(val);
    if(tail == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

   }

   void insert(int data , int position){
   if(position<0){
      cout<<"INVALID POSITION \n";
      return;
   }
   else if(position == 0){
      push_front(data);
      return;
   }
   Node* newNode = new Node(data);
   Node* temp = head;
   for(int i = 0 ; i<position-1;i++){
      temp = temp->next;
   }
   newNode->next = temp->next;
   newNode->prev = temp;
   temp->next->prev = newNode;
   temp->next = newNode;
  }

  void printll(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" <--> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;

  }
};

int main(){
    DoublyList ll;
    ll.push_front(1);
    ll.push_back(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_front(5);
    ll.push_back(6);
    ll.push_front(7);
    ll.push_back(8);
   

    ll.insert(15,3);
    ll.printll();
}