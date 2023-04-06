#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:    
    vector<int> rank,par,siz;
    

    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        siz.resize(n+1,1);
        for(int i=0; i<=n; i++){
            par[i] = i;
        }
    }

    int findParent(int node){
        if(node == par[node]){
            return node;
        }
        return par[node] = findParent(par[node]);
    }

    void unionByRank(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]){
            par[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            par[ult_v] = ult_u;
        }
        else{
            par[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if(ult_u == ult_v) return;

        if(siz[ult_u] < siz[ult_v]){
            par[ult_u] = ult_v;
            siz[ult_v] += siz[ult_u];
        }
        else{
            par[ult_v] = ult_u;
            siz[ult_u] += siz[ult_v];
        }
    }
};

int main(){

// #ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// #endif

    DisjointSet dis(7);

    dis.unionBySize(1,2);
    dis.unionBySize(2,3);
    dis.unionBySize(4,5);
    dis.unionBySize(6,7);
    dis.unionBySize(5,6);
    if(dis.findParent(3) == dis.findParent(7)){
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";

    dis.unionBySize(3,7);

    if(dis.findParent(3) == dis.findParent(7)){
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";
    return 0;
}