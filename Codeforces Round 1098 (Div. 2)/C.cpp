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
        ull a; int n; ull ans=LONG_LONG_MAX, b=0;
        cin>>a>>n;
        vl d(n);
        input(d);
        if(a==0) ans=d[0];
        else{
            int dig=0; ull num=a; int k;
            string s = to_string(a); 
            string t=s;
            while(num>0){
                k=num%10;
                dig++; num/=10;
            }

            for (int i = 0; i < (1 << dig); i++) {
                ull k=0;
                for (int j = dig-1; j >= 0; j--){
                    if(((i >> j) & 1)==0) k=k*10+d[0];
                    else k=k*10+d[1];
                }
                if(k>a && ans>(k-a)) ans=k-a;
                else if(a>=k && ans>(a-k)) ans= a-k; 
                //cout<<k<<" ";
            }
            for (int i = 0; i < (1 << (dig-1)); i++) {
                ull k=0;
                for (int j = dig-2; j >= 0; j--){
                    if(((i >> j) & 1)==0) k=k*10+d[0];
                    else k=k*10+d[1];
                }
                if(k>a && ans>(k-a)) ans=k-a;
                else if(a>=k && ans>(a-k)) ans= a-k; 
                //cout<<k<<" ";
            }
            for (int i = 0; i < (1 << (dig+1)); i++) {
                ull k=0;
                for (int j = dig; j >= 0; j--){
                    if(((i >> j) & 1)==0) k=k*10+d[0];
                    else k=k*10+d[1];
                }
                if(k>a && ans>(k-a)) ans=k-a;
                else if(a>=k && ans>(a-k)) ans= a-k; 
                //cout<<k<<" ";
            }

            // loop(i, s.size()){
            //     k=s[i]-'0';
            //     if(k==d[0]) t[i]=d[0]+'0';
            //     else if(k==d[1]) t[i]=d[1]+'0';
            //     else if(k>d[1]){
            //         while(t.size()!=dig) t[i]=d[1]+'0';
            //         break;
            //     }
            //     else if(k<d[0]){
            //         while(t.size()!=dig) t[i]=d[0]+'0';
            //         break;
            //     }
            //     else if(abs(k-d[0])<abs(k-d[1])) t[i]=d[0]+'0';
            //     else t[i]=d[1]+'0';
                    
            // } 
            // b=stoull(t);
            // //cout<<b<<" ";
            // ans = (b > a) ? (b - a) : (a - b);
            // ull x=0;
            // for(int i=1; i<=dig-1; i++){
            //     x=x*10+d[1];
            // }
            // //cout<<x<<" ";
            // if((a-x) <ans) ans= (a-x);
            // x= x*10+d[1];
            // if (a >= x && (a - x) < ans) ans = a - x;
            // if (x >= a && (x - a) < ans) ans = x - a;
            // x=0;
            // for(int i=1; i<=dig; i++){
            //     x=x*10+d[0];
            // }
            // //cout<<x<<endl;
            // if (a >= x && (a - x) < ans) ans = a - x;
            // if (x >= a && (x - a) < ans) ans = x - a;
            
            // x=x*10+d[0];
            // if((x-a)<ans) ans= (x-a);
            
        }
        cout<<ans<<endl;

    }
    
    return 0;
}