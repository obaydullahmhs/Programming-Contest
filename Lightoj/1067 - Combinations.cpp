#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs;

template<typename Type>
class Modular{
private:
    const Type mod = Type(1000003);
    Type value;
    template<typename U>
    Type normalize(const U& x){
        Type v;
        if(-mod<=x && x<mod) v = static_cast<Type>(x);
        else v = static_cast<Type>(x%mod);
        if(v<0) v+=mod;
        return v;
    }
    template <typename T> T bigmod(T p,T e) {
        T ret = 1;
        for(; e > 0; e >>= 1) {
            if(e & 1) ret = (ret * p) % mod;
            p = (p * p) % mod;
        }
        return (T)ret;
    }
public:
    Modular(): value(0){}
    template<typename U>
    Modular(const U& x): value(normalize(x)){}

    Type get(){ return value; }
    template<typename T> T Bigmod(T x, T y){ return (T)bigmod(x, y);}

    void operator = (const Modular<Type>& x){this->value = x.value;}
    template<typename U> void operator = (const U& x){ value = normalize(x);}

    template<typename U> friend istream& operator>>(istream& is, Modular<U>& input){ U x; is>>x; input = x; return is;}
    template<typename U> friend ostream& operator<<(ostream& os, Modular<U>& output){ os<<output(); return os;}

    Modular& operator+=(const Modular<Type>& x){if((value+=x.value)>=mod) value-=mod; return *this;}

    Modular& operator-=(const Modular<Type>& x){if((value-=x.value)<0) value+=mod; return *this;}

    Modular& operator*=(const Modular<Type>& x){ value = normalize(value*x.value); return *this;}

    Modular& operator/=(const Modular<Type>& x){ *this*=Modular<Type>(Bigmod(x.value,static_cast<Type>(mod-2))); return *this;}
    Modular operator++() { return *this += 1; }
    Modular operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }
    const Type& operator()() const {return value; }

    template<typename T, typename U> friend Modular<T> operator += ( Modular<T>& x, U y){ return x+=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator -= ( Modular<T>& x, U y){ return x-=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator *= ( Modular<T>& x, U y){ return x*=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator /= ( Modular<T>& x, U y){ return x/=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator + ( Modular<T> x, U y){ return x+=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator + (U y,Modular<T> x){ return x+=Modular<T>(y);}
    template<typename T> friend Modular<T> operator + (Modular y, Modular<T> x){ return x+=y;}
    template<typename T, typename U> friend Modular<T> operator - ( Modular<T> x, U y){ return x-=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator - ( U y, Modular<T> x){ return Modular<T>(y)-=x;}
    template<typename T> friend Modular<T> operator - (Modular x, Modular<T> y){ return x-=y;}
    template<typename T, typename U> friend Modular<T> operator * ( Modular<T> x, U y){ return x*=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator * ( U y, Modular<T> x){ return x*=Modular<T>(y);}
    template<typename T> friend Modular<T> operator * (Modular<T> x, Modular<T> y){ return x*=y;}
    template<typename T, typename U> friend Modular<T> operator / ( Modular<T> x, U y){ return x/=Modular<T>(y);}
    template<typename T, typename U> friend Modular<T> operator / ( U y, Modular<T> x){ return Modular<T>(y)/=x;}
    template<typename T> friend Modular<T> operator / (Modular<T> x, Modular<T> y){ return x/=y;}
    template <typename U> friend const Modular<U>& abs(const Modular<U>& v) { return v; }
    template <typename T> friend Modular<T> power(Modular<T> x,Modular<T> v) { T r = Modular<T>().Bigmod(x(), v()); return Modular<T>(r); }
};
using mint  = Modular<ll>;
const int N = 1e6 + 1;

mint fact[N], invfact[N];
void pre(){
    fact[0] = 1;
    for(ll i = 1; i < N; i++){
        fact[i] = fact[i - 1] * i;
    }
    invfact[N - 1] = 1 / fact[N - 1];

    for(ll i = N - 2; i >= 0; i--){
        invfact[i] = invfact[i + 1] * (i + 1);
    }
}

mint nCr(int n, int r){
    return fact[n] * invfact[r] * invfact[n - r];
}

void solve(){
    int n, k; cin >> n >> k;
    mint ans = nCr(n, k);
    cout << "Case " << ++cs << ": " << ans << "\n";
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    pre();
    int tc = 1; cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}
/**

**/

