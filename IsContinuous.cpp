/*LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,
如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。*/
#include <vector>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int size = numbers.size();
		if(size < 5)
		{
			return false;
		}
		
		qsort(numbers, 0, size - 1);
		
		//0的个数
		int zerocount = 0;
		int index = 0;
		while(index < size && numbers[index] == 0)
		{
			index++;
			zerocount++;
		}
		
		int count = 0;
		int diff = 0;
		for(int i = index + 1; i < size; i++)
		{
			if(numbers[i] == numbers[i - 1])
			{
				//对子
				return false;
			}
			else
			{
				diff = numbers[i] - numbers[i - 1] - 1;
				if(diff > 0)
				{
					count += diff;
				}
			}
		}
		
		if(count > zerocount)
		{
			return false;
		}
		
		return true;
    }
	
	void qsort(vector<int> &nums, int begin, int end)
	{
		if(begin < end)
		{
			int base = nums[begin];
			int left = begin;
			int right = end;
			while(left < right)
			{
				while(left < right && nums[right] >= base)
				{
					right--;
				}
				
				nums[left] = nums[right];
				
				while(left < right && nums[left] <= base)
				{
					left++;
				}
				
				nums[right] = nums[left];
			}
			
			nums[left] = base;
			
			qsort(nums, begin, left - 1);
			qsort(nums, left + 1, end);
		}
	}
};

int main()
{
	Solution sol;
	vector<int> vec = {0,3,1,6,4};
	sol.IsContinuous(vec);
	
	return 1;
}
