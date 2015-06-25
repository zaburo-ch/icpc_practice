#include <iostream>
#define MAX_N 50
using namespace std;

int N,M,A,B,C,T;
int mat[MAX_N][MAX_N];
int s1[MAX_N];
int s2[MAX_N];

void matxs(){
  memset(s2,0,sizeof(s2));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      s2[i] += mat[i][j]*s1[j];
    }
  }
  for(int i=0;i<N;i++){
    s1[i] = s2[i];
  }
}

void matxmat(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        mat[i][j]+=mat[i][k]*mat[k][j];
      }
    }
  }
}

void init(){
  memset(mat,0,sizeof(mat));
  /*for(int i=0;i<N;i++){
    if(i-1>=0){
      mat[i][i-1] = A;
    }
    mat[i][i] = B;
    if(i+1<N){
      mat[i][i+1] = C;
    }
  }
  */
  for(int i=0;i<N;i++)
    mat[i][i]=1;
}

int main(){
  while(1){
    cin >>N>>M>>A>>B>>C>>T;
    if(!N&&!M&&!A&&!B&&!C&&!T) break;
    for(int i=0;i<N;i++){
      cin>>s1[i];
    }
    init();
    while(1){
      if(T%2) matxs();
      T/=2;
      if(T==0) break;
      matxmat();
    }
    for(int i=0;i<N-1;i++){
      cout << s1[i] << " ";
    }
    cout << s1[N-1] << endl;
  }
}