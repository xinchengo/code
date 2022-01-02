#include <iostream>
using namespace std;
struct node
{
    node *ch[2];
    int val, cnt;
    node(int v) : ch{0, 0}, val(v), cnt(1){};
    int find(int v)
    {
        return v == val ? -1 : v > val;
    }
} *root = 0;
void rotate(node *&cur, bool type)
{
    node *rt = cur->ch[type];
    cur->ch[type] = rt->ch[!type], rt->ch[!type] = cur, cur = rt;
}
void splay(node *&cur, int val)
{
    int type1 = cur->find(val);
    if (type1 == -1 || cur->ch[type1] == 0)
        return;
    int type2 = cur->ch[type1]->find(val);
    if (type2 == -1 || cur->ch[type1]->ch[type2] == 0)
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
    if (cur == 0)
        cur = new node(val);
    else if (val == cur->val)
        cur->cnt++;
    else
        _insert(cur->ch[cur->find(val)], val);
}
void insert(int val)
{
    _insert(root, val), splay(root, val);
}
int val(int v)
{
    splay(root, v);
    if (root->cnt > 1)
        return 0;
    node *pre = root->ch[0], *nxt = root->ch[1];
    int ans = 0x7fffffff;
    if (pre)
    {
        while (pre->ch[1])
            pre = pre->ch[1];
        ans = min(ans, root->val - pre->val);
    }
    if (nxt)
    {
        while (nxt->ch[0])
            nxt = nxt->ch[0];
        ans = min(ans, nxt->val - root->val);
    }
    return ans;
}
int n, ans, a;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        insert(a);
        ans += i == 1 ? a : val(a);
    }
    cout << ans << endl;
}