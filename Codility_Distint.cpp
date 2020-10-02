#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <deque>

using namespace std;

int solution(vector<int> &A)
{
    if(A.empty())
        return 0;
    if(A.size() == 1u)
        return 1;
    sort(A.begin(),A.end());
    auto lastIt= unique(A.begin(),A.end());

    return lastIt-A.begin();
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
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};
    int result = 0;

    result = solution(v);
    cout<<result<<endl;
    assert(result == 3u);
    v.clear();

    v= {2,1,1,2,3,1};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 3u);
    v.clear();

    v = {};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 0u);
    v.clear();

    v={1};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 1u);
    v.clear();

    v = {2,2};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 1u);
    v.clear();

    v = {-1,0,-100,5,100,7,8,100,50,70};
    result = solution(v);
    cout<<result<<endl;
    assert(result == 9u);
    v.clear();

    return 0;

    return 0;

}
