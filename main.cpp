#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <queue>
using namespace std;
#include <string>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>
#include <math.h>

void printPattern(int n)
{
    /*
     * STUDENT ANSWER
     */

    if (n > 0)
    {
        cout << n << " ";
        printPattern(n - 5);
        cout << " " << n;
    }
    else if (n <= 0)
    {
        cout << n;
    }
}
void printArray(int n)
{
    /*
     * STUDENT ANSWER
     */
    if (n == 0)
        cout << n;
    else if (n < 0)
        return;
    else if (n > 0)
    {
        printArray(n - 1);
        cout << ", " << n;
    }
}

bool isPalindrome(string str)
{
    if (str[0] == ' ')
        str.erase(0, 1);
    if (str[str.size() - 1] == ' ')
        str.erase(str.size() - 1, 1);
    if (str[0] != str[str.size() - 1])
        return false;
    if (str.size() == 1 || str.size() == 0)
        return true;
    str.erase(0, 1);
    str.erase(str.size() - 1, 1);
    return isPalindrome(str);
}
string mutil(string str, string word, int n)
{
    if (n == 0)
        return str;
    str += word;
    return mutil(str, word, --n);
}

string expand(string s)
{
    int l;
    int r;
    if (s.find(')') == string::npos)
        return s;
    r = s.find(')');
    string subs = "";
    subs = s.substr(0, r + 1);
    l = subs.find_last_of('(');

    int num = s[l - 1] - '0';
    string word = s.substr(l + 1, r - 1 - l);
    string str = "";
    str = mutil(str, word, num);
    s.replace(l - 1, r - l + 2, str);
    return expand(s);
}

int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    return a * power(a, --b);
}
int myArrayToInt(char *str, int n)
{
    /*
     * STUDENT ANSWER
     */
    if (n == 1)
        return str[0] - '0';
    return (str[0] - '0') * power(10, n - 1) + myArrayToInt(str + 1, --n);
}
int buyCar(int *nums, int length, int k)
{
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (nums[i] > nums[j])
                swap(nums[i], nums[j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += nums[i];
        if (sum <= k)
            res++;
        if (sum >= k)
            break;
    }
    return res;
}

// int longestSublist(vector<string> &words)
// {
//     // STUDENT ANSWER
//     int max = 0;
//     words.push_back("@");
//     for (int i = 0; i < words.size(); i++)
//     {
//         int len = 0;
//         for (int j = i; j < words.size(); j++)
//         {
//             if (words[i][0] == words[j][0])
//                 len++;
//             else
//             {
//                 if (len > max)
//                     max = len;
//                 break;
//             }
//         }
//     }
//     return max;
// }

template <class T>
class ArrayList
{
protected:
    T *data;      // dynamic array to store the list's items
    int capacity; // size of the dynamic array
    int count;    // number of items stored in the array
public:
    ArrayList()
    {
        capacity = 5;
        count = 0;
        data = new T[5];
    }
    ~ArrayList() { delete[] data; }
    void add(T e)
    {
        if (count == capacity)
        {
            ensureCapacity(capacity);
        }
        data[count] = e;
        count++;
    }
    void add(int index, T e)
    {
        if (count == capacity)
        {
            ensureCapacity(capacity);
        }
        if (index < 0 || index > count)
        {
            throw std::out_of_range("the input index is out of range!");
        }
        else
        {
            if (index == count)
            {
                data[index] = e;
                count++;
            }
            else
            {
                for (int i = count; i > index; i--)
                {
                    data[i] = data[i - 1];
                }
                data[index] = e;
                count++;
            }
        }
    }
    int size()
    {
        return count++;
    }

    void ensureCapacity(int cap)
    {
        if (cap == capacity)
        {
            int size = capacity * 1.5;
            T *arr = data;
            data = new T[size];
            for (int i = 0; i < count; i++)
            {
                data[i] = arr[i];
            }
            capacity *= 1.5;
            delete[] arr;
        }
    }
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << data[i] << " ";
        }
    }
    
};
int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    int arr[26] = {0};
    for(int i=0;i<words.size();i++){
        arr[int(words[i][0])-97]++;
        cout<<int(words[i][0])-97<<" ";
    }
    
    int max = 0;
    for(int i=0;i<26;i++){
        if(arr[i]>max) max=arr[i];
    }
    return max;
}


// template <class T>
// SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
// {
    //             this->pList = pList;
    //             if (begin) {
    //                 this->current = pList ? pList->head : nullptr;
    //                 this->index = pList ? 0 : -1;
    //             } else {
    //                 this->current = nullptr;
    //                 this->index = pList ? pList->size() : -1;
    //             }
    // }

// template <class T>
// typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
// {
//     this->pList = iterator.pList;
//     this->current = iterator.current;
//     this->index = iterator.index;
//     return *this;
// }



// template <class T>
// void SLinkedList<T>::Iterator::set(const T &e)
// {
//     if (current)
//         current->data = e;
// }

