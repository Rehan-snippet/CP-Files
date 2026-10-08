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
        ll n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        string s1=s;
        vl move(n+1,0);
        for(ll i=1; i<n; i++){
                if(s[i]!=s[i-1]) {move[i+1]=move[i]; continue;}
                else{
                    if(s[i]=='0') s[i]='1';
                    else s[i]='0';
                    move[i+1]=move[i]+1;
                    ll j=i+1;
                    while(j<n && s[j]==s[j-1]){
                        if(s[j]=='0') s[j]='1';
                        else s[j]='0';
                        move[j+1]=move[i+1];
                        i++;
                        j++;
                        
                    }
                    
                }
            }
            //output(move);
        while(q--){
            //string s=s1;
            ll l,r,k;
            cin>>l>>r>>k;
            if(l==r) yes;
            else if(r==l+1) {
                if(s1[l-1]==s1[r-1] && k==0) no;
                else yes;
            }
            else if(s1[l-1]==s[l-1] || move[l]!=move[l-1]){
                if(move[r]-move[l-1]<=k) yes;
                else no;
            }
            else{
                if(move[r]-move[l-1]+1<=k) yes;
                else no;
            }
            
        }
    }
    
    return 0;
}