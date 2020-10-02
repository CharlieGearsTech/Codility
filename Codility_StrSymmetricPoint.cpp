/*

Write a function:

    int solution(string &S);

that, given a string S, returns the index (counting from 0) of a character such that the part of the string to the left of that character is a reversal of the part of the string to its right. The function should return −1 if no such index exists.

Note: reversing an empty string (i.e. a string whose length is zero) gives an empty string.

For example, given a string:

"racecar"

the function should return 3, because the substring to the left of the character "e" at index 3 is "rac", and the one to the right is "car".

Given a string:

"x"

the function should return 0, because both substrings are empty.

Write an efficient algorithm for the following assumptions:

        the length of S is within the range [0..2,000,000].

*/
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

/*https://app.codility.com/demo/results/training4P2XJG-HXV/*/
int solution(string &S)
{
    if(S.empty())
        return -1;
    /*Indice 0 es el indice intermedio de un string de un elemento*/
    if(S.size()==1)
        return 0;
    /* Numeros pares no pueden tener un indice intermedio palindrome*/
    if(S.size()%2==0)
        return -1;

    int mid= floor((float)(S.size()/2));

    /*Checar del centro hacia afuera cada uno de los caracteres.*/
    for(int i=1; i<=mid; ++i)
    {
        if(S[mid-i] != S[mid+i])
            return -1;
    }
    return mid;
}

int main()
{
    int result;
    string s="racecar";

    result=solution(s);
    cout<<result<<endl;
    assert(result==3);
    s.clear();

    s="x";
    result=solution(s);
    cout<<result<<endl;
    assert(result==0);

    s="";
    result=solution(s);
    cout<<result<<endl;
    assert(result==-1);

    s="civic";
    result=solution(s);
    cout<<result<<endl;
    assert(result==2);

    s="repaper";
    result=solution(s);
    cout<<result<<endl;
    assert(result==3);

    s="wow";
    result=solution(s);
    cout<<result<<endl;
    assert(result==1);

    s="redrumsirismurder";
    result=solution(s);
    cout<<result<<endl;
    assert(result==8);

    s="abc";
    result=solution(s);
    cout<<result<<endl;
    assert(result==-1);

    return 0;
}
