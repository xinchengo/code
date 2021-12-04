#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, f[3][3], i, j, ni, nj, p;
map<int, int> v;
queue<int> q;
inline int encode()
{
    return f[2][2] + 10 * f[2][1] + 100 * f[2][0] + 1000 * f[1][2] + 10000 * f[1][1] + 100000 * f[1][0] +
           1000000 * f[0][2] + 10000000 * f[0][1] + 100000000 * f[0][0];
}
inline void decode(int n)
{
    f[2][2] = n % 10, f[2][1] = (n /= 10) % 10, f[2][0] = (n /= 10) % 10, f[1][2] = (n /= 10) % 10,
    f[1][1] = (n /= 10) % 10, f[1][0] = (n /= 10) % 10, f[0][2] = (n /= 10) % 10, f[0][1] = (n /= 10) % 10,
    f[0][0] = (n /= 10) % 10;
}
int main()
{
    cin >> n;
    q.push(n);
    v[n] = 0;
    while (q.size())
    {
        decode(q.front());
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (!f[i][j])
                    goto lab;
    lab:
        for (int p = 0; p < 4; p++)
        {
            if (i + dx[p] + 1 && j + dy[p] + 1 && i + dx[p] < 3 && j + dy[p] < 3)
            {
                swap(f[i][j], f[i + dx[p]][j + dy[p]]);
                n = encode();
                if (!v.count(n))
                    v[n] = v[q.front()] + 1, q.push(n);
                swap(f[i][j], f[i + dx[p]][j + dy[p]]);
            }
        }
        q.pop();
    }
    cout << v[123804765] << endl;
}