// template <class T>
// T &SLinkedList<T>::Iterator::operator*()
// {
//     if (current)
//         return current->data;
//     throw std::out_of_range("Iterator out of range");
// }

// template <class T>
// bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
// {
//     return current != iterator.current;
// }

// template <class T>
// void SLinkedList<T>::Iterator::remove() {
//             if (this->current == nullptr) throw std::out_of_range("Segmentation fault!");

//             if (this->index == 0) {
//                 this->pList->removeAt(0);
//                 this->current = nullptr;
//                 this->index = -1;
//             } else {
//                 Node* tmp = this->pList->head;
//                 for (int i = 0; i < this->index - 1; i++) tmp = tmp->next;
//                 this->current = tmp;
//                 this->pList->removeAt(this->index);
//                 this->index = this->index - 1;
//             }
//         }

// template <class T>
// typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
// {
//     if (current)
//     {
//         current = current->next;
//         index++;
//     }
//     return *this;
// }

// template <class T>
// typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
// {
//     Iterator temp = *this;
//     ++(*this);
//     return temp;
// }

    bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>>dp(n+1, vector<bool>(m+1,false));

    dp[0][0]=true;

    for(int i=0; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[j-1] != '*'){
                dp[i][j]=i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1];
            } 
            else{
                dp[i][j]=dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
            }
        }
    }

    return dp[n][m];
    }

int mininumBracketAdd(string s){
    if(s.find("()")!=string::npos){
        s.erase(s.find("()"),2);
        return(mininumBracketAdd(s));
    }
    if(s.size()==0) return 0;
    return s.size();
 

}

// string reverseSentence(string s){
//     if(s.size()==0) return "";
//     if(s.size()==1) return s;
    
//     return s[s.size()-1]+reverseSentence(s.erase(s.size()-1,1));
// }

// vector<int> stock_span(const vector<int>& ns) {
//     // STUDENT ANSWER
//     vector<int> res;
//     res.push_back(1);
//     stack<int> st;  // luu index;
//     st.push(0);
//     for(unsigned int i=1;i<ns.size();i++){
//         // bo cac so nho hon
//         while(!st.empty()&& ns[st.top()]<=ns[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             res.push_back(i+1);
//         }
//         else{
//             res.push_back(i-st.top());
//         }
//         st.push(i);
//     }
//     return res;
// }
// iostream, vector and queue are included
// You can write helper methods


long long nthNiceNumber(int n) {
    queue<string> q;
    q.push("");
    int k=0;
    string s;
    while(k!=n){
        s=q.front()+'2';
        k++;
        if(k==n) break;
        q.push(s);
        s=q.front()+'5';
        k++;
        if(k==n) break;
        q.push(s);
        q.pop();
    }
    long long res=0;
    for(auto digit: s){
        res=res*10+ (digit-'0');
    }
    return res;
}

// iostream, vector and queue are included
// Hint: use breadth-first-search

int secondsToBeRotten(vector<vector<int>>& grid) {
    // lưu số táo hỏng hiện tại
    // số táo chưa hỏng
    // duyệt hết số táo hỏng hiện tại
    // thêm số bị làm hỏng
    // khi duyệt hết táo hỏng hiện tại sẽ duyệt tiếp táo bị làm hỏng tiếp theo;
    queue<int> x;
    queue<int> y;
    int countRotNow=0;
    int day=0;
    int countRotNext=0;
    int countFresh=0;

    int xAxis[]={0,1,0,-1};
    int yAxis[]= {1,0,-1,0};
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2){
                countRotNow++;
                grid[i][j]=0;
                x.push(i);
                y.push(j);
            }
            else if(grid[i][j]==1){
                countFresh++;
            }
        }
    }
    while(!x.empty()){
        countRotNow--;
        for(int i=0;i<4;i++){
            int xCoor=x.front()+xAxis[i];
            int yCoor=y.front()+ yAxis[i];
            if(xCoor>=0 && xCoor<grid.size() && yCoor>=0 && yCoor<grid[0].size() && grid[xCoor][yCoor]==1){
                grid[xCoor][yCoor]=0;
                x.push(xCoor);
                y.push(yCoor);
                countFresh--;
            }
        }
        x.pop();
        y.pop();
        if(countRotNow==0 && countRotNext>0){
            day++;
            countRotNow=countRotNext;
            countRotNext=0;
        }
    }
    if(countFresh) return -1;
    return day;
}

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n=nums.size();
    if(n<k){
        return -1;
    }
    queue<int> q;
    int sum=0;
    int sumMax;
    for(int i=0;i<k;i++){
        q.push(nums[i]);
        sum+=nums[i];
    }
    sumMax=sum;
    for (int i=k;i<n;i++){
        sum-=q.front();
        q.pop();
        sum+=nums[i];
        q.push(nums[i]);
        sumMax=max(sum,sumMax);
    }
    return sumMax;
}



int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<sumOfMaxSubarray(v,3);
   
}