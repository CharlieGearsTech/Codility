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
#include <set>

using namespace std;

int solution(int K, vector<int> &A)
{
    auto N= A.size();

    unsigned length=0;
    unsigned countRopes=0;

    for(auto i = 0u; i < N; ++i)
    {
        length+=A[i];
        /*Check if the tied rope is greather or equal than K*/
        if(length >= (unsigned)K)
        {
            /*Cut the ropes to start over again*/
            length=0;
            countRopes++;
        }
    }
    return countRopes;
}

int main()
{
    vector<int> v;
    int result=0;

    v={1,2,3,4,1,1,3};
    result=solution(4,v);
    cout<<result<<endl;
    assert(result==3);
    v.clear();


    v={4};
    result=solution(4,v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v={1};
    result=solution(4,v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={4};
    result=solution(1,v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v={1,2,3,4,1,1,3};
    result=solution(2,v);
    cout<<result<<endl;
    assert(result==5);
    v.clear();

    return 0;
}
