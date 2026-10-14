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
        ll n, m,k, a=0,b=-1;
        cin>>n>>m>>k;
        vl l(n), r(n), d(n), p(n+1);
        loop(i,n){
            cin>>l[i]>>r[i];
            d[i]=r[i]-l[i]+1;
            p[i+1]=p[i]+d[i];
            if(p[i+1]>=k && b==-1) b=i;
        }
        //cout<<a<<b<<endl;
        ll s=-1, start=1, end=-1, f;
        if(l[0]==1) f=1;
        else f=0;

        while(b!=-1 && a<n){
            ll move= p[b+1]-p[a]-k;
            //cout<<move<<" ";
            while(move<d[a] && b<n) {
                b++;
                if(b<n) move= p[b+1]-p[a]-k;
            }
            if(b==n) break;
            if(f){
                if(b+1<n) end= l[b+1]-1;
                else end= LONG_LONG_MAX/4;
                if(move<d[a]){
                    start+=move;
                    if(end-start+1 >=m && -start+1-m <= -r[b]){
                        s=start;
                        break; 
                    }
            
                }
            }
            else{
                end= r[b];
                end-=move;
                if(start==1 && f==0){
                    if(end-start+1 >=m && end-l[0]+1 <=m ){

                        start+=(end-start+1 -m);
                        s= start;
                        break;
                    }
                }
                else{
                    if(end-start+1 >=m && end-l[a]+1 <=m ){
                        start+=(end-start+1 -m);
                        s= start;
                        break;
                    }
                }
            }
            if(start== 1 && f==0 && r[b]!=1) {start=l[0]; f=1;}
            else if(f==1) {start=r[a]+1; f=0; a++;}
            else if(f==0){
                start= l[a];
                f=1;
            } 
        }
        if(k==0) s=r[n-1]+1;
        cout<<s<<endl;

    }
    
    return 0;
}