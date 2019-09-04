#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forl(z,i,l) for(int z=i;z<l;z++)
#define pb push_back
#define endl "\n"

int search(ll v,int i, int l, vector<ll> a)
{
    if (l>=i)
    {
        int mid=i+(l-i)/2;
        if(v==a[mid]) return mid;
        else if (v<a[mid]) return search(v,0,mid-1,a);
        else if (v>a[mid]) return search(v,mid+1,l,a);
    }
    return -1;
}

int main()
{
    ll n,max_value=-1;
    int e=0,q,max_index=-1;
    cin>>n>>q;
    ll Q[q][3];
    vector<ll> U;
    forl(i,0,q)
    {
        cin>>Q[i][0];
        if (Q[0][0]==2) break;
        if (Q[i][0]==1)
        {
            cin>>Q[i][1]>>Q[i][2];
            if(i==0) U.pb(Q[i][1]);
            else 
            {
                if(search(Q[i][1],0,U.size()-1,U)==-1) U.pb(Q[i][1]);
            }
            sort(U.begin(),U.end());
        }
    }
    ll Amount[U.size()];
    fill_n(Amount, U.size(), 0);
    forl(i,0,q)
    {
        if(Q[i][0]==1)
        {
            e=search(Q[i][1],0,U.size()-1,U);
            Amount[e]+=Q[i][2];
            if (max_value<=Amount[e])
            {
                max_value=Amount[e];
                max_index=e;
            }
        }
        if(Q[i][0]==2) 
        {
            if(max_index<0) cout<<"\nNo data Available!\n";
            else cout<<"\n"<<U[max_index]<<endl;
        }
    }
    return 0;
}