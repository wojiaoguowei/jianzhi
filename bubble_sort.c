#include <stdio.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

//设置一个标志，如果这一趟发生了交换，则为true，否则为false。明显如果有一趟没有发生交换，说明排序已经完成
void BubbleSort2(int a[], int n)
{
	int j, k;
	bool flag;
	
	k = n;
	flag = true;
	while (flag)
	{
		flag = false;
		for (j = 1; j < k; j++)
			if (a[j - 1] > a[j])
			{
				Swap(a[j - 1], a[j]);
				flag = true;
			}
		k--;
	}
}

//如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已经有序了，记录下这位置，第二次只要从数组头部遍历到这个位置就可以了。
oid BubbleSort3(int a[], int n)
{
	int j, k;
	int flag;
	
	flag = n;
	while (flag > 0)
	{
		k = flag;
		flag = 0;
		for (j = 1; j < k; j++)
			if (a[j - 1] > a[j])
			{
				Swap(a[j - 1], a[j]);
				flag = j;
			}
	}
}

