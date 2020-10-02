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

int solution(string &S)
{
    istringstream ss(S);
    string token;
    int maxsize=0;

    while(getline(ss,token,' '))
    {
        bool alphanum=true;
        int alpha = 0;
        int num = 0;
        int N=token.size();

        for(auto i=0; i<N; ++i)
        {
            auto c=token[i];
            if(!isalnum(c))
            {
                alphanum=false;
                break;
            }
            else
            {
                alphanum=true;
                if(isalpha(c))
                {
                    alpha++;
                }
                else if(isdigit(c))
                {
                    num++;
                }
            }
        }
        if((alphanum == true) && (alpha%2==0) && (num%2!=0))
        {
            maxsize=max(maxsize,N);
        }
    }
    return (maxsize)?maxsize:-1;
}

int main()
{
    int result;
    string s;

    s="test 5 a0A pass007 ?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==7);
    s.clear();

    s="test 5 ?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==1);
    s.clear();

    s="     ";
    result=solution(s);
    cout<<result<<endl;
    assert(result==-1);
    s.clear();

    s="?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==-1);
    s.clear();

    s="test 5 a0A pass0070 ?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==3);
    s.clear();

    s="test 5 a0A passs007 ?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==3);
    s.clear();

    s="test 5 a0A -pass007 ?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==3);
    s.clear();

    s=" 01234567890 test 5 a0A pass007 ?xy1";
    result=solution(s);
    cout<<result<<endl;
    assert(result==11);
    s.clear();

    return 0;
}
