#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
int solution(int A, int B, int K)
{
    vector<int> v(B-A+1,0u);
    vector<int> mask(B-A+1,1u);
    mask.at(0)=A;
    int count=0;

    vector<int> results(B-A,0u);

    std::partial_sum(mask.begin(),mask.end(), v.begin());

    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it % K) == 0)
            count++;

    return count;
} */

int main()
{

    int A = 6, B = 11;
    int K = 2;
    int count =0;

    count=solution(A,B,K);
    cout<<count<<endl;
    assert(count==3u);

    A=6, B=11;
    K = 3;
    count=solution(A,B,K);
    cout<<count<<endl;
    assert(count==2u);

    A=0, B=10;
    K = 2;
    count=solution(A,B,K);
    cout<<count<<endl;
    assert(count==6u);

    A=0, B=10;
    K = 3;
    count=solution(A,B,K);
    cout<<count<<endl;
    assert(count==4u);

    A=0, B=1000;
    K = 10;
    count=solution(A,B,K);
    cout<<count<<endl;
    assert(count==101u);

    return 0;
}
