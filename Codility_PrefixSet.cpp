/*

A non-empty array A consisting of N integers is given. The first covering prefix of array A is the smallest integer P such that 0≤P<N and such that every value that occurs in array A also occurs in sequence A[0], A[1], ..., A[P].

For example, the first covering prefix of the following 5−element array A:
  A[0] = 2
  A[1] = 2
  A[2] = 1
  A[3] = 0
  A[4] = 1

is 3, because sequence [ A[0], A[1], A[2], A[3] ] equal to [2, 2, 1, 0], contains all values that occur in array A.

Write a function

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the first covering prefix of A.

For example, given array A such that
  A[0] = 2
  A[1] = 2
  A[2] = 1
  A[3] = 0
  A[4] = 1

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..1,000,000];
        each element of array A is an integer within the range [0..N−1].

*/
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
#include <cctype>
#include <sstream>
#include <stdio.h>

using namespace std;

/*100% https://app.codility.com/demo/results/trainingQ2RUS7-RZC/*/
int solution(vector<int> &A)
{
    const int N=A.size();
    vector<int> track(N,0);

    long result=0;

    for(auto i=0; i<N; ++i)
    {
        if(track[A[i]] != true)
        {
            track[A[i]]=true;
            result=i;
        }
    }
    return result;
}

int main()
{
    vector<int> v;
    int result=0;

    v={2,2,1,0,1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==3);
    v.clear();

    v={2,2,1,0,5};
    result=solution(v);
    cout<<result<<endl;
    assert(result==4);
    v.clear();

    v={1,2,3,4,5,6,1,2,3};
    result=solution(v);
    cout<<result<<endl;
    assert(result==5);
    v.clear();

    v={1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    for(auto i=0; i<1000000; ++i)
        v.push_back(i);
    result=solution(v);
    cout<<result<<endl;
    assert(result==1000000-1);
    v.clear();

    v={0,0,0,0,0};
    result=solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    return 0;
}
