/*

An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.

A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.

For example, consider integer M = 6 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2

There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

The goal is to calculate the number of distinct slices.

Write a function:

    class Solution { public int solution(int M, int[] A); }

that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.

If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.

For example, given integer M = 6 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2

the function should return 9, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        M is an integer within the range [0..100,000];
        each element of array A is an integer within the range [0..M].

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

int solution(int M, vector<int>& A)
{
    auto sum = 0u;
    auto front = 0u, back=0u;
    vector<int> seen(M+1,0);

	/*While no one reaches the end of the container*/
    while(front < A.size() && back < A.size())
    {
        /* Move foward adding slides until a repeated number is found*/
        while(front < A.size() && seen[A[front]] != true)
        {
            sum+=(front-back+1); /*El numero de sub slices es igual a front-back+1*/
            seen[A[front]]=true;
            front++;
        }
        /* Iterate to reset all the values excluding the one that is in front,
		   This is to enable new slides that are ahead the array. When front had reached the end, there is no slides to add so moving back is not necessary*/
        while(front <A.size() && back<A.size() && A[back] != A[front])
        {
            seen[A[back]]=false;
            back++;
        }
        /* Last check of back to permit overcome the duplicated value = to front. */
        seen[A[back]]=0u;
        back++;
    }
    return min((int)sum,1000000000);
}

/*Retorna los Distint Slides de un arreglo mediante la regla que se traslada la parte
 trasera de la oruga cuando se encuentra un numero duplicado- Elementos con los valores duplicados, no deben de contarse.*/
//int solution(int M, vector<int>& A)
//{
//    size_t front=0;
//    size_t back=0;
//    size_t count=0;

//    if(A.size() <= 1)
//        return 1;

//    vector<int> seen(M+1,0);
//    while(back <A.size())
//    {
//        while(front<A.size() && true != seen[A[front]])
//        {
//            seen[A[front]]=true;
//            ++count;
//            ++front;
//        }
//        while(back<A.size() && A[front] != A[back])
//        {
//            ++back;
//        }
//        front=back;
//    };

//    return min((int)count,1000000000);
//}

vector<int> f;
int fib(int n)
{
    f.reserve(n);
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    if (f[n])
        return f[n];

    int k = (n & 1)? (n+1)/2 : n/2;

    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1))
           : (2*fib(k-1) + fib(k))*fib(k);

    return f[n];
}

int fibonacci(size_t n)
{
    if(n <= 1)
        return n;
    return fibonacci(n-1)+ fibonacci(n-2);
}

int dyn_fibonacci(size_t n)
{
    vector<int> fib(n+2);
    size_t i;

    fib[0]=0;
    fib[1]=1;

    for(i=2 ; i<n; ++i)
        fib[i]=fib[i-1]+fib[i-2];
    return fib[n];
}

int solution(vector<int> &A)
{
    set<int> result;
    for(auto i = 0u; i< A.size(); ++i)
        result.insert(abs(A[i]));

    return result.size();
}

int main()
{
    vector<int> v={3,4,5,5,2};
    int result=0u;

    result=solution(6,v);
    cout<<result<<endl;
    assert(result==9);
    v.clear();

    v={1,1};
    result=solution(6,v);
    cout<<result<<endl;
    assert(result==2);
    v.clear();

    v={100000,10000};
    result=solution(100000,v);
    cout<<result<<endl;
    assert(result==3);
    v.clear();

    return 0;
}
