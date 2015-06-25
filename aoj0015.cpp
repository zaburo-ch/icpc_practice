#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    string str1,str2;
    cin >> str1 >> str2;
    if(str1.size()>str2.size()){
      string temp = str1;
      str1 = str2;
      str2 = temp;
    }

    int len1 = str1.size(),len2 = str2.size();
    int kuriagari = 0;
    for(int j=1;len2-j>=0;j++){
      if(len1-j>=0){
        int sum = (str2[len2-j]-'0') + (str1[len1-j]-'0') + kuriagari;
        if(sum>=10){
          sum -=10;
          kuriagari = 1;
        }else{
          kuriagari = 0;
        }
        str2[len2-j] = sum+'0';
      }else{
        if(kuriagari){
          int sum = (str2[len2-j]-'0') + kuriagari;
          if(sum>=10){
            sum -=10;
            kuriagari = 1;
          }else{
            break;
          }
          str2[len2-j] = sum+'0';
        }else{
          break;
        }
      }
    }
    if(kuriagari){
      str2 = "1" + str2;
    }
    if(str2.size()>80){
      cout << "overflow" << endl;
    }else{
      cout << str2 << endl;
    }
  }
}