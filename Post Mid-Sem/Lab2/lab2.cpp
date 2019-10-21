#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define forl(z,i,l) for(int z=i;z<l;z++)
#define pb push_back
#define endl "\n"

class point {
    public:
        int x;
        int y;
        double dist=sqrt((x*x)+(y*y));
};

void swap(point* a,point* b) {
    point temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int orientation(point a,point b,point c) {
    int d=(b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
    if (d==0) return 0;
    return (d>0)?-1:1;
}

static point p0;

int sortSlope(point a,point b) {
    int o=orientation(a,p0,b);
    return (o<0)?0:1;
}

int main() {
    int n,minIndex=-1;
    cin>>n;
    vector<point> convexHull;
    point points[n];
    forl(i,0,n) {
        cin>>points[i].x>>points[i].y;
        if (points[minIndex].y==points[i].y) {
            minIndex=(points[minIndex].x>points[i].x)?i:minIndex;
        }
        else minIndex=(points[minIndex].y>points[i].y)?i:minIndex;
    }
    swap(&points[minIndex],&points[0]);
    p0=points[0];
    sort(points+1,points+n,sortSlope);
    //forl(u,0,n) cout<<points[u].x<<points[u].y<<endl;
    forl(j,0,n) {
        convexHull.pb(points[j]);
        if(j<3) continue;
        while(1) {
            int i=convexHull.size();
            int o=orientation(convexHull[i-3],convexHull[i-2],convexHull[i-1]);
            if (o>=0) convexHull.erase(convexHull.cbegin()+i-2);
            else break;
        }
    }
    minIndex=0;
    forl(i,0,convexHull.size()) minIndex=(convexHull[minIndex].x>convexHull[i].x)?i:minIndex;
    //forl(i,0,convexHull.size()) cout<<convexHull[i].x<<" "<<convexHull[i].y<<endl;
    //cout<<minIndex<<endl;
    cout<<convexHull.size()<<endl;
    int i=minIndex;
    do {
        cout<<convexHull[i].x<<" "<<convexHull[i].y<<endl;
        i--;
        if (i==-1) i=convexHull.size()-1;
    }while (i!=minIndex);
	return 0;
}