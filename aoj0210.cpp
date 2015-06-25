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
const int INF = 1<<29;

typedef complex<int> P;
const P turn[] = {P(0,1),P(1,0),P(0,-1),P(-1,0)};
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

struct person{
    P pos,dire;
    bool not_move;
};

int pos2i[30][30];
char field[30][30];
int w,h;

int pos_rank(P& dire){
    if(dire==turn[3]) return 0;
    else if(dire==turn[0]) return 1;
    else if(dire==turn[1]) return 2;
    else return 3;
}

int main(){
    while(1){
        scanf("%d%d",&w,&h);
        if(w==0)break;

        vector<person> people;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> field[i][j];
                if(field[i][j]=='S'){
                    people.push_back((person){P(j,i),turn[0],false});
                }else if(field[i][j]=='E'){
                    people.push_back((person){P(j,i),turn[1],false});
                }else if(field[i][j]=='N'){
                    people.push_back((person){P(j,i),turn[2],false});
                }else if(field[i][j]=='W'){
                    people.push_back((person){P(j,i),turn[3],false});
                }
            }
        }

        int t = 0;
        while(people.size()&&t<=180){
            t++;

            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    pos2i[i][j] = -1;
                }
            }
            for(int i=0;i<people.size();i++){
                pos2i[imag(people[i].pos)][real(people[i].pos)] = i;
            }

            for(int i=0;i<people.size();i++){
                person& p = people[i];
                for(int j=0;j<4;j++){
                    P next_pos = p.pos + p.dire * turn[j];
                    int nextx = real(next_pos), nexty = imag(next_pos);
                    if(0<=nextx && nextx<w && 0<=nexty && nexty<h){
                        if(pos2i[nexty][nextx]==-1 && field[nexty][nextx]!='#'){
                            p.dire *= turn[j];
                            break;
                        }
                    }
                }
            }

            for(int i=0;i<people.size();i++)people[i].not_move = false;
            for(int i=0;i<people.size();i++){
                if(people[i].not_move) continue;
                P pi_next_pos = people[i].pos + people[i].dire;
                int nextx = real(pi_next_pos), nexty = imag(pi_next_pos);
                if(field[nexty][nextx]=='#' || pos2i[nexty][nextx]>=0) continue;

                for(int j=i+1;j<people.size();j++){
                    if(people[i].not_move) continue;
                    P pj_next_pos = people[j].pos + people[j].dire;
                    if(pi_next_pos == pj_next_pos){
                        int rank_i = pos_rank(people[i].dire),rank_j = pos_rank(people[j].dire);
                        if(rank_i < rank_j){
                            people[j].not_move = true;
                        }else{
                            people[i].not_move = true;
                            break;
                        }
                    }
                }
                if(!people[i].not_move){
                    people[i].pos = pi_next_pos;
                    if(field[imag(pi_next_pos)][real(pi_next_pos)]=='X'){
                        people.erase(people.begin()+i); i--;
                    }
                }
            }
        }
        if(t<=180) printf("%d\n",t);
        else printf("NA\n");

        //break;
    }

    return 0;
}
