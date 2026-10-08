#include<bits/stdc++.h>
//typedef vector<int> vi;
typedef long long ll;
#define test int t;cin>>t;for(int i=0;i<t;i++)
#define loop(i,n) for(int i=0;i<n;i++)
#define pb push.back
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v={2,3,4,6,8,9,14,23,78,400};
    int t=33;
    int l=0,r=9,sum;
    while(l+1<r){
        sum=v[l]+v[r];
        if(sum==t) {cout<<"Yes "<<l<<" "<<r<<"\n"; break;}
        else if(sum>t) r--;
        else l++;
        //cout<<l<<" "<<r<<"\n";
    }
    sum=v[l]+v[r];
    cout<<l<<" "<<r;


    return 0;
}