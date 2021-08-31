string s = "";
long long int DFS(int le, int ri) // (0, string final index)
{
    int c = 0;
    for (int i = ri; i >= le; i--)
    {
        if (s[i] == ')')
            c++;
        if (s[i] == '(')
            c--;
        if (s[i] == '+' && c == 0)
            return DFS(le, i - 1) + DFS(i + 1, ri);
        if (s[i] == '-' && c == 0)
            return DFS(le, i - 1) - DFS(i + 1, ri);
    }
    for (int i = ri; i >= le; i--)
    {
        if (s[i] == ')')
            c++;
        if (s[i] == '(')
            c--;
        if (s[i] == '*' && c == 0)
            return DFS(le, i - 1) * DFS(i + 1, ri);
        if (s[i] == '/' && c == 0)
            return DFS(le, i - 1) / DFS(i + 1, ri);
        if (s[i] == '%' && c == 0)
            return DFS(le, i - 1) % DFS(i + 1, ri);
    }
    if ((s[le] == '(') && (s[ri] == ')'))
        return DFS(le + 1, ri - 1); //去除刮號
    if (s[le] == ' ' && s[ri] == ' ')
        return DFS(le + 1, ri - 1); //去除左右兩邊空格
    if (s[le] == ' ')
        return DFS(le + 1, ri); //去除左邊空格
    if (s[ri] == ' ')
        return DFS(le, ri - 1); //去除右邊空格
    long long int num = 0;
    for (int i = le; i <= ri; i++)
        num = num * 10 + s[i] - '0';
    return num;
}