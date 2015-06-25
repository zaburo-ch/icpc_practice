//union-find木
#define N 10000
int par[N];
int urank[N];
void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    urank[i] = 0;
  }
}
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}
void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y)return;

  if(urank[x]<urank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(urank[x]==urank[y])urank[x]++;
  }
}
bool same(int x,int y){
  return find(x)==find(y);
}
