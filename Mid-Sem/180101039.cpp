#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forl(z,i,l) for(int z=i;z<l;z++)
#define pb push_back
#define endl "\n"
#define mod 10000001

int main() {
    ll n,q,a,b;
    cin>>n;
    ll Q[n];
    Q[0]=0;
    Q[1]=0;
    Q[2]=0;
    Q[3]=1;
    Q[4]=0;
    Q[5]=0;
    Q[6]=2;
    Q[7]=1;
    forl(i,8,n){
        Q[i]=((Q[i-3]%mod)+(Q[i-6]%mod)+(Q[i-7]%mod))%mod;
    }
    cin>>q;
    forl(i,0,q) {
        cin>>a>>b;
        if(a==1) b=n-b;
        if(a==-1) b=b-1;
        cout<<Q[b]<<endl;
    }
}