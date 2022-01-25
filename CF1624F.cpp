#include <iostream>
using namespace std;
int n;
int lim = 1, jmp, lval, val = 0;
int main()
{
    cin >> n;
    while (lim < n)
        lim <<= 1;
    lim >>= 1;
    for (int i = lim; i >= 1; i >>= 1)
    {
        if (val == lval)
            jmp = 0;
        else
            jmp = 1;
        cout << "+ " << (jmp ? (n - i) : i) << endl;
        lval = val;
        cin >> val;
    }
    if (val == lval)
        cout << "! " << (val + 1) * n - 1 << endl;
    else
        cout << "! " << (val)*n << endl;
}
