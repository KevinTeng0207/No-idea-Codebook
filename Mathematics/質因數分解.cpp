void cal(int in)
{
    for (long long x = 2; x <= in; x++)
    {
        while (in % x == 0)
        {
            cout << x << "*";
            in /= x;
        }
    }
}