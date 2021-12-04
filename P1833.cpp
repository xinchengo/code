#include<iostream>
using namespace std;
int hs, ms, he, me;
int n, t;
int f[1007];
struct cb
{
	int t, c, p;
}a[10007];
int main()
{
	scanf("%d:%d %d:%d %d",&hs, &ms, &he, &me, &n);
	t = (he - hs) * 60 + (me - ms);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&a[i].t,&a[i].c,&a[i].p);
	for(int i=1;i<=n;i++)
	{
		if(a[i].p==0)
			for(int c=a[i].t;c<=t;c++)
				f[c] = max(f[c-a[i].t]+a[i].c, f[c]);
		else
			for(int k=1;k<=a[i].p;k++)
			for(int c=t;c>=k*a[i].t;c--)
				f[c] = max(f[c-a[i].t]+a[i].c, f[c]);
	}
	printf("%d\n", f[t]);
}
