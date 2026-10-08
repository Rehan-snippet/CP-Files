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

ll C(ll n, ll r){
    ll k=1;
    loop2(i,n) {
        k= k*i % MOD;
        //cout<<ans<<" ";
    }
    ll ans= k;

    k=1;
    loop2(i,r) k=k*i % MOD;
    k= power(k, MOD-2, MOD);
    ans= ans*k %MOD;

    k=1;
    loop2(i,n-r) k=k*i % MOD;
    k= power(k, MOD-2, MOD);
    ans= ans*k % MOD;

    return ans;
}

int main() {
    fastio;

        ll x,y,ans;
        cin>>x>>y;
        if(x>2*y || y> 2*x || (x+y)%3!=0) ans=0;
        else{
            ll n= (x+y)/3, r=abs(x-y)+ (n-abs(x-y))/2;
            ans= C(n,r);
        }
       cout<<ans<<endl;
       
    
    return 0;
}