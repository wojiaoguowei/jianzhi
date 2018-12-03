/*题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

思路：需要满足一下规则（正则表达式，直接用理解困难）
1 e/E后面必须跟数字，且只能有一个e/E；不能最后一个
2 第一次出现的符号（+/-）要么在开头，要么紧接在e/E后面，
  第二次出现的符号（+/-）只能在e/E后面；
3 小数点只能出现一次，并且只能出现在e/E前面；
4 不能出现除了0~9，+/-,.,e/E以外的字符

前提条件：
1 如果小数点前面没有数字自动补零。比如-.799相当于-0.799;
2 如果符号后面没有数字自动补零。比如+e+相当于+0e+0;

class Solution {
public:
    bool isNumeric(char* string)
    {
        //标记符号sign，小数点decimal，e/E是否出现过
        bool hasS = false,hasD = false,hasE = false; 
        for(int i=0;i<strlen(string);i++){
            if(string[i]=='e' || string[i]=='E')
			{//规则1
                if(i==strlen(string)-1) return false;
                if(hasE) return false;
                hasE = true;
            }
			else if(string[i]=='+' || string[i]== '-')
			{//规则2
                if(hasS && string[i-1]!='e' && string[i-1]!='E') 
                    return false;
                if(!hasS && i!=0 && string[i-1]!='e' && string[i-1]!='E')
                    return false;
                hasS = true;
            }
			else if(string[i]=='.')
			{//规则3
                if(hasD || hasE)
                    return false;
                hasD = true;
            }
			else if(string[i]<'0' || string[i]>'9')//规则4
                return false;
        }	
        return true;
    }
};

*/
#include <iostream>
#include <string.h>
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == NULL)
		{
			return false;
		}
		//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
		bool hasS = false, hasD = false, hasE = false;
		for(int i = 0; i < strlen(string); i++)
		{
			if(string[i] == '+' || string[i] == '-')
			{
				   //不是符号 
				if(!hasS && i != 0 && string[i - 1] != 'e' && string[i - 1] != 'E')
				{
					return false;
				}
				
				if(hasS && string[i - 1] != 'e' && string[i - 1] != 'E')
				{
					return false;
				}
				
				hasS = true;
			}
			
			else if(string[i] == 'e' || string[i] == 'E')
			{
				if(hasE)
				{
					return false;
				}
				
				//最后一个字符
				if(i == strlen(string) - 1)
				{
					return false;
				}
				
				hasE = true;
			}
			
			else if(string[i] == '.')
			{
				if(hasD || hasE)
				{
					return false;
				}
				
				hasD = true;
			}
			
			else if(string[i] < '0' || string[i] > '9')
			{
				return false;
			}
		}
		
		return true;
    }

};

int main()
{
	char *c = "+500";
	Solution sol;
	sol.isNumeric(c);
	
	return 1;
}
