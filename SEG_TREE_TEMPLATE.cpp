#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ff first
#define ss second
#define present(c, x) (c.find(x) != c.end())
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ff first
#define ss second
#define present(c, x) (c.find(x) != c.end())
#define ull unsigned long long
#define sz(a) (int)(a).size()
#define ld long double 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repin(i,a,b) for(int i=a;i>=b;i--)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define PI 3.1415926535
#define mxe max_element
#define mne min_element
#define all(x) x.begin(),x.end()
#define nl "\n"
#define con continue
#define pii pair<int,int> 
#define pll pair<long long int,long long int> 


//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//
//using namespace std;
//using namespace __gnu_pbds;
//
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 // __builtin_popcount(n)
//__builtin_popcount = int
//__builtin_popcountl = long int
//__builtin_popcountll = long long
//s[i + 1].find(s[i]) == string::npos
//s.find(string) s.rfind(string)..index return krte hai......kaafi helpful
//const ll INF = 1e18;
 
//const ll mod = 998244353;
//const ll mxN = 1e6+1;

using namespace std;

//int dx[8] = {0,1,1,1,0,-1,-1,-1};
//int dy[8] = {1,1,0,-1,-1,-1,0,1};
ll MOD= 1e9+7;
//THINK TWICE BUT CODE ONCE :)
 // __builtin_popcount(n)
//__builtin_popcount = int
//__builtin_popcountl = long int
//__builtin_popcountll = long long
//s[i + 1].find(s[i]) == string::npos
//s.find(string) s.rfind(string)..index return krte hai......kaafi helpful

//rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1); // rotate right in range [l,r)
            //first        //  middle    //last
            
//THINK TWICE BUT CODE ONCE :)
//MAKE SURE TO CLEAR GLOBAL VARIABLES!!!!
//int need = 0;
//map<int,vector<int>> mp;
struct my_data{
	int open;
	int close;
	int full;
};

class SGTree {
	
public:
	vector<my_data> seg;
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high,string &s) {
		if (low == high) {
			int open = 0;
			int close = 0;
			
			if(s[low]=='(')
			open++ ;
			if(s[low]==')')
			close++; 
			
			seg[low].open = open;
			seg[low].close = close;
			seg[low].full = 0;
			
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);

		seg[ind].full = min(seg[2*ind+1].open,seg[2*ind+2].close);
		seg[ind].open += seg[2*ind+1].open + s[ind]=='(' ;
		seg[ind].close += seg[2*ind+1].close + s[ind]==')' ;
		seg[ind].open += seg[2*ind+1].open + s[ind]=='(';
		seg[ind].close += seg[2*ind+2].close + s[ind]==')';
		
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left, right);
	}
	void update(int ind, int low, int high, int i, ll val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1]*seg[2 * ind + 2] + 1;
	}
};


void solve()
{ 
  string s;
  cin>>s;
  int m;
  cin>>m;

  SGTree *ans = new SGTree(n);
   
  ans->build(0,0,n-1,s);
  
  repi(i,0,m)
  {
  	int l,r;
  	cin>>l>>r;
  	l-- ;
  	r-- ;
  	
  	int final_ans = ans->query(0,0,n-1,l,r);
  	
  	cout<<final_ans<<nl;
  }
  
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int testcase;
  //cin>>testcase;
  testcase=1;
  
  //testcase*=2;

    while(testcase--)
    {
    	//cout<<" "<<nl;
    	solve() ;
	}
 
return 0;
}
