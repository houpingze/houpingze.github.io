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
//struct PROBLEM_SOLVER{
//	   int n,m;
//}solver;

//signed main(){
int N=100005;
struct node{
	int l,r,val,key,sz;
}fhq[1500005];
int root;
std::mt19937 rnd(370);
	int lst=0;
int newnode(int val){
	cnt++;
	fhq[cnt].val=val;
	fhq[cnt].key=rnd();
	fhq[cnt].sz=1;
	return cnt;
} 
void upd(int now){
	fhq[now].sz=fhq[fhq[now].l].sz+1+fhq[fhq[now].r].sz;
}
void split(int now,int val,int &x,int &y){
	if(now==0) x=y=0;
	else{
		if(fhq[now].val<=val) x=now,split(fhq[now].r,val,fhq[now].r,y);
		else y=now,split(fhq[now].l,val,x,fhq[now].l);
		upd(now);
	}
}
int merge(int x,int y){
	if(x==0||y==0) return x+y;
	if(fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		upd(x);
		return x;
	}
	
		fhq[y].l=merge(x,fhq[y].l);
		upd(y);
		return y;
}
int x,y,z;
int XOR;
void insert(int val){
	split(root,val,x,y);
	root=merge(merge(x,newnode(val)),y);
//	cout<<root; 
}
int pre(int val){
	split(root,val-1,x,y);
	int now=x;
	while(fhq[now].r) now=fhq[now].r;
	lst=fhq[now].val;
	
	int ret=fhq[now].val;
//	cout<<fhq[now].val<<'\n';
	root=merge(x,y); 
	return ret;
}
int nxt(int val){
	split(root,val,x,y);
	int now=y;
	while(fhq[now].l) now=fhq[now].l;//
	int ret=fhq[now].val;
	root=merge(x,y); 
	return ret;
}
signed main() {
//	ios::sync_with_stdio(false);
	cin>>n; 
//	int XOR;
	int ans=0;
	rep(i,1,n){
		int x;
		cin>>x;
		if(i==1) ans+=x;
		else
		ans+=min(pre(x)-x , x-nxt(x));
		insert(x);
	}
	cout<<ans;
    return 0;
}
