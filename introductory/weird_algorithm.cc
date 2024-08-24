#include <iostream>

int main()
{
    using namespace std;
    long long x;
    cin >> x;
    for (; x != 1; x = (x & 1) ? x * 3 + 1 : x >> 1)
    {
        cout << x << " ";
    }
    cout << "1\n";
}