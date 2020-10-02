#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <deque>

using namespace std;

int solution(vector<int> &A)
{
    deque<int> stack;

    int value = 0U;

    for(auto i = 0u; i< A.size(); ++i)
    {
        if(stack.empty())
        {
            value= A[i];
            stack.push_back(A[i]);
        }
        else
        {
            if(value != A[i])
                stack.pop_back();
            else
                stack.push_back(A[i]);
        }
    }

    int res = -1;

    auto lastIt= unique(stack.begin(), stack.end());

    for(auto it= stack.begin(); it != lastIt; ++it)
        if((size_t)count(A.begin(), A.end(),*it) > (A.size()/2))
            res= find(A.begin(),A.end(),*it)-A.begin();

    return res;
}

int main()
{
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};

    int result = solution(v);
    cout<<result<<endl;
    assert(result==5);
    v.clear();

    v= {3,2,3,4,3,3,3,-1};
    result = solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v= {};
    result = solution(v);
    cout<<result<<endl;
    assert(result==-1);
    v.clear();

    v= {1,0,2};
    result = solution(v);
    cout<<result<<endl;
    assert(result==-1);
    v.clear();

    v= {1,2,2};
    result = solution(v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v= {1,2};
    result = solution(v);
    cout<<result<<endl;
    assert(result==-1);
    v.clear();

    return 0;
}
