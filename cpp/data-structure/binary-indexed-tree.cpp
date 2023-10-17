template<typename T>
struct BIT{//1_Indexed
  int n;
  vector<T> bit;
  BIT(int n_):n(n_+1),bit(n,0){}

  T sum(int a){
    T ret = 0;
    for(int i = a; i > 0; i -= i & -i) ret += bit[i];
    return ret;
  }

  void add(int a,T w){
    for(int i = a; i <= n; i += i & -i)bit[i] += w;
  }

  T query(int r,int l){
    return sum(l-1)-sum(r-1);
  }

};
