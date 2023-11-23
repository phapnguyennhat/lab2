#include <iostream>
#include <sstream>
#include <string>
#include<vector>
#include<queue>
#include<math.h>
#include<map>
#include<algorithm>
#include<set>
using namespace std;


int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    multiset<int> s(nums.begin(),nums.end());
    multiset<int> ::iterator it=s.begin();

    for(int i=0;i<k;i++){
        s.insert(*it*2);
        s.erase(it);
        it=s.begin();
    }
    return *it;
}
int main(){
    vector<int> nums {1, 3, 3, 2};
int k = 4;
cout << leastAfter(nums, k);

}