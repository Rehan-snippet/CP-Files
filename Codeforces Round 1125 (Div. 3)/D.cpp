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
        ll n,k;
        cin>>n>>k;
        vl a(n), b(n), c(n), key(n,0);
        vpl s(n);
        loop(i,n){
            cin>>a[i]>>b[i]>>c[i];
            s[i]={a[i]+b[i]+c[i], i};
            if(a[i]<=b[i] && b[i]<=c[i]){
                if(a[i]==b[i] && b[i]==c[i]) key[i]=LLONG_MAX/4;
                else if(a[i]==b[i] || b[i]==c[i]) key[i]= 1;
                else if(b[i]-a[i] <= c[i]-a[i] && b[i]-a[i] <= c[i]-b[i]) key[i]= b[i]-a[i]+1;
                else if(c[i]-a[i] <= b[i]-a[i] && c[i]-a[i] <= c[i]-b[i]) key[i]= c[i]-a[i]+1;
                else key[i]= c[i]-b[i]+1;
            }
        }

        sort(all(s));
        ll ans=s[0].first;
        loop(i,n-1){
            ll idx=s[i].second;
            ll dif= s[i+1].first - s[i].first;
            //cout<<key[idx]<<" ";
            dif*=(i+1);
            if(k<= 2*key[idx]) {k=0; break;}
            else{
                k-=2*key[idx];
                if(dif>=k) {
                    ans+=(k/(i+1));
                    k=0;
                    break;
                }
                else{
                    k-=dif;
                    ans= s[i+1].first;
                }
            }

        }
        k= max(0LL, k-2*key[s[n-1].second]);
        ans+=(k/n);
        cout<<ans<<endl;
        //cout<<s[0].second<<s[1].second<<endl;
        
    }
    
    return 0;
}