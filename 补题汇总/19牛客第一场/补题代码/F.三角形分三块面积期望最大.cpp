#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define mem(x) memset(x,0,sizeof(x))
#define mes(x,y) memset(x,y,sizeof(x))
#define max(x,y) ( (x)>(y)?(x):(y) )
#define min(x,y) ( (x)<(y)?(x):(y) )
#define rep(i,l,r) for( int i=l;i<=r;++i)
#define dd(x) cout<<#x<<"="<<x<<' ';
#define de(x) cout<<#x<<"="<<x<<'\n';
#define INF 0XX3f3f3f3f
#define DBG cout<<"^_^"<<endl;
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int SI=5e5+100;
const ll mod=1e9+7;
double eps=1e-9;
struct TPoint{
    double x,y;
}A,B,C;
int main()
{  
    ll X1,Y1,X2,Y2,X3,Y3;
    while( cin>>X1>>Y1>>X2>>Y2>>X3>>Y3 )
        {
            X2-=X1;
            X3-=X1;
            Y2-=Y1;
            Y3-=Y1;
            ll s=X2*Y3-X3*Y2;
            ll t=11;
            ll vv=s*t;
            if(vv<0)vv*=(ll)-1;
            cout<<vv << endl;
        }
    return 0;
}
