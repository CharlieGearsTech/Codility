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

/*Return the highest amount of no-overlapping lines*/
int solution(vector<int> &A, vector<int> &B)
{
    if(A.size() < 2)
        return A.size();

    /*Seems that at least one line is not being overlapping*/
    unsigned noOverlapping=1;
    unsigned i=0;
    unsigned b = B[0];

    /* Terminate the algorithm until end*/
    while(i < A.size())
    {
        /* Iterate until we reach a non overlaping line: start of line is not before the end of line*/
        while(i < A.size() && (int)b >= A[i])
            ++i;
        /* If reaching the end of the container*/
        if(i==A.size())
            break;
        /* We found a non overlaping line, increment counter and replace the end of the line
           with the new one.*/
        noOverlapping++;
        b=B[i];
    }
    return noOverlapping;
}

int main()
{
    vector<int> a= {1,3,7,9,9};
    vector<int> b= {5,6,8,9,10};
    auto result=0u;

    result=solution(a,b);
    cout<<result<<endl;
    assert(result==3);
    a.clear();
    b.clear();

    a={};
    b={};
    result=solution(a,b);
    cout<<result<<endl;
    assert(result==0);
    a.clear();
    b.clear();

    a={1};
    b={2};
    result=solution(a,b);
    cout<<result<<endl;
    assert(result==1);
    a.clear();
    b.clear();

    a={1,2,3,6,9,10};
    b={4,5,7,8,9,11};
    result=solution(a,b);
    cout<<result<<endl;
    assert(result==4);
    a.clear();
    b.clear();

    return 0;
}
