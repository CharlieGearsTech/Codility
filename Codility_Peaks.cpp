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
    if(A.size() <= 1)
        return 0;

    vector<vector<int>::iterator> peaksIt;
    for(auto it = A.begin()+1; it != A.end()-1;++it)
        if((*it > *(it-1)) && (*it >*(it+1)))
            peaksIt.push_back(it);

    if(peaksIt.size() == 0)
        return 0;

    for(auto K= peaksIt.size(); K > 0; --K)
    {
        auto found = vector<int>(K);
        auto found_count= 0u;
        for(auto it = peaksIt.begin(); it != peaksIt.end();++it)
        {
            auto block_number = it-peaksIt.begin();
            if(found[block_number] == false)
            {
                found[block_number] = true;
                found_count += 1;
            }
        }
        if(found_count == K)
            return K;
    }
    return 0;
}


//int solution(vector<int> &A)
//{
//    if(A.size() <= 1)
//        return 0;

//    vector<vector<int>::iterator> peaksIt;
//    for(auto it = A.begin()+1; it != A.end()-1;++it)
//        if((*it > *(it-1)) && (*it >*(it+1)))
//            peaksIt.push_back(it);

//    size_t K=1u;
//    size_t result= 0u;
//    auto N= A.size();
//    auto M = peaksIt.size();

//    if(M == 0)
//        return 0;
//    if(M == 1)
//        return 1;

//    while(K*K<N)
//    {
//        if(N%K == 0)
//        {
//            size_t count=0;
//            for(auto i = 1u; i <= K; ++i)
//                if((size_t)((peaksIt[M-i]- A.begin())) < (size_t)(N/i))
//                    count++;
//            if(count == K)
//                result = max(result,K);
//        }
//        ++K;
//    }
//    if(K*K == N)
//        result = max(result,M);

//    return result;
//}

int main()
{
    vector<int> v = {1,2,3,4,3,4,1,2,3,4,6,2};
    int result;

    result= solution(v);
    cout<<result<<endl;
    assert(result == 3);
    v.clear();

    v= {1};
    result= solution(v);
    cout<<result<<endl;
    assert(result == 0);
    v.clear();

    v= {1,4,3};
    result= solution(v);
    cout<<result<<endl;
    assert(result == 1);
    v.clear();

    v= {1,4,3,1,2,3,4};
    result= solution(v);
    cout<<result<<endl;
    assert(result == 1);
    v.clear();

    v= {1,1000000000,3,1,2,3,4};
    result= solution(v);
    cout<<result<<endl;
    assert(result == 1);
    v.clear();

    v= {1,1000000000,3,1,2,3,4,2};
    result= solution(v);
    cout<<result<<endl;
    assert(result == 2);
    v.clear();

    v={0, 1, 0, 0, 1, 0, 0, 1, 0};
    result= solution(v);
    cout<<result<<endl;
    assert(result == 3);
    v.clear();

    return 0;
}
