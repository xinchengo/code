#include <iostream>
#define int long long
using namespace std;
class splay_tree
{
  private:
    struct node
    {
        node *ch[2];
        int val, cnt;
        node(int v) : ch{nullptr, nullptr}, val(v), cnt(1)
        {
        }
        int find(int v)
        {
            return v == val ? -1 : v > val;
        }
    } *root = nullptr;
    void rotate(node *&cur, bool type)
    {
        node *rt = cur->ch[type];
        cur->ch[type] = rt->ch[!type], rt->ch[!type] = cur, cur = rt;
    }
    void splay(node *&cur, int v)
    {
        int type1 = cur->find(v);
        if (type1 == -1 || cur->ch[type1] == nullptr)
            return;
        int type2 = cur->ch[type1]->find(v);
        if (type2 == -1 || cur->ch[type1]->ch[type2] == nullptr)
        {
            rotate(cur, type1);
            return;
        }
        splay(cur->ch[type1]->ch[type2], v);
        if (type1 == type2)
            rotate(cur, type1), rotate(cur, type2);
        else
            rotate(cur->ch[type1], type2), rotate(cur, type1);
    }
    void _insert(node *&cur, int v)
    {
        if (cur == nullptr)
            cur = new node(v);
        else if (v == cur->val)
            cur->cnt++;
        else
            _insert(cur->ch[cur->find(v)], v);
    }

  public:
    void insert(int v)
    {
        _insert(root, v), splay(root, v);
    }
    void del(int v)
    {
        splay(root, v);
        if (root->cnt > 1)
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
        while (cur->ch[1] != nullptr)
            cur = cur->ch[1];
        cur->ch[1] = root->ch[1];
        cur = root->ch[0], delete root, root = cur;
    }
    int pre(int v)
    {
        insert(v);
        if (root->cnt > 1)
        {
            del(v);
            return root->val;
        }
        node *pre = root->ch[0];
        if (pre != nullptr)
            while (pre->ch[1] != nullptr)
                pre = pre->ch[1];
        del(v);
        return pre == nullptr ? -0x7fffffff : pre->val;
    }
    int nxt(int v)
    {
        insert(v);
        if (root->cnt > 1)
        {
            del(v);
            return root->val;
        }
        node *nxt = root->ch[1];
        if (nxt != nullptr)
            while (nxt->ch[0] != nullptr)
                nxt = nxt->ch[0];
        del(v);
        return nxt == nullptr ? 0x7fffffff : nxt->val;
    }
    bool empty()
    {
        return root == nullptr;
    }
} pets, customers, test_tree;
int n, ans, opt, x;
signed main()
{
    cin >> n;
    while (n--)
    {
        cin >> opt >> x;
        if (opt == 0)
        {
            if (!customers.empty())
            {
                int nxt = customers.nxt(x), pre = customers.pre(x);
                if (pre == -2147483647)
                    customers.del(nxt), ans += nxt - x;
                else if (nxt == 2147483647)
                    customers.del(pre), ans += x - pre;
                else if (nxt - x >= x - pre)
                    customers.del(pre), ans += x - pre;
                else
                    customers.del(nxt), ans += nxt - x;
            }
            else
                pets.insert(x);
        }
        else
        {
            if (pets.empty())
                customers.insert(x);
            else
            {
                int nxt = pets.nxt(x), pre = pets.pre(x);
                if (pre == -2147483647)
                    pets.del(nxt), ans += nxt - x;
                else if (nxt == 2147483647)
                    pets.del(pre), ans += x - pre;
                else if (nxt - x >= x - pre)
                    pets.del(pre), ans += x - pre;
                else
                    pets.del(nxt), ans += nxt - x;
            }
        }
        ans %= 1000000;
    }
    cout << ans << endl;
}