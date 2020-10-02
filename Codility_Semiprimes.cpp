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

using namespace std;

vector<int> sieve(int n)
{
    vector<int> sieve(n+1,1);

    /* Para 0 y 1 que no son usados en la logica de sieve*/
    sieve[0] = 0;
    sieve[1] = 0;

    /* Empezamos con 2 como el numero mas pequeño*/
    auto i =2u;

    /* Limitando el rango a numeros que dividen a N*/
    while(i*i <= (size_t)n)
    {
        /* Revisar si hemos pasado por este valor*/
        if(false != sieve[i])
        {
            auto k=i*i;
            /* Loop del numero en analisis*/
            while(k <= (unsigned)n)
            {
                /* Marcar como numero compuesto*/
                sieve[k] = 0;
                /*Incrementar multiplos del posible numero primo para encontrar numeros compuestos*/
                k+=i;
            }
        }
        /*Move to search the next prime number*/
        i++;
    }
    return sieve;
}

 vector<int> primeArray(const int N)
 {
     vector<int> sieve_=sieve(N);
     vector<int> prime;
     prime.reserve(N);

     for(auto idx=0; idx < N; ++idx)
         if(sieve_[idx] == 1)
             prime.push_back(idx);

     return prime;
 }

 set<int> semiPrimeArray(const int N, const vector<int>& primes)
 {
     set<int> semiPrime;

     for(auto i=0u;i<primes.size();++i)
         for(auto j=0u; j<primes.size();++j)
         {
             if(primes[i]*primes[j] >N)
                 break;
             else
                semiPrime.insert(primes[i]*primes[j]);
         }

     return semiPrime;
 }

/*55% https://app.codility.com/demo/results/training27SBTN-MXF/
  Esta solucion se basa en conseguir arreglos de semiprimos y revisar  en cada elemento que la regla en la que el semiprimo esta en el rango es correcta, si lo es se */
 vector<int> solution(int N, vector<int> &P, vector<int> &Q)
 {
     auto setSemiPrimes=semiPrimeArray(N,primeArray(N));
     vector<int> semiPrimes;

     copy(setSemiPrimes.begin(),setSemiPrimes.end(),back_inserter(semiPrimes));

     auto M=P.size();
     vector<int> result(M,0);

     for(auto k=0u; k<M; ++k)
         for(auto i=0u; i< semiPrimes.size();++i)
             if(semiPrimes[i]>=P[k] && semiPrimes[i]<=Q[k])
                 result[k]++;
     return result;
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

void printSet(set<int>& S)
{
    for(const auto& s:S)
        cout<<s<<endl;
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
    vector<int> result;
    vector<int> p;
    vector<int> q;

    p={1,4,16};
    q={26,10,20};
    result=solution(26,p,q);
    printV(result);
    assertV(result,{10,4,0});

    p={1,4,16};
    q={26,10,20};
    result=solution(1,p,q);
    printV(result);
    assertV(result,{0,0,0});

    p={1,4,16};
    q={26,10,20};
    result=solution(2,p,q);
    printV(result);
    assertV(result,{0,0,0});

    p={1,4,16};
    q={26,10,20};
    result=solution(4,p,q);
    printV(result);
    assertV(result,{1,1,0});

    p={1};
    q={26};
    result=solution(9,p,q);
    printV(result);
    assertV(result,{3});

    p={4};
    q={4};
    result=solution(4,p,q);
    printV(result);
    assertV(result,{1});

    return 0;
}
