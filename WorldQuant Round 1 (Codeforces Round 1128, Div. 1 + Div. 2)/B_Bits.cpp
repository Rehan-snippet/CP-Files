#include <bits/stdc++.h>
using namespace std;

// ============ MACROS ============
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define pll pair<ll,ll>
#define vpl vector<pair<ll,ll>>
#define pb push_back
#define ff first
#define ss second
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop2(i,n) for(ll i=1;i<=n;i++)
#define rloop(i,n) for(ll i=(n)-1;i>=0;i--)
#define input(a) for(auto &x:a) cin>>x
#define output(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define sz(x) ((ll)x.size())
#define summation(a) accumulate(a.begin(), a.end(), 0LL)
#define pi 3.14159265358979323846L
const ll MOD = 1e9+7;      // switch to 998244353 when needed
const ll INF = 4e18;
const int N = 2e5+5;
// memset(a, -1, sizeof(a));

ll power(ll base, ll exp, ll mod= MOD) {
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

// unweighted shortest distance from src, -1 if unreachable
vl bfsDistance(ll src, const vector<vl> &adj) {
    vl dist(adj.size(), -1);
    queue<ll> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl a(n);
        input(a);
        ll ans=0;

        ll maxi= a[max_element(all(a))-a.begin()];
        loop(i,n){
            ll x= maxi^a[i];
            ans= max(ans, x);
        }
        if(ans!=0){
            ll exp= log2(ans);
            ans= 1<<(exp); ans= 2*ans-1; 
        }
        ans|=maxi;
        cout<<ans<<endl;
    }
    
    return 0;
}