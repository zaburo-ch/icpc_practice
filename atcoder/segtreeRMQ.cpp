//区間の最小値を持つsegtree
class segtree{
private:
    const static int int_max = ~(1<<31);
    int n,dat[2*(1<<17)-1];
public:
    void init(int n_){
        n = 1;
        while(n < n_) n*=2;
        for(int i=0;i<2*n-1;i++) dat[i] = int_max/2;
    }
    void init(int value[], int n_){
        n = 1;
        while(n < n_) n*=2;
        for(int i=0;i<n_;i++){
            dat[i+n-1] = value[i];
        }
        for(int i=n_+n-1;i<2*n-1;i++){
            dat[i] = int_max/2;
        }
        for(int k=n-2;k>=0;k--){
            dat[k] = min(dat[k*2+1],dat[k*2+2]);
        }
    }
    //k:index (0-indexed), a:value
    void update(int k, int a){
        k += n-1;
        dat[k] = a;
        while(k>0){
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1],dat[k*2+2]);
        }
    }
    //query(a, b) =>  minimum in [a,b]
    int query(int a,int b){
        return _query(a,b,0,0,n-1);
    }
    //node k is minimum in [l,r]
    int _query(int a, int b, int k, int l, int r){
        if(r<a||b<l){
            return int_max/2;
        }
        if(a<=l&&r<=b){
            return dat[k];
        }else{
            int vl = _query(a,b,k*2+1,l,(l+r)/2);
            int vr = _query(a,b,k*2+2,(l+r)/2+1,r);
            return min(vl,vr);
        }
    }
    //k:index (0-indexed)
    int get(int k){
        return dat[k+n-1];
    }
};


//区間の最小値のインデックスを持つsegtree
class segtree{
private:
    const static int int_max = ~(1<<31);
    int n,dat[2*(1<<17)-1];
    int *v;
public:
    void init(int *value, int n_){
        v = value;
        n = 1;
        while(n < n_) n*=2;
        for(int i=0;i<n_;i++){
            dat[i+n-1] = i;
        }
        for(int i=n_+n-1;i<2*n-1;i++){
            dat[i] = -1;
        }
        for(int k=n-2;k>=0;k--){
            if(dat[k*2+2]==-1 || v[dat[k*2+1]]<=v[dat[k*2+2]]){
                dat[k] = dat[k*2+1];
            }else{
                dat[k] = dat[k*2+2];
            }
        }
    }
    //k:index (0-indexed), a:value
    void update(int k, int a){
        v[k] = a;
        k += n-1;
        while(k>0){
            k = (k-1)/2;
            if(dat[k*2+2]==-1 || v[dat[k*2+1]]<=v[dat[k*2+2]]){
                dat[k] = dat[k*2+1];
            }else{
                dat[k] = dat[k*2+2];
            }
        }
    }
    //query(a, b) =>  minimum in [a,b]
    int query(int a,int b){
        return _query(a,b,0,0,n-1);
    }
    //node k is minimum in [l,r]
    int _query(int a, int b, int k, int l, int r){
        if(r<a||b<l){
            return -1;
        }
        if(a<=l&&r<=b){
            return dat[k];
        }else{
            int vl = _query(a,b,k*2+1,l,(l+r)/2);
            int vr = _query(a,b,k*2+2,(l+r)/2+1,r);
            if(vr==-1){
                return vl;
            }else if(vl==-1){
                return vr;
            }else{
                if (v[vl]>v[vr]){
                    return vr;
                }else{
                    return vl;
                }
            }
        }
    }
};




// long long int version!
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








const int MAX_N = 1 << 17;

int n,dat[2*MAX_N-1];

void init(int n_){
  n = 1;
  while(n < n_) n*=2;
  for(int i=0;i<2*n-1;i++) dat[i] = INT_MAX;
}

void update(int k, int a){
  k += n-1;
  dat[k] = a;
  while(k>0){
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1],dat[k*2+2]);
  }
}

int query(int a, int b, int k, int l, int r){
  if(r<=a||b<=1) return INT_MAX;
  if(a<=1&&r<=b){
    return dat[k];
  }else{
    int vl = query(a,b,k*2+1,l,(l+r)/2);
    int vr = query(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
  }
}