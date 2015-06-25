#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
	while(1){
		string str;
		getline(cin,str);
		if(str==".") break;

		int i=0;
		int sum = 0;
		vector<int> inkakko;
		while(1){
			if(str[i]=='('){
				inkakko.push_back(1);
				sum++;
			}else if(str[i]==')'){
				if(inkakko.size()){
					if(inkakko[inkakko.size()-1]==1){
						inkakko.pop_back();
						sum--;
					}else{
						cout << "no" << endl;
						break;
					}
				}else{
					cout << "no" << endl;
					break;
				}
			}else if(str[i]=='['){
				inkakko.push_back(2);
				sum++;
			}else if(str[i]==']'){
				if(inkakko.size()){
					if(inkakko[inkakko.size()-1]==2){
						inkakko.pop_back();
						sum--;
					}else{
						cout << "no" << endl;
						break;
					}
				}else{
					cout << "no" << endl;
					break;
				}
			}else if(str[i]=='.'){
				if(inkakko.size()){
					cout << "no" << endl;
				}else{
					cout << "yes" << endl;
				}
				break;
			}
			i++;
		}
	}
}