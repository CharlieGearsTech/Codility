
/*

You are helping a geologist friend investigate an area with mountain lakes. A recent heavy rainfall has flooded these lakes and their water levels have reached the highest possible point. Your friend is interested to know the maximum depth in the deepest part of these lakes.

We simplify the problem in 2-D dimensions. The whole landscape can be divided into small blocks and described by an array A of length N. Each element of A is the altitude of the rock floor of a block (i.e. the height of this block when there is no water at all). After the rainfall, all the low-lying areas (i.e. blocks that have higher blocks on both sides) are holding as much water as possible. You would like to know the maximum depth of water after this entire area is flooded. You can assume that the altitude outside this area is zero and the outside area can accommodate infinite amount of water.

For example, consider array A such that:
    A[0] = 1
    A[1] = 3
    A[2] = 2
    A[3] = 1
    A[4] = 2
    A[5] = 1
    A[6] = 5
    A[7] = 3
    A[8] = 3
    A[9] = 4
    A[10] = 2

The following picture illustrates the landscape after it has flooded:

The gray area is the rock floor described by the array A above and the blue area with dashed lines represents the water filling the low-lying areas with maximum possible volume. Thus, blocks 3 and 5 have a water depth of 2 while blocks 2, 4, 7 and 8 have a water depth of 1. Therefore, the maximum water depth of this area is 2.

Write a function:

    class Solution { public int solution(int[] A); }

that, given a non-empty array A consisting of N integers, returns the maximum depth of water.

Given array A shown above, the function should return 2, as explained above.

For the following array:
    A[0] = 5
    A[1] = 8

the function should return 0, because this landscape cannot hold any water.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..100,000,000].

*/
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

using namespace std;

/*41% https://app.codility.com/demo/results/trainingVQ2VR4-TE6/*/
int solution(vector<int> &A)
{
    /*Minimum size to perform the logic is 3.*/
    const int N=A.size();
    if(N<=2)
        return 0;

    vector<vector<int>::iterator> peakIts;

    /*Get the peaks without excluding the first and last element of the array*/
    if(*A.begin() >= *(A.begin()+1))
    {
        peakIts.push_back(A.begin());
    }
    for(auto it = A.begin()+1; it != A.end()-1;++it)
        if((*it >= *(it-1)) && (*it >=*(it+1)))
        {
            peakIts.push_back(it);
        }
    if(*(A.end()-1) >= *(A.end()-2))
    {
        peakIts.push_back(A.end()-1);
    }

    if(peakIts.size() <2) /*Flat area or not enough peaks to contain the water.*/
    {
        return 0;
    }

    /*Cannot remove intermediate peaks if there is only two*/
    if(peakIts.size() >2)
    {
        for(auto it=peakIts.begin()+1; it<peakIts.end()-1;++it)
        {
            /*Remove low intermediate peaks to have global peaks alone,
             * side peaks don't care because there is no left or right that make them required to ignore*/
            if((**it <= **(it+1)) && (**it <= **(it-1)))
            {
                peakIts.erase(it);
            }
        }
    }

    int maxdeep=0;

    /*For each peak */
    for(auto i=0u; i<peakIts.size()-1;++i)
    {
        /*For each element between peaks*/
        for(auto it=peakIts[i]+1;it != peakIts[i+1];++it)
        {
            /*Compare against the min peak to obtain the deepest flood*/
            int minpeak=min(*peakIts[i],*peakIts[i+1]);
            maxdeep=max(maxdeep,minpeak-*it);
        }
    }

    return maxdeep;
}

int main()
{
    int result;
    vector<int> a;

    a={1,3,2,1,2,1,5,3,3,4,2};
    result=solution(a);
    cout<<result<<endl;
    assert(result==2);
    a.clear();

    a={5,8};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);
    a.clear();

    a={5};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);
    a.clear();

    a={5,0,5};
    result=solution(a);
    cout<<result<<endl;
    assert(result==5);
    a.clear();

    a={5,0,5,2,10};
    result=solution(a);
    cout<<result<<endl;
    assert(result==5);
    a.clear();

    a={3,3,3,3,3};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);
    a.clear();

    a={3,3,2,3,3};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);
    a.clear();

    a={3,3,2,3,3,0,3,3};
    result=solution(a);
    cout<<result<<endl;
    assert(result==3);
    a.clear();

    a={6,5,4,3,2,3,4,5,6};
    result=solution(a);
    cout<<result<<endl;
    assert(result==4);
    a.clear();

    a={6,4,5,4,5,4,5,4,6};
    result=solution(a);
    cout<<result<<endl;
    assert(result==2);
    a.clear();

    return 0;
}
