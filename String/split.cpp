vector<string> mysplit(string s, string d)
{
    int ps = 0, pe, dl = d.length();
    string token;
    vector<string> res;
    while ((pe = s.find(d, ps)) != string::npos)
    {
        token = s.substr(ps, pe - ps);
        ps = pe + dl;
        res.push_back(token);
    }
    res.push_back(s.substr(ps));
    return res;
}