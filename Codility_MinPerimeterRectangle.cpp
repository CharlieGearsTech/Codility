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
    if(N == 0)
        return 0;

    size_t i=1u;
    size_t min_p=4294967295;

    while(i*i < (size_t)N)
    {
        if(N%i == 0u)
            min_p = min(min_p,2*(i+(N/i)));
        ++i;
    }
    if(i*i == (size_t)N)
        min_p = min(min_p,2*(i+i));

    return min_p;
}

int main()
{
    int N;
    int result;

    N = 30;
    result = solution(N);
    cout<<result<<endl;
    assert(result==22);

    N = 9;
    result = solution(N);
    cout<<result<<endl;
    assert(result==12);

    N = 1;
    result = solution(N);
    cout<<result<<endl;
    assert(result==4);

    N = 27;
    result = solution(N);
    cout<<result<<endl;
    assert(result==24);

    N = 1000000000;
    result = solution(N);
    cout<<result<<endl;
    assert(result==126500);

    return 0;
}
