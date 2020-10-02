/*

A non-empty array A consisting of N numbers is given. The array is sorted in non-decreasing order. The absolute distinct count of this array is the number of distinct absolute values among the elements of the array.

For example, consider array A such that:
  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6

The absolute distinct count of this array is 5, because there are 5 distinct absolute values among the elements of this array, namely 0, 1, 3, 5 and 6.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N numbers, returns absolute distinct count of array A.

For example, given array A such that:
  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6

the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647];
        array A is sorted in non-decreasing order.

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

using namespace std;

/* To get the abs distint, you can insert all abs values of the vector into a set, the set will not       alllow duplicated elements*/
int solution(vector<int> &A)
{
    set<int> result;
    for(auto i = 0u; i< A.size(); ++i)
        result.insert(abs(A[i]));

    return result.size();
}

int main()
{
    vector<int> v = {-5, -3, -1, 0 ,3 , 6};
    int result = 0;

    result=solution(v);
    cout<<result<<endl;
    assert(result = 5);
    v.clear();

    v= {-1,-1, 1, 1};
    result=solution(v);
    cout<<result<<endl;
    assert(result = 1);
    v.clear();

    v= {-2147483648,-2147483648, 1, 1};
    result=solution(v);
    cout<<result<<endl;
    assert(result = 2);
    v.clear();

    return 0;
}
