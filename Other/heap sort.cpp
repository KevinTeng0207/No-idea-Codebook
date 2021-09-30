void MaxHeapify(vector<int> &array, int root, int length)
{
    int left = 2 * root,      
        right = 2 * root + 1, 
        largest;              
    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;
    if (right <= length && array[right] > array[largest])
        largest = right;
    if (largest != root)
    {                                       
        swap(array[largest], array[root]);  
        MaxHeapify(array, largest, length); 
    }
}
void HeapSort(vector<int> &array)
{
    array.insert(array.begin(), 0);
    for (int i = (int)array.size() / 2; i >= 1; i--)
        MaxHeapify(array, i, (int)array.size() - 1);
    int size = (int)array.size() - 1;
    for (int i = (int)array.size() - 1; i >= 2; i--)
    {
        swap(array[1], array[i]);
        size--;
        MaxHeapify(array, 1, size);
    }
    array.erase(array.begin());
}