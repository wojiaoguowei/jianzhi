class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
			if(matrix.size() == 0)
			{
				return vector<int>();
			}
			
			if(matrix[0].size() == 0)
			{
				return vector<int>();		
			}
			
			int nRow = 0;
			int nCol = 0;
			int nRowCount = matrix.size();
			int nColCount = matrix[0].size();
			
			vector<int> result;
			
			
			while(1)
			{
				//从左到右打印
				for(int i = nCol; i < nColCount; i++)
				{
					result.push_back(matrix[nRow][i]);
				}
				
				nRow++;	//下一行
				if(nRow >= nRowCount)
				{
					return result;
				}
				
				//从上到下打印
				for(int i = nRow; i < nRowCount; i++)
				{
					result.push_back(matrix[i][nColCount - 1]);
				}
				
				nColCount--;	//列数减一
				if(nCol >= nColCount)
				{
					return result;
				}
				
				//从右到左打印
				for(int i = nColCount - 1; i >= nCol; i--)
				{
					result.push_back(matrix[nRowCount - 1][i]);
				}
				
				nRowCount--;
				if(nRow >= nRowCount)
				{
					return result;
				}
				
				//从下到上打印
				for(int i = nRowCount - 1; i>= nRow; i--)
				{
					result.push_back(matrix[i][nCol]);					
				}
				
				nCol++;
				if(nCol >= nColCount)
				{
					return result;
				}
				
			}

			
    }
};






























