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
        vl v(n);
        input(v);
        vector<vl> a(n, vl(m,0));
        vl sum(n,0); vector<vl> maxi(n, vl(m,0));
        loop(i,n){
            loop(j,m){
                cin>>a[i][j];
            }  
        }

        for(ll i=n-1; i>=0; i--){
            vl b(m);
            b=a[i];
            sort(allr(b));
            if(i==n-1) {
                maxi[i]=b;
                loop(j,m) sum[i]+=b[j];
            }
            else{
                ll idx1=0, idx2=0;
                loop(j,m){
                    if(maxi[i+1][idx1]>=b[idx2]) maxi[i][j]=maxi[i+1][idx1++];
                    else maxi[i][j]=b[idx2++];
                    sum[i]+=maxi[i][j];
                }
            }
        }
        ll ans=m;

        loop(i,n){
            if(sum[i]>=v[i]){
                ll x=0, idx=0;
                while(x<v[i]) x+=maxi[i][idx++];
                ans=min(ans, idx);
            }
        }

        cout<<ans<<endl;
        //output(sum);

    }
    
    return 0;
}