#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forl(z,i,l) for(int z=i;z<l;z++)
#define pb push_back
#define endl "\n"

int concCompare(string x,string y) {
    string XY=x.append(y);
    string YX=y.append(x);
    return XY.compare(YX)>0?1:0;
}

int main() {
    int t,n;
    cin>>t;
    forl(i,0,t){
        cin>>n;
        string a[n];
        forl(k,0,n) {
            cin>>a[k];
        }
        sort(a,a+n,concCompare);
        forl(l,0,n) {
            cout<<a[l];
        }
        cout<<endl;
    }
    return 0;
}