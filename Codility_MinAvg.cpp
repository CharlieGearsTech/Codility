#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

int solution(vector<int> &A)
{
    double currAvg = 0;
    double minAvg = ((double)(A.at(0) + A.at(1))/2);
    int minAvgIdx = 0;

    for(size_t i=0u; i< A.size()-2; ++i)
    {
        currAvg=((double)(A.at(i)+A.at(i+1))/2);
        if(currAvg<minAvg)
        {
            minAvg= currAvg;
            minAvgIdx = i;
        }

        currAvg = ((double)(A.at(i)+A.at(i+1)+A.at(i+2))/3);
        if(currAvg<minAvg)
        {
            minAvg = currAvg;
            minAvgIdx = i;
        }
    }

    currAvg = ((double)(A.at(A.size()-2)+ A.at(A.size()-1))/2);
    if(currAvg<minAvg)
    {
        minAvg = currAvg;
        minAvgIdx = A.size()-2;
    }

    return minAvgIdx;
}


int main()
{
    vector<int> v= {4,2,2,5,1,5,8};
    int result = 0;

    result=solution(v);
    cout<<result<<endl;
    assert(result==1u);
    v.clear();

    v= {1,2,3,4,5};

    result=solution(v);
    cout<<result<<endl;
    assert(result==0u);
    v.clear();

    v= {5,4,3,2,1};

    result=solution(v);
    cout<<result<<endl;
    assert(result==3u);

    return 0;
}
