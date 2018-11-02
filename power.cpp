/**
 * 1.全面考察指数的正负、底数是否为零等情况。
 * 2.写出指数的二进制表达，例如13表达为二进制1101。
 * 3.举例:10^1101 = 10^0001*10^0100*10^1000。  a^(mn)=(a^m)^n  e(10)右移两位除于2，base ^ e = (base ^ 2) ^ 1 = (base*base)^1
 * 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
 */
/*public double Power(double base, int n) {
    double res = 1,curr = base;
    int exponent;
    if(n>0){
        exponent = n;
    }else if(n<0){
        if(base==0)
            throw new RuntimeException("分母不能为0"); 
        exponent = -n;
    }else{// n==0
        return 1;// 0的0次方
    }
    while(exponent!=0){
        if((exponent&1)==1)
            res*=curr;
        curr*=curr;// 翻倍
        exponent>>=1;// 右移一位
    }
    return n>=0?res:(1/res);       
}*/


#include <stdlib.h>

/*class Solution {
public:
    double Power(double base, int exponent) {
        long long p = abs((long long)exponent);
      double r = 1.0;
        while(p){
            if(p & 1) r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/ r : r;
    }
};*/

class Solution {
public:
    double Power(double base, int exponent) {
       /*if(base == 0)
	 {
	     return 0;
	 }*/

	 double result = 1;
	 int p = abs(exponent);
	 while(p)
	 {
	     if(p & 1)
              {
	         result *= base;
	      }

	     
           base *= base;

	     p >>= 1;           		     
	 }

	 return exponent < 0 ? 1 / result : result;
    }
};

int main()
{
	Solution sol;
	double n = sol.Power(2, -3);
	
	return 1;
}








 
