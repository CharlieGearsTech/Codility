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

using namespace std;

/*100% https://app.codility.com/demo/results/trainingW68FH6-VWM/*/
int solution(vector<int> &A) {
    const int N = A.size();

    int count = 0;

    // Since 0<=P<Q<R<N, sorting makes the logic simpler to identify R as the largest index always.
    std::sort(A.begin(), A.end());

    /*Iterate ordenally*/
    for (int p=0; p<N-2; ++p) {
        // {P}, {Q = P+1}, {R = Q+1 = P+2}
        int r = p+2;

        /* Since the array is sorted, is easy to define a range between R and Q where all the combinations
           yield to a triangule.*/
        for (int q=(p+1); q<(N-1); q++) {
            // Stop if R reaches the end or if A[P] <= A[R]-A[Q]
            while ( (r<N) && (A[p] > (A[r]-A[q])) ) {
                // Increment the triangles and keep pushing R out to the right
                r++;
            }
            count += (r-q-1);
        }
    }

    return count;
}

/*45% https://app.codility.com/demo/results/trainingQAPY67-8TX/*/
///* Rule to find a triplet triangle*/
//bool CheckTriangle(long P, long Q, long R)
//{
//    if((P+Q) > R)
//        if((P+R) > Q)
//            if((Q+R) > P)
//                return true;
//    return false;
//}

//int solution(vector<int> &A)
//{
//    const int N=A.size();
//    if(N < 3)
//        return 0;

//    if(N ==3)
//        return (CheckTriangle(A[0],A[1],A[2]))?1:0;

//    int count=0;
//    int b=0;
//    int m=1;
//    int f=2;

//    sort(A.begin(),A.end());

//    for(;;)
//    {
//        bool triangle=false;
//        if(CheckTriangle(A[b],A[m],A[f]))
//        {
//            count++;
//            triangle=true;
//        }
//        while(f<N-1 && triangle)
//        {
//            f++;
//            triangle=CheckTriangle(A[b],A[m],A[f]);
//            if(triangle)
//                count++;
//        }
//        if((!triangle) && (f<N-1) && (f==b+2) && (f=m+1))
//        {
//            b++;
//            m++;
//            f++;
//        }
//        else if(f==N-1 && m<N-2)
//        {
//            m++;
//        }
//        else if((f=N-1) && (m=N-2) && (b<N-3))
//        {
//            b++;
//        }
//        else if((f=N-1) && (m=N-2) && (b=N-3))
//        {
//            break;
//        }
//    }
//    return count;
//}

int main()
{
    int result;
    vector<int> a;

    a={10,2,5,1,8,12};
    result=solution(a);
    cout<<result<<endl;
    assert(result==4);

    a={};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={10};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={10,2};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={5,8,12};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={10,50,5,1};
    result=solution(a);
    cout<<result<<endl;
    assert(result==0);

    a={10,2,5,1,8,20};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={10,2,5,1,8,17};
    result=solution(a);
    cout<<result<<endl;
	
    assert(result==2);

    return 0;
}
