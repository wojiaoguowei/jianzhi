/*题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。*/
/*
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子
 * 
 * 思路：回溯法：首先任意一个点都有可能成为起点，所以要获得任意一点的坐标(位于第几行，第几列)
 * 其次要有一个数组记录这个点是否被访问过，同时要有一个指针来记录字符串中字符的位置。
 * 当某个点成为合法的起点时，即这个点与字符串中第一个字符相等，则可以继续朝上下左右搜索下一个点；
 * 如果这个点不能成为合法的起点，则恢复现场(这个点没有被访问过且字符串指针后退)
 */
/*public class HasPath {
	public boolean hasPath(char[] matrix, int rows, int cols, char[] str) {
		if(matrix.length <= 0 || rows < 0 || cols < 0 || str.length <= 0) {
			return false;
		}
		
		boolean visited[] = new boolean[rows * cols];
		int [] index = {0};
		for(int i = 0;i < rows;i ++) {
			for(int j = 0;j < cols;j ++) {
				if(isPath(matrix, rows, cols, i, j, str, visited, index)) {
					return true;
				}
			}
		}
		return false;
    }
	
	public boolean isPath(char[] matrix, int rows, int cols, int row, int col, char[] str, boolean visited[], int [] index) {
		if(index[0] == str.length) {
			return true;
		}
		
		boolean flag = false; 
		//当前点折算到原数组的位置是：row * cols + col
		if(row >= 0 && row < rows && col >= 0 && col < cols 
		   && !visited[row * cols + col] && matrix[row * cols + col] == str[index[0]]) 
		{
			index[0] ++;	//指针右移
			visited[row * cols + col] = true;
			
			//第一个点是合法的起点之后开始回溯:上下左右进行搜索
			flag = isPath(matrix, rows, cols, row - 1, col, str, visited, index) || 
				   isPath(matrix, rows, cols, row + 1, col, str, visited, index) ||
				   isPath(matrix, rows, cols, row, col - 1, str, visited, index) ||
				   isPath(matrix, rows, cols, row, col + 1, str, visited, index);
			if(!flag) {		//恢复现场
				index[0] --;
				visited[row * cols + col] = false;
			}
		}
		
		return flag;
	}
	
	public static void main(String[] args) {
		String str = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
		char[] matrix = str.toCharArray();
		String str2 = "SGGFIECVAASABCEEJIGOEM";
		char[] c = str2.toCharArray();
		System.out.println(new HasPath().hasPath(matrix, 5, 8, c));
	}
}*/
/*
分析：回溯算法
 这是一个可以用回朔法解决的典型题。首先，在矩阵中任选一个格子作为路径的起点。如果路径上的第i个字符不是ch，那么这个格子不可能处在路径上的
第i个位置。如果路径上的第i个字符正好是ch，那么往相邻的格子寻找路径上的第i+1个字符。除在矩阵边界上的格子之外，其他格子都有4个相邻的格子。
重复这个过程直到路径上的所有字符都在矩阵中找到相应的位置。
　　由于回朔法的递归特性，路径可以被开成一个栈。当在矩阵中定位了路径中前n个字符的位置之后，在与第n个字符对应的格子的周围都没有找到第n+1个
字符，这个时候只要在路径上回到第n-1个字符，重新定位第n个字符。
　　由于路径不能重复进入矩阵的格子，还需要定义和字符矩阵大小一样的布尔值矩阵，用来标识路径是否已经进入每个格子。 当矩阵中坐标为（row,col）的
格子和路径字符串中相应的字符一样时，从4个相邻的格子(row,col-1),(row-1,col),(row,col+1)以及(row+1,col)中去定位路径字符串中下一个字符
如果4个相邻的格子都没有匹配字符串中下一个的字符，表明当前路径字符串中字符在矩阵中的定位不正确，我们需要回到前一个，然后重新定位。
　　一直重复这个过程，直到路径字符串上所有字符都在矩阵中找到合适的位置*/
#include <stddef.h>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {  
      if(str==NULL||rows<=0||cols<=0)
           return false;
      bool *isOk=new bool[rows*cols]();
	  memset(isOk, true, rows*cols);
	  int index = 0;
      for(int i=0;i<rows;i++)
      {
           for(int j=0;j<cols;j++)
                if(isHsaPath(matrix,rows,cols,str,isOk,i,j, index))
                   return true;
      }
      return false;
    }
 bool isHsaPath(char *matrix,int rows,int cols,char *str,bool *isOk,int curx,int cury, int findindex)
 {
     //字符串结束符，成功 
	 if(str[findindex]=='\0')
           return true;
	 
	 int index = curx * cols + cury;
	 if(index < 0 || index >= rows * cols)
	 {
	     return false;
	 }
	 
	 //是否被占位 字符不等
	 if(!isOk[index] || matrix[index] != str[findindex])
	 {
		return false;
	 }
	   
      
	  
	  if(curx >= 0 && curx < rows && cury >= 0 && cury < cols )
	  {
		  isOk[index] = false;
		  findindex++;
		  vec.push_back(matrix[index]);
		  bool sign=isHsaPath(matrix,rows,cols,str,isOk,curx-1,cury, findindex)
					||isHsaPath(matrix,rows,cols,str,isOk,curx+1,cury, findindex)
					||isHsaPath(matrix,rows,cols,str,isOk,curx,cury-1, findindex)
					||isHsaPath(matrix,rows,cols,str,isOk,curx,cury+1, findindex);
		  
		  if(!sign) 
		  {	  //恢复现场
			  
			  isOk[index] = true;
			  		  findindex--;
					  vec.pop_back();
				return sign;
		  }
		  
		  return sign;

	  }

	return false;
 }
 
 vector<char> vec;
};

int main()
{
	char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";  
	char *str = "SGGFIECVAASABCEHJIGQEM";
	Solution sol;
	bool flag = sol.hasPath(matrix, 5, 8, str);
	return flag;
}
