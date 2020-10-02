/*


An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

    vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given
    A = [3, 8, 9, 7, 6]
    K = 3

the function should return [9, 7, 6, 3, 8]. Three rotations were made:
    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

For another example, given
    A = [0, 0, 0]
    K = 1

the function should return [0, 0, 0]

Given
    A = [1, 2, 3, 4]
    K = 4

the function should return [1, 2, 3, 4]

Assume that:

        N and K are integers within the range [0..100];
        each element of array A is an integer within the range [−1,000..1,000].

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    if(A.empty() || A.size() == 1u)
        return A;

	/*Std algorithm is based on set the a "middle" element to be the first element of the container by rotation, so here we required to determine the "middle" that correspond to the K times rotation.*/
    auto IterMiddle= A.begin();

    if ((size_t)K > A.size())
        IterMiddle = A.end()- (K%A.size());
    else
        IterMiddle = A.end()-K;

    std::rotate(A.begin(),IterMiddle, A.end());
    return A;
}

void printV(const vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

string vToString(const vector<int>& vRes)
{
    string res = "[ ";
    const string comma = ",";

    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        res +=*it;
        res +=", ";
    }
    return res;
}

void assertV( vector<int>& result,  vector<int>&& comp)
{
    string text = vToString(result);
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

int main()
{
    vector<int> v= {3,8,9,7,6};

    auto vRes= solution(v,3);
    printV(vRes);
    assertV(vRes,{9,7,6,3,8});
    v.clear();

    v={-1,-2,-3,-4,-5,-6};
    vRes=solution(v,4);
    printV(vRes);
    assertV(vRes,{-3,-4,-5,-6,-1,-2});
    v.clear();

    v={2, 3, 4, 5, 6, 7, 1};
    vRes=solution(v,3);
    printV(vRes);
    assertV(vRes,{6,7,1,2,3,4,5});
    v.clear();

    v={1, 2, 3, 4};
    vRes=solution(v,4);
    printV(vRes);
    assertV(vRes,{1,2,3,4});
    v.clear();

    v={5, -1000};
    vRes=solution(v,1);
    printV(vRes);
    assertV(vRes,{-1000,5});
    v.clear();

    v={1, 1, 2, 3, 5};
    vRes=solution(v,42);
    printV(vRes);
    assertV(vRes,{3, 5, 1, 1, 2});
    v.clear();

    v={1, 2, 3, 4, 5, 6, 7};
    vRes=solution(v,2);
    printV(vRes);
    assertV(vRes,{6,7,1,2,3,4,5});
    v.clear();

    v={1, 2, 3, 4, 5, 6};
    vRes=solution(v,10);
    printV(vRes);
    assertV(vRes,{3,4,5,6,1,2});
    v.clear();
    return 0;
}
