#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(int N, vector<int> &A)
{
    vector<int> count(N,0u);

    for(size_t i = 0; i < A.size(); ++i)
    {
        if(A[i] <= N)
            count[A[i]-1]++;
        else
        {
            size_t counter_max = *max_element(count.begin(), count.end());
            std::fill(count.begin(),count.end(), counter_max);
        }
    }

    return count;
}

void assertV( vector<int>& result,  vector<int>&& comp)
{
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

void printV(const vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

int main()
{
    vector<int> v= {3,4,4,6,1,4,4};
    vector<int> res;

    res= solution(5,v);
    printV(res);
    assertV(res,{3,2,2,4,2});
    v.clear();

    v = {6,2,1,6,6,2,3};
    res= solution(4,v);
    printV(res);
    assertV(res,{1,2,2,1});

    v = {6,5,5,6,6,5,5};
    res= solution(4,v);
    printV(res);
    assertV(res,{0,0,0,0});

    return 0;
}
