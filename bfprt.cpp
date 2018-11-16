#include <iostream>
#include <algorithm>

using namespace std;

int InsertSort(int array[], int left, int right);
int GetPivotIndex(int array[], int left, int right);
int Partition(int array[], int left, int right, int pivot_index);
int BFPRT(int array[], int left, int right, int k);

int main()
{
    int k = 8; // 1 <= k <= array.size
    int array[20] = { 11,9,10,1,13,8,15,0,16,2,17,5,14,3,6,18,12,7,19,4 };

    cout << "原数组：";
    for (int i = 0; i < 20; i++)
        cout << array[i] << " ";
    cout << endl;

    // 因为是以 k 为划分，所以还可以求出第 k 小值
    cout << "第 " << k << " 小值为：" << array[BFPRT(array, 0, 19, k)] << endl;

    cout << "变换后的数组：";
    for (int i = 0; i < 20; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}

/**
 * 对数组 array[left, right] 进行插入排序，并返回 [left, right]
 * 的中位数。
 */
int InsertSort(int array[], int left, int right)
{
    int temp;
    int j;

    for (int i = left + 1; i <= right; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= left && array[j] > temp)#include <iostream>
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

            array[j + 1] = array[j--];
        array[j + 1] = temp;
    }

    return ((right - left) >> 1) + left;
}

/**
 * 数组 array[left, right] 每五个元素作为一组，并计算每组的中位数，
 * 最后返回这些中位数的中位数下标（即主元下标）。
 *
 * @attention 末尾返回语句最后一个参数多加一个 1 的作用其实就是向上取整的意思，
 * 这样可以始终保持 k 大于 0。
 */
int GetPivotIndex(int array[], int left, int right)
{
    if (right - left < 5)
        return InsertSort(array, left, right);

    int sub_right = left - 1;

    // 每五个作为一组，求出中位数，并把这些中位数全部依次移动到数组左边
    for (int i = left; i + 4 <= right; i += 5)
    {
        int index = InsertSort(array, i, i + 4);
        swap(array[++sub_right], array[index]);
    }

    // 利用 BFPRT 得到这些中位数的中位数下标（即主元下标）
    return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

/**
 * 利用主元下标 pivot_index 进行对数组 array[left, right] 划分，并返回
 * 划分后的分界线下标。
 */
int Partition(int array[], int left, int right, int pivot_index)
{
    swap(array[pivot_index], array[right]); // 把主元放置于末尾

    int partition_index = left; // 跟踪划分的分界线
    for (int i = left; i < right; i++)
    {
        if (array[i] < array[right])
        {
            swap(array[partition_index++], array[i]); // 比主元小的都放在左侧
        }
    }

    swap(array[partition_index], array[right]); // 最后把主元换回来

    return partition_index;
}

/**
 * 返回数组 array[left, right] 的第 k 小数的下标
 */
int BFPRT(int array[], int left, int right, int k)
{
    int pivot_index = GetPivotIndex(array, left, right); // 得到中位数的中位数下标（即主元下标）
    int partition_index = Partition(array, left, right, pivot_index); // 进行划分，返回划分边界
    int num = partition_index - left + 1;

    if (num == k)
        return partition_index;
    else if (num > k)
        return BFPRT(array, left, partition_index - 1, k);
    else
        return BFPRT(array, partition_index + 1, right, k - num);
}
