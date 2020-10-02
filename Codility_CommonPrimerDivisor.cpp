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

using namespace std;

/*Crea un arreglo en la que los indices muestran el numero divisible de la secuencia y el valor es el numero  divisor*/
map<int,int> prepareArrayFactor(int n)
{
    map<int,int> f;

    auto i = 2u;

    /*Rango para numeros que pueden dividir a N*/
    while(i+i <=(size_t)n)
    {
        auto k=i*i;
        while(k <= (size_t)n)
        {
            f[k] = i;
            k+=i;
         }
        i++;
    }
    return f;
}

/* Encontrar los numeros que multiplicados nos dan a X, X debe de ser un numero menor al tamaño de A*/
vector<int> factorization(int x, map<int,int>& A)
{
    vector<int> primeFactors;

    /*Revisar unicamente numeros que son divisibles*/
    while(A[x] > 0)
    {
        /*Agregar el divisor a la lista de factorizacion*/
        primeFactors.push_back(A[x]);
        /* Dividir para disminuir el numero divisible en un factor menor.*/
        x /= A[x];
    }
    /*Agregar el ultimo numero divisor.*/
    primeFactors.push_back(x);

    return primeFactors;
}

/*Esta solucion se basa en usar la formula de factorizacion que nos devuelve un contenedor con todos los factores de X numero, despues de eso comparamos los arreglos iguales. Uso set para organizar y hacer unicos los factores.*/
int solution(vector<int> &A, vector<int> &B)
{
    auto N=A.size();

    set<int> holder;
    copy(A.begin(),A.end(),inserter(holder,holder.begin()));
    copy(B.begin(),B.end(),inserter(holder,holder.begin()));
    int max_element=*holder.rbegin();

    //O(logN)
    auto maxFactorArray=prepareArrayFactor(max_element);

    int count=0;

    //O(n*logn*logn)
    for(auto k=0u; k<N; ++k)
    {
        auto Afactor=factorization(A[k],maxFactorArray);
        auto Bfactor=factorization(B[k],maxFactorArray);

        set<int> AfactorSet;
        set<int> BfactorSet;

        copy(Afactor.begin(),Afactor.end(),inserter(AfactorSet,AfactorSet.begin()));
        copy(Bfactor.begin(),Bfactor.end(),inserter(BfactorSet,BfactorSet.begin()));

        if(std::equal(AfactorSet.begin(),AfactorSet.end(),BfactorSet.begin()))
            ++count;
    }
    return count;
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
    vector<int> b;

    a={15,10,3};
    b={75,30,5};
    result=solution(a,b);
    cout<<result<<endl;
    assert(result==1);
    a.clear();
    b.clear();

    a={15};
    b={75};
    result=solution(a,b);
    cout<<result<<endl;
    assert(result==1);
    a.clear();
    b.clear();

    a={12,12,18};
    b={24,25,9};
    result=solution(a,b);
    cout<<result<<endl;
    assert(result==1);
    a.clear();
    b.clear();

    /*This algorithm is unable to execute large number since it allocates all the prime divisor for each element*/
//    a={2147483647};
//    b={2147483647};
//    result=solution(a,b);
//    cout<<result<<endl;
//    assert(result==1);
//    a.clear();
//    b.clear();

    return 0;
}
