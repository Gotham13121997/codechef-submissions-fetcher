//ABHINAV GAUTAM (gotham13121997)
#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007
#define getC(n) scanf("%c",&n)
#define getL(n) scanf("%ld",&n)
#define getLL(n) scanf("%lld",&n)
#define getD(n) scanf("%lf",&n)
#define getS(n) scanf("%s",n)
#define getI(a) scanf("%d", &a) 
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getIIII(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define FOR(i,L,R) for (int i = L; i < R; i++) 
#define FORE(i,L,R) for (int i = L; i <= R; i++)
#define FORD(i,L,R) for (int i = L; i > R; i--)
#define FORDE(i,L,R) for (int i = L; i >= R; i--)
#define foreach(v, c)  for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define whileT int T; getI(T); while(T--)
#define mem(a,x) memset(a,x,sizeof(a))
#define abs(x) (x<0?(-x):x)
#define maX(a,b) ( (a) > (b) ? (a) : (b))
#define miN(a,b) ( (a) < (b) ? (a) : (b))
#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define fr first
#define se second
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii; 
typedef queue<int> qi;

int main()
{
	int p,q,r;
	whileT
	{
		getIII(p,q,r);
		ll a[p];
		ll b[q];
		ll c[r];
		FOR(i,0,p)
		getLL(a[i]);
		FOR(i,0,q)
		getLL(b[i]);
		FOR(i,0,r)
		getLL(c[i]);
		sort(a,a+p, greater<ll>());
		sort(b,b+q);
		sort(c,c+r);
		ll sum=0;
		FOR(i,0,p)
		{
			int find=lower_bound(b,b+q,a[i])-b;
			FOR(j,find,q)
			{
				int find1=upper_bound(c,c+r,b[j])-c;
				find1--;
				if(find1==r-1)
					if(c[find1]>b[j])
						find1=-1;
				FORDE(k,find1,0)
				{
					sum=sum+((a[i]+b[j])*(b[j]+c[k]))%inf;
				}
			}
		}
		cout<<sum%inf<<endl;
	}
    return 0;
} 