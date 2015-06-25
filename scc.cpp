vector<vec> g;
vector<vec> rg;
vector<bool> visited;
vector<int> vs;
vector<int> cmp;

void dfs(int v) {
    visited[v] = true;
    for(int i=0;i<g[v].size();i++){
        if(!visited[g[v][i]]) dfs(g[v][i]);
    }
    vs.push_back(v); // 帰りがけにvを記録。グラフの末端に近いものから並ぶ
}

void rdfs(int v, int k) {
    visited[v] = true;
    cmp[v] = k;

    for(int i=0;i<rg[v].size();i++){
        if(!visited[rg[v][i]]) rdfs(rg[v][i], k);
    }
}

int scc(int n) { // 強連結成分分解
  vs.clear();

  visited.assign(n, false);
  for(int i=0;i<n;i++){
    if(!visited[i]) dfs(i);
  }

  cmp.assign(n, -1);
  visited.assign(n, false);
  int k=0;
  for(int i=vs.size()-1;i>=0;i--){
    if(!visited[vs[i]]) rdfs(vs[i], k++);
  }
  return k;
}