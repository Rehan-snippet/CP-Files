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
#define summation(a) accumulate(a.begin(), a.end(), 0LL)
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

ll modInverse(ll a, ll mod = MOD) {
    return power(((a % mod) + mod) % mod, mod - 2, mod);
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

bool isPrime(ll n){
    if(n<=1) return false;
    if(n==2) return true;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;

}

int main() {
    fastio;
    test{
        ll n, m, x, y;
        cin>>n>>m>>x>>y;
        vl a(x), b(y);
        input(a); input(b);

        vl ans;
        ll idx1=x-1, idx2=y-1;
        ll xa=0, yb=0, zc=0;
        while(idx1>=0 && idx2>=0 && xa<n && yb<m){
            if(a[idx1]==b[idx2]){
                ans.pb(a[idx1]);
                idx1--; idx2--; zc++;
            }
            else if(a[idx1]>b[idx2]){
                ans.pb(a[idx1]);
                idx1--; xa++;
            }
            else{
                ans.pb(b[idx2]);
                idx2--; yb++;
            }
            if(xa+yb+zc==n+m-1) break;
        }

        if(idx1<0 || xa==n) {
            while(idx2>=0 && yb<m && xa+yb+zc<n+m-1) {
                ans.pb(b[idx2]);
                idx2--; yb++;
            }
        }
        else if(idx2<0 || yb==m){
            while(idx1>=0 && xa<n && xa+yb+zc<n+m-1){
                ans.pb(a[idx1]);
                idx1--; xa++;
            }
        }
        
        
        //output(ans);
       cout<<summation(ans)<<endl;
        
        
    }
    
    return 0;
}