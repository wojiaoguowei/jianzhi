class Temp   
{   
public:   
       Temp() 
	   { 
			++ N; 
			Sum += N; 
	   }   
      static void Reset() 
	  { 
			N = 0; 
			Sum = 0; 
	  }
	  
      static int GetSum() 
	  { 
			return Sum; 
	  }   
private:   
      static int N;   
      static int Sum;   
};   
  
int Temp::N = 0;   
int Temp::Sum = 0;   
int solution1_Sum(int n)   
{   
       Temp::Reset();   
  
       Temp *a = new Temp[n];   
      delete []a;   
       a = 0;   
  
       return Temp::GetSum();   
}

class Solution {
public:
    int Sum_Solution(int n) {
		int ret = 0;
        n && (ret = Sum_Solution(n - 1) + n);
		return ret;
    }
};

int main()
{
	int n = solution1_Sum(5);
	
	return 1;
}
