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

typedef complex<double> P;
const int INF = 1<<29;
const double EPS = 1e-8;

double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}

double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}


struct ufo{
    P pos,v;
    int xs,ys,vs,r,id;
};

double dist(const ufo& a, int t){
    return sqrt(a.xs*a.xs+a.ys*a.ys) - a.vs * t;
}


int main(){
    while(1){
        int R,N;
        scanf("%d %d",&R,&N);
        if(N==0)break;

        vector<ufo> enemys(N);
        for(int i=0;i<N;i++){
            int x,y,r,vs;
            scanf("%d %d %d %d",&x,&y,&r,&vs);
            P pos = P(x,y);
            P v = -(double)vs * pos / abs(pos);
            enemys[i] = (ufo){pos,v,x,y,vs,r,i};
        }

        int ans = 0, t = 1;
        while(enemys.size()){
            double min_d = 1500;
            int min_i = -1;
            for(int i=0;i<enemys.size();i++){
                enemys[i].pos += enemys[i].v;
                double d = dist(enemys[i],t);
                //printf("%d d = %lf\n",enemys[i].id,d);
                if(d <= R+EPS){
                    enemys.erase(enemys.begin()+i);
                    i--;
                    ans++;
                    continue;
                }
                if(min_d>d){
                    min_d = d;
                    min_i = i;
                }
            }
            if(enemys.size()==0) break;

            ufo min_e = enemys[min_i];
            double min_abs = abs(min_e.pos);
            for(int i=0;i<enemys.size();i++){
                double d = abs(cross(min_e.pos, enemys[i].pos)) / min_abs;
                if(d <= enemys[i].r+EPS){
                    P R_vec = (double)R * min_e.pos / min_abs;
                    P A = enemys[i].pos - R_vec;
                    if (dot(R_vec, A) > 0 || abs(A) < enemys[i].r){
                        enemys.erase(enemys.begin()+i);
                        i--;
                    }
                }
            }
            t++;
        }
        cout << ans << endl;
    }

    return 0;
}
