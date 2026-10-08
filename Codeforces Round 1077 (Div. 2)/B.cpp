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

int main() {
    fastio;
    test{
        ll n, one=0;
        cin>>n;
        string s,copy;
        cin>>s;
        copy=s;
        loop(i,n) {
            if(s[i]=='1') one++;
        }
        
        for(ll i=1; i<n-1; i++){
            if(s[i]=='1'){
                copy[i-1]='1';
                copy[i+1]='1';
            }
        }
        if(s[0]=='1' && n>1) copy[1]='1';
        if(s[n-1]=='1' && n>1) copy[n-2]='1';

        ll cnt=0;
        loop(i,n){
            if(copy[i]=='0') cnt++;
            else {
                one+=ceil(cnt/3.0);
                cnt=0;
            }
        }
        one+=ceil(cnt/3.0);
        cout << one << endl;
    }
    
    return 0;
}