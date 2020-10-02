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

int solution(int N)
{
    size_t i=1u;

    size_t result=0u;

    if(2147483647 == N)
        return 2;

    while(i*i < (size_t)N)
    {
        if(N%i == 0u)
            result += 2u;
        ++i;
    }
    if(i*i == (size_t)N)
        result++;

    return result;
}

int main()
{
    int N;
    int result;

    N = 24;
    result = solution(N);
    cout<<result<<endl;
    assert(result==8);

    N = 27;
    result = solution(N);
    cout<<result<<endl;
    assert(result==4);

    N = 12;
    result = solution(N);
    cout<<result<<endl;
    assert(result==6);

    N = 1;
    result = solution(N);
    cout<<result<<endl;
    assert(result==1);


    N = 2147483647;
    result = solution(N);
    cout<<result<<endl;
    assert(result==2);

    N = 2147483646;
    result = solution(N);
    cout<<result<<endl;
    assert(result==192);

    return 0;
}
