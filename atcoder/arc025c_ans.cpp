#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1) /2;


struct edge{int to,cost;};


int main(){
    int N, M, R, T;
    vector<edge> g[2500];
    int d[2500];
    int dR[2500];

    scanf("%d %d %d %d", &N, &M, &R, &T);
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        g[a-1].push_back((edge){b-1,c});
        g[b-1].push_back((edge){a-1,c});
    }

    long long int ans = 0;
    for(int a=0;a<N;a++){
        fill(d, d+N, INF);

        priority_queue<P, vector<P>, greater<P> > que;
        d[a] = 0;
        que.push(P(0, a));
        while(que.size()){
            P p = que.top(); que.pop();
            int dist = p.first;
            int pos = p.second;
            if(d[pos] < dist) continue;
            for(int i=0;i<g[pos].size();i++){
                int to = g[pos][i].to;
                int dist_to = dist + g[pos][i].cost;
                if(d[to] > dist_to){
                    d[to] = dist_to;
                    que.push(P(dist_to, to));
                }
            }
        }

        sort(d, d+N);
        for(int i=0;i<N;i++){
            dR[i] = d[i] * R;
        }
        for(int b=1;b<N;b++){
            int *ite_dR = lower_bound(dR+1, dR+N, d[b] * T);
            ans += distance(dR+1, ite_dR);
            if(ite_dR-(dR+b) > 0){
                ans--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}