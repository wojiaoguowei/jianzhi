#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;   //创建字符串数组
        int len = str.length();  //求出字符串长度，作为参数传递控制循环次数
        if(!len) return result;  //当输入为空时，直接返回
        Permutations(result, str, 0, len);
        return result;
 
    }
 
   //递归函数
    void Permutations(vector<string>&result, string str,int index, int len){
     //当索引指向字符串尾部时，将str压入数组   

     if (index == len){ 
            result.push_back(str);
            return;
        }
        for (int i = index; i < len; ++i) {
            if (i!=index && str[i]== str[index])
			{
				// 保证当输入多个重复字符时，不会重复计算
				continue;
			}
			
            swap(str[i],str[index]);//每一次，交换从第index位以后的一个元素
            Permutations(result, str, index+1, len);
        }
    }
};

int main()
{
	string str("abc");
	
	Solution so;
	vector<string> vec = so.Permutation(str);
	
	return 1;
}


/*题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述

输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

这道题是剑指offfer中一道经典的题,如果有n个元素,我们就能有n*(n - 1)个全排列,n为1时,只有一个全排列

举个栗子,当字符串为ABC时,分析一下全排列的过程:

1.固定A在字符串的最左边,然后全排列B和C

2.全排列B和C

3.当全排列的字符串只有一个字符时,它的全排列就是它自身

4.当固定A后,其他字符串的全排列完毕后,把A与其他字符进行交换,然后重复上面的步骤进行全排列

示意图如下:
--------------------- 
作者：Qregi 
来源：CSDN 
原文：https://blog.csdn.net/Qregi/article/details/82049298 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/














class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
		int len = str.size();
		if(len == 0)
		{
			return result;
		}
		
		Permutations(str, result, len, 0);
		
		return result;
    }
	
	//递归函数
	void Permutations(string str, vector<string> &result, int len, int index)
	{
		if(index == len)
		{
			result.push_back(str);
			return;
		}
		
		for(int i = index; i < len; i++)
		{
			if(index != i && str[index] == str[i])
			{
				conitune;
			}
			
			swap(str[i], str[index]);
			Permutations(str, result, len, index + 1);
		}
	}
};






























