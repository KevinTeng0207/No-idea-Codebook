// manacher
void LPS(string s)
{
  int maxlen = 0, l, r;
  int n = n;
  for (int i = 0; i < n; i++)
  {
    int x = 0;
    while ((s[i - x] == s[i + x]) && (i - x >= 0) && (i + x < n)) //odd length
      x++;
    x--;
    if (2 * x + 1 > maxlen)
    {
      maxlen = 2 * x + 1;
      l = i - x;
      r = i + x;
    }
    x = 0;
    while ((s[i - x] == s[i + 1 + x]) && (i - x >= 0) && (i + 1 + x < n)) //even length
      x++;
    if (2 * x > maxlen)
    {
      maxlen = 2 * x;
      l = i - x + 1;
      r = i + x;
    }
  }
  cout << maxlen << '\n';                // 最後長度
  cout << l + 1 << ' ' << r + 1 << '\n'; //頭到尾
}
