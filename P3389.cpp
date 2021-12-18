#include<iostream>
#include<valarray>
using namespace std;
int n, flag = 1;
valarray<double> a[100];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        a[i].resize(n+1);
        for(int j=0;j<=n;j++)
            cin >> a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        int c = i;
        while(c < n && -1e-6 < a[c][i] && a[c][i] < 1e-6) c++;
        if(c==n){flag = 0; break;}
        swap(a[i],a[c]);
        for(int j=i+1;j<n;j++)
            a[j] -= a[i] * (a[j][i] / a[i][i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(-1e-6 < a[i][i] && a[i][i] < 1e-6){flag = 0; break;}
        for(int j=i-1;j>=0;j--)
            a[j] -= a[i] * (a[j][i] / a[i][i]);
    }
    if(flag == 1)
    for(int i=0;i<n;i++)
        printf("%.2lf\n",a[i][n]/a[i][i]);
    else
        cout << "No Solution" << endl;
}