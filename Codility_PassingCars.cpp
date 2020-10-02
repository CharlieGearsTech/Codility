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
    vector<vector<int>::iterator> vo;
    auto itNew = A.begin();
    int count=0u;

    while(1)
    {
        itNew = find(itNew, A.end(),0u);
        if(A.end() == itNew)
            break;
        vo.push_back(itNew);
        itNew++;
    }

    for(auto i =1u; i<=vo.size();++i)
    {
        if(vo.size()==0u)
            break;
        int ElementsFromZero= A.end()-1u-vo[i-1];
        int ZeroToIgnore = vo.size()-i;
        count+= ElementsFromZero-ZeroToIgnore;
    }

    if(count > 1000000000 || count < 0)
    {
        return -1;
    }
    else
    {
        return count;
    }
}

//int solution(vector<int> &A)
//{
//    auto itNew = A.begin();
//    int count=0u;

//    while(1)
//    {
//        itNew = find(itNew, A.end(),0u);
//        if(A.end() == itNew)
//            break;
//        count += std::count(itNew,A.end(),1u);
//        itNew++;
//    }

//    if(count > 1000000000)
//    {
//        return -1;
//    }
//    else
//    {
//        return count;
//    }
//}

int main()
{
    vector<int> v= {0,1,0,1,1};
    int count = 0u;

    count=solution(v);
    cout<<count<<endl;
    assert(count == 5u);
    v.clear();

    v= {0};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 0u);
    v.clear();

    v= {1};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 0u);
    v.clear();

    v= {0,1,1,1,0,1};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 5u);
    v.clear();

    v= {0,1,1,0,1,0};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 4u);
    v.clear();

    v= {0,0,1,1,1,1};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 8u);
    v.clear();

    v= {0,1,0,1,0,1};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 6u);
    v.clear();


    v= {1,0,1,0,1,0,1,0,1,0};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 10u);
    v.clear();

    v= {0,1};
    count=solution(v);
    cout<<count<<endl;
    assert(count == 1u);
    v.clear();

    for(auto i=0u;i<100000;++i)
    {
        if(i%2==0u)
            v.push_back(0u);
        else
            v.push_back(1u);
    }
    count=solution(v);
    cout<<count<<endl;
    assert(count == -1);
    v.clear();

    return 0;
}
