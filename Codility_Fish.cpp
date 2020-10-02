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

int solution(vector<int> &A, vector<int> &B)
{
    if(A.size() == 0 || B.size()==0)
        return 0u;
    if(A.size() == 1 || B.size()==1)
        return 1u;

    auto itA = A.begin();
    auto itB = B.begin();

    if(*itB == 0)
    {
        itA++;
        itB++;
    }

    while(1)
    {
        if(*itB == 0)
        {
            if(itA-1 ==A.begin() && *(itB-1) == 0u)
                break;

            if(*(itB-1) == 1)
            {
                if(*itA > *(itA-1))
                {
                    auto ret = A.erase(itA-1); B.erase(itB-1);
                    if(ret == A.end())
                        break;
                }
                else
                {
                    itA--;
                    itB--;
                    auto ret = A.erase(itA+1); B.erase(itB+1);
                    if(ret == A.end())
                        break;
                }
            }
            else
            {
                itA--;
                itB--;
            }
        }

        else if(*itB == 1)
        {
            if(itA+1 ==A.end())
                break;
            if(*(itB+1) == 0)
            {
                if(*itA > *(itA+1))
                {
                    auto ret = A.erase(itA+1); B.erase(itB+1);
                    if(ret == A.end())
                        break;
                }
                else
                {
                    itA++;
                    itB++;
                    auto ret = A.erase(itA-1); B.erase(itB-1);
                    if(ret == A.end())
                        break;
                }
            }
            else
            {
                itA++;
                itB++;
            }
        }
    }

    return A.size();
}

int main()
{
    vector<int> a = {4,6,2,1,5};
    vector<int> b= {0,1,0,1,0};

    auto result = solution(a,b);
    cout<<result<<endl;
    assert(result == 2);
    a.clear();
    b.clear();

    a= {4,3,2,1,5};
    b= {0,1,0,0,0};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 2);
    a.clear();
    b.clear();

    a= {4,3,2,1,5};
    b= {1,0,1,1,1};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 4);
    a.clear();
    b.clear();


    a= {4,3,2,1,5};
    b= {0,0,0,0,0};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 5);
    a.clear();
    b.clear();


    a= {4,3,2,1,5};
    b= {1,1,1,1,1};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 5);
    a.clear();
    b.clear();

    a= {4};
    b= {1};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 1);
    a.clear();
    b.clear();

    a= {};
    b= {};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 0);
    a.clear();
    b.clear();

    a= {4,3,2,1,5};
    b= {1,0,1,0,1};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 3);
    a.clear();
    b.clear();

    a= {4,3,2,1,5};
    b= {1,1,1,0,1};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 4);
    a.clear();
    b.clear();

    a= {4,3,2,1,5};
    b= {1,1,0,0,0};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 1);
    a.clear();
    b.clear();

    a= {6,3,2,1,5};
    b= {1,1,0,0,0};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 1);
    a.clear();
    b.clear();

    a= {6,3,2,1,5};
    b= {1,1,0,0,1};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 3);
    a.clear();
    b.clear();

    a= {6,3,2,1,5};
    b= {1,1,0,0,0};
    result = solution(a,b);
    cout<<result<<endl;
    assert(result == 1);
    a.clear();
    b.clear();

    return 0;
}
