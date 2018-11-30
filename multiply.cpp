/*题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/
//B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//从左到右算 B[i]=A[0]*A[1]*...*A[i-1]
//从右到左算B[i]*=A[i+1]*...*A[n-1]
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
     
        int n=A.size();
        vector<int> b(n);
        int ret=1;
        for(int i=0;i<n;ret*=A[i++]){
            b[i]=ret;
        }
        ret=1;
        for(int i=n-1;i>=0;ret*=A[i--]){
            b[i]*=ret;
        }
        return b;
    }
};


public class Solution {
    public int[] multiply(int[] A) {
		int[] B = new int[A.length];
        for(int i=0;i<A.length;i++){
            B[i] = multiplyA(A,i);
        }
        return B;
    }
    public int multiplyA(int[] A,int i){
        int mul = 1;
        for(int j=0;j<i;j++){
            mul*=A[j];
        }
        for(int k=i+1;k<A.length;k++){
            mul*=A[k];
        }
        return mul;
    }
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5};
	Solution sol;
	sol.multiply(vec);
}
