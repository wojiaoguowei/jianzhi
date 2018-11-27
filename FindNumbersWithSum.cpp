题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:

对应每个测试案例，输出两个数，小的先输出。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int nSize = array.size();
	    vector<int> res;	
		if(nSize < 2)
		{
			return res;
		}
		
		int begin = 0;
		int end = nSize - 1;
		while(begin < end)
		{
			int curSum = array[begin] + array[end];
			if(curSum > sum)
			{
				end--;
			}
			else if(curSum < sum)
			{
				begin++;
			}
			else
			{
				res.push_back(array[begin]);
				res.push_back(array[end]);
				
				break;
			}
		}
		
		return res;
    }
};

