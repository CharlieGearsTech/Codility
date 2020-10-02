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

/* Returns true when the number is prime, false when the number is even*/
bool primality(size_t n)
{
    size_t i = 2;

    while(i*i < n)
    {
        if(n%i == 0)
            return false;
        ++i;
    }
    return true;
}

size_t gcd_euclidean(size_t a,size_t b,size_t res)
{
    if( a == b)
        return res*a;
    else if(a%2 == 0 && b%2 == 0)
        return gcd_euclidean(floor(a/2),floor(b/2),2*res);
    else if(a%2 == 0)
        return gcd_euclidean(floor(a/2),b,res);
    else if(b%2 == 0)
        return gcd_euclidean(a, floor(b/2),res);
    else if (a>b)
        return gcd_euclidean(a-b,b,res);
    else
        return gcd_euclidean(a,b-a,res);
}

int solution(int N, int M)
{
    return N/gcd_euclidean(N,M,1);
}

//int solution(int N, int M)
//{
//    if(false != primality(N))
//        return N;
//    else
//    {
//        if(M < N)
//            return gcd_euclidean(N,M*N,1);
//        else if(N > M)
//            return gcd_euclidean(N,M,1);
//        else if (N == M)
//            return 1;
//    }
//}

//int solution(int N, int M)
//{
//    size_t x=0;
//    vector<int> f(N,0);
//    f[0]=1;
//    size_t count=1;

//    if(N == 1)
//        return count;

//    while(1)
//    {
//        x+=M;
//        if(f[x%N] != 0)
//            return count;
//        else
//        {
//            f[x%N] = 1u;
//            ++count;
//        }
//    }
//}

size_t gcd_sub(size_t a, size_t b)
{
    if(a==b)
        return a;
    if( a> b)
        return gcd_sub(a-b,b);
    else
        return gcd_sub(a,b-a);
}

/* Maximo comun divisor, maximo numero que puede dividir ambos numeros a y b, por ejemplo
    24 y 18 gcd es 2*/
size_t gcd(size_t a, size_t b)
{
    if( a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}

/* Minimo comun multiplo es el minimo numero que puede ser divisible por a y b por ejemplo
   para 4 y 3 el mcm es 12*/
size_t lcm(size_t a, size_t b,size_t c = 0)
{
    auto ap=a;
    auto bp=b;

    for(;;)
    {
        if(a==b)
            return a;
        if(a>b)
            b+=bp;
        else
            a+=ap;
    }

    size_t s_lcm = 0u;
    if(c != 0u)
        s_lcm= lcm(bp,c);
    return max(a,s_lcm);
}

size_t lcm_2(size_t a, size_t b)
{
    size_t lcm = 1;
    while(1)
    {
        if(lcm%a == 0&& lcm%b == 0)
            return lcm;
        lcm++;
    }
}

size_t lcm_vector(vector<int>& A)
{
    size_t lcm = lcm_2(A[0],A[1]);

    for(auto i = 2u; i< A.size();++i)
        lcm = lcm_2(lcm,A[i]);

    return lcm;
}

int main()
{
    int result = 0;

    result=solution(10,4);
    cout<<result<<endl;
    assert(result==5);
    result=0;

    result=solution(10,12);
    cout<<result<<endl;
    assert(result==5);
    result=0;

    result=solution(10,10);
    cout<<result<<endl;
    assert(result==1);
    result=0;

    result=solution(10,10);
    cout<<result<<endl;
    assert(result==1);
    result=0;

    result=solution(2,3);
    cout<<result<<endl;
    assert(result==2);
    result=0;

    result=solution(10,7);
    cout<<result<<endl;
    assert(result==10);
    result=0;

    result=solution(1000000000,7);
    cout<<result<<endl;
    assert(result==1000000000);
    result=0;

    result=solution(5,3);
    cout<<result<<endl;
    assert(result==5);
    result=0;

    result=solution(7,2);
    cout<<result<<endl;
    assert(result==7);
    result=0;

    result=solution(7,4);
    cout<<result<<endl;
    assert(result==7);
    result=0;

    result=solution(7,2);
    cout<<result<<endl;
    assert(result==7);
    result=0;

    result=solution(7,1);
    cout<<result<<endl;
    assert(result==7);
    result=0;

    result=solution(7,5);
    cout<<result<<endl;
    assert(result==7);
    result=0;

    result=solution(7,6);
    cout<<result<<endl;
    assert(result==7);
    result=0;

    result=solution(11,5);
    cout<<result<<endl;
    assert(result==11);
    result=0;

    return 0;
}
