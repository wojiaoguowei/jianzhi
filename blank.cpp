#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>































































































/*class Solution {
public:
	void replaceSpace(char *str,int length) {
        //遍历一边字符串找出空格的数量
        if(str==NULL||length<0)
            return ;
        int i=0;
        int oldnumber=0;//记录以前的长度
        int replacenumber=0;//记录空格的数量
        while(str[i]!='\0')
		{
			oldnumber++;
			if(str[i]==' ')
			{
				replacenumber++;
			}
			i++; 
		}
        int newlength=oldnumber+replacenumber*2;//插入后的长度
        if(newlength>length)//如果计算后的长度大于总长度就无法插入
            return ;
        int pOldlength=oldnumber; //注意不要减一因为隐藏个‘\0’也要算里
        int pNewlength=newlength;
        while(pOldlength>=0&&pNewlength>pOldlength)//放字符
		{
			if(str[pOldlength]==' ') //碰到空格就替换
			{
				str[pNewlength--]='0';
				str[pNewlength--]='2';
				str[pNewlength--]='%';
				
			}
			else //不是空格就把pOldlength指向的字符装入pNewlength指向的位置
			{
				str[pNewlength--]=str[pOldlength];
				
			}
			pOldlength--; //不管是if还是elsr都要把pOldlength前移
			
		}
        

	}
}; */
























































class Solution {
public:
	void replaceSpace(char *str,int length) 
	{
		if(str == NULL)
		{
			return;
		}
		int nBlankCounts = 0;
		for(int i = 0; i < length; i++)
		{
			if(*(str + i) == ' ')
			{				
				nBlankCounts++;
			}
		}

		int nOldLength = strlen(str);
		int nNewLength = nOldLength + nBlankCounts * 2;
		
		if(nNewLength + 1 > length)
		{
			return;
		}

		
		while(nOldLength >= 0 && nNewLength > nOldLength)
		{
			if(*(str + nOldLength) == ' ')
			{	
				str[nNewLength--] = '0';
				str[nNewLength--] = '2';
				str[nNewLength--] = '%';
			}
			else
			{
				str[nNewLength--] = str[nOldLength];
			}
			
			nOldLength--;
		}
	}
};

int main()
{
	char str[20] = "We Are Happy!";
	//memcpy(str, "We Are Happy!", 13);
	Solution sol;
	sol.replaceSpace(str, 20);
	printf("%s\n", str);

	system("read");

	return true;	
}
