long long merge(vector<int> &P, int left, int mid, int right)
{
	int *tmp = new int[right - left + 1];
	long long sum = 0;

	int iLeft = left;
	int iRight = mid + 1;
	int iMerge = 0;

	// the middle reverse numbers
	while (iLeft <= mid && iRight <= right)
	{
		if (P[iLeft] <= P[iRight])
		{
			tmp[iMerge++] = P[iLeft++];
		}
		else
		{
			tmp[iMerge++] = P[iRight++];
			sum += mid - iLeft + 1; // key point
		}
	}
	while (iLeft <= mid)
		tmp[iMerge++] = P[iLeft++];

	while (iRight <= right)
		tmp[iMerge++] = P[iRight++];

	for (int i = left; i <= right; ++i)
		P[i] = tmp[i - left];

	delete[] tmp;
	return sum;
}

long long mergesort(vector<int> &P, int left, int right)
{
	long long sum = 0;
	// left = 0, right = P.size() - 1
	if (left < right)
	{
		int mid = (left + right) / 2;
		sum = mergesort(P, left, mid);
		sum += mergesort(P, mid + 1, right);
		sum += merge(P, left, mid, right);
	}
	return sum; // 回傳為 swap 次數
}