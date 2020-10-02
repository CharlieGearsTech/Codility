#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <deque>
#include <stdlib.h>
#include <string>

using namespace std;

int solution(vector<int> &H)
{
    int stackAcum=0u;
    int countBlock = 0u;
    deque<int> stack;

    if(H.size() == 1)
        return 1;
    if(H.size() == 0)
        return 0;

    for(auto i = 0u; i< H.size();)
    {
        if(H[i] > stackAcum)
        {
            auto toAdd = H[i]-stackAcum;
            stack.push_back(toAdd);
            stackAcum += toAdd;
            countBlock++;
            ++i;
        }
        else if(H[i]< stackAcum)
        {
            stackAcum -= stack.back();
            stack.pop_back();
        }
        else if(H[i] == stackAcum)
            ++i;
    }
    return countBlock;
}

int main()
{
    vector<int> h = {8,8,5,7,9,8,7,4,8};
    int result = 0u;

    result= solution(h);
    cout<<result<<endl;
    assert(result == 7);
    h.clear();

    h= {8,8,8,8};
    result= solution(h);
    cout<<result<<endl;
    assert(result == 1);
    h.clear();

    h= {5,7,5,8,7,6,3,1};
    result= solution(h);
    cout<<result<<endl;
    assert(result == 7);
    h.clear();

    h= {5,7,0,8,7,6,3,1};
    result= solution(h);
    cout<<result<<endl;
    assert(result == 7);
    h.clear();

    h= {5,7,0,8,7,5,6,3,1};
    result= solution(h);
    cout<<result<<endl;
    assert(result == 8);
    h.clear();

    return 0;
}
