#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int l, r;
struct node
{
    node *ch[2];
    int val, siz;
    bool tag;
    node(int v) : ch{0, 0}, val(v), siz(1), tag(0){};
    void pushup()
    {
        siz = (ch[0] ? ch[0]->siz : 0) + 1 + (ch[1] ? ch[1]->siz : 0);
    }
    void pushdown()
    {
        if (tag)
        {
            if (ch[0])
                ch[0]->tag ^= 1;
            if (ch[1])
                ch[1]->tag ^= 1;
            swap(ch[0], ch[1]);
            tag = 0;
        }
    }
    int chsiz(int x)
    {
        return ch[x] ? ch[x]->siz : 0;
    }
    int find(int v)
    {
        return (v == chsiz(0) + 1) ? -1 : v > chsiz(0);
    }
} *root = 0;
void rotate(node *&cur, bool type)
{
    node *rt = cur->ch[type];
    cur->ch[type] = rt->ch[!type], rt->ch[!type] = cur, cur = rt;
    cur->ch[!type]->pushup(), cur->pushup();
}
void splay(node *&cur, int k)
{
    cur->pushdown();
    int type1 = cur->find(k);
    if (type1 == -1 || cur->ch[type1] == 0)
        return;
    cur->ch[type1]->pushdown();
    int type2 = cur->ch[type1]->find(k - (type1 ? (cur->chsiz(0) + 1) : 0));
    if (type2 == -1 || cur->ch[type1]->ch[type2] == 0)
    {
        rotate(cur, type1);
        return;
    }
    splay(cur->ch[type1]->ch[type2],
          k - (type1 ? (cur->chsiz(0) + 1) : 0) - (type2 ? (cur->ch[type1]->chsiz(0) + 1) : 0));
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
    cur = new node(mid);
    build(cur->ch[0], l, mid - 1);
    build(cur->ch[1], mid + 1, r);
    cur->pushup();
}
void print(node *cur)
{
    if (cur == 0)
        return;
    cur->pushdown();
    print(cur->ch[0]);
    if (cur->val > 0 && cur->val <= n)
        cout << cur->val << ' ';
    print(cur->ch[1]);
}
void reverse(int l, int r)
{
    splay(root, l);
    splay(root->ch[1], r - l + 2);
    root->ch[1]->ch[0]->tag ^= 1;
}
int main()
{
    cin >> n >> m;
    build(root, 0, n + 1);
    while (m--)
    {
        cin >> l >> r;
        reverse(l, r);
    }
    print(root);
    cout << endl;
}