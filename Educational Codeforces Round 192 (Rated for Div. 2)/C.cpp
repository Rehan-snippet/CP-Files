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
        ll n,k;
        cin>>n>>k;
        vl a(n), freq(n+1), freq2(n+1);
        input(a);
        loop(i,n) freq[a[i]]++;
        ll d1=0, d2=0, ans=0, min_freq=LONG_LONG_MAX;
        set<ll> fr;
        loop2(i,n) {
            if(freq[i]!=0) {
                min_freq=min(min_freq, freq[i]);
                d1++;
                fr.insert(freq[i]);
                freq2[freq[i]]++;
            }
        }
        d2=fr.size();
        ll i=0;
        for(auto x:fr){
            if(k>=n && (k-n)%d1==0) ans++;
            else if(n>k && (n-k)%d1==0 && n-k<(x-i)*d1) ans++;
            n-=(x-i)*d1;
            
            d1-=freq2[x];
            i=x;
            
        }
      
        cout<<ans<<endl;
    }
    
    return 0;
}