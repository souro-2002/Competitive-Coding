#include <iostream>
using namespace std;
void pattern_num(int range)
{
    for (int i = 1; i <= range; i++)
    {
        for (int j = i; j <= range; j++)
        {
            if (j == i)
            {
                for (int s = 1; s < i; s++)
                {
                    cout << ' ';
                }
            }
            cout << i;
        }
        cout << endl;
    }
}
void pattern_star(int range)
{
    for (int i = 1; i <= range; i++)
    {
        if (i == 1 || i == range)
        {
            for (int j = 1; j <= range; j++)
            {
                cout << '*';
            }
        }
        else
        {
            for (int g = 1; g <= range; g++)
            {
                if (g == 1 || g == range)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }
}
int main()
{
    int range;
    cout << "Enter the range of the pattern = " << endl;
    cin >> range;
    pattern_num(range);
    cout << endl;
    cout << endl;
    pattern_star(range);
    return 0;
}