#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
public:
   int data;
   Node* next;

   Node(int val){
    data = val;
    next = NULL;
   }
};

class List{

   Node* head;
   Node* tail;
  
   public:
   List(){
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
         head = newNode;
      }
   }

   void printll(){
      Node* temp = head;
      while(temp!= NULL){
         cout<<temp->data<<" --> ";
         temp = temp->next;
      }
      cout<<"NULL"<<endl;;
   }

   void push_back(int val){
      Node* newNode = new Node(val);
      if(tail == NULL){
         head = tail =  newNode;
         return;
      }
      else{
         tail->next = newNode;
         tail = newNode;
      }
   }
   void pop_front(){
      if(head == NULL){
         cout<<"LL is empty"<<endl;
         return;
      }
      else{
         Node* temp = head;
         head = head->next;
         temp->next = NULL;
         delete temp;
      }
   }
  void pop_back(){
   if(head == NULL){
      cout<<"LL is empty"<<endl;
      return;
   }
   else if(head == tail){
        delete head;
        head = tail = NULL;
        return;
   }
   else{
      Node* temp = head;
      while(temp->next != tail){
         temp = temp->next;
      }
      temp->next = NULL;
      delete tail;
      tail = temp;

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
   temp->next = newNode;
  }
};

int main(){
   List ll;
   ll.push_back(1);
   ll.push_front(2);
   ll.push_back(3);
   ll.push_front(4);
   ll.push_back(5);
   ll.push_front(6);
   ll.push_back(7);
   ll.push_front(8);

   
   ll.printll();
   
   ll.pop_front();
   ll.printll();
   ll.pop_back();
   ll.printll();
   ll.insert(9,0);
   ll.printll();
}