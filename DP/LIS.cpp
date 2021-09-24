void getMaxElementAndPos(vector<int> &LISTbl, vector<int> &LISLen, int tNum, 
    int tlen, int tStart, int &num, int &pos)
{
    int max = numeric_limits<int>::min();
    int maxPos;
    for (int i = tStart; i >= 0; i--)
    {
        if (LISLen[i] == tlen && LISTbl[i] < tNum)
        {
            if (LISTbl[i] > max)
            {
                max = LISTbl[i];
                maxPos = i;
            }
        }
    }
    num = max;
    pos = maxPos;
}
int LIS(vector<int> &LISTbl)
{
    if (LISTbl.size() == 0)
        return 0;
    vector<int> LISLen(LISTbl.size(), 1);
    for (int i = 1; i < LISTbl.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (LISTbl[j] < LISTbl[i])
                LISLen[i] = max(LISLen[i], LISLen[j] + 1);
        }
    }

    int maxlen = *max_element(LISLen.begin(), LISLen.end());
    int num, pos;
    vector<int> buf;
    getMaxElementAndPos(LISTbl, LISLen,
                        numeric_limits<int>::max(),
                        maxlen, LISTbl.size() - 1, num, pos);
    buf.push_back(num);
    for (int len = maxlen - 1; len >= 1; len--)
    {
        int tnum = num;
        int tpos = pos;
        getMaxElementAndPos(LISTbl, LISLen,
                            tnum, len, tpos - 1, num, pos);
        buf.push_back(num);
    }
    reverse(buf.begin(), buf.end());
    for (int k = 0; k < buf.size(); k++) //列印
    {
        if (k == buf.size() - 1)
            cout << buf[k] << endl;
        else
            cout << buf[k] << ",";
    }
    return maxlen;
}