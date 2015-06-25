#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <utility>
#include <set>
using namespace std;

char block[3][2][2][2]; //3個 2段 2*2
int H,N;
int ans = 0;

int rewrite(char t[16][2][2]){
/*
    cout << "in" << endl;
    for(int i=0;i<16;i++){
        for(int l=0;l<2;l++){
            for(int m=0;m<2;m++){
                cout << t[i][l][m];
            }
            cout << endl;
        }
    }*/
    bool can_down;
    for(int i=13;i>=0;i--){
        can_down = true;
        for(int l=0;l<2;l++){
            for(int m=0;m<2;m++){
                if(t[i][l][m]=='#'&&t[14][l][m]=='#'){
                    can_down = false;
                    break;
                }
                if(i!=13){
                    if(t[i+1][l][m]=='#'&&t[15][l][m]=='#'){
                        can_down = false;
                        break;
                    }
                }
            }
            if(!can_down)break;
        }
        if(!can_down){
            for(int l=0;l<2;l++){
                for(int m=0;m<2;m++){
                    if(t[14][l][m]=='#'){
                        t[i+1][l][m] = '#';
                        t[14][l][m] = '.';
                    }
                    if(t[15][l][m]=='#'){
                        t[i+2][l][m] = '#';
                        t[15][l][m] = '.';
                    }
                }
            }
            break;
        }
    }
    if(can_down){
        if(t[14][0][0]=='.'&&t[14][0][1]=='.'&&t[14][1][0]=='.'&&t[14][1][1]=='.'){
            for(int l=0;l<2;l++){
                for(int m=0;m<2;m++){
                    if(t[15][l][m]=='#'){
                        t[0][l][m] = '#';
                        t[15][l][m]='.';
                    }
                }
            }
        }else{
            for(int l=0;l<2;l++){
                for(int m=0;m<2;m++){
                    if(t[14][l][m]=='#'){
                        t[0][l][m] = '#';
                        t[14][l][m]='.';
                    }
                    if(t[15][l][m]=='#'){
                        t[1][l][m] = '#';
                        t[15][l][m]='.';
                    }
                }
            }
        }
    }
    /*
    cout << "mid" << endl;
    for(int i=0;i<16;i++){
        for(int l=0;l<2;l++){
            for(int m=0;m<2;m++){
                cout << t[i][l][m];
            }
            cout << endl;
        }
    }*/

    int ret = 0;
    for(int i=0;i<14;i++){
        if(t[i][0][0]=='#'&&t[i][0][1]=='#'&&t[i][1][0]=='#'&&t[i][1][1]=='#'){
            ret++;
            for(int j=i;j<14;j++){
                t[j][0][0] = t[j+1][0][0]; t[j][0][1] = t[j+1][0][1];
                t[j][1][0] = t[j+1][1][0]; t[j][1][1] = t[j+1][1][1];
            }
            i--;
        }
    }
/*
    cout << "out" << endl;
    for(int i=0;i<16;i++){
        for(int l=0;l<2;l++){
            for(int m=0;m<2;m++){
                cout << t[i][l][m];
            }
            cout << endl;
        }
    }
    */
    return ret;
}

void dfs(int b_i, int point, char t[16][2][2]){
    if(b_i == N){
        ans = max(ans, point);
        return;
    }
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            bool can_move = true;
            for(int k=0;k<2;k++){
                if (block[b_i][k][0][0]=='#' && !(0<=0+i&&0+i<=1 && 0<=0+j&&0+j<=1)){
                    can_move = false;
                    break;
                }
                if (block[b_i][k][0][1]=='#' && !(0<=0+i&&0+i<=1 && 0<=1+j&&1+j<=1)){
                    can_move = false;
                    break;
                }
                if (block[b_i][k][1][0]=='#' && !(0<=1+i&&1+i<=1 && 0<=0+j&&0+j<=1)){
                    can_move = false;
                    break;
                }
                if (block[b_i][k][1][1]=='#' && !(0<=1+i&&1+i<=1 && 0<=1+j&&1+j<=1)){
                    can_move = false;
                    break;
                }
            }
            if(can_move){
                //cout << i << " " << j << endl;
                char t_copy[16][2][2];
                for(int h=0;h<16;h++){
                    t_copy[h][0][0] = t[h][0][0]; t_copy[h][0][1] = t[h][0][1];
                    t_copy[h][1][0] = t[h][1][0]; t_copy[h][1][1] = t[h][1][1];
                }
                for(int k=0;k<2;k++){
                    for(int l=0;l<2;l++){
                        for(int m=0;m<2;m++){
                            t_copy[14+k][l][m] = '.';
                        }
                    }
                }
                for(int k=0;k<2;k++){
                    for(int l=0;l<2;l++){
                        for(int m=0;m<2;m++){
                            if(0<=l+i&&l+i<=1 && 0<=m+j&&m+j<=1){
                                t_copy[14+k][l+i][m+j] = block[b_i][k][l][m];
                            }
                        }
                    }
                }
                int p = rewrite(t_copy);
                dfs(b_i+1, point+p, t_copy);
            }
        }
    }
}

int main(){
    while(1){
        scanf("%d%d",&H,&N);
        if(!H)break;

        char tower[16][2][2];
        for(int i=0;i<H;i++){
            char c0,c1,c2,c3;
            cin >> c0 >> c1 >> c2 >> c3;
            tower[i][0][0] = c0; tower[i][0][1] = c1;
            tower[i][1][0] = c2; tower[i][1][1] = c3;
        }
        for(int i=H;i<16;i++){
            tower[i][0][0] = '.';
            tower[i][1][0] = '.';
            tower[i][0][1] = '.';
            tower[i][1][1] = '.';
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<2;j++){
                char c0,c1,c2,c3;
                cin >> c0 >> c1 >> c2 >> c3;
                block[i][j][0][0] = c0; block[i][j][0][1] = c1;
                block[i][j][1][0] = c2; block[i][j][1][1] = c3;
            }
        }

        ans = 0;

        dfs(0,0,tower);
        cout << ans << endl;

    }
}