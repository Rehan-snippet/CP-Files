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
        ll l,a,b,ans=0;
        cin>>l>>a>>b;
        b=b%l;
        ll c=a;
        if(b==0) ans=a;
        else if(b==1) ans=l-1;
        else{
            do{
                a+=b;
                a%=l;
                ans=max(ans,a);
            }while(a!=c);
        }
        cout<<ans<<endl;
        

    }
    
    return 0;
}