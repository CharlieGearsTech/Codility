/*
In this problem we consider binary trees, represented by pointer data structures.

A binary tree is either an empty tree or a node (called the root) consisting of a single integer value and two further binary trees, called the left subtree and the right subtree.

For example, the figure below shows a binary tree consisting of six nodes. Its root contains the value 5, and the roots of its left and right subtrees have the values 3 and 10, respectively. The right subtree of the node containing the value 10, as well as the left and right subtrees of the nodes containing the values 20, 21 and 1, are empty trees.

A path in a binary tree is a non-empty sequence of nodes that one can traverse by following the pointers. The length of a path is the number of pointers it traverses. More formally, a path of length K is a sequence of nodes P[0], P[1], ..., P[K], such that node P[I + 1] is the root of the left or right subtree of P[I], for 0 ≤ I < K. For example, the sequence of nodes with values 5, 3, 21 is a path of length 2 in the tree from the above figure. The sequence of nodes with values 10, 1 is a path of length 1. The sequence of nodes with values 21, 3, 20 is not a valid path.

The height of a binary tree is defined as the length of the longest possible path in the tree. In particular, a tree consisting of only one node has height 0 and, conventionally, an empty tree has height −1. For example, the tree shown in the above figure is of height 2.

Problem

Write a function:

    int solution(tree * T);

that, given a non-empty binary tree T consisting of N nodes, returns its height. For example, given tree T shown in the figure above, the function should return 2, as explained above. Note that the values contained in the nodes are not relevant in this task.

Technical details

A binary tree can be given using a pointer data structure. Assume that the following declarations are given:

    struct tree {
      int x;
      tree * l;
      tree * r;
    };

An empty tree is represented by an empty pointer (denoted by NULL). A non-empty tree is represented by a pointer to an object representing its root. The attribute x holds the integer contained in the root, whereas attributes l and r hold the left and right subtrees of the binary tree, respectively.

For the purpose of entering your own test cases, you can denote a tree recursively in the following way. An empty binary tree is denoted by None. A non-empty tree is denoted as (X, L, R), where X is the value contained in the root and L and R denote the left and right subtrees, respectively. The tree from the above figure can be denoted as:
  (5, (3, (20, None, None), (21, None, None)), (10, (1, None, None), None))

Assumptions

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..1,000];
        the height of tree T (number of edges on the longest path from root to leaf) is within the range [0..500].
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

struct tree {
  int x;
  tree * l;
  tree * r;
};

int checkH(tree* T)
{
    int countL=0;
    int countR=0;

    /*Llamada recursiva de los hijos de este nodo, retornan 0 si son NULL*/
    if(T->l != NULL)
    {
        countL=checkH(T->l);
    }
    if(T->r != NULL)
    {
        countR=checkH(T->r);
    }

    /* Retornar la maxima altura de los hijos + 1 de este nodo.*/
    if(T != NULL)
    {
        return max(countL,countR)+1;
    }
    /*Si es nulo, retornar 0 porque un nodo nulo no debe de tener hijos no-nulos*/
    else
    {
        return 0;
    }
}

/*100% https://app.codility.com/demo/results/training68D37D-MYB/*/
int solution(tree * T)
{
    return checkH(T)-1;
}

int main()
{

    tree r21; r21.x=21; r21.l=NULL; r21.r=NULL;
    tree* pR21 = &r21;

    tree l20; l20.x=20; l20.l=NULL; l20.r=NULL;
    tree* pL20 = &l20;

    tree l3; l3.x=3; l3.l=pR21; l3.r=pL20;
    tree* pL3 = &l3;

    tree l1; l1.x=1; l1.l=NULL; l1.r=NULL;
    tree* pL1 = &l1;

    tree r10; r10.x=1; r10.l=pL1; r10.r=NULL;
    tree* pR10 = &r10;

    tree root; root.x=5; root.l=pL3; root.r=pR10;
    tree* pRoot = &root;

    int result;

    result=solution(pRoot);
    cout<<result<<endl;
    assert(result==2);

    result=solution(pL20);
    cout<<result<<endl;
    assert(result==0);

    result=solution(pL3);
    cout<<result<<endl;
    assert(result==1);

    return 0;
}
