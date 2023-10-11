#include <iostream>
#include <list>
#include<stack>
using namespace std;

// template <class T>
// class DLinkedList {
// public:
//     class Node; // Forward declaration
// protected:
//     Node* head;
//     Node* tail;
//     int count;
// public:
//     DLinkedList(){
//       head=NULL;
//       tail=NULL;
//       count=0;
//     }
//     // ~DLinkedList();
//     void    add(const T &e);
//     // void    add(int index, const T &e);
//     // int     size();
//     // bool    empty();
//     // T       get(int index);
//     // void    set(int index, const T &e);
//     // int     indexOf(const T &item);
//     // bool    contains(const T &item); 
//     T       removeAt(int index);
//     bool    removeItem(const T &item);
//     void    clear();
// public:
//     class Node
//     {
//     private:
//         T data;
//         Node *next;
//         Node *previous;
//         friend class DLinkedList<T>;

//     public:
//         Node()
//         {
//             this->previous = NULL;
//             this->next = NULL;
//         }

//         Node(const T &data)
//         {
//             this->data = data;
//             this->previous = NULL;
//             this->next = NULL;
//         }
//     };

// };

// template <class T>
// void DLinkedList<T>::add(const T& e) {
//     /* Insert an element into the end of the list. */
//     Node* newNode=new Node(e);
//     if(head==NULL){
//         head=newNode;
//         tail=newNode;
//         count=1;
//     }
//     else{
//         tail->next=newNode;
//         newNode->previous=tail;
//         tail=newNode;
//         count++;
//     }
// }
// template <class T>
// T DLinkedList<T>::removeAt(int index)
// {
//     /* Remove element at index and return removed value */
//     if(count==1){
//         count--;

//         int val=head->data;
//         delete head;
//         head=NULL;
//         tail=NULL;
//         return val;
//     }
//     else if(index==0){
//         count--;
//         int val=head->data;
//         Node* del=head;
//         head=head->next;
//         delete del;
//         return val;
//     }
//     else if(index==count-1){
//       count--;
//         int val=tail->data;
//         Node* del=tail;
//         tail=tail->previous;
//         tail->next=NULL;
//         delete del;
//         return val;
//     }
//     else{
//       count--;
//         Node* tmp=head;
//         for(int i=0;i<index;i++){
//             tmp=tmp->next;
//         }
//         Node* del=tmp;
//         int val=del->data;
//         tmp->previous->next=tmp->next;
//         tmp->next->previous=tmp->previous;
//         delete del;
//         return val;
//     }
    
// }

// template <class T>
// bool DLinkedList<T>::removeItem(const T& item)
// {
//     /* Remove the first apperance of item in list and return true, otherwise return false */
//     Node* tmp=head;
//     for(int i=0;i<count;i++){
//         if(tmp->data==item){
//             removeAt(i);
//             return true;
//         }
//         tmp=tmp->next;
//     }
//     return false;
// }

// template<class T>
// void DLinkedList<T>::clear(){
//     /* Remove all elements in list */
//     while(head!=NULL){
//         removeAt(0);
//     }
// }

bool canEatFood(int maze[5][5], int fx, int fy)
{
    
    if (maze[fx][fy] == 0)
        return false;
    int xAxis[] = {0, 1, 0, -1};
    int yAxis[] = {1, 0, -1, 0};
    stack<int> x;
    stack<int> y;
    x.push(0);
    y.push(0);
    while (!x.empty())
    {
        maze[x.top()][y.top()]=false;
        int xtop=x.top();
        int ytop=y.top();
        if(xtop==fx && ytop==fy) return true;
        x.pop();
        y.pop();
        for (int i=0;i<4;i++){
            int xCoor=xAxis[i]+xtop;
            int yCoor=yAxis[i]+ ytop;
            if(xCoor>=0 && xCoor<5 && yCoor>=0 && yCoor<5 && maze[xCoor][yCoor]){

                x.push(xCoor);
                y.push(yCoor);
            }
        }

    }
    return false;
}

int main()
{
    int maze[5][5] = {
    { 1, 0, 1, 1, 0 },
    { 1, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 1 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 }
};

// Food coordinates
int fx = 2, fy = 3;

cout << canEatFood(maze, fx, fy);

}  