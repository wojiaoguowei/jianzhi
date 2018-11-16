#include <stdio.h>

/*
copyright@wunaihualuo 
直接插入排序：
    直接插入排序就是从待排序列中选出一个元素，插入到已经有序的元素之中，直到所有的元素都插入到有序序列中所有的元素就全部
有序了。
    通常的做法就是将第一个元素看做是有序的元素（即待排序列的第一个元素看做是有序序列），然后我们将第二个元素和有序序列（即
第一个元素）作比较，按正确的序列插入到序列中去。然后在将第三个元素和前面有序序列（即整个待排序列的前两个元素）作比较，将第
三个插入到前两个元素中去，使得前三个元素有序。以此类推，直到所有的元素都有序。 
*/

void insertSort(int arr[],int len);
void test(int A[], int len)
{
	if(A == NULL || len <= 0)
	{
		return;
	}
		
	for(int i = 1; i < len; i++)
	{
		int tmp = A[i];
		int j;
		for(j = i - 1; j >= 0; j--)
		{
			if(A[j] > tmp)
			{
				A[j + 1] = A[j];
			}
			else
			{
				break;
			}
		}
		
		//比较j位置，数据填充到j+1的空位置
		A[j + 1] = tmp;
	}
}

int main(int argc, char *argv[])
{
    int arr[5]={3,89,72,43,1};
    test(arr,5);
    int i;
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

/*
简单插入排序函数 
*/
void insertSort(int arr[],int len){
    int i;
    int j;
    int temp;  //定义一个临时变量，用于交换数据时存储 
    for(i=1;i<len;i++){  //因为我们要对该待排序列的每一个元素都和前面的已排好序的序列进行插入，所以我们会对序列进行遍历 
        for(j=0;j<i;j++){  //第二层循环主要用于对已排好序的序列进行扫描，和要插入进来的数据进行逐一比较，然后决定插入到哪里 
            if(arr[j]>arr[i]){//从前往后对已排好序的元素和待插入元素进行大小比较，然后直到找到一个元素比被插入元素大，则交换位置 
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}























































