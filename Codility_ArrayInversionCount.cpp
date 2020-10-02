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
#include <vector>
#include <new>
#include <memory>
#include <iterator>

using namespace std;

/* Brute force O(n**2) 72%*/
// int solution(vector<int> &A)
// {
//    const int N=A.size();
//
//    if(N<=1) return 0;
//
//    long long count=0;
//
//    for(int i=0; i<N;++i)
//    {
//        for(int j=i+1;j<N;++j)
//        {
//            if(A[i]>A[j])
//            {
//                count++;
//            }
//        }
//    }
//
//    return (count>1000000000)?-1:count;
// }

/*9% Seems that the problem was not addresses correctly here.*/
int solution(vector<int> &A)
{
    const int N=A.size();

    if(N<=1) return 0;

    long long count=0;

    multimap<int,int> mm;

    for(auto i=0;i<N;++i)
    {
        mm.insert(make_pair(A[i],i));
    }

    for(auto i=0; i<N;++i)
    {
        auto it=prev(mm.end(),i+1);
        auto idxVal= it->second;
        count+=max(0,N-1-i-idxVal);
    }

    return (count>1000000000)?-1:count;
}

int main()
{
    int result;
    vector<int> a;

    a={-1,6,3,4,7,4};
    result=solution(a);
    cout<<result<<endl;
    assert(resul#include <iostream>
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
#include <vector>
#include <new>
#include <memory>
#include <iterator>

using namespace std;

/* Brute force O(n**2) 72%*/
// int solution(vector<int> &A)
// {
//    const int N=A.size();
// 
//    if(N<=1) return 0;
// 
//    long long count=0;
// 
//    for(int i=0; i<N;++i)
//    {
//        for(int j=i+1;j<N;++j)
//        {
//            if(A[i]>A[j])
//            {
//                count++;
//            }
//        }
//    }
// 
//    return (count>1000000000)?-1:count;
// }

int solution(vector<int> &A)
{
    const int N=A.size();

    if(N<=1) return 0;

    long long count=0;

    multimap<int,int> mm;

    for(auto i=0;i<N;++i)
    {
        mm.insert(make_pair(A[i],i));
    }

    for(auto i=0; i<N;++i)
    {
        auto it=prev(mm.end(),i+1);
        auto idxVal= it->second;
        count+=max(0,N-1-i-idxVal);
    }

    return (count>1000000000)?-1:count;
}

int main()
{
    int result;
    vector<int> a;

    a={-1,6,3,4,7,4};
    result=solution(a);
    cout<<result<<endl;
    assert(result==4);

    a={6,-1,3,7,4,4};
    result=solution(a);
    cout<<result<<endl;
    assert(result==6);

    a={};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={6};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={6,-1};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={6,3,1};
    result=solution(a);
    cout<<result<<endl;
    assert(result==3);

    return 0;
}
t==4);

    a={6,-1,3,7,4,4};
    result=solution(a);
    cout<<result<<endl;
    assert(result==6);

    a={};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={6};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={6,-1};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={6,3,1};
    result=solution(a);
    cout<<result<<endl;
    assert(result==3);

    return 0;
}
