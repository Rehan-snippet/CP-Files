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
        ll x,y;
        cin>>x>>y;
        ll p=x,q=y;
        ll msb1 = 1, msb2=1, big, dif1, dif2, f=0;
        if(y>x) f=1;

            big= x;
            while (msb1 <= big) msb1 <<= 1;
            dif1=msb1 - x;
            big= y;
            while (msb2 <= big) msb2 <<= 1;
            dif2=msb2 - y;


        vl bitx(32,0), bity(32,0);
        for(int i=31; i>=0; i--){
            bitx[i]=x&1;
            x>>=1;
        }
        for(int i=31; i>=0; i--){
            bity[i]=y&1;
            y>>=1;
        }

        int i=0;
        while(!(bitx[i]==1 && bity[i]==1) && i<32) i++;
        while(i<32){
            if(bitx[i]==1 && bity[i]==1){
                bitx[i]=0;
            }
            else if(bitx[i]==0 && bity[i]==0){
                bitx[i]=1;
            }
            i++;
        }

        x=0;
        for(int i=0; i<32; i++){
            x=(x<<1) | bitx[i];
        }

        if(abs(x-p)<dif1 && abs(x-p)<dif2 && x&q==0) cout<<x<<" "<<q<<endl;
        else if(dif1 < dif2 && msb1&q==0) cout<<msb1<<" "<<q<<endl;
        else cout<<p<<" "<<msb2<<endl;


    }
    
    return 0;
}