/*

You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:

        with your first step you can stand on rung 1 or 2,
        if you are on rung K, you can move to rungs K + 1 or K + 2,
        finally you have to stand on rung N.

Your task is to count the number of different ways of climbing to the top of the ladder.

For example, given N = 4, you have five different ways of climbing, ascending by:

        1, 1, 1 and 1 rung,
        1, 1 and 2 rungs,
        1, 2 and 1 rung,
        2, 1 and 1 rungs, and
        2 and 2 rungs.

Given N = 5, you have eight different ways of climbing, ascending by:

        1, 1, 1, 1 and 1 rung,
        1, 1, 1 and 2 rungs,
        1, 1, 2 and 1 rung,
        1, 2, 1 and 1 rung,
        1, 2 and 2 rungs,
        2, 1, 1 and 1 rungs,
        2, 1 and 2 rungs, and
        2, 2 and 1 rung.

The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.

Write a function:

    vector<int> solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].

For example, given L = 5 and:
    A[0] = 4   B[0] = 3
    A[1] = 4   B[1] = 2
    A[2] = 5   B[2] = 4
    A[3] = 5   B[3] = 3
    A[4] = 1   B[4] = 1

the function should return the sequence [5, 1, 8, 0, 1], as explained above.

Write an efficient algorithm for the following assumptions:

        L is an integer within the range [1..50,000];
        each element of array A is an integer within the range [1..L];
        each element of array B is an integer within the range [1..30].

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

vector<int> solution(vector<int> &A, vector<int> &B)
{
    int L= *max_element(A.begin(),A.end());
    int P= *max_element(B.begin(),B.end());

    /*+1 due Fib[L+1] is the max combination of L
      +1 to overcome the index 0*/
    vector<int> fib(L+2,0);
    fib[1]=1;

    /*Create fibonacci, 1<<P limits the greatest number to be*/
    for(auto i=2u; i<fib.size();++i)
        fib[i]=fib[i-1]+fib[i-2];

    /*El numero de configuraciones de L es un fib[] +1, enmascarar basado en mod(B[i])*/
    vector<int> result(A.size(),0);

    /*Enmascaramiento es el orden de 0 agregados (1<<3)=1000-1=111*/
    for(auto i=0u; i<A.size();++i)
        result[i]=fib[A[i]+1]&((1<<B[i])-1);

    return result;
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
    vector<int> a,b;
    vector<int> result(a.size());

    a={4,4,5,5,1};
    b={3,2,4,3,1};
    result=solution(a,b);
    printV(result);
    assertV(result,{5,1,8,0,1});
    a.clear();
    b.clear();

    /* 5,5,8,8,1*/
    a={4,4,5,5,1};
    b={1,1,1,1,1};
    result=solution(a,b);
    printV(result);
    assertV(result,{1,1,0,0,1});
    a.clear();
    b.clear();

    /* 5,5,8,8,1*/
    a={4,4,5,5,1};
    b={1,1,1,1,1};
    result=solution(a,b);
    printV(result);
    assertV(result,{1,1,0,0,1});
    a.clear();
    b.clear();

    /* 5,8,13,21,34*/
    a={4,5,6,7,8};
    b={6,6,6,6,6};
    result=solution(a,b);
    printV(result);
    assertV(result,{5,8,13,21,34});
    a.clear();
    b.clear();

    /* 5,8,13,21,34*/
    a={4,5,6,7,8};
    b={2,2,2,2,2};
    result=solution(a,b);
    printV(result);
    assertV(result,{1,0,1,1,2});
    a.clear();
    b.clear();
    return 0;
}
