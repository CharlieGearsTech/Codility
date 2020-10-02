/*
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

  1,2,3,3,4= 1,3,6,9,13
             4-(13-4)=4-9=5
             1-(13-1)=11
             6-(13-6)=6-7=1
             9-(13-9)=9-4=5

We can split this tape in four places:

        P = 1, difference = |3 − 10| = 7
        P = 2, difference = |4 − 9| = 5
        P = 3, difference = |6 − 7| = 1
        P = 4, difference = |10 − 3| = 7

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

*/
#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

/*Solucion se basa en la suma en direccion directa e inversa de los elementos,
   de esta manera disminuimos la complejidad a la hora de restar
   abs(... +A[p-2] +A[p-1] - A[p] + ...A[p+1] + ...)*
  100% https://app.codility.com/demo/results/trainingQGU7A9-7UP/*/
int solution(vector<int> &A)
{
    int N=A.size();
    vector<int> foward(N,0);
    vector<int> backward(N,0);

    foward[0]=A[0];
    backward[N-1]=A[N-1];

    if(N<=2)
        return abs(foward[0]-backward[N-1]);

    /*Llenar los contenedores con la suma en direccion directa e inversa*/
    for(auto i=1; i<N; ++i)
    {
        foward[i]=foward[i-1]+A[i];
        backward[N-1-i]=backward[N-i]+A[N-1-i];
    }

    int result=1001u;

    for(int i=0; i<N-1;++i)
    {
        /*backward i+1 respeta el orden en la que la resta se tiene que hacer entre los 2 acumulados.*/
        result=min(result,abs(foward[i]-backward[i+1]));
    }

    return result;
}

/*54% https://app.codility.com/demo/results/trainingPCMTDA-QR7/*/
//int solution(vector<int> &A)
//{
//    size_t p=1u;
//    int result=2147483647u;

//    for(p=1; p< A.size(); ++p)
//    {
//        int sign = 1;
//        int accum = 0u;
//        for(size_t i=0; i<A.size();++i)
//        {
//            /*Si llegamos al limite de P: ... (A[P-1] + [P])- (A[P+1] + A[P+2])
//             cambiar el signo para acumular la resta del otro segmento.*/
//            if((i+1u) > p)
//                sign=-1;
//            accum +=A.at(i)*sign;
//        }
//        /*Reemplazar si la resta acumulada es menor que el resultado*/
//        result=min(result,abs(accum));
//    }
//    return result;
//}

int main()
{
    vector<int> v= {3,1,2,4,3};
    int result=0;

    result=solution(v);
    cout<<result<<endl;
    assert(result==1);
    v.clear();

    v= {3,6,2,4,3};
    result=solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v = {-4,3,2,6,-1};
    result=solution(v);
    cout<<result<<endl;
    assert(result==4);
    v.clear();

    v={-1000, 1000};
    result=solution(v);
    cout<<result<<endl;
    assert(result==2000);
    v.clear();

    return 0;
}
