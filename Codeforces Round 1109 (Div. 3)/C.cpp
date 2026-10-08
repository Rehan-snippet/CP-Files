#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop2(i,n) for(ll i=1;i<=n;i++)
#define input(a) for(auto &x:a) cin>>x
#define output(a) for(auto x:a) cout<<x<<" ";cout<<endl
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846LL
const ll MOD = 1e9+7;
// memset(a, -1, sizeof(a));

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b; 
}

int main() {
    fastio;
    test{
        ll n, x, y;
        cin>>n>>x>>y;
        x= gcd(n,x);
        y= gcd(n,y);
        // if(x>y) swap(x,y);
        // ll a,b,c=LONG_LONG_MAX,d=LONG_LONG_MAX;
        // if(n%x==0) a=x;
        // else a=n%x;
        // if(n%y==0) b=y;
        // else b=n%y;
        // if(a%y!=0) c=a%y;
        // if(b%x!=0) d=b%x;
        ll e=gcd(x,y);
        //cout<<e<<" ";
        vl v(n);
        input(v);
        bool f=0;
        loop(i,n){
            ll dif= abs(v[i]-(i+1));
            if(dif%e!=0){
                f=1; 
                break;
            }
        }
        if(f) no;
        else yes;

        
    }
    
    return 0;
}