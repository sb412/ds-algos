bool check(int mid, VV a)
{
    VV pre(n + 1, V(m + 1)); //1 based indexing
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (a[i][j] >= mid) a[i][j] = 1;
            else a[i][j] = 0;
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + a[i][j];
        }
    }
    rep(i, mid, n + 1) // from mid to n (here mid*mid represents the size of sq matrix)
    {
        rep(j, mid, m + 1)
        {
            int sum = pre[i][j] - pre[i][j - mid] - pre[i - mid][j] + pre[i - mid][j - mid];
            if (sum == mid * mid) return true;
        }
    }
    return false;
}
