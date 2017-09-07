//ABHINAV GAUTAM (gotham13121997)
#include <bits/stdc++.h>
using namespace std;
#define getC(n) scanf("%c",&n)
#define getL(n) scanf("%ld",&n)
#define getLL(n) scanf("%lld",&n)
#define getULL(n) scanf("%llu",&n)
#define getD(n) scanf("%lf",&n)
#define getI(a) scanf("%d", &a) 
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getIIII(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define putI(a) printf("%d", a)
#define putIn(a) printf("%d\n", a)
#define FOR(i,L,R) for (int i = L; i < R; i++) 
#define FORE(i,L,R) for (int i = L; i <= R; i++)
#define FORD(i,L,R) for (int i = L; i > R; i--)
#define FORDE(i,L,R) for (int i = L; i >= R; i--)
#define FORIT(c,v)  for (auto &c: v)
#define whileT int T; getI(T); while(T--)
#define mem(a,x) memset(a,x,sizeof(a))
#define CMP(a,b) ((a) > (b) ? mp((a),(b)) : mp((b),(a)))
#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define ll long long 
#define ull unsigned long long
#define fs first
#define sd second
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
int i1=0;
int dfs(vector<pair<ll,int> >v1[],int u,int v, bool vis[],ll k,int path[],int pathid,int ide[])
{
    vis[u]=true;
    if(pathid!=0)
        ide[pathid]=i1;
    path[pathid]=u;
    pathid++;
    if(u==v)
    {
        ll xoru=0;
        FOR(i,0,pathid-1)
        {
            ll cnt=v1[path[i]][ide[i+1]].fs;
            if(cnt<=k)
                xoru=xoru^cnt;
        }
        cout<<xoru<<endl;
    }
    else
    {
    FOR(i,0,v1[u].size())
    {
        if(!vis[v1[u][i].sd])
        {
            i1=i;
            dfs(v1,v1[u][i].sd,v,vis,k,path,pathid,ide);
        }
    }
    }
}
int main()
{
    int n,m;
    int u,v;
    ll c,k;
    whileT
    {
        getI(n);
        vector<pair<ll,int> > v1[n+1];
        bool vis[n+1];
        FOR(i,0,n-1)
        {
            getII(u,v);
            getLL(c);
            v1[u].pb(mp(c,v));
            v1[v].pb(mp(c,u));
        }
        getI(m);
        while(m--)
        {   int path[n+1];
            int ide[n+1];
            int pathid=0;
            getII(u,v);
            getLL(k);
            mem(vis,false);
            dfs(v1,u,v,vis,k,path,pathid,ide);
        }
    }
    return 0;
}