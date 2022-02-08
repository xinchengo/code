#include <algorithm>
#include <iostream>
using namespace std;
int n;
pair<int, int> r[100007]; // raw array (value, index)
int a[100007];            // array after discretization
struct node
{
    node *ch[2];
    int val, siz, mval;
    bool tag;
    node(int v) : ch{nullptr, nullptr}, val(v), siz(1), mval(v), tag(false)
    {
    }
    bool exist(int t)
    {
        return ch[t] != nullptr;
    }
    int chsiz(int t)
    {
        return !exist(t) ? 0 : ch[t]->siz;
    }
    int find_by_size(int k)
    {
        return (k == chsiz(0) + 1) ? -1 : (k > chsiz(0));
    }
    int find_min()
    {
        int lval = 0x7fffffff, rval = 0x7fffffff;
        if (exist(0))
            lval = ch[0]->mval;
        if (exist(1))
            rval = ch[1]->mval;
        if (mval < min(lval, rval))
            return -1;
        else if (mval == lval)
            return 0;
        else if (mval == rval)
            return 1;
        perror("Internal Error 1\n");
        exit(2);
    }
    void pushup()
    {
        siz = chsiz(0) + 1 + chsiz(1);
        mval = val;
        if (exist(0))
            mval = min(mval, ch[0]->mval);
        if (exist(1))
            mval = min(mval, ch[1]->mval);
    }
    void pushdown()
    {
        if (tag)
        {
            if (exist(0))
                ch[0]->tag ^= 1;
            if (exist(1))
                ch[1]->tag ^= 1;
            swap(ch[0], ch[1]);
            tag = 0;
        }
    }
} *root = nullptr;
void rotate(node *&cur, bool type)
{
    node *rt = cur->ch[type];
    cur->ch[type] = rt->ch[!type], rt->ch[!type] = cur, cur = rt;
    cur->ch[!type]->pushup(), cur->pushup();
}
void splay_kth(node *&cur, int k) // rotate the k_th element to root
{
    cur->pushdown();
    int type1 = cur->find_by_size(k);
    if (type1 == -1 || !cur->exist(type1))
        return;
    cur->ch[type1]->pushdown();
    int type2 = cur->ch[type1]->find_by_size(k - (type1 ? (cur->chsiz(0) + 1) : 0));
    if (type2 == -1 || !cur->ch[type1]->exist(type2))
    {
        rotate(cur, type1);
        return;
    }
    splay_kth(cur->ch[type1]->ch[type2],
              k - (type1 ? (cur->chsiz(0) + 1) : 0) - (type2 ? (cur->ch[type1]->chsiz(0) + 1) : 0));
    if (type1 == type2)
        rotate(cur, type1), rotate(cur, type2);
    else
        rotate(cur->ch[type1], type2), rotate(cur, type1);
}
void splay_min(node *&cur)
{
    cur->pushdown();
    cur->pushup();
    int type1 = cur->find_min();
    if (type1 == -1 || !cur->exist(type1))
        return;
    cur->ch[type1]->pushdown();
    cur->ch[type1]->pushup();
    int type2 = cur->ch[type1]->find_min();
    if (type2 == -1 || !cur->ch[type1]->exist(type2))
    {
        rotate(cur, type1);
        return;
    }
    splay_min(cur->ch[type1]->ch[type2]);
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
void reverse(int l, int r)
{
    if (l == 1 && r == n)
        root->tag ^= 1;
    else if (l == 1 && r != n)
    {
        splay_kth(root, r + 1);
        root->ch[0]->tag ^= 1;
    }
    else if (l != 1 && r == n)
    {
        splay_kth(root, l - 1);
        root->ch[1]->tag ^= 1;
    }
    else
    {
        splay_kth(root, l - 1);
        splay_kth(root->ch[1], r - l + 2);
        root->ch[1]->ch[0]->tag ^= 1;
    }
}
int get_minpos(int l)
{
    int pos, lval;
    splay_kth(root, l);
    lval = root->val;
    if (l == 1)
    {
        splay_min(root);
        pos = root->chsiz(0) + 1;
        if (root->val < lval)
            return pos;
        else
            return l;
    }
    else
    {
        splay_kth(root, l - 1);
        splay_min(root->ch[1]);
        pos = l + root->ch[1]->chsiz(0);
        if (root->ch[1]->val < lval)
            return pos;
        else
            return l;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i].first, r[i].second = i;
    sort(r + 1, r + n + 1);
    for (int i = 1; i <= n; i++)
        a[r[i].second] = i;
    build(root, 1, n);
    for (int i = 1; i <= n; i++)
    {
        int mp = get_minpos(i);
        cout << mp << ' ';
        if (mp != i)
            reverse(i, mp);
    }
    cout << endl;
}