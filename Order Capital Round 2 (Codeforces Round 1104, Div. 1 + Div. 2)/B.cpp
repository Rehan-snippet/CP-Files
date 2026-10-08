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
        ll n;
        cin>>n;
        vl a(n), b(n);
        input(a); input(b);

        ll cost=0; bool f=0;
        loop(i,n){
            ll idx=-1;
            for(ll j=i; j<n; j++){
                if(a[j]<=b[i]) {
                    idx=j; break;
                }
            }
            if(idx==-1) {
                f=1; break;
            }
            for(ll j=idx; j>i; j--){
                swap(a[j], a[j-1]);
                cost++;
            }
        }
        if(f) cout<<-1<<endl;
        else cout<<cost<<endl;
        
    }
    
    return 0;
}