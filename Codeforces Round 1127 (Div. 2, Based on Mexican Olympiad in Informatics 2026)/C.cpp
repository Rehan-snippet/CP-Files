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
        ll n;
        cin>>n;
        if(n==5) {
            vl v= {1,1, 2,2, 2};
            cout<<3<<endl;
            output(v);
        }
        else if(n==9){
            vl v={1,1, 2,2,2,3,3,3,3};
            cout<<4<<endl;
            output(v);
        }
        else if(n==2){
            vl v={1,1};
            cout<<2<<endl;
            output(v);
        }
        else{
            ll s=0, idx=1;
            while(s<=n){
                s+=idx;
                idx++;
            }
            idx--; 
            
                s-=idx; idx--;
                vl v;
                for(ll i=1; i<=idx; i++){
                    loop(j,i){
                        v.pb(i);
                    }
                }
                ll ans= idx;
                
                if(n-s==idx){
                    v.pb(idx+1); v.pb(idx+1);
                    s+=2; idx++;
                }
                idx++;
                loop(i, n-s) {
                    v.pb(idx); idx++;}
            
            cout<<ans<<endl;
            output(v); 
            }
        
        
    }
    
    return 0;
}