#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define N 35

typedef pair<long long int,int> P;
long long int INF = (unsigned long long int)-1/2;

long long int _abs(long long int a){
  if(a>0) return a;
  else return -a;
}

int main(){

  while(1){
    int n;
    long long int num[N];
    cin >> n; if(!n)break;
    for(int i=0;i<n;i++){
      scanf("%lld",&num[i]);
    }

    //前半の全列挙
    int n2 = n/2;
    int size = 1<<n2;
    P sumf[1<<(N/2)];
    for(int i=0;i<size;i++){
      long long int sum = 0;
      int cnt = 0;
      for(int j=0;j<n2;j++){
        if(i>>j&1){
          sum += num[j];
          cnt++;
        }
      }
      sumf[i] = P(sum,cnt);
    }
    sort(sumf,sumf+size);

    //後半を使わない場合の求解と不要部分の削除
    P ans = P(INF,0);
    for(int i=1;i<size;i++){
      P temp = P(_abs(sumf[i].first),sumf[i].second);
      if(ans>temp){
        ans = temp;
      }
      if(sumf[i].first==sumf[i-1].first){
        sumf[i].second = sumf[i-1].second; //sortしてあるので必ずi-1のsecond以下なので不要
      }
    }
    size = unique(sumf,sumf+size) - sumf;

    //後半の全列挙と求解
    for(int i=1;i< 1<<(n-n2);i++){
      long long int sumb = 0;
      int cnt = 0;
      for(int j=0;j<n-n2;j++){
        if(i>>j&1){
          sumb += num[n2+j];
          cnt++;
        }
      }
      int pos = lower_bound(sumf,sumf+size,P(-sumb,0)) - sumf;
      for(int j=-1;j<=1;j++){
        if(pos+j>=0&&pos+j<size){
          P temp = P(_abs(sumf[pos+j].first+sumb),sumf[pos+j].second+cnt);
          if(ans>temp){
            ans = temp;
          }
        }
      }
    }
    printf("%lld %d\n",ans.first,ans.second);
  }
}