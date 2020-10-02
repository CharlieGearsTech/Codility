#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> &A)
{
    vector<int> incr(A.size(),0u);
    vector<int> mask(A.size(),1u);
    vector<int> result ={0u};

    std::partial_sum(mask.begin(),mask.end(),incr.begin());

    sort(A.begin(),A.end());

    set_difference(incr.begin(),incr.end(),A.begin(),A.end(),inserter(result, result.begin()));

    return (0==*max_element(result.begin(),result.end()))? 1 : 0;
}

int main()
{
    vector<int> v= {4,1,3,2,};
    int res= 0;

    res= solution(v);
    cout<<res<<endl;
    assert(res==1);
    v.clear();

    v= {4,1,3};
    res= solution(v);
    cout<<res<<endl;
    assert(res==0);

    v= {2,4,5, 1, 3,6};
    res= solution(v);
    cout<<res<<endl;
    assert(res==1);

    v= {4,1,5,3,6};
    res= solution(v);
    cout<<res<<endl;
    assert(res==0);

    return 0;
}
