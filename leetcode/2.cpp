char *convert(char *s, int numRows)
{
    int n = strlen(s);
    if (numRows == 1)
        return s;
    char *res = (char *)malloc(sizeof(char) * (n + 1));
    int k = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j % (2 * numRows - 2) == i ||
                j % (2 * numRows - 2) == 2 * numRows - 2 - i)
            {
                res[k++] = s[j];
            }
        }
    }
    res[k] = '\0';
    return res;
}
