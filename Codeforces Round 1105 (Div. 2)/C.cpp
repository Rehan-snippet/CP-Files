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

int main() {
    fastio;
    test{
        ll n,m,r,c;
        cin>>n>>m>>r>>c;
        ll k=power(2, (r-1)*m + (c-1)*n - (r-1)*(c-1),998244353);
        // if(r%2 && c%2==0) k*= power(2, n-r,998244353);
        // else if(c%2 && r%2==0) k*= power(2, m-c,998244353);
        // else if(r%2==0 && c%2==0) k*= power(2, n-r + m-c,998244353);
        // k%=998244353;
        cout<<k<<endl;
    }  
    return 0;
}