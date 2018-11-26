/*题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:

输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

根据所学知识，有：

(a + b)(b - a + 1) = 2 * sum;此为等差数列公式。

令i = b - a + 1(项数), j = a + b（首末项之和）;现讨论取值范围。i >= 2（序列中至少有2项）, j >= 3（序列之和至少为3）；
隐藏的关系是： j > i同时还有 i * j = 2 * sum，进行放缩之后就有 i * i < 2 * sum，即 i < 根号（2 * sum）。对i进行遍历，找出i,j∈正整数且j - i + 1为偶的取值。
*/

/*class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        if(sum < 3)
            return allRes;
        
        int twofoldSum = 2 * sum;
        int i,j;
        for(i = sqrt(twofoldSum); i >= 2; --i)    //枚举出合适的项数
        {
            if(twofoldSum % i == 0)    //首末项之和为整数
            {
                j = twofoldSum / i;    //求出首末项之和
                int temp = j - i + 1;    //解方程得到2倍的左值等于j - i + 1；要求左边界为整数 temp == 2a
                if (!(temp & 1))        //要求temp是偶数
                {
                    int begin = temp >> 1;
                    int end = j - begin;    //j的实际意义是首末项之和
                    vector<int> res;
                    InsertRes(begin, end, res);
                    allRes.push_back(res);
                }
            }
        }
        return allRes;
    }
    
    void InsertRes(int begin, int end, vector<int> &res)
    {
        for(int i = begin; i <= end; ++i)
            res.push_back(i);
    }
};*/

#include <vector>
#include <math.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > FindContinuousSequence(int sum) 
	{
        vector<vector<int> > res;
		res.clear();
		
		if(sum < 3)
		{
			return res;
		}
		
		//等差数列和 差是1
		//sum=(a + b)*(b - a + 1) / 2
		//i = b - a + 1相数,j = a + b首末项之和
		//j > i, 2 * sum = i * j > i * 2 所以sqrt(2 * sum) > i
		int i, j;
		int twosum = 2 * sum;
		for(i = sqrt(twosum); i >= 2; --i)
		{
			int temp = twosum % i;	//i项数
			//temp首项+末项 %可以整除
			if(temp == 0)
			{
				j = twosum / i;
				int a_2 = j - i + 1; //2a	偶数
				if((a_2 & 1) == 0)
				{
					int begin = a_2 / 2;
					int end = j - begin;
					vector<int> tmpves;
					for(int i = begin; i <= end; ++i)
						tmpves.push_back(i);
					
					res.push_back(tmpves);
				}
			}
		}
		
		return res;
    }
};


class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		//至少包含2个数
		vector<vector<int> > allRes;
		int low = 1;
		int high = 2;
		while(high > low){    //终止条件，因为题干要求至少2个数
			//连续且差为1的序列，求和公式可知
			int cur = (low + high) * (high - low + 1) / 2;
			if(cur < sum)    //当前窗口内的值之和小于sum，右框右移一下
				high++;
			else if(cur == sum){   //相等，就将窗口内所有数添加进结果集
				vector<int> res;
				for(int i = low; i <= high; ++i)
					res.push_back(i);
				allRes.push_back(res);
				low++;
			}    
			else    //如果当前窗口内的值之和大于sum，左窗框左移一下
				low++;   
		}
		return allRes;
	}
};

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		//至少包含2个数
		vector<vector<int> > allRes;
		int low = 1;
		int high = 2;

		while(high > low)
		{
			int cur = (low + high) * (high - low + 1) / 2;
			if(cur < sum)
			{
				high++;
			}
			else if(cur == sum)
			{
				for(int i = low; i <= high; i++)
				{
					vector<int> tmp;
					tmp.push_back(i);
				}
			}
			else
			{
				low++;
			}
		}
		
		return allRes;
	}
};


int main()
{
	return 1;
}
