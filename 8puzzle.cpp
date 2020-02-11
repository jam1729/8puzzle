/*
Enter the number of test cases.
Then enter the 3*3 matrix for each test case.
Enter the position of gap as zero.
There are 9! total possible states , in which only half (i.e) 9!/2 
states are solvable states.

Some states like 
1 2 3
4 6 5
7 8 0

1 2 3
4 5 6
8 7 0 
are unsolvable cases.

For each solvable test case , I have printed the minimum number of steps
taken to solve the puzzle.
And then I have printed the states (moves) , that proceeds towards 
the solution.

The states given below takes the longest possible steps , 31 steps.
8 6 7
2 5 4
3 0 1
 
6 4 7
8 5 0
3 2 1

The program might take upto 10 seconds to execute.
*/
#include <bits/stdc++.h> 
 
using namespace std;
 
#define MOD 1000000007
#define INF 1e9
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define mp make_pair
#define pb push_back
#define pq priority_queue
ll maxi=LLONG_MIN;
ll mini=LLONG_MAX;
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
 
int t,i,n;
int a[12]={0,0,1,1,2,3,3,4,4,5,6,7};
int b[12]={1,3,2,4,5,4,6,5,7,8,7,8};
vi reqd;
vi orig(9);
void genreqd()
{
	for(i=1;i<=8;i++)
		reqd.pb(i);
	reqd.pb(0);
}
bool comp(vi r)
{
	for(int i=0;i<9;i++)
		if(r[i]!=reqd[i])
			return false;
	return true;
}
void print(vi r)
{
	for(i=0;i<9;i++)
	{
		cout<<r[i]<<' ';
		if(i%3==2) cout<<endl;
	}
	cout<<endl;
}
map <vi,vi> par;
void printpar(vi r)
{
	vector <vi > v;
	while(r!=orig)
	{
		v.pb(r);
		r=par[r];
	}
	cout<<"Minimum number of steps taken to solve the puzzle is "<<v.size()<<endl;
	cout<<"The states/moves are :"<<endl;
	while(!v.empty())
	{
		vi tem=*(v.rbegin());
		print(tem);
		v.pop_back();
	}

}
int bfs(vi v)
{
	map<vi,int> vis;
	queue<pair<vi,int> > q;
	q.push(mp(v,0));
	vis[v]=1;
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		for(i=0;i<12;i++)
		{
			auto t=u.first;
			auto depth=u.second;
			if( t[a[i]]==0||t[b[i]]==0 )
			{
				swap(t[a[i]],t[b[i]]);
				if(comp(t))
				{	
					par[t]=u.first;
					printpar(t);
					return depth+1;
				}
				else if(vis[t]==0)
				{
					vis[t]=1;
					par[t]=u.first;
					q.push(mp(t,depth+1));
				}
			}
		}
	}
	return -1;
 
}
int main() {
    
    #ifndef ONLINE_JUDGE
	freopen("E:\\Codes\\in.txt", "r", stdin);
	freopen("E:\\Codes\\out.txt", "w", stdout);
	#endif
	cin>>t;			
	genreqd();
	while(t--)
	{
		for(i=0;i<9;i++)
			cin>>orig[i];
		if(orig==reqd)
			cout<<"The puzzle is already in solved state"<<endl;
		else
		{
			ll ans=bfs(orig);
			if(ans==-1)
				cout<<"Unsolvable State"<<endl;
		}  
	}
	return 0;
}