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

vector<int> solution(vector<int> &A)
{
    const int N = A.size();

    map<int,int> divisors;

    for(const auto& a:A)
        divisors[a]++;

    vector<int> track((2*N)+1,N);

    /*Por cada posible divisor en el arreglo */
    for(const auto& d: divisors)
        /*Substraer "second" veces todo multiplo del posible divisor.*/
        for(auto i=1;i*d.first<=2*N;++i)
            /*i*first son los indices de los arreglos, disminuye second veces en cada indice*/
            track[i*d.first]-=d.second;

    vector<int> nondivisors(N,0);
    for(auto i=0;i<N;++i)
        nondivisors[i]=track[A[i]];

    return nondivisors;
}

/*Crea un arreglo en la que los indices muestran el numero divisible de la secuencia y el valor es el numero  divisor*/
//vector<int> prepareArrayFactor(int n)
//{
//    vector<int> f(n+1,0);

//    auto i = 2u;

//    /*Rango para numeros que pueden dividir a N*/
//    while(i+i <=(size_t)n)
//    {
//        /*Si no ha sido analizado o es un numero divisible por otro divisor anterior*/
//        if(f[i] == 0)
//        {
//            auto k=i*i;
//            while((int)k <= n)
//            {
//                /*Primera vez, setea el divisor como valor, esto ya no sera reemplazado por otros divisores*/
//                if(f[k] == 0)
//                    f[k] = i;
//                k+=i;
//            }
//        }
//        i++;
//    }
//    return f;
//}

///* Encontrar los numeros que multiplicados nos dan a X, X debe de ser un numero menor al tamaño de A*/
//vector<int> factorization(int x, vector<int>& A)
//{
//    vector<int> primeFactors;

//    /*For the purpose of this algorithm, add divisor 1 too.*/
//    primeFactors.push_back(1u);
//    /*Revisar unicamente numeros que son divisibles*/
//    while(A[x] > 0)
//    {
//        /*Agregar el divisor a la lista de factorizacion*/
//        primeFactors.push_back(A[x]);
//        /* Dividir para disminuir el numero divisible en un factor menor.*/
//        x /= A[x];
//    }
//    /*Agregar el ultimo numero divisor.*/
//    primeFactors.push_back(x);

//    return primeFactors;
//}

///*Retorna la diferencia entre 2 sets con valores duplicados*/
//template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
//OutputIterator set_difference_any( InputIterator1 first1, InputIterator1 last1,
//                                   InputIterator2 first2, InputIterator2 last2,
//                                   OutputIterator result )
//{
//  while ( first1 != last1 && first2 != last2 )
//    if ( *first1 < *first2 ) {
//      *result = *first1;
//      ++first1;
//      ++result;
//    } else if ( *first2 < *first1 ) {
//      ++first2;
//    } else {
//      ++first1;
//      //++first2;
//    }
//  return std::copy( first1, last1, result );
//}

//vector<int> solution(vector<int> &A)
//{
//    auto N=A.size();
//    if(N==0)
//        return vector<int>{};
//    if(N==1)
//        return vector<int>{0};

//    vector<int> result(A.size());
//    auto factorArray=prepareArrayFactor(*std::max_element(A.begin(),A.end()));
//    auto sortArray= A;
//    std::sort(sortArray.begin(),sortArray.end());

//    for(auto i=0u;i<N;++i)
//    {
//        vector<int> holder;
//        auto factors = factorization(A[i],factorArray);
//        set_difference_any(sortArray.begin(),sortArray.end(),factors.begin(),factors.end(),std::inserter(holder,holder.begin()));
//        auto itRemoved= std::remove(holder.begin(), holder.end(), A[i]);
//        result[i]=itRemoved-holder.begin();
//    }
//    return result;
//}

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

int main()
{
    vector<int> v;
    vector<int> result(v.size());

    v={3,1,2,3,6};
    result=solution(v);
    printV(result);
    assertV(result,{2,4,3,2,0});
    v.clear();

    v={1};
    result=solution(v);
    printV(result);
    assertV(result,{0});
    v.clear();

    v={5,12,1,3,12};
    result=solution(v);
    printV(result);
    assertV(result,{3,1,4,3,1});
    v.clear();

    return 0;
}
