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

using namespace std;

vector<int> sieve(int n)
{
    vector<int> sieve(n,1);

    sieve[0] = 0;
    sieve[1] = 0;

    auto i =2u;

    while(i*i <= (size_t)n)
    {
        if(false != sieve[i])
        {
            auto k = i*i;
            while(k <= (size_t)n)
            {
                sieve[k] = 0;
                k+=i;
            }
        }
        i++;
    }

    return sieve;
}

vector<int> prepareArrayFactor(int n)
{
    vector<int> f(n+1,0);

    auto i = 2u;

    while(i+i <=(size_t)n)
    {
        if(f[i] == 0)
        {
            auto k=i*i;
            while(k <= n)
            {
                if(f[k] == 0)
                    f[k] = i;
                k+=i;
            }
        }
        i++;
    }
    return f;
}

/* Encontrar los numeros que multiplicados nos dan a X, X debe de ser un numero menor al tamaño de A*/
vector<int> factorization(int x, vector<int>& A)
{
    vector<int> primeFactors;

    while(A[x] > 0)
    {
        primeFactors.push_back(A[x]);
        x /= A[x];
    }
    primeFactors.push_back(x);

    return primeFactors;
}

int main()
{
    //auto result = sieve(17);

    auto A = prepareArrayFactor(27);
    auto result= factorization(25,A);

    return 0;
}
