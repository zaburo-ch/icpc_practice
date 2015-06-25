#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

/************ LCA : segtree ************/
class segtree{
private:
    const static int int_max = ~(1<<31);
    int n,dat[2*(1<<17)-1];
    int *v;
public:
    void init(int *value, int n_){
        v = value;
        n = 1;
        while(n < n_) n*=2;
        for(int i=0;i<n_;i++){
            dat[i+n-1] = i;
        }
        for(int i=n_+n-1;i<2*n-1;i++){
            dat[i] = -1;
        }
        for(int k=n-2;k>=0;k--){
            if(dat[k*2+2]==-1 || v[dat[k*2+1]]<=v[dat[k*2+2]]){
                dat[k] = dat[k*2+1];
            }else{
                dat[k] = dat[k*2+2];
            }
        }
    }
    //k:index (0-indexed), a:value
    void update(int k, int a){
        v[k] = a;
        k += n-1;
        while(k>0){
            k = (k-1)/2;
            if(dat[k*2+2]==-1 || v[dat[k*2+1]]<=v[dat[k*2+2]]){
                dat[k] = dat[k*2+1];
            }else{
                dat[k] = dat[k*2+2];
            }
        }
    }
    //query(a, b) =>  minimum in [a,b]
    int query(int a,int b){
        return _query(a,b,0,0,n-1);
    }
    //node k is minimum in [l,r]
    int _query(int a, int b, int k, int l, int r){
        if(r<a||b<l){
            return -1;
        }
        if(a<=l&&r<=b){
            return dat[k];
        }else{
            int vl = _query(a,b,k*2+1,l,(l+r)/2);
            int vr = _query(a,b,k*2+2,(l+r)/2+1,r);
            if(vr==-1){
                return vl;
            }else if(vl==-1){
                return vr;
            }else{
                if (v[vl]>v[vr]){
                    return vr;
                }else{
                    return vl;
                }
            }
        }
    }
};

const int MAX_V = 8;
const int MAX_LOG_V = 3;
vector<int> G[MAX_V];
int root;
segtree s;

int vs[MAX_V * 2 -1];
int depth[MAX_V * 2 -1];
int id[MAX_V];

void dfs(int v, int p, int d, int &k){
    id[v] = k;
    vs[k] = v;
    depth[k++] = d;
    for(int i=0;i<G[v].size();i++){
        if(G[v][i] != p){
            dfs(G[v][i], v, d+1, k);
            vs[k] = v;
            depth[k++] = d;
        }
    }
}

void init(int V){
    int k=0;
    dfs(root, -1, 0, k);
    s.init(depth, 2*V-1);
}

int lca(int u, int v){
    return vs[s.query(min(id[u], id[v]), max(id[u], id[v])+1)];
}


int main(){
    int a[] = {0,0,1,1,2,4,4};
    int b[] = {1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    root = 0;
    init(8);

    cout << lca(3,6) << endl;  // 1
    cout << lca(7,5) << endl;  // 0
    cout << lca(4,7) << endl;  // 4
    /*
    int a[] = {5,3,7,9,6,4,1,2};
    s.init(a,8);
    cout << s.query(0,3) << endl;  // index:1, value:3
    cout << s.query(1,6) << endl;  // index:6, value:1
    cout << s.query(1,5) << endl;  // index:1, value:3
    cout << s.query(2,5) << endl;  // index:5, value:4
    */
    return 0;
}