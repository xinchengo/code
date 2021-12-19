#include<iostream>
#include<cmath>
#include<cassert>
#include<valarray>
using namespace std;
int n, c;
double a[12][11];
valarray<double> g[12];
int main()
{
    cin >> n;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    for(int i=1;i<=n;i++)
        g[i].resize(n+2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            g[i][j] = 2.0*a[i+1][j] - 2.0*a[i][j];
            g[i][n+1] += a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j];
        }
    for(int i=1;i<=n;i++)
    {
        for(c=i;c<=n&&abs(g[c][i])<1e-6;c++);
        swap(g[i], g[c]);
        for(int j=i+1;j<=n;j++)
            g[j]-=g[i]*(g[j][i]/g[i][i]);
    }
    for(int i=n;i>=1;i--)
        for(int j=i-1;j>=1;j--)
            g[j]-=g[i]*(g[j][i]/g[i][i]);
    cout.precision(3);
    cout.setf(ios::fixed);
    for(int i=1;i<=n;i++)
        cout << g[i][n+1]/g[i][i] << ' ';
    cout << endl;
}