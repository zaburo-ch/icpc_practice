#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

bool notzero[10]; //i番目の文字は0になれない
int num[10]; //i番目の文字の値
bool used[10]; //iが使われているか
int co[10]; //i番目の係数
int m; //係数の数
int ans;

void dfs(int pos){
	if(pos==m){
		int sum = 0;
		for(int i=0;i<m;i++){
			sum += co[i] * num[i];
		}
		if(sum==0) ans++;
		return;
	}
	for(int i=0;i<10;i++){
		if(used[i] || (i==0&&notzero[pos])) continue;
		used[i] = true;
		num[pos] = i;
		dfs(pos+1);
		used[i] = false;
	}
}


int main(){

	int n;
	while(cin >> n,n){
		vector<string> inputs(n);
		string dict = "";
		for(int i=0;i<n;i++){
			cin >> inputs[i];
			for(int j=0;j<inputs[i].size();j++){
				if(dict.find(inputs[i][j])==-1) dict.push_back(inputs[i][j]);
			}
		}

		m = dict.size();
		fill(co,co+m,0);
		fill(notzero,notzero+m,false);
		int p;
		for(int i=0;i<n-1;i++){
			p = 1;
			for(int j=inputs[i].size()-1;j>=0;j--){
				co[dict.find(inputs[i][j])] += p;
				p *= 10;
			}
			if(inputs[i].size()!=1){
				notzero[dict.find(inputs[i][0])] = true;
			}
		}
		p = 1;
		for(int j=inputs[n-1].size()-1;j>=0;j--){
			co[dict.find(inputs[n-1][j])] -= p;
			p *= 10;
		}
		if(inputs[n-1].size()!=1){
			notzero[dict.find(inputs[n-1][0])] = true;
		}

		ans = 0;
		dfs(0);
		cout << ans << endl;
	}
	return 0;

}