string minWindow(string s, string t)
{
    unordered_map<char, int> letterCnt;
    for (int i = 0; i < t.length(); i++)
        letterCnt[t[i]]++;
    int minLength = INT_MAX, minStart = -1;
    int left = 0, matchCnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (--letterCnt[s[i]] >= 0)
            matchCnt++;
        while (matchCnt == t.length())
        {
            if (i - left + 1 < minLength)
            {
                minLength = i - left + 1;
                minStart = left;
            }
            if (++letterCnt[s[left]] > 0)
                matchCnt--;
            left++;
        }
    }
    return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
}