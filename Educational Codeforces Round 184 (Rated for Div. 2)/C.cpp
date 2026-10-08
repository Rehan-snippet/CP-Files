#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
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

int main() {
    fastio;
    test{
        ll n,t=0,sum=0,sam=0;
        cin>>n;
        vl a(n+1),v(n+1);
        for(int i=1; i<=n;i++){
            cin>>a[i];
            v[i]=2*i - a[i];
            sum+=a[i];
            sam+=v[i];
        }
        ll c=0;
        for(auto x:v){
            c=max(x, c+x);
            t=max(t,c);
        }
       
        sum+=t;
        //output(v);
        cout<<sum<<endl;
    }
    
    return 0;
}