#include <cstring>
#include <iostream>
using namespace std;
int num[4];
int a[8001];
void mul1()
{
    for (int i = 7999; i >= 0; i--)
        a[i + 1] += a[i];
}
void mul2()
{
    for (int i = 7998; i >= 0; i--)
        a[i + 2] += a[i];
}
void mul5()
{
    for (int i = 7995; i >= 0; i--)
        a[i + 5] += a[i];
}
int main()
{
    cin >> num[1] >> num[2] >> num[3];
    while (!(num[1] == 0 && num[2] == 0 && num[3] == 0))
    {
        memset(a, 0, sizeof(a));
        a[0] = 1;
        for (int i = 1; i <= num[1]; i++)
            mul1();
        for (int i = 1; i <= num[2]; i++)
            mul2();
        for (int i = 1; i <= num[3]; i++)
            mul5();
        for (int i = 0; i <= 8000; i++)
            if (a[i] == 0)
            {
                cout << i << endl;
                break;
            }
        cin >> num[1] >> num[2] >> num[3];
    }
}
