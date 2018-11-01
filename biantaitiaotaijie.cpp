
/*因为n级台阶，第一步有n种跳法：跳1级、跳2级、到跳n级
跳1级，剩下n-1级，则剩下跳法是f(n-1)
跳2级，剩下n-2级，则剩下跳法是f(n-2)
所以f(n)=f(n-1)+f(n-2)+...+f(1) + 1			//1直接调到位
因为f(n-1)=f(n-2)+f(n-3)+...+f(1) + 1
所以f(n)=2*f(n-1) */  



/*/
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
	  {
		return -1;
	  }

	  int pre = 1, next = 2;
	  while(number-- > 1)
	  {
	  	pre = next;
		next *= 2;
	  }

	  return pre;
     }
};

*/

class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
	  {
		return -1;
	  }

	 return 1 << (number - 1);
     }
};
