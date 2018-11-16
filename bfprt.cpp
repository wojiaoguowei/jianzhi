#include <iostream>
using namespace std;

void swap(int *array, int s,int e)
{
    int temp;
    temp = array[s];
    array[s] = array[e];
    array[e] = temp;
}

// BFPRT: 在数组中寻找第 k 小元素（Top k）
/************************************************************************
FindKthSmallest(Array, k)
pivot = some pivot element of the array. 
L = Set of all elements smaller than pivot in Array
R = Set of all elements greater than pivot in Array
if |L| > k FindKthSmalles(L, k)
else if(|L|+1 == k) return pivot
else return FindKthSmallest(R, k-|L|+1)
************************************************************************/

void insertsort(int *array_t, int start, int end)
{
    for (int i = start; i <= end; i++) {
        int inserted_data = array_t[i];
        int j = i;
        for (; j > start && inserted_data < array_t[j - 1]; j--) {
			array_t[j] = array_t[j - 1];
        }
        if (j != i) {
            array_t[j] = inserted_data;        
        }
    }
}

int partition(int *array_t, int low, int high, int pivot_index)
{
    int pivot_value = array_t[pivot_index];
    swap(array_t, low, pivot_index);
    while (low < high) {
        while (low < high && array_t[high] >= pivot_value) {
            high--;
        }
        if (low < high) {
            array_t[low++] = array_t[high];
        }
        while (low < high && array_t[low] <= pivot_value) {
            low++;
        }
        if (low < high) {
            array_t[high--] = array_t[low];
        }
    }
    array_t[low] = pivot_value;
    return low;
}

// 五划分中项：中位数的中位数（the median of medians algorithm）
// Return the kth value
int select(int *array_t, int left, int right, int k)
{
    const int k_group_size = 5;
    int size = right - left + 1;
    if (size <= k_group_size) {
        insertsort(array_t, left, right);
        return array_t[k + left - 1];
    }
    // (right - left) / 2 + left
    const int num_group = (size % k_group_size) > 0 ? (size / k_group_size) + 1 : (size / k_group_size);

    for (int i = 0; i < num_group; i++) {
        int sub_left = left + i * k_group_size;
        int sub_right = sub_left + k_group_size - 1;
        if (sub_right > right) {
            sub_right = right;
        }
        insertsort(array_t, sub_left, sub_right);
        // IMPORTANT !!
        // Place these median in front of array_t, so as to recurse to find the median of median
        int median = sub_left + ((sub_right - sub_left) >> 1);
        swap(array_t, left + i, median);
    }

    // Get the index of median
    int pivot_index = left + ((num_group - 1) >> 1);

    // Recurse to call and place the median on the pivot_index, without care about the median value
    // Because the value of pivot_index must be the median after select function recursive call.
	/*
	 //k = (num_group + 1) >> 1 中位数 防止k=0,所以num_group+1
	//int select(int *array_t, int left, int right, int k)
	{
    const int k_group_size = 5;
    int size = right - left + 1;
    if (size <= k_group_size) {
        insertsort(array_t, left, right);
        return array_t[k + left - 1];				//k + left - 1=(num_group+1)/2 + left -1=num_group/2 + left - 1/2 中位数
    }*/
    select(array_t, left, left + num_group - 1, (num_group + 1) >> 1);
    int mid_index = partition(array_t, left, right, pivot_index);
    int _ith = mid_index - left + 1;
    // _ith_element == array_t[_ith]
    if (k == _ith) {
        return array_t[mid_index];
    } else if (k < _ith) {
        return select(array_t, left, mid_index - 1, k);
    } else {
        return select(array_t, mid_index + 1, right, k - _ith);
    }
}

int main()
{
    int k = 8; // 1 <= k <= array.size
    int array[20] = { 11,9,10,1,13,8,15,0,16,2,17,5,14,3,6,18,12,7,19,4 };

    cout << "原数组：";
    for (int i = 0; i < 20; i++)
        cout << array[i] << " ";
    cout << endl;

    // 因为是以 k 为划分，所以还可以求出第 k 小值
    cout << "第 " << k << " 小值为：" << array[select(array, 0, 19, k)] << endl;

    cout << "变换后的数组：";
    for (int i = 0; i < 20; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
