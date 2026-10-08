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
         ll n,ans=0,size=0, even2=0, even4=0, odd=0, mineven4=0;
         cin>>n;
         vl a(2*n), b(2*n +1);
         input(a);
         loop(i, 2*n){
            b[a[i]]++;
         }
         //sort(all(b));
         //output(b); cout<<endl;
         for(ll i=1; i<=2*n; i++){
            if(b[i]==0) continue;
            if(b[i]%2) odd++;
            else if(b[i]%4) even2++;
            else {even4++; mineven4= min(mineven4, b[i]);}
         }
         // for(ll i=1; i<=2*n; i++){
         //    if(b[i]==0) continue;
         //    else if(b[i]%4==0 && b[i]/2 < n-size) {ans+=2; size+= (b[i]/2);}
         // }
        //  ll flag=n-ans, flag2=0;
        //  //cout<<flag<<endl;
        //  if(ans<n){
        //     for(ll i=1; i<=2*n; i++){
        //         if(b[i]){
        //             if(b[i]%2==0) {ans+=2; flag--;}
        //             //else if(b[i]%4) ans+=2;
        //         }
        //         if(flag==0) break;
        //     }
        //  }
        
        ans= odd+ 2*even2 + even4*2;
        if(odd==0 && even4%2) ans-=2;
         cout<<ans<<endl;

    }
    
    return 0;
}