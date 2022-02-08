#include <iostream>
#define c3(x) ((x) * ((x)-1) * ((x)-2) / 6)
#define c2(x) ((x) * ((x)-1) / 2)
#define c1(x) (x)
using namespace std;
long long n, i;
long double p;
int main()
{
    cin >> n >> p;
    for (i = 0; 1.0l * (c3(i) * 2LL + c2(i) * c1(n - i) * 2LL + c1(i) * c2(n - i)) / (2LL * c3(n)) < p - 1e-6; i++)
        ;
    cout << i << endl;
}