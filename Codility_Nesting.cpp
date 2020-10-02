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

int solution(string &S)
{
    std::string s=S;
    if(s.empty())
        return 1u;
    if(s.size() == 1u)
        return 0;
    if(s.size() > 200000u)
        return 0;

    deque<char> stack;
    stack.clear();

    while(!s.empty())
    {
        char curr = s.back();
        s.pop_back();
        if(stack.empty())
            stack.push_back(curr);
        else if(curr == ')')
            stack.push_back(curr);
        else
        {
            if((curr == '(') && ( stack.back() == ')'))
                stack.pop_back();
            else
                stack.push_back(curr);
        }
    }
    return (stack.empty())?1u:0u;
}


int main()
{
    string s="(()(())())";
    auto result = 0u;

    result=solution(s);
    cout<<result<<endl;
    assert(result==1u);
    s.clear();

    s="())";
    result=solution(s);
    cout<<result<<endl;
    assert(result==0u);
    s.clear();

    s="";
    result=solution(s);
    cout<<result<<endl;
    assert(result==1u);
    s.clear();

    s="()()()()()(())((()))(())";
    result=solution(s);
    cout<<result<<endl;
    assert(result==1u);
    s.clear();

    return 0;
}
