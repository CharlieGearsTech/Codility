#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> &A)
{
    vector<int> incr(100000u,0u);
    vector<int> mask(100000u,1u);
    vector<int> result;

    std::partial_sum(mask.begin(),mask.end(),incr.begin());

    sort(A.begin(),A.end());

    set_difference(incr.begin(),incr.end(),A.begin(),A.end(),inserter(result, result.begin()));

    return *min_element(result.begin(),result.end());
}

int main()
{
    vector<int> v= {1,3,6,4,1,2};
    int res= 0;

    res= solution(v);
    cout<<res<<endl;
    assert(res==5);
    v.clear();

    v= {1,2,3};
    res= solution(v);
    cout<<res<<endl;
    assert(res==4);

    v= {-1,-3};
    res= solution(v);
    cout<<res<<endl;
    assert(res==1);

    return 0;
}
