#include <iostream>
using namespace std;
int q;
int u, v;
void solve()
{
    scanf("%d %d", &u, &v);
    if (v < u)
    {
        puts("NO");
        return;
    }
    int ucnt = 0, vcnt = 0;
    for (int i = 0; i < 30; i++)
    {
        ucnt += (u >> i) & 1;
        vcnt += (v >> i) & 1;
        if (vcnt > ucnt)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main()
{
    scanf("%d", &q);
    while (q--)
        solve();
}