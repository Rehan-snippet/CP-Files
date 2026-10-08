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
#define MOD 998244353
// memset(a, -1, sizeof(a));

int main() {
    fastio;
    test{
        ll x, dig=0, copy, num=0, f=0;
        cin>>x;
        copy=x;
        while(x!=0){
            dig++;
            x/=10;
            num=num*10 +1;
        }
        // vl a(10);
        // a[0]=9;
        // loop(i,10){
        //     a[i]=
        // }
        // if(x%9==0) cout<<10<<endl;
        // else cout<<0<<endl;
        // cout<<dig<<" "<<num<<endl;
        if(copy%9==0){
            copy/=9;
            if(copy>=num || copy<= num-dig) f=1;
        }
        if(f) cout<<10<<endl;
        else cout<<0<<endl;
    }
    
    return 0;
}