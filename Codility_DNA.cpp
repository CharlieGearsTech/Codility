#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    vector<int> result(P.size(),2147483647);
    vector<int> impact(S.size(),0);

    for(size_t e = 0u; e <S.size(); ++e)
    {
        if(S[e] == 'A')
            impact[e]= 1u;
        else if(S[e] == 'C')
            impact[e]= 2u;
        else if(S[e] == 'G')
            impact[e]= 3u;
        else if(S[e] == 'T')
            impact[e]= 4u;
        else{}
    }

    for(size_t k=0u; k< P.size(); ++k)
    {
        result[k]=*min_element(impact.begin()+ P[k], impact.begin()+ Q[k] + 1);
    }

    return result;
}

void assertV( vector<int>& result,  vector<int>&& comp)
{
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

void printV(const vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

int main()
{
    string s ="CAGCCTA";
    vector<int> p = {2,5,0};
    vector<int> q = {4,5,6};
    vector<int> result;

    result = solution(s,p,q);
    printV(result);
    assertV(result, {2,4,1});
    s.clear();
    p.clear();
    q.clear();
    result.clear();

    s= "TC";
    p = {0,0,1};
    q= {0,1,1};
    result = solution(s,p,q);
    printV(result);
    assertV(result, {4,2,2});
    s.clear();
    p.clear();
    q.clear();
    result.clear();

    s = "TCACGG";
    p = {0, 0, 5};
    q = {0, 5, 5};
    result = solution(s,p,q);
    printV(result);
    assertV(result, {4,1,3});
    s.clear();
    p.clear();
    q.clear();
    result.clear();

    s = "T";
    p = {0, 0, 0};
    q = {0, 0, 0};
    result = solution(s,p,q);
    printV(result);
    assertV(result, {4,4,4});
    s.clear();
    p.clear();
    q.clear();
    result.clear();

    s = "TAAAAAAAAAAAAAAAAA";
    p = {0, 0, 0};
    q = {1, 5, 8};
    result = solution(s,p,q);
    printV(result);
    assertV(result, {1,1,1});
    s.clear();
    p.clear();
    q.clear();
    result.clear();


    s = "TAAAAAAAAAAAAAAAAA";
    p = {0, 0, 0};
    q = {0, 5, 8};
    result = solution(s,p,q);
    printV(result);
    assertV(result, {4,1,1});
    s.clear();
    p.clear();
    q.clear();
    result.clear();

    return 0;
}
