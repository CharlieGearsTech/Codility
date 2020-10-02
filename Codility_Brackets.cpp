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
    if(S.empty())
        return 1u;
    if(S.size() == 1u)
        return 0;
    if(S.size() > 200000u)
        return 0;

    deque<char> stack;
    stack.clear();

    while(!S.empty())
    {
        char curr = S.back();
        S.pop_back();
        if(stack.empty())
            stack.push_back(curr);
        else if( (curr == '}') || (curr == ']') || (curr == ')'))
            stack.push_back(curr);
        else
        {
            if((curr == '{') && ( stack.back() == '}'))
                stack.pop_back();

            else if((curr == '[') && ( stack.back() == ']'))
                stack.pop_back();

            else if((curr == '(') && ( stack.back() == ')'))
                stack.pop_back();
            else
                stack.push_back(curr);
        }
    }
    return (stack.empty())?1u:0u;
}

int numberOfDivisors(size_t n)
{
    auto i = 1u;
    auto result=0u;

    while(i*i < n)
    {
        if(n%i == 0u)
            result +=2;
        i++;
    }
    if(i*i == n)
        result ++;

    return result;
}

bool primality(size_t n)
{
    int i = 2;

    while(i*i < n)
    {
        if(n%i == 0)
            return false;
        ++i;
    }
    return true;
}

int main()
{
    string s = "()()";
    int result = 0u;

    result= solution(s);
    cout<<result<<endl;
    assert(result == 1u);
    s.clear();

    s="([)()]";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 0u);
    s.clear();

    s="";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 1u);
    s.clear();

    s="{[()()]}";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 1u);
    s.clear();

    s="{";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 0u);
    s.clear();

    s="()(()))";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 0u);
    s.clear();

    s="{)";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 0u);
    s.clear();

    s="{}{}()[](";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 0u);
    s.clear();

    s="{}{}()[]()";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 1u);
    s.clear();

    s="{}{}()[]({{}})[[[[]]]]()()(){}{}[][][[[()()()]]]";
    result= solution(s);
    cout<<result<<endl;
    assert(result == 1u);
    s.clear();

    return 0;
}
