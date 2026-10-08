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

bool isGood(ll x){
    set<int> s;
    while(x>0){
        s.insert(x%10);
        x/=10;
    }
    if(s.size()>2) return false;
    else return true;
}

int main() {
    fastio;
    test{
        ll n; 
        cin>>n;
        vl a(n), b(n);
        input(a); input(b);
        vl dif(n);
        loop(i,n) dif[i]= b[i]-a[i];

        bool f=0;
        if(dif[0]<0) f=1;
        else{
            // for(ll i=1; i<n; i++){
            //     if(dif[i]<0 && (dif[i]+dif[i-1]) <0){
            //         f=1; break;
            //     }
            // }

            vl pre(n); pre[0]=dif[0];
            for(ll i=1; i<n; i++){
                pre[i]=pre[i-1]+dif[i];
                if(pre[i]<0) {
                    f=1; break;
                }
            }
        }
        if(f) no;
        else yes;
        
    }
    
    return 0;
}