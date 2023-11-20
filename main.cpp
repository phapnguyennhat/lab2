#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
  LH = -1,
  EH = 0,
  RH = 1
};

void printNSpace(int n)
{
  for (int i = 0; i < n - 1; i++)
    cout << " ";
}

void printInteger(int &n)
{
  cout << n << " ";
}

template <class T>
class AVLTree
{
public:
  class Node;

private:
  Node *root;

protected:
  int getHeightRec(Node *node)
  {
    if (node == NULL)
      return 0;
    int lh = this->getHeightRec(node->pLeft);
    int rh = this->getHeightRec(node->pRight);
    return (lh > rh ? lh : rh) + 1;
  }

public:
  AVLTree() : root(nullptr) {}
  ~AVLTree() {}
  int getHeight()
  {
    return this->getHeightRec(this->root);
  }
  void printTreeStructure()
  {
    int height = this->getHeight();
    if (this->root == NULL)
    {
      cout << "NULL\n";
      return;
    }
    queue<Node *> q;
    q.push(root);
    Node *temp;
    int count = 0;
    int maxNode = 1;
    int level = 0;
    int space = pow(2, height);
    printNSpace(space / 2);
    while (!q.empty())
    {
      temp = q.front();
      q.pop();
      if (temp == NULL)
      {
        cout << " ";
        q.push(NULL);
        q.push(NULL);
      }
      else
      {
        cout << temp->data;
        q.push(temp->pLeft);
        q.push(temp->pRight);
      }
      printNSpace(space);
      count++;
      if (count == maxNode)
      {
        cout << endl;
        count = 0;
        maxNode *= 2;
        level++;
        space /= 2;
        printNSpace(space / 2);
      }
      if (level == height)
        return;
    }
  }
  // Helping functions
  Node* rotateLeft(Node *&root)
  {
    Node *right_tree = root->pRight;
    root->pRight = right_tree->pLeft;
    right_tree->pLeft = root;
    root = right_tree;
    return root;
  }
  Node* rotateRight(Node *&root)
  {
    Node *left_tree = root->pLeft;
    root->pLeft = left_tree->pRight;
    left_tree->pRight = root;
    root = left_tree;
    return root;
  }
  void right_balance(Node *&root)
  {
    Node *right_tree = root->pRight;
    if (right_tree->balance == RH)
    {
      root->balance = EH;
      right_tree->balance = EH;
      root=rotateLeft(root);
    }
    else if (right_tree->balance == LH)
    {
      Node *sub_tree = right_tree->pLeft;
      if (sub_tree->balance == EH)
      {
        root->balance = EH;
        right_tree->balance = EH;
      }
      else if (sub_tree->balance == LH)
      {
        right_tree->balance = RH;
        root->balance = EH;
      }
      else if (sub_tree->balance == RH)
      {
        right_tree->balance = EH;
        root->balance = LH;
      }
      sub_tree->balance = EH;
      root->pRight=rotateRight(root->pRight);
      root=rotateLeft(root);
    }
    else if (right_tree->balance == EH && right_tree->pLeft != NULL && right_tree->pRight != NULL)
    {
      root->balance=RH;
      right_tree->balance=LH;
      root=rotateLeft(root);
    }
  }
  void left_balance(Node *&root)
  {
    Node *left_tree = root->pLeft;
    if (left_tree->balance == LH)
    {
      root->balance = EH;
      left_tree->balance = EH;
      root=rotateRight(root);
    }
    else if (left_tree->balance == RH)
    {
      Node *sub_tree = left_tree->pRight;
      if (sub_tree->balance == EH)
      {
        left_tree->balance = EH;
        root->balance = EH;
      }
      else if (sub_tree->balance == LH)
      {
        left_tree->balance = EH;
        root->balance = RH;
      }
      else
      {
        root->balance = EH;
        left_tree->balance = LH;
      }
      sub_tree->balance = EH;
      root->pLeft=rotateLeft(root->pLeft);
      root=rotateRight(root);
    }
    else if(left_tree->balance==EH&&left_tree->pLeft!=NULL&&left_tree->pRight!=NULL){
      root->balance=LH;
      left_tree->balance=RH;
      root=rotateRight(root);
    }
  }
  // Helping functions
  Node* maxValueNode(Node* root){
    while(root->pRight!=NULL){
      root=root->pRight;
    }
    return root;
  }
  Node* removeRecur(Node* root,const T& value,bool& shorter){
    if(root==NULL){
      shorter=false;
      return root;
    }
    else if(value<root->data){
      root->pLeft=removeRecur(root->pLeft,value,shorter);
      if(shorter==true){
        // xoa trai
        if(root->balance==RH){
          right_balance(root);
          shorter=false;
        }
        else if(root->balance==EH){
          root->balance=RH;
          shorter=false;
        }
        else{
          root->balance=EH;
        }
      }
    }
    else if(value>root->data){
      root->pRight=removeRecur(root->pRight,value,shorter);
      if(shorter==true){
        if(root->balance==LH){
          left_balance(root);
          shorter=false;
        }
        else if(root->balance==EH){
          root->balance=LH;
          shorter=false;
        }
        else{
          root->balance=EH;
        }
      }
    }
    else{
      if(root->pLeft==NULL){
        shorter=true;
        Node* tmp=root->pRight;
        delete root;
        return tmp;
      }
      else if(root->pRight==NULL){
        shorter=true;
        Node* tmp=root->pLeft;
        delete root;
        return tmp;
      }
      else{
        Node* tmp=maxValueNode(root->pLeft);
        root->data=tmp->data;
        root->pLeft=removeRecur(root->pLeft,tmp->data,shorter);
      }
    }
    return root;
  }
void insertRecur(Node* &root, const T & value, bool & taller){
    if(root==NULL){
        root=new Node(value);
        taller=true;
    }
    
    else if(value<root->data){
        insertRecur(root->pLeft,value,taller);
        if(taller==true){
            if(root->balance==LH){
                // can bang ben trai
                left_balance(root);
                taller=false;
            }
            else if(root->balance==EH){
                root->balance=LH;
            }
            else{
                root->balance=EH;
                taller=false;
            }
        }
    }
    else{
        insertRecur(root->pRight,value,taller);
        if(taller==true){
            if(root->balance==RH){
                // can bang ben phai
                right_balance(root);
                taller= false;
            }
            else if(root->balance==EH){
                root->balance=RH;
            }
            else{
                root->balance=EH;
                taller=false;
            }
        }
    }
}
void insert(const T &value){
    //TODO
    // balance
    // l-l
    // r-l
    bool taller=true;
    insertRecur(root, value, taller);
}
  void remove(const T &value)
  {
    printTreeStructure();
    // TODO
    bool shorter = true;
    root=removeRecur(root, value, shorter);
  }
  class Node
  {
  private:
    T data;
    Node *pLeft, *pRight;
    BalanceValue balance;
    friend class AVLTree<T>;

  public:
    Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
    ~Node() {}
  };
};
int main()
{

	
	
	
	
AVLTree<int> avl;
int arr[] = {20,10,40,5,7,42,2,6,15};
for (int i = 0; i < 9; i++){
  avl.insert(arr[i]);
}
avl.remove(6);
avl.remove(42);
avl.printTreeStructure();
}