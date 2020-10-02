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
/* El algoritmo se basa en encontrar un numero entre el maximo elemento y la suma de todos los elementos
   que sea la minima suma de elementos de un arreglo. Usando el algoritmo de busqueda binaria,determinamos cuando
   la media entre el maximo elemento y la suma de todoso los elementos debe de ser ajustado basado en si esa
   media como limite de suma entre divisiones es suficiente para poner meter todos los elementos a todas las divisiones.
    Si sobran bloques con esta media es que la media es demasiado pequeña y tenemos que incrementarlo mas a sum(B)
    Si faltan bloques significa que la media es demasiada grande y tenemos que decrementar hacia maxElement(B).
*/
/*Algorithm to adjust the minimum largest sum index, el algoritmo se basa en*/
bool adjustMaxSumIdx (const int K, const vector<int> &B, const int maxSum)
{
    int numBlocks=1;
    int sum=0;

    for(const auto& a:B)
    {
        /*Increment the sum for each element of A until reaching the limit denoted by maxSum
         * to pass to another block*/
        sum+=a;
        /*Had reach the limit of the maxSum, save the sum value and create a new block*/
        if(sum>maxSum)
        {
            numBlocks++;
            sum=a;
        }

        /*If there are over number of blocks means that the minimum maximum sum is greater
         *  than the actual maxSum.
          So we are going to move more into sum(A) from max(A)*/
        if(numBlocks > K)
            return false;
    }
    /*Enough fit and loose blocks indicates that value respect the quantity of blocks,
      let's check if we can have a smaller maximum sum moving more to max(A) from sum(A)*/
    return true;
}

/*https://app.codility.com/demo/results/trainingDTYUPP-2ZR/*/
int solution(int K, int M, vector<int> &A)
{
    const int N=A.size();

    vector<int> B;
    int sum=0u;
    int max=0u;
    /*Determine the max element and the sum of all elements excluding elements with value 0. Faster that calling std library.
      If the array is greater than K, then the minimum maximum sum shall be between the max element
      and the sum of all element. */
    for(int i=0; i<N; ++i)
    {
        if(A[i])
        {
            B.push_back(A[i]);
            sum+=A[i];
            max=std::max(max,A[i]);
        }
    }

    /*Empy arrays returns 0.*/
    if(!B.size())
    return 0;

    /*When the number of non-zero elements are lower than K, means that the division will be
     * single elements for the most part, then max element will be the largest minimum sum.*/
    if((int)B.size() <= K)
        return *max_element(B.begin(),B.end());

    /*Binary search algoritm to seize the minimum largest sum.*/
    int lowBound=max;
    int upBound=sum;
    while(lowBound <= upBound)
    {
        /*If true, means that we can go more into max_element(B) from sum(B)
         *  searching for a smaller maximum sum*/
        if(adjustMaxSumIdx(K,B,(upBound+lowBound)/2))
            upBound--;
        else /*No aligned blocks, more more into sum(B) from max_element(B)*/
            lowBound++;
    }
    return lowBound;
}

/*Imprimir vector<int>s*/
void printV(vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

/*Assertion de vectores de ints*/
void assertV( vector<int>& result,  vector<int>&& comp)
{
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

int main()
{
    int result;
    vector<int> a;

    a={2,1,5,1,2,2,2};
    result=solution(3,5,a);
    cout<<result<<endl;
    assert(result==6);

    return 0;
}
