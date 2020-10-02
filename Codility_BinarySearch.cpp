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

/*Retornar el indice que sea igual o menor mas cercano a X*/
int binarySearch(vector<int>& A, int x)
{
    const unsigned  N= A.size();
    int begin=0;
    int end=N-1;

    int result=-1;

    while(begin<=end)
    {
        auto mid=(begin+end)/2;

        if(A[mid]<=x)
        {
            begin=mid+1;
            result=mid;
        }
        else
            end= mid-1;
    }
    return result;
}

/*No functional*/
int check(vector<int>& A,int k)
{
    const unsigned N=A.size();
    unsigned boards=0;
    int last=-1;

    for(auto i=0;i<N;++i)
    {
        if(A[i]==1 && last<i)
        {
            boards++;
            last=i+k-1;
        }
    }
    return boards;
}

/*No functional*/
int boards(vector<int>& A, int k)
{
    const unsigned N=A.size();
    int begin=1;
    int end=N-1;

    int result=-1;

    while(begin<=end)
    {
        auto mid= (end-begin)/2;

        if(check(A,mid) <= k)
        {
            end=mid-1;
            result=mid;
        }
        else
            begin=mid+1;
    }
    return result;
}

int main()
{
    vector<int> v;
    auto result=0u;

    v={1,2,3,5,5,6,8,9};
    result=binarySearch(v,4);
    cout<<result<<endl;
    v.clear();

    v={1,0,0,0,1,1,1,1};
    result=boards(v,1);
    cout<<result<<endl;
    v.clear();

    return 0;
}
