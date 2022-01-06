#include <iostream>
using namespace std;
long long a[100007], k;
int n, m, o, x, y;
struct node
{
    node *ch[2];
    long long sum, val, lzy;
    int siz;
    node(long long v) : ch{nullptr, nullptr}, sum(v), val(v), siz(1), lzy(0){};
    bool exist(int x)
    {
        return ch[x] != nullptr;
    }
    void pushup()
    {
        sum = val, siz = 1;
        if (exist(0))
            sum += ch[0]->sum, siz += ch[0]->siz;
        if (exist(1))
            sum += ch[1]->sum, siz += ch[1]->siz;
    }
    void pushdown()
    {
        if (lzy != 0)
        {
            if (exist(0))
            {
                ch[0]->lzy += lzy;
                ch[0]->sum += ch[0]->siz * lzy;
                ch[0]->val += lzy;
            }
            if (exist(1))
            {
                ch[1]->lzy += lzy;
                ch[1]->sum += ch[1]->siz * lzy;
                ch[1]->val += lzy;
            }
            lzy = 0;
        }
    }
    int find_kth(int k)
    {
        int lsiz = 0;
        if (exist(0))
            lsiz = ch[0]->siz;
        if (k == lsiz + 1)
            return -1;
        else
            return k > lsiz;
    }
} *root = nullptr;
void rotate(node *&cur, bool type)
{
    node *rt = cur->ch[type];
    cur->ch[type] = rt->ch[!type], rt->ch[!type] = cur, cur = rt;
    cur->ch[!type]->pushup(), cur->pushup();
}
void splay_kth(node *&cur, int k)
{
    cur->pushdown();
    int type1 = cur->find_kth(k);
    if (type1 == -1 || !cur->exist(type1))
        return;
    cur->ch[type1]->pushdown();
    int type2 = cur->ch[type1]->find_kth(k - (type1 ? ((cur->exist(0) ? cur->ch[0]->siz : 0) + 1) : 0));
    if (type2 == -1 || !cur->ch[type1]->exist(type2))
    {
        rotate(cur, type1);
        return;
    }
    splay_kth(cur->ch[type1]->ch[type2],
              k - (type1 ? ((cur->exist(0) ? cur->ch[0]->siz : 0) + 1) : 0) -
                  (type2 ? ((cur->ch[type1]->exist(0) ? cur->ch[type1]->ch[0]->siz : 0) + 1) : 0));
    if (type1 == type2)
        rotate(cur, type1), rotate(cur, type2);
    else
        rotate(cur->ch[type1], type2), rotate(cur, type1);
}
void build(node *&cur, int l, int r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    cur = new node(a[mid]);
    build(cur->ch[0], l, mid - 1);
    build(cur->ch[1], mid + 1, r);
    cur->pushup();
}
void add(int l, int r, long long k)
{
    splay_kth(root, l - 1);
    root->pushdown();
    splay_kth(root->ch[1], r - l + 2);
    root->ch[1]->pushdown();
    root->ch[1]->ch[0]->val += k;
    root->ch[1]->ch[0]->sum += root->ch[1]->ch[0]->siz * k;
    root->ch[1]->ch[0]->lzy += k;
}
long long ask(int l, int r)
{
    splay_kth(root, l - 1);
    splay_kth(root->ch[1], r - l + 2);
    return root->ch[1]->ch[0]->sum;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(root, 0, n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> o >> x >> y;
        if (o == 1)
            cin >> k, add(x + 1, y + 1, k);
        else
            cout << ask(x + 1, y + 1) << endl;
    }
}