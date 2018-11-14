#include <iostream>
#include <vector>
 
using namespace std;
 
void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];/*将比第一个小的移到低端*/
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];    
/*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

class Solution {
public:
    void QSort(vector<int> &array) {
		int len = array.size();
		if(len == 0)
		{
			return ;
		}
		
		quicksork(array, 0, len - 1);
    }
	
	
	void quicksork(vector<int> &array, int first, int last)
	{
		if(first >= last)
		{
			return;
		}
		
		int key = array[first];
		while(first < last)
		{
			while(first < last && key <= array[last])
			{
				last--;
			}
			
			array[first] = array[last];
			
			while(first < last && key >= array[first])
			{
				first++;
			}
			
			array[last] = array[first];
		}
		
		array[first] = key;
		
		quicksork(array, 0, first - 1);
		quicksork(array, first + 1, last);
	}
	
};

int main()
{
	int A[] = {5, 6, 2, 1, 4, 3};
	//Qsort(A, 0, 5);
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(6);	
	vec.push_back(2);	
	vec.push_back(1);	
	vec.push_back(4);
	vec.push_back(3);	
	
	Solution so;
	so.QSort(vec);
	
	return 1;
}
