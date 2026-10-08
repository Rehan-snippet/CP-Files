#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define input(a) for(auto &x:a) cin>>x;
#define output(a) for(auto x:a) cout<<x<<" ";
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846L
#define MOD 998244353LL


ll gcd(ll a, ll b){
    while(b!=0){
        ll r= a%b;
        a=b;
        b=r;
    }
    return abs(a);
}
// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y);

// Function to find modulo inverse of a
ll modInverse(ll A, ll M)
{
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    if (g != 1){
        cout << "Inverse doesn't exist";
        return -1;
    }
    else {

        // m is added to handle negative x
        return (x % M + M) % M;
    }
}

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}


int main() {
    fastio;
    ll n;
    cin>>n;
    vl a(n);
    input(a);

    vector<pair<ll,ll>> p;
    loop(i,n){
        p.pb({a[i],i});
    }
    sort(all(p));
    vl dp(n,0);

    loop(i,n){
        for(int j=0; j<i; j++){
            if(a[j]<a[i]) dp[i]++;
        }
    }
    ll m=0;
    loop(i,n){
        dp[i]=i+1-dp[i];
        m=max(m,dp[i]);
       // cout<<m<<" ";
    }
    ll t, sum=0;
    loop(i,n){
        dp[i]=m-dp[i];
        t=1<<dp[i];
        sum+=t;
    }

    m=1LL<<m;

    sum=sum/gcd(sum,m);
    m=m/gcd(sum,m);

    cout<<(sum*modInverse(m,MOD))%MOD<<endl;

    return 0;
}