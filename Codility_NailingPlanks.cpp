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

using namespace std;

/*100% https://app.codility.com/demo/results/trainingDM4X4U-CFF/*/
bool isNailed(int nail, const vector<int>& A, const vector<int>& B, const vector<int>& C)
{
    const int N=A.size();
    const int M=C.size();

    vector<int> nails(2*M+1,0);
    for(int i=0; i<nail;i++)
        nails[C[i]]=1;

    std::partial_sum(nails.begin(), nails.end(), nails.begin());

    bool nailed=true;
    /* Iterate searching for a difference of nails between tables, there shall always be at least one more nail
       for all the table to return True, if there is no enough nails, return false.
       The expression checks how many new nails are present between the last table end and the current table, if there is no new nail
       means that the selected index has no enough nails.*/
    for(int i=0; (i<N) && nailed;i++)
        nailed = (nails[B[i]]-nails[A[i]-1])>0;

    return nailed;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int minNails=1;
    int maxNails=C.size();

    int result=-1;
    /*Cuando es min es mayor que max significa que hemos encontrado el minimo de la busqueda.*/
    while(minNails <= maxNails)
    {
        int mid=(minNails+maxNails)/2;

        /*Cuando nailed= true, significa que hay suficientes clavos y que todas las tablas estan clavadas,
          se disminuye el rango [0,mid) para buscar un valor minimo posible*/
        if(isNailed(mid,A,B,C))
        {
            /**/
            maxNails=mid-1;
            result=mid;
        }
        /*Cuando nailed=false, significa que falta almenos una tabla para clavar,
          se agranda el indice de C con la cantidad de clavos necesarios
          se incrementa el rango [mid,end)*/
        else
            minNails=mid+1;
    }
    /*Retornar el indice de C minimo para clavar todas las tablas*/
    return result;
}

/* Score: 50% https://app.codility.com/demo/results/trainingDMRG9S-6AF/ */
//int solution(vector<int> &A, vector<int> &B, vector<int> &C)
//{
//    int N=A.size();
//    int M=C.size();
//    int nailedCount=0;
//    int max_nailPos=0;
//    int min_nailPos=2147483647;

//    set<int> result;

//    for(int k=0u; k<N; ++k)
//        for(int i=0u, flag=false; i<M; ++i)
//        {
//            if(C[i]<=B[k] && C[i]>=A[k])
//            {
//                result.insert(i);
//                ++nailedCount;
//                max_nailPos=max(max_nailPos,i);
//                min_nailPos=min(min_nailPos,i);
//                flag=true;
//            }
//            if(false != flag)
//                break;
//        }

//    if(nailedCount<N)
//        return -1;
//    return max_nailPos-min_nailPos+1;
//}

int main()
{
    vector<int> a,b,c;
    int result=0;

    a={1,4,5,8};
    b={4,5,9,10};
    c={4,6,7,10,2};
    result=solution(a,b,c);
    cout<<result<<endl;
    assert(result==4u);
    a.clear();
    b.clear();
    c.clear();

    a={1,4,5,18};
    b={4,5,9,19};
    c={4,6,7,10,2};
    result=solution(a,b,c);
    cout<<result<<endl;
    assert(result==-1);
    a.clear();
    b.clear();
    c.clear();

    a={1,4,5,8};
    b={4,5,9,10};
    c={4,6,7,2};
    result=solution(a,b,c);
    cout<<result<<endl;
    assert(result==-1);
    a.clear();
    b.clear();
    c.clear();

    a={1,7,8};
    b={4,8,10};
    c={1,1,8,2};
    result=solution(a,b,c);
    cout<<result<<endl;
    assert(result==3u);
    a.clear();
    b.clear();
    c.clear();

    return 0;
}
