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

vector<int> createPeaks(vector<int>& A)
{
    vector<int> peaks(A.size());

    for(auto i = 1u; i < A.size()-1; ++i)
        if((A[i] > A[i-1]) && (A[i] > A[i+1]))
            peaks[i] = 1u;

    return peaks;
}

/*Retorna un arreglo con referencia de los peaks mas cercanos para cada elemento
  {1,5,3,4,3,4,1,2,3,4,6,2}; = {1 1 3 3 5 5 10 10 10 10 10 10 -1} , -1 porque el
  ultimo elemento no tiene referencia a un proximo pico
*/
vector<int> nextPeak(vector<int>& A)
{
    auto peaks = createPeaks(A);
    vector<int> next(A.size());

    next[A.size()-1] = -1;

    for(int i = A.size()-2; i > -1; --i)
    {
        if(false != peaks[i]) /* Si es un peak*/
            next[i]=i;
        else
            next[i] = next[i+1];
    }
    return next;
}

int solution(vector<int> &A)
{
    auto next = nextPeak(A);
    size_t i = 1;
    auto result = 0u;

    /*Itera la cantidad de banderas que podemos agregar a los picos*/
    while(((i-1)*i) <= A.size())
    {
        auto pos = 0;
        auto num = 0u;
        /* Esta iteracion revisa los pasos entre flags que podemos agregar, mientras los pasos no soprepasen el tamaño del array
           o el numero de banderas sean menores a las que tenemos*/
        while(((size_t)pos<A.size()) && (num<i))
        {
            pos = next[pos];
            if(pos == -1)
                break;
            num++; /* Aumentarel paso*/
            pos+=i; // Indica la resolucion de pasos entre picos, si num con esta resolucion no llega a ser el maximo, no es un numero de flags correcto.
        }
        result=max(result,num);
        i++;
    }
    return result;
}

int main()
{
    vector<int> v = {1,5,3,4,3,4,1,2,3,4,6,2};
    int result;

    result=solution(v);
    cout<<result<<endl;
    assert(result==3);


    return 0;
}
