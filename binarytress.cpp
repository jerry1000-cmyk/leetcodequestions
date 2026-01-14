#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;
  
  Node(int val){
    data = val;
    left = right = NULL;
  }

};

class binarytree{


};

static int idx = -1;
Node* buildtree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);

    return root;
}

void preordertrav(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preordertrav(root->left);
    preordertrav(root->right);
}

void inordertrav(Node* root){
    if(root == NULL){
        return;
    }
    inordertrav(root->left);
    cout<<root->data<<" ";
    inordertrav(root->right);
}

void postordertrav(Node* root){
    if(root == NULL){
        return;
    }
    postordertrav(root->left);
    postordertrav(root->right);
    cout<<root->data<<" ";
}

void levelordertrav(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

int heightofbt(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftht = heightofbt(root->left);
    int rightht = heightofbt(root->right);

    return max(leftht,rightht) + 1;
}

int countnodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftnode = countnodes(root->left);
    int rightnode = countnodes(root->right);

    return leftnode + rightnode + 1;
}

int main(){
   vector<int> tree = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,-1};
   Node* root = buildtree(tree);
   preordertrav(root);
   cout<<endl;
   inordertrav(root);
   cout<<endl;
   postordertrav(root);
   cout<<endl;
   levelordertrav(root);
   cout<<endl;
   cout<< heightofbt(root)<<endl;
   cout<<countnodes(root)<<endl;
   return 0;

   
}