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
        cin>>n;
        vl p(n+1);
        p[1]=-1, p[0]=-1; 
        for(ll i=2; i<=n; i++) cin>>p[i];
        cin>>m;
        vl a(m); 
        input(a);
        cout<<m-1<<" ";
        vl f(n+1);
        loop(i,m) f[a[i]]=1;

        vector<vl> child(n+1);
        for(ll i=2; i<=n; i++){
            child[p[i]].pb(i);
        }

        vector<vl> h;
        h.pb({1});
        ll sz=1, ans;
        if(f[1]==1) ans=1;
        else {
            ans=-1;

            while(1){
                vl v;
                for(auto x:h[sz-1]){
                    for(auto y:child[x]) {
                        v.pb(y);
                        if(f[y]==1) {
                            ans=y;
                        }
                    }
                }

                if(v.size()==0 || ans!=-1) break;
                h.pb(v); sz++;
            }
        }   

        
        loop(i,m){
            if(a[i]==ans) continue;
            cout<<a[i]<<" ";

        }
        cout<<endl;
        
    }
    
    return 0;
}