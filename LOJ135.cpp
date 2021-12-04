#include<iostream>
using namespace std;
int n, m, o, a, b, c, d;
long long x, c1[2049][2049], ci[2049][2049], cj[2049][2049], cij[2049][2049];
void add(long long c[][2049], int x, int y, long long k)
{
    for(int i=x;i<=n;i+=i&-i)
        for(int j=y;j<=n;j+=j&-j)
            c[i][j] += k;
}
long long ask(long long c[][2049], int x, int y)
{
    long long k = 0;
    for(int i=x;i;i-=i&-i)
        for(int j=y;j;j-=j&-j)
            k += c[i][j];
    return k;
}
void radd(int x, int y, long long k)
{
    add(c1, x, y, k);
    add(ci, x, y, k*x);
    add(cj, x, y, k*y);
    add(cij,x, y, k*x*y);
}
long long rask(int x, int y)
{
    return (x+1)*(y+1)*ask( c1, x, y)
        -  (y+1)      *ask( ci, x, y)
        -  (x+1)      *ask( cj, x, y)
        +              ask(cij, x, y);
}
int main()
{
    cin >> n >> m;
    while(cin >> o)
    {
        if(o == 1)
        {
            cin >> a >> b >> c >> d >> x;
            radd(  a, b,  x);
            radd(  a,d+1,-x);
            radd(c+1,  b,-x);
            radd(c+1,d+1, x);
        }
        else
        {
            cin >> a >> b >> c >> d;
            cout << rask(c,d)
                  - rask(c,b-1)
                  - rask(a-1,d)
                  + rask(a-1,b-1) << endl;
        }
    }
}
