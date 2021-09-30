void Merge(vector<int> &arr, int front, int mid, int end)
{
    vector<int> LeftSub(arr.begin() + front, arr.begin() + mid + 1);
    vector<int> RightSub(arr.begin() + mid + 1, arr.begin() + end + 1);
    LeftSub.insert(LeftSub.end(), INT_MAX);
    RightSub.insert(RightSub.end(), INT_MAX);
    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++)
    {

        if (LeftSub[idxLeft] <= RightSub[idxRight])
        {
            arr[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else
        {
            arr[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}
void MergeSort(vector<int> &arr, int front, int end)
{
    // front = 0 , end = arr.size() - 1
    if (front < end)
    {
        int mid = (front + end) / 2;
        MergeSort(arr, front, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, front, mid, end);
    }
}