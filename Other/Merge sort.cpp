long long merge(vector<int> &arr, int left, int mid, int right)
{
    int *tmp = new int[right - left + 1];
    long long sum = 0;
    int l = left, r = mid + 1, m = 0;
    while (l <= mid && r <= right)
    {
        if (arr[l] <= arr[r])
            tmp[m++] = arr[l++];
        else
        {
            tmp[m++] = arr[r++];
            sum += mid - l + 1;
        }
    }
    while (l <= mid)
        tmp[m++] = arr[l++];
    while (r <= right)
        tmp[m++] = arr[r++];
    for (int i = left; i <= right; ++i)
        arr[i] = tmp[i - left];
    delete[] tmp;
    return sum;
}
long long mergesort(vector<int> &arr, int left, int right)
{
    long long sum = 0;
    // left = 0, right = P.size() - 1
    if (left < right)
    {
        int mid = (left + right) / 2;
        sum = mergesort(arr, left, mid);
        sum += mergesort(arr, mid + 1, right);
        sum += merge(arr, left, mid, right);
    }
    return sum; // 回傳為 swap 次數
}