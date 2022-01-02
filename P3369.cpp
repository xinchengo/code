#include <iostream>
using namespace std;
struct node
{
    node *ch[2];
    int val, cnt, siz;
    node(int v) : ch{nullptr, nullptr}, val(v), cnt(1), siz(1) {}
    void pushup() { siz = (ch[0] == nullptr ? 0 : ch[0]->siz) + cnt + (ch[1] == nullptr ? 0 : ch[1]->siz); }
    int find(int v) { return v == val ? -1 : v > val; }
    int chsiz(int x) { return ch[x] == nullptr ? 0 : ch[x]->siz; }
} *root = nullptr;
void rotate(node *&cur, bool type)
{
    node *rt = cur->ch[type];
    cur->ch[type] = rt->ch[!type], rt->ch[!type] = cur, cur = rt;
    cur->ch[!type]->pushup(), cur->pushup();
}
void splay(node *&cur, int val)
{
    int type1 = cur->find(val);
    if (type1 == -1 || cur->ch[type1] == nullptr)
        return;
    int type2 = cur->ch[type1]->find(val);
    if (type2 == -1 || cur->ch[type1]->ch[type2] == nullptr)
    {
        rotate(cur, type1);
        return;
    }
    splay(cur->ch[type1]->ch[type2], val);
    if (type1 == type2)
        rotate(cur, type1), rotate(cur, type2);
    else
        rotate(cur->ch[type1], type2), rotate(cur, type1);
}
void _insert(node *&cur, int val)
{
    if (cur == nullptr)
        cur = new node(val);
    else if (val == cur->val)
        cur->cnt++;
    else
        _insert(cur->ch[cur->find(val)], val);
    cur->pushup();
}
void insert(int val)
{
    _insert(root, val);
    splay(root, val);
}
void del(int val)
{
    splay(root, val);
    if(root->cnt > 1)
    {
        root->cnt--;
        return;
    }
    node *cur = root->ch[0];
    if (cur == nullptr)
    {
        cur = root->ch[1], delete root, root = cur;
        return;
    }
    while(cur->ch[1] != nullptr)
        cur = cur->ch[1];
    cur->ch[1] = root->ch[1];
    cur = root->ch[0];
    delete root;
    root = cur;
}
int pre(int val)
{
    insert(val);
    node *cur = root->ch[0];
    if (cur == nullptr)
        return 0;
    while(cur->ch[1] != nullptr)
        cur = cur->ch[1];
    del(val);
    return cur->val;
}
int suc(int val)
{
    insert(val);
    node *cur = root->ch[1];
    if (cur == nullptr)
        return 0;
    while(cur->ch[0] != nullptr)
        cur = cur->ch[0];
    del(val);
    return cur->val;
}
int rankof(int val)
{
    insert(val);
    int rank = root->chsiz(0)+1;
    del(val);
    return rank;
}
int _kth(node *cur, int k)
{
    if (cur == nullptr)
        return 0;
    if (cur->chsiz(0) >= k)
        return _kth(cur->ch[0], k);
    else if (cur->chsiz(0) + cur->cnt >= k)
        return cur->val;
    else
        return _kth(cur->ch[1], k - cur->chsiz(0) - cur->cnt);
}
int kth(int k)
{
    int x = _kth(root, k);
    splay(root, x);
    return x;
}
void print(node *cur)
{
    if (cur == nullptr)
        return;
    cout.put('(');
    print(cur->ch[0]);
    for (int i = 1; i <= cur->cnt; i++)
        cout << cur->val << ' ';
    print(cur->ch[1]);
    cout.put(')');
}
int n, opt, x;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> opt >> x;
        switch (opt)
        {
        case 1:
            insert(x);
            break;
        case 2:
            del(x);
            break;
        case 3:
            cout << rankof(x) << endl;
            break;
        case 4:
            cout << kth(x) << endl;
            break;
        case 5:
            cout << pre(x) << endl;
            break;
        case 6:
            cout << suc(x) << endl;
            break;
        case 7:
            print(root), cout.put('\n');
            break;
        }
    }
}