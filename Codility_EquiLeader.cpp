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

/*O(n) busqueda de Lider
    vector<int> v= {4,6,6,6,6,8,8,8,8,8,8,8};
    assert(result==8);*/
int getLeader(vector<int>::iterator itFirst, vector<int>::iterator itLast)
{
    int size =0;
    int value = 0;

    if(itFirst == itLast)
        return *itFirst;

    for(auto k= itFirst; k != itLast+1; ++k)
    {
        if(0u == size)
        {
            size++;
            value = *k;
        }
        else
        {
            if(*k != value)
                size--;
            else
                size++;
        }
    }

    int candidate = -1;

    if(size>0)
        candidate=value;

    int leader = -1;
    auto count =0u;

    for(auto k=itFirst;k != itLast+1;++k)
     if(*k == candidate)
         count++;

    if(count > (itLast+1-itFirst)/2)
        leader= candidate;

    return leader;
}

int solution(vector<int> &A)
{
    int count=0;

    auto it= A.begin();
    auto leader = getLeader(A.begin(), A.end());

    while(1)
    {
        it = find(it,A.end(),leader);
        if(it == A.end())
            break;

        auto leaderFirst = getLeader(A.begin(),it);
        auto leaderSecond = getLeader(it+1,A.end()-1);

        if((leader == leaderFirst) && (leader == leaderSecond))
            count++;
        it++;
    }

    return count;
}


//int solution(vector<int> &A) {
//    // write your code in C++14 (g++ 6.2.0)
    
//    map<int, int> m;
//    int max = 0, index, result = 0, count = 0;
    
//    for(int i = 0; i < A.size(); i++){
//        if(m.find(A[i]) != m.end()){
//            m[A[i]] += 1;
//            if(max < m[A[i]]){
//                max = m[A[i]];
//                index = A[i];   
//            }
//        }else
//            m.insert(pair<int, int>(A[i], 1));
//    }
    
//    if(max < A.size() / 2)
//        return 0;
    
//    for(int i = 0; i < A.size(); i++){
//        if(A[i] == index){
//            count++;
//            m[index]--;
//        }
        
//        if(m[index] > (A.size() - (i + 1)) / 2 && count > (i + 1) / 2)
//            result++;
        
//    }
    
//    return result;
//}
int main()
{

    vector<int> v= {4,3,4,4,4,2};
    int result = 0;

    result= solution(v);
    cout<<result<<endl;
    assert(result==2);
    v.clear();

    v={4,3,4,4,2,4};
    result= solution(v);
    cout<<result<<endl;
    assert(result==3);
    v.clear();

    v={0,4,4,4,2,4,4};
    result= solution(v);
    cout<<result<<endl;
    assert(result==4);
    v.clear();

    v={};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={4};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={4,1,4};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={4,1,4,4};
    result= solution(v);
    cout<<result<<endl;
    assert(result==2);
    v.clear();

    v={0,4,4,4,2,4,4,3,5,5,4,4,5};
    result= solution(v);
    cout<<result<<endl;
    assert(result==0);
    v.clear();

    v={0,4,4,4,2,4,4,5,4,4,5};
    result= solution(v);
    cout<<result<<endl;
    assert(result==3);
    v.clear();

    /*Esta retornando 2 en vez de 3,
      parece ser que el ultimo elemento no se esta tomando en cuenta solo.*/
    v={1, 2, 1, 1, 2, 1};
    result= solution(v);
    cout<<result<<endl;
    assert(result==3);
    v.clear();
    return 0;
}
