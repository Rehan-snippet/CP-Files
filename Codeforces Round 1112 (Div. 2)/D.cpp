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
const ll MOD = 998244353;
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
        ll n;
        cin>>n;
        vl a(n-1);
        input(a);
        vl b=a;
        vl fr(n+1, -1), fp(n+1, -1);
        loop(i,n-1){
            if(fr[a[i]]==-1) fr[a[i]]=i;
            fp[a[i]]=i;
        }
        sort(all(a));
        bool f=0;
        if(a[n-2]!=n-1) f=1;
        
        if(f) cout<<0<<endl;
        else{
            ll ans=2;
            ll used=1;
            ll left=fr[n-1], right=fp[n-1];
            for(ll m=n-2; m>=1; m--){
                if(fr[m]==-1) {
                    ans*= max(0LL, right-left-used+1 ); ans%=MOD; 
                }
                else{
                    if(fp[m]==left-1){
                        left=fr[m];
                    }
                    else if(fr[m]==right+1) {
                        right= fp[m];
                    }
                    else ans=0;
                }
                used++;
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
}