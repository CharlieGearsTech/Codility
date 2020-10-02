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

/* O(N) https://app.codility.com/demo/results/trainingGPVWXZ-4KW */
int solution(vector<int>& A)
{
    const int N=A.size();

    vector<int> foward(N,0);
    vector<int> backward(N,0);

    /*Can ignore both first index and last index since no matter the X and Z option,
      they are going to be ignore always*/
    for(int i=1; i<N; ++i)
        foward[i]=max(0,foward[i-1]+A[i]);

    for(int i= N-2; i>=0; --i)
        backward[i]=max(0,backward[i+1] + A[i]);

    int max_d_slide=0;

    for(int i=1; i<N-1; ++i)
        max_d_slide=max(max_d_slide,foward[i-1]+backward[i+1]);

    return max_d_slide;
}

int main()
{
    vector<int> v= {3,2,6,-1,4,5,-1,2};
    int result = 0;

    result= solution(v);
    cout<<result<<endl;
    assert(result==17);
    v.clear();

    return 0;
}
