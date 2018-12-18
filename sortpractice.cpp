#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
void Print(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
}

//冒泡排序
void BubleSort(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = 0; j < len - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}




void BubleSort1(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		
		bool flag = false;
		for(int j = 0; j < len - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		
		if(flag == false)
		{
			break;
		}
	}
}

void BubleSort2(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		int end = len - 1 - i;

		for(int j = 0; j < end; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				
				end = j;
			}
		}
	}
}

//一轮比较比较得到最大值和最小值
void BubleSort3(int arr[], int len)
{
	int low = 0;
	int high = len - 1;
	while(low < high)
	{
		//找到最大值
		for(int i = low; i < high; ++i)
		{
			if(arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
		
		high--;
		
		//找到最小值
		for(int j = high; j > low; j--)
		{
			if(arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
		
		low++;
	}
}

//直接插入排序
//思路：先取一个有序的队列，然后将其他数字一个一个和这个有序数列排序
//稳定
//时间复杂度  最好情况：O（n） 最坏情况O（n²）
//空间复杂度 O（n)
void InsertSort(int arr[], int len)
{
    //int a[]={98,76,109,34,67,190,80,12,14,89,1};
    //int k=sizeof(a)/sizeof(a[0]);
    
	/*int j;
    for(int i = 1; i < len; i++)//循环从第2个元素开始
    {
        if(a[i] < a[i-1])
        {
            int temp=a[i];
            for(j = i-1; j >= 0 && a[j] > temp; j--)
            {
                a[j+1] =a [j];
            }
            a[j+1] = temp;//此处就是a[j+1]=temp;
        }
    }*/
	
	//从第二元素开始
	for(int i = 1; i < len; i++)
	{
		//插入元素比前一个小
		if(arr[i] < arr[i - 1])
		{
			//插入元素
			int temp = arr[i];
			int j = -1;
			//向后平移
			for(j = i - 1; j >= 0; j--)
			{
				if(arr[j] > temp)
				{
					arr[j + 1] = arr[j];
				}
				else
				{
					break;
				}
			}	
			
			arr[j + 1] = temp;
		}
	}
}

void BubleSortT(int arr[], int len)
{
	/*for(int i = 0; i < len - 1; ++i)
	{
		for(int j = 0; j < len - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}*/
	
	int low = 0;
	int high = len - 1;
	
	while(low < high)
	{
		for(int i = low; i < high; ++i)
		{
			if(arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}	
		}
		
		high--;
		
		for(int j = high; j > low; j--)
		{
			if(arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}


void InsertSortT(int arr[], int len)
{
	//从第二个元素开始比较
	for(int i = 1; i < len; ++i)
	{
		int temp = arr[i];
		int j = -1;
		for(j = i - 1; j >= 0; --j)
		{
			if(arr[j] > temp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		
		arr[j + 1] = temp;
	}
}


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head == NULL || head->next == NULL)
		{
			return head;
		}
		
		ListNode* p = head;
		ListNode* q = p->next;
		
		head->next = NULL;
		
		while(q)
		{
			ListNode *pTmp = q->next;
			q->next = p;
			p = q;
			q = pTmp;
		}
		
		return p;
        
    }
};


int main()
{
	int arr[] = {8, 6, 4, 7, 9};
	Print(arr, 5);
	InsertSortT(arr, 5);
	Print(arr, 5);
	
	return 1;
}
