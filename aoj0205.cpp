#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
#include <complex>
using namespace std;
typedef pair<int,int> P;
const int INF = 1<<29;


int main(){
    while(1){
        int hand[5];
        int gcp[4] = {};
        scanf("%d",&hand[0]);
        if(hand[0]==0)break;

        gcp[hand[0]]++;
        int hand_num = 1;
        for(int i=1;i<5;i++){
            scanf("%d",&hand[i]);
            gcp[hand[i]]++;
            if(gcp[hand[i]]==1){
                hand_num++;
            }
        }
        if(hand_num==2){
            int win;
            if(gcp[1]>0 && gcp[2]>0){
                win = 1;
            }else if(gcp[2]>0 && gcp[3]>0){
                win = 2;
            }else{
                win = 3;
            }
            for(int i=0;i<5;i++){
                if(hand[i]==win){
                    printf("1\n");
                }else{
                    printf("2\n");
                }
            }
        }else{
            for(int i=0;i<5;i++)printf("3\n");
        }
    }

    return 0;
}
