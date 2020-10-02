/*

We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:
  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0

There are eleven (unordered) pairs of discs that intersect, namely:

        discs 1 and 4 intersect, and both intersect with all the other discs;
        disc 2 also intersects with discs 0 and 3.

Write a function:

    class Solution { public int solution(int[] A); }

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [0..2,147,483,647].

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

using namespace std;

/*O(N**2) Timeouts https://app.codility.com/demo/results/training9RGGRB-ZPN/*/
int solution(vector<int> &A)
{
    const auto N=A.size();
    /*Si no hay mas de 2 discos, retornar 0*/
    if(N < 2u)
        return 0;

    int result= 0u;
    /* Cada disco a analizar, como se incrementa al eje X, todos los valores anteriores ya tienen en cuenta este disco, asi que
       no se requiere un analisis anterior*/
    for(auto p = 0u; p< N-1 ; ++p)
    {
        int pSup = p + A[p];
        /* Si tenemos un disco con un radio de lo maximo posible, entonces intercepta a todos los discos */
        if(2147483647 == A[p])
        {
            result+=A.size()-1;
            continue;
        }
        /*Cada disco despues del analizado, todos estan ordenados incrementalmente en el eje de las x, entonces revision posterior a p
          producira el revisar todos los discos que pueden interceptar con P*/
        for(auto q = p+1; q< N; ++q)
        {
            int qInf = q - A[q];
            /*Si el limite superior del disco izquierdo es mayor que el limite inferior del disco derecho,
            entonces tenemos una intercepcion.*/
            if(pSup >= qInf)
                result++;
        }
    }
    if(result > 10000000)
        return -1;

    return result;
}

int main()
{
    vector<int> v= {1,5,2,1,4,0};
    int result = 0u;

    result= solution(v);
    cout<<result<<endl;
    assert(result==11u);
    v.clear();

    v = {0,0,0,0};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0u);
    v.clear();

    v = {0,1,0,0};
    result= solution(v);
    cout<<result<<endl;
    assert(result==2u);
    v.clear();

    v = {0,1,1,0};
    result= solution(v);
    cout<<result<<endl;
    assert(result==3u);
    v.clear();

    v = {3,1,1,1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==6u);
    v.clear();

    v = {1,0,1,1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==4u);
    v.clear();

    v={2147483647, 2147483647};
    result= solution(v);
    cout<<result<<endl;
    assert(result==1u);
    v.clear();

    return 0;
}
