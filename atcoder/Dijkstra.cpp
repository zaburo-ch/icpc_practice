const int MAX_N = 2500;
const int INF = (int)((unsigned int)-1>>1) /2;

struct edge{int to,cost};

int main(){
    int N = 100;

    vector<edge> g[MAX_N];
    int d[MAX_N];
    fill(d, d+N, INF);

    priority_queue<P, vector<P>, greater<P> > que;
    d[0] = 0;
    que.push(P(0, 0));
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
}