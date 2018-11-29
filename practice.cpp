void swap(int &n1, int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

/*
	int i 起始下标
	int N 从i开始的元素个数
*/
void ELementDown(int A[], int i, int N)
{
	for(int index = 2 * i + 1; index < N; index = 2 * index + 1)
	{
		//child=N-1，即child是最大下标，只有左子树
		//index左子节点序号 n - 2 右子节点最后一个n - 1
		if(index < N - 1 && A[index] > A[index + 1])
		{
			index++;
		}
		
		if(A[i] > A[index])
		{
			int tmp = A[i];
			A[i] = A[index];
			A[index] = tmp;
			
			
			//交换后继续比较
			i = index;
		}
		else
		{
			break;
		}
	}
}

//堆排序
void HeapSort(int A[], int N)
{
	//N个节点，最后一个非叶子节点编号=(N-2)/2
	//步骤一：创建小根堆
	for(int i = (N - 2) / 2; i >= 0; --i)
	{
		ELementDown(A, i, N);
	}
	
	//步骤二：调整小根堆
	for(int i = N - 1; i > 0; i--)
	{
		swap(A[0], A[i]);
		ELementDown(A, 0,i);		
	}
}

void GetLastSmallNum(int A[], int N)
{
	for(int i = N - 1; i > 0; i--)
	{
		swap(A[0], A[i]);
		HeapSort(A, i);		
	}
	

}
#include<stdio.h>
int main()
{
	int A[6] = {4,5,3,2,6,1};
	//HeapSort(A, 6);
	
	//N个节点，最后一个非叶子节点编号=(N-2)/2
	//步骤一：创建小根堆
	for(int i = (6 - 2) / 2; i >= 0; --i)
	{
		ELementDown(A, i, 6);
	}
	
	int tmp;
	scanf("%d",&tmp);
	
	if(tmp > A[0])
	{
		A[0] = tmp;
		
		//调整小根堆
		ELementDown(A, 0, 6);
	}
	
	return 1;
}
