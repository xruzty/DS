#include "graph.h"

graph::graph(int v, int directed)
{   V = v;
    d = directed;
    for(int i=0;i<v;++i)
        adj.push_back(*(new vector<int>));
}
void graph::addEdge(int u, int v){
    adj[u].push_back(v);
    if(!d)
        adj[v].push_back(u);
}
void graph::bfsUtil(int v, vector<int>& visit){
    queue<int> q;
    if(!visit[v])
        q.push(v);
    visit[v] = 1;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;++i){
            int node = q.front();q.pop();
            cout<<node<<" ";
            for(int j=0;j<adj[node].size();j++){
                int child = adj[node][j];
                if(!visit[child]){
                    visit[child]=1;
                    q.push(child);
                }
            }
        }
    }
}
void graph::bfs(int v){
    vector<int> visit(V,0);
    if(v==-1)
        for(int i=0;i<V;++i)
        bfsUtil(i,visit);
    else
        bfsUtil(v,visit);
}
void graph::dfsUtil(int v, vector<int>& visit, int print){
    stack<int> s;
    if(!visit[v]){
        s.push(v);
        visit[v]=1;
    }
    while(!s.empty()){
        int node = s.top();s.pop();
        if(print)
            cout<<node<<" ";
        for(int i=adj[node].size();--i>=0;){
            int child = adj[node][i];
            if(!visit[child]){
                s.push(child);
                visit[child]=1;
            }
        }
    }
}
void graph::dfs(int v){
    vector<int> visit(V,0);
    if(v==-1){
        for(int i=0;i<V;++i)
            dfsUtil(i,visit);
    }
    else
        dfsUtil(v,visit);
}
bool graph::cyclesDGUtil(vector<int> visited, int v){
    stack<int> s,p;
    set<int> S;
    if(!visited[v]){
        visited[v] = 1;
        s.push(v);
    }
    while(!s.empty()){
        int node = s.top();
        if(!p.empty()&&p.top()==node){
            p.pop();
            s.pop();
            S.erase(node);
        }
        else{
            p.push(node);
            S.insert(node);
            for(int i=0;i<adj[node].size();++i){
                int child = adj[node][i];
                if(S.count(child))
                    return true;
                if(!visited[child]){
                    s.push(child);
                    visited[child]=1;
                }
            }
        }
    }
    return false;
}
bool graph::cyclesDG(){
    vector<int> visited(V,0);
    for(int i=0;i<V;i++)
        if(cyclesDGUtil(visited,i))
            return true;
    return false;
}
//void graph::printCyclesDGUtil(vector<)
/*void graph::printCyclesDG(){
}*/
int graph::cyclesUDGUtil(int x, vector<int>& v){
    stack<int> s,p;
    s.push(x);
    int c=0;
    while(!s.empty()){
        int node = s.top();
        if(!p.empty()&&p.top()==node){
            s.pop();
            p.pop();
        }
        else{
            for(int i=0;i<adj[node].size();++i){
                int child = adj[node][i];
                if(!v[child]){
                    v[child]=1;
                    s.push(child);
                }
                else if(!p.empty()&&child==p.top())
                    continue;
                else
                    c++;
            }
            p.push(node);
        }
    }
    return c;
}
int graph::cyclesUDG(){
    vector<int> v(V,0);
    int c=0;
    for(int i=0;i<V;++i){
        if(!v[i]){
            v[i]=1;
            c+=cyclesUDGUtil(i,v);
        }
    }
    return c;
}
int graph::islandsUDG(){
    int c=0;
    vector<int> v(V,0);
    for(int i=0;i<V;++i){
        if(!v[i]){
            c++;
            dfsUtil(i,v,0);
        }
    }
    return c;
}
void graph::rDFSUtil(int v, vector<int>& visit, vector<int>& parent){
    cout<<v<<" ";
    visit[v]=1;
    int children = 0;
    for(int i=0;i<adj[v].size();++i){
        int child = adj[v][i];
        if(!visit[child]){
            ++children;
            parent[child] = v;
            rDFSUtil(child,visit,parent);
        }
    }
}
void graph::rDFS(int v){
    vector<int> visit(V,0);
    if(v==-1)
        for(int i=0;i<V;++i);
            //if(!visit[i])
            //    rDFSUtil(i,visit);
   // else
       // rDFSUtil(v,visit);
}
bool graph::isBipartite_B(){
    vector<int> color(V,-1);
    queue<int> q; q.push(0); color[0]=0; int cur = 1;
    while(!q.empty()){
        int x=q.front();q.pop();
        cur = !color[x];
        int n = adj[x].size();
        for(int i=0;i<n;++i){
            int child = adj[x][i];
            int col = color[child];
            if(col==-1){
                color[child] = cur;
                q.push(child);
            }
            else if(col==!cur)
                return false;
        }
        cur = !cur;
    }
    return true;
}
bool graph::isBipartite_DUtil(int v,vector<int>& color, int cur){
    color[v] = cur; bool out = true;
    for(int i=0;i<adj[v].size();++i){
        int child = adj[v][i];
        if(color[child]==cur)
            return false;
        if(color[child]==-1)
            out = isBipartite_DUtil(child,color,!cur);
    }
    return out;
}
bool graph::isBipartite_D(){
    vector<int> color(V,-1);
    return isBipartite_DUtil(0,color,1);
}
