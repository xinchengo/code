#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 2e5;
const int maxk = 2e1;
int n;
double mxscore = 0.0;
int filcnt, mcnt;
int t_when_max;
int c_when_max[maxk + 1];
int v[maxn + 1];
struct student
{
    int cop;
    int exp;
} a[maxn + 1];
struct msg
{
    int ror;
    int ord;
    int con;
    bool operator<(const msg &b) const
    {
        return con > b.con;
    }
} m[maxn + 1];
bool idcmp(msg &a, msg &b)
{
    return a.ord < b.ord;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].exp >> a[i].cop;
        if (!v[a[i].exp])
            v[a[i].exp] = ++filcnt, m[filcnt].ord = filcnt, m[filcnt].ror = a[i].exp;
        a[i].exp = v[a[i].exp];
    }
    for (int t = 1; t <= min(filcnt, 20); t++)
    {
        double score = 0.0;
        for (int i = 1; i <= filcnt; i++)
            m[i].con = 0;
        sort(m + 1, m + filcnt + 1, idcmp);
        for (int i = 1; i <= n; i++)
        {
            if (a[i].cop >= t)
                m[a[i].exp].con += t;
            else
                m[a[i].exp].con += a[i].cop;
        }
        sort(m + 1, m + filcnt + 1);
        for (int i = 1; i <= t; i++)
            score += m[i].con;
        score = score / t;
        if (score > mxscore - 1e-4)
        {
            mxscore = score;
            t_when_max = t;
            for (int i = 1; i <= t; i++)
                c_when_max[i] = m[i].ror;
        }
    }
    cout << t_when_max << endl;
    for (int i = 1; i <= t_when_max; i++)
        cout << c_when_max[i] << ' ';
    cout << endl;
    return 0;
}