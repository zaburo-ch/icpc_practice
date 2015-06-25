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


#define MAX_N 100000


struct light{int left,right,cost;};
bool cmp( const light& left, const light& right ) {
    return left.left == right.left ? left.right < right.right : left.left < right.left;
}


class segtree{
private:
    static const long long int int_max = (long long int)((unsigned long long int)(long long int)-1>>1);
    int n;
    long long int dat[2*(1<<17)-1];
public:
    segtree(int n_){
        n = 1;
        while(n < n_) n*=2;
        for(int i=0;i<2*n-1;i++) dat[i] = int_max/2;
    }

    void update(int k, long long int a){
        k += n-1;
        dat[k] = a;
        while(k>0){
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1],dat[k*2+2]);
        }
    }

    //query(a, b) =>  minimum in [a,b]
    long long int query(int a,int b){
        return _query(a,b,0,0,n-1);
    }

    //node k is minimum in [l,r]
    long long int _query(int a, int b, int k, int l, int r){
        if(r<a||b<l){
            return int_max/2;
        }
        if(a<=l&&r<=b){
            return dat[k];
        }else{
            long long int vl = _query(a,b,k*2+1,l,(l+r)/2);
            long long int vr = _query(a,b,k*2+2,(l+r)/2+1,r);
            return min(vl,vr);
        }
    }

    long long int get(int k){
        return dat[k+n-1];
    }
};


int main(){
    int N, L;
    light lights[MAX_N];
    scanf("%d %d", &N, &L);
    for(int i=0;i<N;i++){
        int l,r,c;
        scanf("%d %d %d", &l, &r, &c);
        lights[i] = (light){l,r,c};
    }

    sort(lights,lights+N,cmp);

    segtree cost(L+1);
    cost.update(0,0);
    for(int i=0;i<N;i++){
        int l = lights[i].left, r = lights[i].right, c = lights[i].cost;
        cost.update(r, min(cost.get(r), cost.query(l,r-1)+c));
    }
    printf("%lld\n",cost.get(L));

    return 0;
}