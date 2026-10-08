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

ll power(ll base, ll exp, ll mod=MOD) {
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
        ll n,m;
        cin>>n>>m;
        vl a(n);
        input(a);
        // set<ll> st;
        // ll sum=0;
        // loop(i,n) {
        //     sum+=a[i];
        //     st.insert(a[i]);
        // }


        // ll e=1; ll p=0;
        // loop(i,n){
        //     if(a[i]>e) {
        //         v.pb(p);
        //         p=0;
        //         e*=2;
        //         i--;
        //     }
        //     else{
        //         p++;
        //     }
        // }
        // v.pb(p);

        // vl freq(m+1);
        // loop(i,n) freq[a[i]]++;
        
        // vl fr(m+1);
        // fr[1]=freq[1];
        // for(ll i=2; i<m+1; i++) fr[i]= fr[i-1]+freq[i];

        
        // ll imp= v.size()-1;

        // ll ans=n;
            
        //     for (auto x:st) if(x<k) ans+=x*freq[x];
        //     for(auto x:st){
        //         else if(x%k==0){
        //             ll y= k*freq[x];
        //             if(y>ans){
        //                 r=x;
        //                 ans= y;
        //             }
        //         }
        //     }
        //     for(auto x:st){
        //         if(x>k) ans+= (k-1)*freq[x];
        //     }
        //     cout<<ans<<" ";
        // }

        sort(all(a));
        ll r= ceil(log2((double)a[n-1]));
        ll ans=1, p=power(2,r-1);

        for(ll i=1; i<=r; i++){
            ans=1;
            ll k= power(2, i);
            for(int last=1; last<= p; last*=2){
                ll y=0;
                for(auto x:a){
                    if(x<last) continue;
                    else if(x>=last && x<=k) y+=(x/last);
                    else if(x>k) y+=(k-1);
                }
                ans= max(ans, y);
            }
            cout<<ans<<" ";
        }
         while(r<m){
            cout<<ans<<" ";
            r++;
         }   
        cout<<endl;
        // output(v);
    }
    
    return 0;
}