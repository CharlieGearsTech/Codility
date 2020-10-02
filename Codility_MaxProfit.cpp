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
    int max_ending = 0u;
    int max_slide = 0u;

    if(A.size() <= 1u)
        return 0;

    for(auto i = 0u; i< A.size()-1u;++i)
    {
        max_ending = max(0,max_ending + (A[i+1]-A[i]));
        max_slide = max(max_slide,max_ending);
    }
    return max_slide;
}

//int solution(vector<int> &A)
//{
//    int max_profit = 0u;
//    for( auto i = 0u; i< A.size();++i)
//        for(auto j = i+1u; j< A.size(); ++j)
//            max_profit = max(max_profit,(A[j]-A[i]));

//    return max_profit;
//}

/*
 max_slide retorna el numero maximo en un rango [p,q] del arreglo.
*/
int max_slide(vector<int>& A)
{
    int max_slide, max_ending = 0;

    for(auto a: A)
    {
        max_ending = max(0, max_ending + a);
        max_slide = max(max_slide,max_ending);
    }
    return max_slide;
}

int main()
{
    vector<int> v= {23171,21011,21123,21366,21013,21367};
    int result = 0;

    result= solution(v);
    cout<<result<<endl;
    assert(result==356);
    v.clear();

    v = {1,2,3,4,5,6};
    result= solution(v);
    cout<<result<<endl;
    assert(result==5);
    v.clear();

    v = {6,5,4,3,2,1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {1,2};
    result= solution(v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v= {23171,21367,21123,21366,21013,21011};
    result= solution(v);
    cout<<result<<endl;
    assert(result==243);
    v.clear();

    v= {23171,21367,21366,21123,21013,21011};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    return 0;
}
