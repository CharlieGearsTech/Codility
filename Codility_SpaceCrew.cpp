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
#include <cctype>
#include <sstream>
#include <stdio.h>
#include <numeric>
#include <cmath>

using namespace std;

//unsigned long long fact(int n)
//{
//    if (n == 1)
//        return 1;
//    long int z;
//    double e = 2.71;
//    z = sqrt(2*M_PI*n) * pow((n/e), n);
//    return z;
//}

//vector<unsigned long long> f(100,0);
//unsigned long long fact(unsigned int n)
//{
//    f[0]=1;
//    f[1]=1;
//    /*Reserve max elements, cannot support 1,000,000 elements yet.
//      Intermediate solution*/
//    if(f[n] != 0)
//        return f[n];

//    if(n==0)
//        return f[0];
//    f[n]=n*fact(n-1);
//    return f[n];
//}

double fact(unsigned int n)
{
    return n*log(n) - n*0.4342944819 + log(sqrt((n+1/3)*M_PIf64x));
}
/*18% no era capaz de obtener el factor de numeros mayores a 60 */
int solution(vector<int> &T, vector<int> &D)
{
    const int N=T.size();
    double sum=0;
    /*Multiplication yields to initial 1 to not omit *= operations*/
    double result=1;

    for(auto i=0; i<N; ++i)
    {
        sum=fact(T[i])/(fact(D[i])*fact(T[i]-D[i]));
        result*=sum;
    }

    return result;
}

int main()
{
    vector<int> t,d;
    int result=0;

    t={6,4,7};
    d={1,3,4};
    result=solution(t,d);
    cout<<result<<endl;
    assert(result==840);

    /*With simple factorial, 60 is the largest number that we can support*/
    t={60,4,7};
    d={1,3,4};
    result=solution(t,d);
    cout<<result<<endl;
    assert(result==8400);

//    t={1000000};
//    d={0};
//    result=solution(t,d);
//    cout<<result<<endl;
//    assert(result==840);

        return 0;
}
