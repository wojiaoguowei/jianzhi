/*题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/

/*class Solution {
public: 
	int FindGreatestSumOfSubArray(int array[], int len) {
        int sum =0;
        int max = array[0];
        for(int i=0;i<len;i++){
          if(sum>=0)
          {  //首先进行求和
             sum= sum+array[i];
          }else{
              //求和的正数区间结束，将当前的值设置为初值
               sum=array[i];


          }
           if(sum>max)
               //记录每个求和区间的最大值
               max = sum; 
       }
       return max;
    }
};*/

#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
		int size = array.size();
		if(size == 0)
		{
			return 0x80000000;
		}
		
		int sum = 0;
		int max = array[0];
		for(int i = 0; i < size; i++)
		{
			if(sum >= 0)
			{
				sum += array[i];
			}
			else
			{
				//i之前之后小于0，从i位置开始从新计算
				sum = array[i];
			}
			
			if(max < sum)
			{
				max = sum;
			}
		}
		
		return max;
    }
};

int main()
{
	int a = -8;
	int b = 0x80000001;
	int c = 0x80000000;
	int A[8] = {6,-3,-2,7,-15,1,2,2};
	
	Solution sol;
	//sol.FindGreatestSumOfSubArray(A, 8);
	
	return 1;
}
