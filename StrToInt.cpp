/*思路：如果字符串能转化成符合题意的整数，那么字符串中的字符肯定实在'0' ~'9'之间的，符号 + 或者 - 如果出现的话，那么肯定是出现的字符串的第一个元素的位置，如果出现在字符串的中间的某个位置，这个字符串就不可以转化为数字。

再有就是：res = (res << 1) + (res << 3) + (str[i] & 0xf);

对这句话的解释： (res << 1) + (res << 3)，左移一位是乘以2，左移3位是乘以8，加起来相当于res*10；

(str[i] & 0xf) 相当于 str[i] - '0'，为什么呢？因为 字符'0' ~ '9' 的SACII码值的低四个二进制位就是 0 ~ 9， 0xf 是数字15，二进制位1111，这样操作之后就可以将 ‘0’ 转化为0，...，将‘9’转化为‘9’。

整体看这句话：res = res * 10 + str[i] - ‘0’。例如字符串为‘123’；

那么单步运行：res = 1； res = 1 * 10 + 2 = 12； res = 12 * 10 + 3 = 12。这句话就是这个意思。
*/

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        if(len <= 0)
            return 0;
        int symbol = 1;
        long long res = 0;
        if(str[0] == '-')
            symbol = -1;
        for(int i = (str[0] == '+' || str[0] == '-')? 1 : 0; i < len; ++ i)
        {
            if(str[i] >= '0' && str[i] <= '9')
                res = /*(res << 1) + (res << 3)*/ res * 10 + (str[i] & 0xf);
            else
                return 0;
        }
        return res * symbol;
    }
};
