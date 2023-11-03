#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<stack>
using namespace std;
class Node{
  public:
    int val;
    Node* left;
    Node* right;
  Node(int val,Node* left=NULL,Node* right=NULL): val(val),left(left),right(right){};

  
  ~Node(){
    delete left;
    delete right;
  }

};

void inOrder(Node* root){
  if(root==NULL) return;
  inOrder(root->left);
  cout<<root->val<<" ";
  inOrder(root->right);
}
void addRecur(Node* r,int val){
    if(r==NULL){
        r=new Node(val);
    }
    else if(val<=r->val){
        addRecur(r->left,val);
    }
    else if(val>r->val){
        addRecur(r->right,val);
    }
}
void deleteNode(int value){
    //TODO
    
}
int singleChild(Node* root) {
    // STUDENT ANSWER
    if(root==NULL) return 0;
    if(root->left!=NULL&&root->right!=NULL){
      return singleChild(root->left)+singleChild(root->right);
    }
    else if(root->left!=NULL&&root->right==NULL){
      return 1+singleChild(root->left);
    }
}


int main(){
    Node* root=new Node(0);
    root->right=new Node(3);
    root->right->left=new Node(1);
    root->right->right=new Node(5);
    root->right->left->right=new Node(2);
    root->right->right->left=new Node(4);
    cout<<singleChild(root);
    delete root;


}