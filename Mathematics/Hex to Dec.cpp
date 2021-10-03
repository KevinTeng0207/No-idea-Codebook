int HextoDec(string num) //16 to 10
{
    int base = 1;
    int temp = 0;
    for (int i = num.length() - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            temp += (num[i] - 48) * base;
            base = base * 16;
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            temp += (num[i] - 55) * base;
            base = base * 16;
        }
    }
    return temp;
}
void DecToHex(int p) //10 to 16
{
    char *l = new (char);
    sprintf(l, "%X", p);
    //int l_intResult = stoi(l);
    cout << l << "\n";
    //return l_intResult;
}