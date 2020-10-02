/*

You are given an array A consisting of the integers −1, 0 and 1. A slice of that array is any pair of integers (P, Q) such that 0 ≤ P ≤ Q < N. Your task is to find the longest slice of A whose elements yield a non-negative sum.

Write a function:

    int solution(vector<int> &A);

that, given an array A of length N, consisting only of the values −1, 0, 1, returns the length of the longest slice of A that yields a non-negative sum. If there's no such slice, your function should return 0.

For example, given A = [−1, −1, 1, −1, 1, 0, 1, −1, −1], your function should return 7, as the slice starting at the second position and ending at the eighth is the longest slice with a non-negative sum.

For another example, given A = [1, 1, −1, −1, −1, −1, −1, 1, 1] your function should return 4: both the first four elements and the last four elements of array A are longest valid slices.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1..1].

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
#include <stdio.h>

using namespace std;
/*100% external*/
// int solution(vector<int>& A)
// {
//     const int N=A.size();
//     int sum = 0;
//     int maxslice = 0;
//     vector<int> sumindex(N);
// 
//     for(int i = 0; i<N; i++) {
//         sum -= A[i];
//         if(sum <= 0)
//             maxslice = i + 1;
//         else if(sumindex[sum-1]!=0)
//             maxslice=max(maxslice, i - sumindex[sum-1]);
//         else
//             sumindex[sum-1]=i;
//     }
//     return maxslice;
// }


/*18% No considera sequencia al revez v={0, -1, 0, 0, 1, 0, -1, -1}; tiene un maximo de 5 si va de 0 a N pero tiene un maximo de N hacia 0 de 6. Talvez si hacemos la misma logica pero de N a 0 y al final comparar el max(max_slide_foward,max_slide:backward) se obtendria el resultado esperado https://app.codility.com/demo/results/trainingJ9FMCN-6BP/*/
// int solution(vector<int> &A)
// {
//     const int N=A.size();
//     int count=0;
//     int max_slide=0;
//     int reset=0;
// 
//     for(auto i=0; i<N;++i)
//     {
//         /*Filtrar numeros que no agreguen al slide.*/
//         if(A[i]+count >=0)
//         {
//             count+=A[i];
//             reset++;
//             max_slide=max(max_slide,reset);
//         }
//         /*Prevent the addition of minor slides after a no slide elements adding*/
//         else
//         {
//             reset=0;
//         }
//     }
//     return max_slide;
// }

int main()
{
    vector<int> v;
    int result=0;

	v={0, -1, 0, 0, 1, 0, -1, -1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==6);
    v.clear();
	
    v={-1,-1,1,-1,1,0,1,-1,-1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==7);
    v.clear();

    v={1, 1, -1, -1, -1, -1, -1, 1, 1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==4);
    v.clear();

    v={1, 1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==2);
    v.clear();

    v={-1, -1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={0, 0};
    result=solution(v);
    cout<<result<<endl;
    assert(result==2);
    v.clear();

    v={0, -1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v={-1, 0};
    result=solution(v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    for(auto i=0; i<100000;++i)
        v.push_back(1);
    result=solution(v);
    cout<<result<<endl;
    assert(result==100000);
    v.clear();

    for(auto i=0; i<100000;++i)
        v.push_back(-1);
    result=solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={-1, -1, -1, -1, 0, 1, -1, 1, 1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==5);
    v.clear();

    return 0;
}
