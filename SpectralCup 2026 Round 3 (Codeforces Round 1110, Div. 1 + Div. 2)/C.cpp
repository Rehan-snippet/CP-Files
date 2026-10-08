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
        ll n,k,x=LONG_LONG_MAX;
        cin>>n>>k;
        vl ans, f(n,0);
        
        ll c=k^(n);
        ll i=1;
        while(i<n+1 && c>=n){
            c=c^(n-i);
            ans.pb(n-i);
            f[n-i]=1;
            i++;
        }
        ans.pb(c); i--; 
        if(c<n) f[c]=1;

        if(n==1){
                if(k==1){
                    yes;
                    cout<<0<<endl;
                }
                else no;
            }
        else if(c>=n) no;
        else{
            yes;
            if(f[0]==0) {ans.pb(0); f[0]=1;}
            for(ll i=n-1; i>0; i--){
                if(f[i]==0) ans.pb(i);
            }
            reverse(all(ans));
            output(ans);

            // if(c>= n-i && c<= n-1) {
            //     cout<<c<<" ";
            //     for(ll j=1; j<n-i; j++){
            //     cout<<j<<" ";
            //     }
            //     cout<<0<<" ";
            //     for(ll j=n-i; j<n; j++) if(j!=c) cout<<j<<" ";
            //     cout<<endl;
            // }
            // else{
            //     for(ll j=1; j<n-i; j++){
            //     if(j!=c) cout<<j<<" ";
            //     }
            //     cout<<0<<" ";
            //     if(c<n) cout<<c<<" ";
            //     for(ll j=n-i; j<n; j++) cout<<j<<" ";
            //     cout<<endl;
            // }
        }
        
    }
   
    
    return 0;
}