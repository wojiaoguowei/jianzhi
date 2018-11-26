/*考虑过程：
首先我们考虑这个问题的一个简单版本：一个数组里除了一个数字之外，其他的数字都出现了两次。请写程序找出这个只出现一次的数字。
这个题目的突破口在哪里？题目为什么要强调有一个数字出现一次，其他的出现两次？我们想到了异或运算的性质：任何一个数字异或它自己都等于0 。也就是说，如果我们从头到尾依次异或数组中的每一个数字，那么最终的结果刚好是那个只出现一次的数字，因为那些出现两次的数字全部在异或中抵消掉了。
有了上面简单问题的解决方案之后，我们回到原始的问题。如果能够把原数组分为两个子数组。在每个子数组中，包含一个只出现一次的数字，而其它数字都出现两次。如果能够这样拆分原数组，按照前面的办法就是分别求出这两个只出现一次的数字了。
我们还是从头到尾依次异或数组中的每一个数字，那么最终得到的结果就是两个只出现一次的数字的异或结果。因为其它数字都出现了两次，在异或中全部抵消掉了。
由于这两个数字肯定不一样，那么这个异或结果肯定不为0 ，也就是说在这个结果数字的二进制表示中至少就有一位为1 。我们在结果数字中
找到第一个为1 的位的位置，记为第N 位。现在我们以第N 位是不是1 为标准把原数组中的数字分成两个子数组，第一个子数组中每个数字的第N 位都为1 ，而第二个子数组的每个数字的第N 位都为0 。
现在我们已经把原数组分成了两个子数组，每个子数组都包含一个只出现一次的数字，而其它数字都出现了两次。因此到此为止，所有的问题我们都已经解决。*/ 

/*class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
	{
		int size = data.size();
	
		for(int i = 0; i < size; i++)
		{
			if(map.find(data[i]) == map.end())
			{
				map[data[i]] = 1;
			}
			else
			{
				map[data[i]]++;
			}
		}
		
		bool f1 = false;
		bool f2 =false;
		 for (std::map<int,int>::iterator it = map.begin(); it != map.end(); ++it)
		 {
			if(!f1 && it->second == 1)
			{
				*num1 = it->first;
				f1 = true;
			}
			else if(!f2 && it->second == 1)
			{
				*num2 = it->first;
				f2 = true;
			}
		 }
	 }
		
		map<int, int> map;
};
*/

#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
	{
		int size = data.size();
		
		int result = 0;
		for(int i = 0; i < size; i++)
		{
			result ^= data[i];
		}
		
		int n = -1;
		for(int i = 0; i < 32; i++)
		{
			if((result >> i & 1) == 1)
			{
				n = i;
			}
		}
		
		int bit1 = 1 << n;
		
		vector<int> vec0;
		vector<int> vec1;
		
		for(int i = 0; i < size; i++)
		{
			if((data[i] & bit1) == 0)
			{
				vec0.push_back(data[i]);
			}
			else
			{
				vec1.push_back(data[i]);		
			}
		}
		
		size = vec0.size();
		result = 0;
		for(int i = 0; i < size; i++)
		{
			result ^= vec0[i];
		}
		
		*num1 = result;
		
		
		size = vec1.size();
		result = 0;
		for(int i = 0; i < size; i++)
		{
			result ^= vec1[i];
		}
		
		*num2 = result;
	}
};


int main()
{
	vector<int> vec = {2,4,3,6,3,2,5,5};
	Solution sol;
	int n1, n2;
	sol.FindNumsAppearOnce(vec, &n1, &n2);
	
	return 1;
}
