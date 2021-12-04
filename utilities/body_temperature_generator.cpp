#include<iomanip>
#include<iostream>
#include<random>
using namespace std;
const double average = 36.5;
const double stdv = 0.3;
const int t=100;
int main()
{
    default_random_engine e;
    normal_distribution<double> n(average,stdv);
    while(1)
    {
        for(int i=1;i<=t;)
        {
            double genv = n(e);
            if(35.99 <= genv && genv <= 37.00)
            {
                cout << setiosflags(ios::fixed) << setprecision(1) << genv << '\n';
                i++;
            }
        }
        fflush(stdout);
        cin.get();
    }
}