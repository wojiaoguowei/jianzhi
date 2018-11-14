数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		int count = 0;
		for(int i = 0; i < len; i++)
		{
			int tmp = numbers[i];
			for(int j = i; i < len; j++)
			{
				if(tmp == numbers[j])
				{
					count++;
					
					if(count > len / 2)
					{
						return numbers[j];
					}
				}
				
				count = 0;
			}
		}
		
		return 0;
    }
};

 思路一：数组排序后，如果符合条件的数存在，则一定是数组中间那个数。（比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等）
这种方法虽然容易理解，但由于涉及到快排sort，其时间复杂度为O(NlogN)并非最优；
参考代码如下：

	
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size()/2];
         
        int count=0; // 出现次数
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};
思路二：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
参考代码如下：

	
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.empty()) return 0;
         
        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1; // 次数
         
        for(int i=1;i<numbers.size();++i)
        {
            if(times == 0)
            {
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
            {
                ++times; // 相同则加1
            }
            else
            {
                --times; // 不同则减1               
            }
        }
         
        // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i] == result) ++times;
        }
         
        return (times > numbers.size()/2) ? result : 0;
    }
};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		if(len == 0)
		{
			return 0;
		}
		
		int count = 1;
		int tmp = numbers[0];
		for(int i = 1; i < len; i++)
		{
		    if(numbers[i] == tmp)
			{
				count++;
			}
			else
			{
				count--;
			}
			
			if(count == 0)
			{
				tmp = numbers[i];
				count = 1;
			}
		}
		
		count = 0;
		for(int i = 0; i < len; i++)
		{
			if(tmp == numbers[i])
			{
				 count++;
			}
		}
		
		return count > len / 2 ? tmp : 0;
		
		
		return 0;
    }
};
