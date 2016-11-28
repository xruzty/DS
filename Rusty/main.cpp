#include <iostream>
#include "trees.h"
#include <math.h>
#include <stdlib.h>
#include "treenode.h"
#include "bst.h"
#include "bstnode.h"
#include "listnode.h"
#include "ll.h"
#include <stack>
#include <vector>
#include <unordered_set>
#include <thread>
#include <map>
#include "bstinorderiter.h"
#include "minheap.h"
#include "arrays.h"
#include "avltree.h"
#include <chrono>
#include <graph.h>
#include <list>
using namespace std;

int main()
{
 /*   vector<int> T;
   unsigned long long n = 20999;
    //while (true) {
        auto start = std::chrono::high_resolution_clock::now();
        for(int i=0;i<n;i++)
        T.push_back(n-i);
        BSTnode* root = create_pre2(T);
        cout<<"done for n="<<n<<endl;
        auto finish = std::chrono::high_resolution_clock::now();

        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
        std::cout << int(microseconds.count())/1000 << "ms\n"<<endl;
   //     if (microseconds > std::chrono::seconds(10))
   //         break;
   // }
        start = std::chrono::high_resolution_clock::now();
        BSTnode* root2 = create_pre(T);
        cout<<"done for n="<<n<<endl;
        finish = std::chrono::high_resolution_clock::now();
        microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
        std::cout << int(microseconds.count())/1000 << "ms\n";
*/
    graph G(5,1);
    G.addEdge(0,4);
    G.addEdge(4,2);
    G.addEdge(2,3);
    G.addEdge(3,1);
    G.addEdge(1,4);
    G.addEdge(1,2);


    //G.addEdge(0,3);
    //G.addEdge(0,1);
 //   if(G.cyclesDG())
 //       cout<<"yes";
 //   else
 //       cout<<"noo";
    //G.dfs();
    string s = "Bipartite";
    if(G.isBipartite_D())
        cout<<"is "+s;
    else
        cout<<"not "+s;
    //G.rDFS();
    return 0;
}
