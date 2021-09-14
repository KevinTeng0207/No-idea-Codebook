/*input type string or vector*/
for (int i = 0; i < (1 << input.size()); ++i)
{
    string testCase = "";
    for (int j = 0; j < input.size(); ++j)
        if (i & (1 << j))
            testCase += input[j];
}
    