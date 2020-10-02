/*

Let A be a non-empty array consisting of N integers.

The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ≤ P ≤ Q < N.

For example, the following array A:
  A[0] =  1
  A[1] =  4
  A[2] = -3

has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (−3)| = 2.
The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (−3)| = 1.
The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(−3) + (−3)| = 6.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.

For example, given the following array A:
  A[0] =  1
  A[1] =  4
  A[2] = -3

the function should return 1, as explained above.

Given array A:
  A[0] = -8
  A[1] =  4
  A[2] =  5
  A[3] =-10
  A[4] =  3

the function should return |(−8) + 5| = 3.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

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

/*Encuentra la minima suma de abs de 2 elementos, se hace mediante la iteracion de front hacia adelante
  y la iteracion de back hacia atras*/
int solution(vector<int> &A)
{
    if(A.size() == 0)
        return 0;
    if(A.size() == 1)
        return abs(*A.begin()*2);

    auto value=2000000000;
    int front=0;
    int back= A.size()-1;

	/*Require sorted array*/
    std::sort(A.begin(),A.end());

    while(front <= back)
    {
		/* Hold the minimum sum*/
        value=min(value,abs(A[front]+A[back]));
		/*If absolute greater, we would like to move further looking for minor numbers*/
        if(abs(A[front]) > abs(A[back]))
            front++;
        else
            back--;
    }
    return value;
}

//int solution(vector<int> &A)
//{
//    if(A.size() == 0)
//        return 0;
//    if(A.size() == 1)
//        return abs(*A.begin()*2);
//    if(A[0]== -1000000000 && A[1]== -999999999)
//        return 1999999998;
//    if(A.size() == 2)
//        return abs(A[0] + A[1]);

//    std::sort(A.begin(), A.end());

//    if(A[0] >= 0)
//        return A[0]+A[0];
//    else
//    {
//        auto minPosIt = std::find_if(A.begin(),A.end(),[](int i){return i>=0;});
//        return min(abs(*minPosIt*2),min(abs(*(minPosIt-1)+*(A.end()-1)),abs(*(A.begin()))+*(A.end()-1)));
//    }
//}

int main()
{
    vector<int> v={-8,4,5,-10,3};
    int result=0u;

    result=solution(v);
    cout<<result<<endl;
    assert(result == 3);
    v.clear();

    v={1,4,-3};
    result=solution(v);
    cout<<result<<endl;
    assert(result == 1);
    v.clear();

    v={};
    result=solution(v);
    cout<<result<<endl;
    assert(result == 0);
    v.clear();

    v={-1000000000};
    result=solution(v);
    cout<<result<<endl;
    assert(result == 2000000000);
    v.clear();

    v={-1000000000, -999999999};
    result=solution(v);
    cout<<result<<endl;
    assert(result == 1999999998);
    v.clear();

    v={1,2,3,4,5,6,7};
    result=solution(v);
    cout<<result<<endl;
    assert(result == 2);
    v.clear();

    v={-5,1,0,3,-8,7};
    result=solution(v);
    cout<<result<<endl;
    assert(result == 0);
    v.clear();

    return 0;
}
