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
        string s;
        ll one=0, two=0, three=0, four=0, f=0, odd=0, even=0, ans=0;
        cin>>s;
        string t;
        for(char c:s){
            if(c!='4') t.pb(c);
        }

        vl left(t.size()), right(t.size());
        ll i=0,j=0;
        for(char c:t){
            if(c=='1' || c=='3') odd++;
            else even++;
            left[i++]=even;
            right[j++]=odd;
        }
        ll n=t.size(); 
        ans=even;
        loop(k,n){
            ans= min(ans, even-left[k]+right[k] );
        }
        for(char c:s){
            if(c=='1') one++;
            else if(c=='2') two++;
            else if(c=='3') three++;
            else four++;
        }

        // vl imp;
        // ll a=0,b=0;
        // for(char c:s){
        //     if(f==0 && (c=='2'|| c=='4')) continue;
        //     f=1;
        //     if(c=='1'|| c=='3') {
        //         if(b){imp.pb(b);
        //         b=0;}
        //         a++;
        //     }
        //     else if(c=='2'){
        //         if(a){imp.pb(a);
        //         a=0;}
        //         b++;
        //     }
        // }
        // imp.pb(max(a,b));

        

        // even=two;
        // odd= one+three;

        // for(char c:s){
        //     if(c=='1' || c=='3') break;
        //     else if(c=='2') even--;
        // }

        // string s1(allr(s));
        // for(char c:s1){
        //     if(c=='2') break;
        //     else if(c=='1' || c=='3') odd--;
        // }

        // if(imp[0]==0 || imp.size()==1) ans=four;
        // else{
        //     ll n=imp.size();
        //     if(n%2) n--;
        //     ll stop=odd+even, sum=0;
        //     loop(i,n){
        //         sum+=imp[i];
        //         if(sum<stop/2 && i%2==0) ans+=imp[i];
        //         else if(sum>=stop/2 && i%2==1) ans+=imp[i];
        //     }
        // }
        // ans=min(ans, four+min(even,odd));

        cout<<ans+four<<endl;
       // output(imp);
    }
    
    return 0;
}