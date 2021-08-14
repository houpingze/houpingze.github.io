#include <cstdio> 
#include <algorithm>
using namespace std;

double a[1005],b[1005];
int n,k;

void inp()
{
	int i;
//	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%lf",&b[i]);
}

int check(double G)
{
	double d[1005],ans=0;
	int i;
	
	for(i=1;i<=n;i++) d[i]=a[i]-G*b[i];
	sort(d+1,d+1+n);
	for(i=k+1;i<=n;i++) ans+=d[i];
	
//	printf("Check %lf=%lf\n",G,ans);
	
	return ans>=0;
}

void calc()
{
	double l=0,r=1,mid;
	while(r-l>0.000001)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",int(l*100+0.5));
}

void work()
{
	inp();
	calc();
}

int main(void)
{
	while(scanf("%d%d",&n,&k),n||k)
		work();
	return 0;
}