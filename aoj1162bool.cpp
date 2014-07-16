#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define N 30
#define INF 100000

struct road{int to,cost,lim;};
struct situ{int v,now,from;double d;};
bool operator < (const situ &a,const situ &b){
	return a.d > b.d;
}

int main(){
	while(1){
		int n,m,s,g;
		vector<road> roads[N];
		cin >> n >> m;
		if(!n&&!m) break;
		cin >> s >> g;
		s--;g--;

		for(int i=0;i<m;i++){
			int x,y,d,c;
			scanf("%d%d%d%d",&x,&y,&d,&c);
			x--;y--;
			roads[x].push_back((road){y,d,c});
			roads[y].push_back((road){x,d,c});
		}

		priority_queue<situ> que;
		for(int i=0;i<roads[s].size();i++){
			int to = roads[s][i].to;
			int d = roads[s][i].cost;
			que.push((situ){1,to,s,(double)d});
		}
		bool used[N][N][31];
		memset(used,0,sizeof(used));

		bool isClear = false;
		while(que.size()){
			situ st = que.top(); que.pop();
			if(used[st.now][st.from][st.v]) continue;
			used[st.now][st.from][st.v] = true;
			if(st.now==g&&st.v==1){
				printf("%.5f\n",st.d);
				isClear = true;
				break;
			}
			for(int i=0;i<roads[st.now].size();i++){
				int to = roads[st.now][i].to;
				int d = roads[st.now][i].cost;
				if(to == st.from) continue;
				for(int j=-1;j<=1;j++){
					if(st.v+j<=roads[st.now][i].lim&&st.v+j>0){
						//if(!used[to][st.now][st.v+j])
							que.push((situ){st.v+j,to,st.now,st.d+(double)d/(st.v+j)});
					}
				}
			}
		}
		if(!isClear) cout << "unreachable" << endl;


	}
	return 0;

}