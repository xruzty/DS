#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <set>
using namespace std;
class graph
{
    public:
        int V;
        int d;
        vector<vector<int>> adj;
        graph(int, int=0);
        void addEdge(int,int);
        void bfsUtil(int,vector<int>&);
        void bfs(int=-1);
        void dfsUtil(int,vector<int>&, int print=1);
        void dfs(int=-1);
        bool cyclesDG();
        bool cyclesDGUtil(vector<int>,int);
        int cyclesUDG();
        int cyclesUDGUtil(int,vector<int>&);
        int islandsUDG();
        void rDFSUtil(int,vector<int>&, vector<int>&);
        void rDFS(int=-1);
        bool isBipartite_B();         // G is connected
        bool isBipartite_D();
        bool isBipartite_DUtil(int,vector<int>&,int);
};

#endif // GRAPH_H
