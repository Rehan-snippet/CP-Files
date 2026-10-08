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

int main() {
    fastio;
    test{
        ll n,m;
        cin>>n>>m;
        vl a(n), b(m);
        input(a); input(b);
        sort(all(a)); sort(all(b));
        if(2*m>n) no;
        
        else{
            bool f=0;
            ll l=1;
            ll idx=0;
            for(ll i=0; i<n-1; i++) {
                if(b[idx]>a[i] && b[idx]>a[i+1]) l++;
                else if(b[idx]>a[i] && b[idx]<a[i+1]) {
                    if(l<(idx+1) || n-l<(m-idx)){
                        f=1; break;
                    }
                    i--; idx++;
                }
                if(idx==m) break;
            }
            
            if(idx<m) f=1;

            if(f) no;
            else yes;
            

        }
        
    }
    
    return 0;
}