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
const int INF = (int)((unsigned int)-1>>1) /2;


int main(){
    int N;
    scanf("%d", &N);

    int s_color;
    scanf("%d", &s_color);
    int s_len = 1;
    int now_len = 1;
    int now_color = s_color;
    bool exist_two_color = false;
    int len_max = 1;

    for(int i=1;i<N-1;i++){
        int c;
        scanf("%d", &c);
        if (c == now_color){
            now_len++;
            if (!exist_two_color){
                s_len++;
            }
        }else{
            if (!exist_two_color){
                exist_two_color = true;
            }
            len_max = max(len_max, now_len);
            now_len = 1;
            now_color = c;
        }
    }

    int f_color;
    scanf("%d", &f_color);
    if (f_color == now_color){
        now_len++;
        if (!exist_two_color){
            printf("-1\n");
            return 0;
        }
        len_max = max(len_max, now_len);
    }else{
        len_max = max(len_max, now_len);
        now_len = 1;
    }
    if (f_color == s_color){
        len_max = max(len_max, now_len+s_len);
    }

    printf("%d\n", (len_max+1)/2);
    return 0;
}