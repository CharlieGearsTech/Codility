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

using denominations= std::size_t;
using numCoins= std::size_t;

map<denominations,numCoins> greedyCoinChanging(const vector<denominations>& M,unsigned k)
{
    map<denominations,numCoins> result;

    for(int i=M.size()-1; i>-1; --i)
    {
        if(M[i] <= k)
        {
            result[M[i]]=floor(k/M[i]);
            k%=M[i];
        }
    }
    return result;
}

int greedyCanoeistA(vector<int>& A, int K)
{
    int canoes = 0u;
    auto j=0u;
    auto i=A.size()-1;

    while(i>=j)
    {
        if(A[i] + A[j] <= K)
            j++;
        canoes++;
        i--;
    }
    return canoes;
}

int greedyCanoeistB(vector<int>& A, int K)
{
    deque<int> skinny;
    deque<int> fatso;

    for(int i = A.size()-1; i<=0;--i)
    {
        if(A[i] + A[A.size()-1] <= K)
            skinny.push_front(A[i]);
        else
            fatso.push_front(A[i]);
    }

    fatso.push_front(A[A.size()-1]);
    int canoes=0;

    while(!skinny.empty() || !fatso.empty())
    {
        if(fatso.size() > 0)
            skinny.pop_back();
        fatso.pop_back();
        canoes++;

        if(fatso.empty() && !skinny.empty())
        {
            fatso.push_front(skinny.back());
            skinny.pop_back();
        }
        while(fatso.size() > 1 && *(fatso.end()-1) + fatso[0] <= K)
        {
            skinny.push_front(fatso.front());
            fatso.pop_front();
        }
    }
    return canoes;
}

int main()
{
    map<denominations,numCoins> m;
    const vector<denominations> v= {1,3,4,8,10};

    m= greedyCoinChanging(v,6);

    return 0;
}
