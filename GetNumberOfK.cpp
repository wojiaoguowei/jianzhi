/*题目描述
统计一个数字在排序数组中出现的次数。*/
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int size = data.size();
		if(size == 0)
		{
			return 0;
		}
		
		int first = GetFirstK(data, k, 0, size - 1);
		int last = GetLastK(data, k, 0, size - 1);
		
		int nums = 0;
		if(first < last)
		{
			nums = last - first + 1;
		}
		
		return nums;
    }
	
	int GetFirstK(vector<int>& data , int k, int start, int end)
	{
		if(start > end)
		{
			return -1;
		}
		
		int mid = (start + end) >> 1;
		
		if(data[mid] > k)
		{
			end = mid - 1;
		}
		else if(data[mid] < k)
		{
			start = mid + 1;
		}
		else // ==
		{
			if(mid == 0 || (mid > 0 && data[mid - 1] != k))
			{
				return mid; 
			}
			else
			{
				end = mid - 1;
			}
		}
		
		return GetFirstK(data, k, start, end);
	}
	
		int GetLastK(vector<int>& data , int k, int start, int end)
		{
			if(start > end)
			{
				return -1;
			}
			
			int mid = (start + end) >> 1;
		
			if(data[mid] > k)
			{
				end = mid - 1;
			}
			else if(data[mid] < k)
			{
				start = mid + 1;
			}
			else
			{
				if(mid == data.size() - 1 || (mid < data.size() - 1 && data[mid + 1] != k ))
				{
					return mid;
				}
				else
				{
					start = mid + 1;
				}
			}
			
			return GetLastK(data , k, start, end);
		}
};

int main()
{
	vector<int> vec = {3};
	Solution sol;
	sol.GetNumberOfK(vec, 3);
}
