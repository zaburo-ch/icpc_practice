#include <iostream>
#define M 10000000
using namespace std;
int n,i,j;
bool prime[M];
void sieve(){
	for(i=0;i<M;i++){
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for(i=2;i<M;i++){
		if(prime[i]){
			for(j=2*i;j<M;j+=i) prime[j] = false;
		}
	}
}
int main(){
	sieve();
	while(cin >> n){
		if(!n) break;
		int ans = 0;
		for(i=1;i<=n;i++){
			if(prime[i+n]) ans++;
		}
		cout << ans <<endl;
	}
	return 0;
}
