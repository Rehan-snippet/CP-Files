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

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl a(n);
        input(a);
        if(a[0]==-1 && a[n-1]==-1){
            a[0]=0; a[n-1]=0;
        }
        else if(a[0]==-1) a[0]=a[n-1];
        else if(a[n-1]==-1) a[n-1]=a[0];
        ll dif=abs(a[0]-a[n-1]);
        cout<<dif<<endl;
        loop(i,n){
            if(a[i]==-1) cout<<0<<" ";
            else cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}