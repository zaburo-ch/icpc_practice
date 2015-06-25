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
#include <complex>
using namespace std;

const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef pair<int,P> iP;

//char field[1000][1000];

int main(){
    while(1){
        int x,y;
        scanf("%d%d",&x,&y);
        if(!x)break;

        P start,goal;
        vector<P> pos[5];
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                char temp; cin >> temp;
                if(temp=='S'){
                    start = P(i,j);
                }else if(temp=='G'){
                    goal = P(i,j);
                }else if(temp!='.'){
                    int type = temp - '1';
                    pos[type].push_back(P(i,j));
                }
            }
        }

        int min_type, min_d = INF;
        for(int s_type=0;s_type<5;s_type++){
            int g_type = s_type!=0 ? s_type-1 : 4;
            int d[6][1000];
            for(int i=0;i<6;i++)fill(d[i], d[i]+1000, INF);
            //cout << s_type << " " << g_type << endl;

            priority_queue<iP, vector<iP>, greater<iP> > que;
            d[s_type][0] = 0;
            que.push( iP(0,P(s_type, 0)) );
            while(que.size()){
                iP p = que.top(); que.pop();
                int dist = p.first;
                int type = (p.second).first;
                int index = (p.second).second;
                //printf("dist=%d type=%d index=%d\n",dist,type,index);
                if(d[type][index] < dist) continue;
                if(type==5){
                    if(min_d>dist){
                        min_d = dist;
                        min_type = s_type;
                    }
                    break;
                }

                P from;
                if(dist==0){
                    from = start;
                }else{
                    from = pos[type][index];
                }

                if(type==g_type){
                    int dist_to = dist + abs(goal.first - from.first) + abs(goal.second - from.second);
                    if(d[5][0] > dist_to){
                        d[5][0] = dist_to;
                        que.push(iP(dist_to,P(5,0)));
                    }
                }else{
                    int t_next = type!=4 ? type+1 : 0;
                    for(int i=0;i<pos[t_next].size();i++){
                        int dist_to = dist + abs(pos[t_next][i].first - from.first) + abs(pos[t_next][i].second  - from.second);
                        if(d[t_next][i] > dist_to){
                            d[t_next][i] = dist_to;
                            que.push(iP(dist_to,P(t_next,i)));
                        }
                    }
                }
            }
        }
        if(min_d!=INF)cout << min_type+1 << " " << min_d << endl;
        else cout << "NA" << endl;
    }

    return 0;
}
