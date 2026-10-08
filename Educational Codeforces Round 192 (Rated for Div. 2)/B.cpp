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
        vl a(n);
        input(a);
        bool f1=0, f2=0;
        ll one=0, two=0, three=0, x=0;
        loop(i,n){
            if(f1==0){
                if(a[i]==1) one++;
                else if(a[i]==2) two++;
                else three++;

                if(one>=two+three) {
                    f1=1; x=one- (two+three);
                    one=0; two=0; three=0; 
                }
            }
            else{
                if(a[i]==1) one++;
                else if(a[i]==2) two++;
                else three++;

                if(one+two>0 && x+one+two>=three && i<n-1) {
                    f2=1;
                    one=0; two=0; three=0;
                }
            }
            if(f2==1) break;
        }
        if(f2) yes;
        else no;
        
    }
    
    return 0;
}