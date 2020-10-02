/*
The Fibonacci sequence is defined using the following recursive formula:
    F(0) = 0
    F(1) = 1
    F(M) = F(M - 1) + F(M - 2) if M >= 2

A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

        0 represents a position without a leaf;
        1 represents a position containing a leaf.

The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

For example, consider array A such that:
    A[0] = 0
    A[1] = 0
    A[2] = 0
    A[3] = 1
    A[4] = 1
    A[5] = 0
    A[6] = 1
    A[7] = 0
    A[8] = 0
    A[9] = 0
    A[10] = 0

The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.

Write a function:

    class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return −1.

For example, given:
    A[0] = 0
    A[1] = 0
    A[2] = 0
    A[3] = 1
    A[4] = 1
    A[5] = 0
    A[6] = 1
    A[7] = 0
    A[8] = 0
    A[9] = 0
    A[10] = 0

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer that can have one of the following values: 0, 1.

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

using namespace std;

const vector<int> fibonacci={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,
                             10946,17711,28657,46368,75025,121393};

int solution(vector<int> &A) {
    const int N = A.size();

    // Create our list to track if frogs are already at a location
    vector<bool> locations(N, false);

    // Calculate the fibonacci numbers up to 100000 (max N)
    // Do it once at the start of the function
    // F(0) = 0; F(1) = 1;
    // This is O(1)
    vector<int> F = {0, 1};
    int i = 2;
    while ( (F[i-1]+F[i-2]) <= 100000 ) {
        F.push_back(F[i-1] + F[i-2]);
        i++;
    }

    // Start at location -1.  Set jumps to 0.  Push to list
    // 1. Check list
    //    - If empty, no path possible
    // 2. Check if (jumps+1) >= minimumJumps, discard if so
    // 2. Iterate through all fibonacci positions away from this one that place me <= N
    // 3. Where path available, increment jumps
    // 4. Check if we are already on that leaf, if not, push to list
    int minimumJumps = std::numeric_limits<int>::max();

    struct PathStruct {
        int location;
        int jumps;

        PathStruct(int l, int j) : location(l), jumps(j) {}
    };

    std::list<PathStruct> paths;

    // Initialize and place first position
    paths.push_back(PathStruct(-1, 0));

    // Check list
    while ( !paths.empty() ) {
        // Grab from the list.  There is no guarantee of order
        // anywhere in the list - A frog further along could not have a leaf to 
        // jump to, or could just jump one more, while a frog further behind
        // could jump ahead.  So we aren't saving any time by guessing if front
        // of list of back of list is faster, just use a FIFO.
        const PathStruct path = paths.front();
        paths.pop_front();

        // Remove this leaf from the tracked locations
        if ( path.location >= 0 ) {
            locations[path.location] = false;
        }

        // Check if this path could be shorter than the current minimumJumps
        // If not, then discard it from the queue
        if ( (path.jumps+1) >= minimumJumps ) {
            continue;
        }

        // Go through each fibonacci number and see if
        // we can reach another leaf (location<N) or the
        // bank (location == N).  F[1] and F[2] are duplicates, and F[0] is 0
        for (unsigned int f=2; f<F.size(); f++) {
            int candidate = path.location + F[f];

            if ( (candidate < N) && A[candidate] ) {
                // Don't consider leaf if it is already under conseration
                if ( locations[candidate] ) {
                    continue;
                }
                // Reached another leaf
                paths.push_back(PathStruct(candidate, path.jumps+1));
                locations[candidate] = true;
            } else if ( candidate == N ) {
                // Reached bank
                minimumJumps = std::min(minimumJumps, path.jumps+1);

                // jump out of this loop, logic says this has to be a new
                // minimum jump for this possible path
                break;
            } else if (candidate > N) {
                // Oops - kerplop!
                // F is increasing from here on out so 
                // lets stop checking this iteration
                break;
            }
        }
    }

    // check if I found a path
    if ( minimumJumps == std::numeric_limits<int>::max() ) {
        minimumJumps = -1;
    }

    return minimumJumps;
}
/* O(N*logN*logN) https://app.codility.com/demo/results/training5UNQSG-8JT/*/
// int solution(vector<int> &A)
// {
//     const int N=A.size();
//     int count=0u;
// 
//     if(N==0)
//         return 1;
//     /*If the size is a fibonacci number, then can just go directly to the end,
//       +1 is to compensate the indexing 0*/
//     if(fibonacci.end() != find(fibonacci.begin(),fibonacci.end(),A.size()+1))
//         return 1;
// 
//     /*Get only the Fibonacci that can be used based on the array size*/
//     auto itMax=lower_bound(fibonacci.begin(),fibonacci.end(),A.size());
// 
//     auto k=-1;
//     /*Ensure that at least all the iteration is complete before throwing -1*/
//     for(auto i=0u;i<A.size();++i)
//     {
//         /*Begin always from the biggest fibonacci to have the minimum steps*/
//         for(reverse_iterator<decltype (itMax)> it(itMax+1); it != fibonacci.rend();++it)
//         {
//             unsigned currFibIdx=*it+k;
//             /*If the jump does not overpass as a non-fibonacci and the jump yields to a leaf,
//               increment the counter and refrhes k to set new point of jump*/
//             if(currFibIdx < A.size() && A[currFibIdx]==1)
//             {
//                 ++count;
//                 k=currFibIdx;
//                 break;
//             }
//             /*Reaching exactly the end of the container yields to a correct finish*/
//             if(currFibIdx==A.size())
//             {
//                 ++count;
//                 k=A.size();
//                 return count;
//             }
//         }
//     }
//     return -1;
// }

/*Imprimir vector<int>s*/
void printV(vector<int>& vRes)
{
    for(auto it= vRes.begin(); it != vRes.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

/*Assertion de vectores de ints*/
void assertV( vector<int>& result,  vector<int>&& comp)
{
    bool res = std::equal(result.begin(),result.end(),comp.begin());
    assert(res);
}

int main()
{
    int result;
    vector<int> a;

    a={0,0,0,1,1,0,1,0,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==3);

    a={0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={0,0,1,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={0,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={0,0,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==-1);

    a={};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={0,0,0,0,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==1);

    a={0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==4);

    a={1,0,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==2);

    /*It will fail because it goes from max fibonacci to min fibonacci,
      and sets element 2 always and won't refresh to check if there is another minimum fibonacci combination
      in this case element 1, to later jump 5 elements.*/
    a={1,1,0,0,0};
    result=solution(a);
    cout<<result<<endl;
    assert(result==2);

    return 0;
}
