#include <algorithm>
#include <iostream>
#define nr(x, y)                                                                                                       \
    if (x == nullptr)                                                                                                  \
    return y
using namespace std;
int n, m, t, x, y;
struct node
{
    int val, id;
    node *ch, *sb;
    node(int v, int i) : val(v), id(i), ch(nullptr), sb(nullptr)
    {
    }
} * h[100007];
node *merge(node *a, node *b)
{
    nr(a, b);
    nr(b, a);
    if (make_pair(a->val, a->id) > make_pair(b->val, b->id))
        swap(a, b);
    b->sb = a->ch, a->ch = b;
    return a;
}
node *merges(node *x)
{
    nr(x, x);
    nr(x->sb, x);
    node *a = x->sb, *b = a->sb;
    x->sb = a->sb = nullptr;
    return merge(merge(x, a), merges(b));
}
bool del[100007];
int fa[100007];
int get_fa(int x)
{
    if (x == fa[x])
        return fa[x];
    return fa[x] = get_fa(fa[x]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        h[i] = new node(t, i);
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            if (del[x] || del[y])
                continue;
            int u = get_fa(x), v = get_fa(y);
            if (u != v)
                h[u] = h[v] = merge(h[u], h[v]);
            fa[v] = u;
        }
        else
        {
            cin >> x;
            if (del[x])
            {
                cout << -1 << endl;
                continue;
            }
            x = get_fa(x);
            cout << h[x]->val << endl;
            del[h[x]->id] = true;
            node *ch = h[x]->ch;
            delete h[x];
            h[x] = merges(ch);
        }
    }
}