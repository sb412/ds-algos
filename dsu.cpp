#include<bits/stdc++.h>
#define nl "\n"
#define repi(i,a,b) for(int i=a;i<b;i++)
using namespace std;
 
int parent[100001];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

//{
//	parent[a] += parent[b];		//adding size of set b to set a
//	parent[b] = a;				//making a , parent of new set
//}
 
long long int MOD = 1e9 + 7;
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
    	 int n;
    	 cin>>n;
    	 
    	 int a[n];
    	 int b[n];
    	 int d[n];
    	 vector<int> vis(100001,0);
//    	 repi(i,1,n+1)
//    	 {
//    	 	make_set(i);
//		 }
    	 repi(i,0,n)
    	 {
    	 	cin>>a[i];
    	 	//vis[a[i]]=1;
		 }
    	 
    	 
    	 repi(i,0,n)
    	 {
    	 	cin>>b[i];
    	 	//vis[b[i]]=1;
		 }
    	 
    	 repi(i,0,n)
    	 {
    	 	cin>>d[i];
    	    if(d[i]>0)
    	    {
    	    	vis[a[i]]=1;
    	    	vis[b[i]]=1;
			}
			
		 }
		
		repi(i,0,n)
		{
			if(d[i]==0)
			{
				if(vis[a[i]]==1 || vis[b[i]]==1)
				{
					d[i]=1;
				}
			}
		 }
		 
		 repi(i,0,n)
		 {
		 	if(d[i]==0 && !vis[a[i]] && !vis[b[i]])
		 	{
		 		union_sets(a[i],b[i]);
		 		vis[a[i]]=1;
		 		vis[b[i]]=1;
			 }
		 }
		 int cnt = 0 ;
		 for(int i=1;i<=n;++i)
		 {
		 	
		 	if(parent[i]==i)
		 	cnt++ ;
		 }
		 
		 long long int ans = 1;
		 while(cnt)
		 {
		 	ans=(ans*2*1ll)%MOD;
		 	cnt-- ;
		 }
		 cout << ans <<nl;
	}
}
