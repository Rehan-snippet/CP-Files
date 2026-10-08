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
#define loop(i,n) for(ll i=0;i<n;i++)
#define input(a) for(auto &x:a) cin>>x;
#define output(a) for(auto x:a) cout<<x<<" ";
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846L

int main() {
    fastio;
    ll amount, coin_numbers;
    cin>>amount>>coin_numbers;
    vl coins(coin_numbers);
    input(coins);

    ll dp[coin_numbers][amount+1];
    loop(i,coin_numbers){
        dp[i][0]=1;
    }

    loop(i,coin_numbers){
        for(ll j=1; j<=amount; j++){
            dp[i][j]=0;
            if(i>0) dp[i][j]+=dp[i-1][j];
            if(j>=coins[i]) dp[i][j]+= dp[i][j-coins[i]];
        }
    }
    cout<<dp[coin_numbers-1][amount];
    
    return 0;
}