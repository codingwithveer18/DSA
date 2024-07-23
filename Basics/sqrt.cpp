#include <iostream>
using namespace std;

double sqrt(int n)
{
    int s = 0;
    int e = n;
    double mid = s + (e - s) / 2;
    double ans = 0;
    while (s <= e)
    {
        double square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;  
    }
    return ans;
}

double precise(int n, int precise, int tempsol)
{
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precise; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans; 
}
int main()
{
    int n;
    cout << "enter number" << endl;
    cin >> n; 
    int tempsol = sqrt(n);
    cout << "sqrt with preciosion is " << precise(n, 10, tempsol);
    return 0;
}