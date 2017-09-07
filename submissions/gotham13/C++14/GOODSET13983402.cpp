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
	/*
	GENERATING FUNCTION

	vector <int> s1;
	set <int> s;
	s1.pb(1);
	s1.pb(2);
	s.insert(3);
	int i=4;
	while(true)
	{
		if(s1.size()==100)
		break;
		if(s.find(i)==s.end())
		{
			FOR(j,0,s1.size())
			{
				int c=i+s1[j];
				s.insert(c);
			}
			s1.pb(i);
		}
		i++;
	}
	FOR(j,0,s1.size())
	{
		cout<<s1[j]<<",";
	}
	*/
	int n;
	int a[100]={1,2,4,7,10,13,16,19,22,25,28,31,34,37,40,43,46,49,52,55,58,61,64,67,70,73,76,79,82,85,88,91,94,97,100,103,106,109,112,115,118,121,124,127,130,133,136,139,142,145,148,151,154,157,160,163,166,169,172,175,178,181,184,187,190,193,196,199,202,205,208,211,214,217,220,223,226,229,232,235,238,241,244,247,250,253,256,259,262,265,268,271,274,277,280,283,286,289,292,295};
	whileT
	{
		getI(n);
		FOR(i,0,n)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;

	}
}