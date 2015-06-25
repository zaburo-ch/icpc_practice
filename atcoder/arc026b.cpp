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

int main(){
  long long int N;
  scanf("%lld",&N);

  if(N==1){
    printf("Deficient\n");
    return 0;
  }
  long long int divsum = 1;
  for(long long int i=2;i*i<=N;i++){
    if(N%i==0){
      if(i*i==N){
        divsum += i;
      }else{
        divsum += i+(N/i);
      }
    }
  }
  if(divsum==N){
    printf("Perfect\n");
  }else if(divsum<N){
    printf("Deficient\n");
  }else{
    printf("Abundant\n");
  }
  return 0;
}