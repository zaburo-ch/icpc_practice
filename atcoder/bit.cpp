


const int MAX_N = 1 << 17;

int bit[MAX_N+1],n;

void init(int n_){
  n = 1;
  while(n < n_) n*=2;
  for(int i=1;i<=n;i++) bit[i] = 0;
}

int sum(int i){
  int s = 0;
  while(i>0){
    s += bit[i];
    i -= i&-i;
  }
  return s;
}

void add(int i,int x){
  while(i<=n){
    bit[i] += x;
    i += i&-i;
  }
}
