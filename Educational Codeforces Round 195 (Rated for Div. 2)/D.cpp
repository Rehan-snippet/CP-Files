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

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    fastio;
    test{
        ll n,m;
        cin>>n>>m;
        vector<vl> adj(n+1);
        vl visited(n+1);

        loop(i,m){
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ll f1=0, f2=0;
        loop2(i,n){
            if(adj[i].size()==0) {
                f1=1;
                break;
            }
        }
        if(f1) cout<<"Brain Melt\n";
        else if(n==2) cout<<2<<endl;
        else{
            ll node=1;
            if(adj[node].size()==1) node= adj[node][0];
            if(adj[node].size()==1) {
                f2=1;
            }
            visited[node] =1;
            for(auto x:adj[node]){
                visited[x]=1;
                if(adj[x].size()>1) {
                    f2=1;
                    break;
                }
            }
            loop2(i,n) {
                if(visited[i]==0) {
                    f2=1;
                    break;
                }
            }
            if(f2) cout<<"Many\n";
            else cout<<2<<endl;
        }
          
    }
    
    return 0;
}
