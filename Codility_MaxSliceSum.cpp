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

int solution(vector<int> &A)
{
    if(A.size()==0)
        return 0;

    auto maxNeg=-2147483648;
    bool ZeroFlag = false;
    int max_slide = 0, max_ending = 0;

    for(auto a: A)
    {
        max_ending = max(0, max_ending + a);
        if(a <0 && maxNeg < a)
            maxNeg = a;
        if(a==0)
            ZeroFlag=true;
        max_slide = max(max_slide,max_ending);
    }

    if(max_slide==0 && maxNeg!=-2147483648 && ZeroFlag == false)
        return maxNeg;
    else
        return max_slide;
}

int main()
{
    vector<int> v= {3,2,-6,4,0};
    int result = 0;

    result= solution(v);
    cout<<result<<endl;
    assert(result==5);
    v.clear();

    v = {-10};
    result= solution(v);
    cout<<result<<endl;
    assert(result==-10);
    v.clear();

    v = {5,-7,3,5,-2,4,-1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==10);
    v.clear();

    v = {-3,-2,-6,-4,-8};
    result= solution(v);
    cout<<result<<endl;
    assert(result==-2);
    v.clear();

    v = {};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {0,0,0,0,0};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {-1,-1,-1,-1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==-1);
    v.clear();

    v = {-1,-2,-3,-4};
    result= solution(v);
    cout<<result<<endl;
    assert(result==-1);
    v.clear();

    v = {-1,0,-1,-1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {0};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    return 0;
}
