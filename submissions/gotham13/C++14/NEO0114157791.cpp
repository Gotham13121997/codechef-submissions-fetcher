//ABHINAV GAUTAM (gotham13121997)
#include <bits/stdc++.h>
using namespace std;
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
	int n;
	long long l;
	whileT
	{
		int countpos=0;
		ll sumpos=0;
		ll sumneg=0; 
		getI(n);
		FOR(i,0,n)
		{
			getLL(l);
			if(l>=0)
			{
				sumpos=sumpos+l;
				countpos++;
			}
			else
			{
				sumneg=sumneg+l;

			}
		}
		cout<<(sumpos*countpos)+sumneg<<endl;
	}
    return 0;
}