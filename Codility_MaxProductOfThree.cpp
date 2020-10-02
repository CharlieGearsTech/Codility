/*

A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6

contains the following example triplets:

        (0, 1, 2), product is −3 * 1 * 2 = −6
        (1, 2, 4), product is 1 * 2 * 5 = 10
        (2, 4, 5), product is 2 * 5 * 6 = 60

Your goal is to find the maximal product of any triplet.

Write a function:

    class Solution { public int solution(int[] A); }

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6

the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [3..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

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

int solution(vector<int> &A)
{
    sort(A.begin(),A.end());

    int result= 0u;
    int ai=*A.begin();
    int ai1= *(A.begin()+1u);
    int ak= *(A.end()-1u);
    int ak1 = *(A.end()-2u);
    int ak2 = *(A.end()-3u);

	/*Evaluate if there is only 3 elements*/
    if(ak2 == 0u)
        if(ai1 != 0u)
            return ai*ai1*ak;

    if(ak < 0)
        return ak*ak1*ak2;

    if((ak*ak1*ak2) > (ai*ai1*ak))
        result = (ak*ak1*ak2);
    else
        result = (ai*ai1*ak);

    return result;
}

/*Funcion que guarda secuencialmente cuantas veces se repite en un arrays de [0 a n]
    vector<int> v= {0,0,4,2,4,5};
    assertV(result,{2,0,1,0,2,1});
*/
vector<int> countElement(vector<int>& A)
{
    vector<int> count(A.size(),0u);

    for(auto i =0u; i< A.size(); ++i)
        count[A[i]] += 1u;

    return count;
}

/* Funcion que suma los elementos consecutivamente hasta A.size()+1 donde p[0] siempre sera cero:
 *  vector<int> v= {2,3,7,5,1,3,9};
    assertV(result,{0,2,5,12,17,18,21,30});
*/
vector<int> prefixSums(vector<int>& A)
{
    vector<int> p(A.size()+1u,0);

    for(auto i = 1u; i <p.size(); ++i)
        p[i]=p[i-1]+A[i -1];

    return p;
}

/* Acomodo por O(n2)
    vector<int> v= {2,3,7,5,1,3,9};
    assertV(v,{1,2,3,3,5,7,9});*/
void selectionSort(vector<int>& A)
{
    int minimal = 0u;

    /* Itera todo el contenedor, indice contiene el elemento siguiente al que esta ordenado*/
    for(auto k = 0u; k< A.size();++k)
    {
        minimal = k;
        /* Itera los elementos no ordenados hasta encontrar un valor minimo al nuevo para ordenar*/
        for(auto j = k + 1; j < A.size(); ++j)
            if(A[j] < A[minimal])
                minimal = j;
        swap(A[k],A[minimal]);
    }
}

/* Acomodo por O(n+k)
    vector<int> v= {2,3,7,5,1,3,9};
    assertV(v,{1,2,3,3,5,7,9});*/
void countingSort(vector<int>& A)
{
    vector<int> count = countElement(A);

    int p=0;

    /* Itera los contadores de cada elemento de A, el indice i es el elemento que se esta buscando,
        y cuando se itera en j, se esta buscando cuantas veces es repetido en A para ser ordenado consecutivamente.*/
    for(auto i=0u ; i< count.size()+1; ++i)
        for(auto j=0; j < count[i]; ++j)
        {
            A[p]=i;
            p+=1;
        }
}

/*O(n)
    mergeSort(v,0,v.size()-1);
    assertV(v,{1,2,3,3,5,7,9});
*/
void merge(vector<int>& A, int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2= r-m;

    vector<int> L(n1);
    vector<int> R(n2);

    for(i = 0u; i<n1; ++i)
        L[i] =A[l+i];
    for(j = 0; j< n2; ++j)
        R[j] = A[m+1+j];

    i=0;
    j=0;
    k=l;

    /*Ordenar para A los subsets de Left y Right array.*/
    while(i<n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            A[k]= L[i];
            ++i;
        }
        else
        {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    /*Setear los elementos remanentes de Left*/
    while(i<n1)
    {
        A[k]=L[i];
        ++i;
        ++k;
    }
    /*Setear los elementos remanentes de Right*/
    while(j<n2)
    {
        A[k]= R[j];
        ++j;
        ++k;
    }
}
void mergeSort(vector<int>& A, int l, int r)
{
    if(l<r)
    {
        int m= l+(r-l)/2;

        mergeSort(A,l,m);
        mergeSort(A,m+1,r);

        merge(A,l,m,r);
    }
}

/*Assertion de vectores de ints*/
void assertV( vector<int>& result,  vector<int>&& comp)
{
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

/*Imprimir vector<int>s*/
void printV(const vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

/*O(n logn) busqueda de Lider
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};
    assert(result==8);*/
int fastLeader(vector<int>& A)
{
    int leader = -1;

    sort(A.begin(),A.end());
    int candidate = A[A.size()/2];
    auto count =0u;

    for(auto i = 0u; i< A.size();++i)
        if(A[i]== candidate)
            count++;
    if(count> A.size()/2)
        leader=candidate;

    return leader;
}

/*O(n) busqueda de Lider
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};
    assert(result==8);*/
int goldenLeader(vector<int>& A)
{
    int size =0;
    int value = 0;

    for(auto k=0u; k<A.size(); ++k)
    {
        if(0u == size)
        {
            size++;
            value = A[k];
        }
        else
        {
            if(A[k] != value)
                size--;
            else
                size++;
        }
    }

    int candidate = -1;

    if(size>0)
        candidate=value;

    int leader = -1;
    auto count =0u;

    for(auto k=0u;k< A.size();++k)
     if(A[k] == candidate)
         count++;

    if(count > A.size()/2)
        leader= candidate;

    return leader;
}

int main()
{
    vector<int> v= {-3,-2,1,2,5,6};
    int result = 0;

    result = solution(v);
    cout<<result<<endl;
    assert(result == 60u);
    v.clear();

    v= {-9,-8,0,4,5,10};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 720u);
    v.clear();

    v= {1,2,3,5,7};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 105u);
    v.clear();

    v= {-9,-9,0,4,5,10};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 810u);
    v.clear();

    v= {-9,-7,0,5,7,10};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 630u);
    v.clear();

    v= {-10,-9,0,5,8,10};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 900u);
    v.clear();

    v= {-10,-9,0,5,8,9};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 810u);
    v.clear();

    v= {-9,-9,0,5,9,10};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 810u);
    v.clear();

    v= {-9,-8,0,5,9,10};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 720u);
    v.clear();

    v= {-9,-9,0,9,10,11};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 990u);
    v.clear();

    v= {-9,-9,-9,-9,-9,9};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 729u);
    v.clear();

    v= {0,0,0,0,0,0};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 0u);
    v.clear();

    v= {-9,0,0,0,0,9};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 0u);
    v.clear();

    v= {1,1,0,0,0,0};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 0u);
    v.clear();

    v= {-2,-1,0,0,2,3};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 6u);
    v.clear();

    v= {-2,-1,0,0,3};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 6u);
    v.clear();

    v= {-9,-1,0,10,13};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 117u);
    v.clear();

    v= {-2,0,0,0,3};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 0u);
    v.clear();

    v= {-2,0,0,1,3};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 0u);
    v.clear();

    v= {-5,-3,1,2,3,4,7};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 105u);
    v.clear();

    return 0;
}
