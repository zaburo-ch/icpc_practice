#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#define INF 10000000000
using namespace std;
typedef pair<int,int> P;
typedef pair<long long int,P> P2;

#define MAX_N 100000
#define MAX_L 100000
struct light{int left,right,cost;};

bool cmp( const light& left, const light& right ) {
    return left.right < right.right;
}

int main(){
    int N, L;
    light lights[MAX_N];
    scanf("%d %d", &N, &L);
    for(int i=0;i<N;i++){
        int l,r,c;
        scanf("%d %d %d", &l, &r, &c);
        lights[i] = (light){l,r,c};
    }

    long long int c[MAX_L+1];
    fill(c,c+L+1,INF);
    /*
    c[0] = 0;
    for(int i=0;i<L;i++){
        for(int j=0;j<N;j++){
            long long int next = c[i] + lights[j].cost;
            int to = lights[j].right;
            if(i >= lights[j].left && c[to] > next){
                c[to] = next;
            }
        }
    }
    */

    sort(lights,lights+N,cmp);
    priority_queue<P2, vector<P2> , greater<P2> > que;
    que.push(P2(0,P(0,-1))); //P2(cost,P(pos,i))
    while(que.size()){
        P2 p = que.top(); que.pop();
        long long int cost = p.first;
        int pos = p.second.first;
        int index = p.second.second;
        if(c[pos] < cost) continue;
        if(pos == L){
            break;
        }
        for(int i=index+1;i<N;i++){
            long long int next = cost + lights[i].cost;
            int to = lights[i].right;
            if(pos >= lights[i].left && c[to] > next){
                c[to] = next;
                que.push(P2(next, P(to, i)));
            }
        }
    }
    printf("%lld\n",c[L]);

    return 0;
}