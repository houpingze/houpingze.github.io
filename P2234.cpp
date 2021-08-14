/*houpingze \CCF/ \CCF/ \CCF/ \CCF/ \CCF/ */
/*
Note:

*/
#include<bits/stdc++.h>
#define reg register int
#define INF (1<<30)
#define pb push_back
#define vc vector
#define fst first
#define scd second
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#include<random>
using namespace std;
int read(){
	int res=0,fs=1; char c=getchar();
	while(!(c>='0' && c<='9')){ if(c=='-')fs=-1; c=getchar(); }
	while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
	return res*fs;
}
void print(int x){
    if(x<0) { putchar('-'); x=-x;}
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,cnt,m,a[5010],ans,tmp,k;
typedef pair<int,int> P; 
vector<int>v;
signed main() {
//	ios::sync_with_stdio(false);
	cin>>n; 
//	int XOR;
	int ans=0;
	v.pb(-INF);
	rep(i,1,n){//??????????????????????????
		int x;
		cin>>x;
		if(i==1) ans+=x;
		else {
			int n1=*--lower_bound(v.begin(),v.end(),x);
			int n2=*lower_bound(v.begin(),v.end(),x);
			if(n1==-INF) ans+=abs(x-n2);
			else ans+=min(abs(x-n1),abs(x-n2));	
		}
//		insert(x);
		v.insert(upper_bound(v.begin(),v.end(),x),x);
        // cout<<(*lower_bound(v.begin(),v.end(),x));
	}
	cout<<ans;
    return 0;
}
