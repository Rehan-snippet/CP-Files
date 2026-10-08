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

int main() {
    fastio;
    
    test{
        ll n;
        cin>>n;
        vl a(n);
        input(a);
        ll k=1, p=1, c=1;
        map<ll, pair<ll,ll>> mp;
        for(ll i=1; i<n; i++){
            if(a[i]==a[i-1]) {p*=2; p%=MOD; c++;}
            else{
                mp[a[i-1]]={c,p};
                if(p!=1) {k*=p; k%=MOD;}
                p=1; c=1;
            }
        }
        mp[a[n-1]]={c,p};
        if(p!=1) {k*=p; k%=MOD;}
        ll ans=k; k=0;
        //cout<<ans<<" ";
        if(a[0]==-1){
            for(ll i=0; i<n-1; i++){
                if(a[i]==-1) continue;
                if(a[i]==a[i+1]-1){
                    // k+=(mp[a[i+1]].first*mp[a[i]].first*mp[-1].first);
                    // k+=(mp[a[i+1]].second/2);
                    // k+=(mp[a[i]].second/2);
                    // k+=(mp[a[-1]].second/2);
                    ll denom = mp[a[i+1]].second % MOD;
                    denom = denom * (mp[a[i]].second % MOD) % MOD;
                    denom = denom * (mp[-1].second % MOD) % MOD;
                    ll d = ans * modInverse(denom) % MOD;
                    if(mp[a[i+1]].first>1) {d*=mp[a[i+1]].second; d%=MOD;}
                    //else if(mp[a[i+1]].first==2) d*=2;
                    if(mp[a[i]].first>1) {d*=mp[a[i]].second; d%=MOD;}
                    //else if(mp[a[i]].first==2) d*=2;
                    if(mp[-1].first>1) {d*=mp[-1].second; d%=MOD;}
                    //else if(mp[-1].first==2) d*=2;
                    //d*=(mp[a[i+1]].first*mp[a[i]].first*mp[-1].first);
                    //cout<<d<<" ";
                    // cout<<(mp[a[i+1]].first*mp[a[i]].first*mp[-1].first)<<" ";
                    k+=d;
                    k%=MOD;
                }
            }
            ans+=k; ans%=MOD;
        }
        
        //if(ans==0) ans=1;
        cout<<ans<<endl;
    }
    
    return 0;
}