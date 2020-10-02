/*An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

    class Solution { public int solution(int[] A); }

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)]*/
#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

/*Esta logica sencilla ordena el contenedor e itera de 1 a N hasta encontrar el elemento faltante
  pongo 100,000 pero al momento de encontrar alguna diferencia, se rompera la iteracion asi que
  normalmente la complejidad sera O(logN) en lo mas complicado.
  100% https://app.codility.com/demo/results/trainingKKCTSR-S3T/*/
int solution(vector<int> &A)
{
    if(A.size()==0)
        return 1;
    std::sort(A.begin(),A.end());

    for(auto i=1; i<=100000;++i)
    {
        if(A[i-1] != i)
        {
            return i;
        }
    }
    return -1;
}

/*Esta solucion se basa en iterar en todo el contenedor con find por un valor que falte... El problema es que este algoritmo es probablemente muy tardado O(n²)*/
//int solution(vector<int> &A)
//{
//    for(size_t i=1; i<= 100000; ++i)
//        if(A.end() == find(A.begin(), A.end(),i))
//            return i;
//}


int main()
{
    vector<int> v= {2,3,1,5};
    int result=0;

    result=solution(v);
    cout<<result<<endl;
    assert(result==4);
    v.clear();

    v= {3,4,2,5,7,6,9,8};
    result=solution(v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18};
    result=solution(v);
    cout<<result<<endl;
    assert(result==17);
    v.clear();


    return 0;
}
