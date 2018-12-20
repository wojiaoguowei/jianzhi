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

//希尔排序
void ShellSort(int ary[], int len)
{
    int i,j;
    int increment = len;//增量
    int key;
    while(increment > 1)//最后在增量为1并且是执行了情况下停止。
    {
        increment = increment/3 + 1;//根据公式
        //printf("increment:%d\n",increment);
        for (i=increment;i<len;i++)//从[0]开始，对相距增量步长的元素集合进行修改。
        {
            key = ary[i];
            //以下和直接插入排序类似。
            j=i-increment;
            while(j >= 0)
            {
                if (key < ary[j] )
                {
                    int temp = ary[j];
                    ary[j] = key;
                    ary[j+increment] = temp;
                }
                j=j-increment;
            }
        }
    }
}




void ShellSortT(int arr[], int len)
{
	int increment = len;
	
	//间隔大于等于1
	do
	{
		increment = increment / 3 + 1;
		
		for(int i = increment; i < len; i++)
		{
			int temp = arr[i];
			
			//从后面开始比较，间隔increment
			int j = i - increment;
			while(j >= 0)
			{
				if(temp < arr[j])
				{
					arr[j + increment] = arr[j];
				}
				else
				{
					break;
				}
				
				j = j - increment;
			}
			
			arr[j + increment] = temp;
		}
		

	}while(increment > 1);
}


//选择排序
void SelectSort(int arr[], int len)
{
	//最后一次遍历
	for(int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for(int j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		
		if(arr[i] != arr[minIndex])
		{
			swap(arr[i], arr[minIndex]);			
		}
		
	}
}

void SelectSortT(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for(int j = i + 1; j < len; j++)
		{
			if(arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		
		if(arr[i] != arr[minIndex])
		{
			swap(arr[i], arr[minIndex]);
		}
	}
}


void Merge(int arr[], int left, int mid, int right, int temp[])
{
	int i = left;
	int j = mid + 1;
	int t = 0;
	
	while(i <= mid && j <= right)
	{
		if(arr[i] < arr[j])
		{
			temp[t++] = arr[i++];
		}
		else
		{
			temp[t++] = arr[j++];
		}
	}
	
	while(i <= mid)
	{
		temp[t++] = arr[i++];
	}
	
	while(j <= right)
	{
		temp[t++] = arr[j++];
	}
	
	t = 0;
	while(left <= right)
	{
		arr[left++] = temp[t++];
	}
	
}

void Sort(int arr[], int left, int right, int temp[])
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		Sort(arr, left, mid, temp);	
		Sort(arr, mid + 1, right, temp);
		Merge(arr, left, mid, right, temp);
	}
}

void MergeSort(int arr[], int len)
{
	if(len < 0)
	{
		return;
	}
	
	int temp[6] = {0};
	Sort(arr, 0, len - 1, temp);
}


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  
  #include <string>
  using namespace std;
  
/*class Solution {
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
};*/

class Solution {
public:
    int strStr(string haystack, string needle) 
	{
        int len1 = haystack.size();
		int len2 = needle.size();
		if(len1 == 0)
		{
			return -1;
		}
		
		if(len1 < len2)
		{
			return -1;
		}
		
		if(len2 == 0)
		{
			return 0;
		}
		
		int count = 0;
		for(int i = 0; i <= len1; i++)
		{	
			int j = 0;
			for( ; j < len2; j++)
			{
				
				if(haystack[i + j] != needle[j])
				{
					count = 0;
					break;
				}
				else
				{
					count++;
					
					if(count == len2)
					{
						return i;
					}
				}
			}
		}
		
		return -1;
		
    }
};


int main()
{
	int arr[] = {8, 6, 4, 7, 9, 5};
	Print(arr, 6);
	//InsertSortT(arr, 5);
	//SelectSortT(arr, 6);
	//ShellSortT(arr, 6);
	MergeSort(arr, 6);
	Print(arr, 6);
	
	ShellSort(arr, 6);
	
	Solution sol;
	string str1 = "ababc";
	string str2 = "abc";
	sol.strStr(str1, str2);
	
	return 1;
}
