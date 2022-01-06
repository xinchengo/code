#include<iostream>
using namespace std;
int a, b, y1, y2, x1, x2;
int main()
{
    cout << "? 1 1000000000" << endl;
    cin >> a;
    cout << "? 1000000000 1000000000" << endl;
    cin >> b;
    cout << "? " << (a-b+1000000001)/2 << " 1" <<  endl;
    cin >> y1, y1++;
    cout << "? " << (a-b+1000000001)/2 << " 1000000000" << endl;
    cin >> y2, y2 = 1000000000 - y2;
    cout << "? 1 " << (y1+y2)/2 << endl;
    cin >> x1, x1++;
    x2 = a - b + 1000000001 - x1;
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}