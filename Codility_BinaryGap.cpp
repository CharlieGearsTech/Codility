/*

A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

    class Solution { public int solution(int N); }

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..2,147,483,647].

*/
#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int N)
{
    bitset<31> num(N);
    int count =0;
    bool gapFlag = false;
    vector<int> v= {0};
    v.clear();

    for(size_t i=0; i< num.size(); ++i)
    {
        if(1 == num[i])
        {
			/*Un limite encontrado, guardarlo en el contenedor de gaps*/ 
            if(0 != count)
                v.push_back(count);
			/**/
            if(true == gapFlag)
            {
                gapFlag= false;
            }
            gapFlag = true;
            count = 0;
        }
        /*Contar 0s mientras no se encuentre un 1.*/
        else if(0 == num[i] && true == gapFlag)
        {
            ++count;
        }
    }
    /*Retornar el maximo gap*/
    return *max_element(v.begin(),v.end());
}


int main()
{
    cout<<solution(9)<<endl;
    cout<<solution(529)<<endl;
    cout<<solution(20)<<endl;
    cout<<solution(15)<<endl;
    cout<<solution(32)<<endl;
    
    return 0;
}
