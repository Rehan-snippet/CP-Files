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
    ll n,k;
    cin>>n>>k;
    vl a(n);
    input(a);
    set<ll> s;
    loop(i,n) s.insert(a[i]);


    vl ans(n);
    ans[0]=a[0];

    for(ll i=1; i<n; i++){
        ans[i]=a[ans[i-1]-1];
    }
        vl freq(n+1,0);
        ll c, idx1, idx2=-1;
        loop(i,n){
            freq[ans[i]]++;
            if(freq[ans[i]]>1) {
                c=ans[i];
                idx2=i;
                break;
            }
        }
        if(idx2==-1) cout<<ans[k%n]<<endl;
        else{
        loop(i,n){
            if(ans[i]==c) {
                idx1=i;
                break;
            }
        }
        if(k<n) cout<<ans[k]<<endl;
        else cout<<ans[(k-idx1 -1)%(idx2-idx1)+idx1]<<endl;
        //cout<<idx1<<idx2;
    }
    
}