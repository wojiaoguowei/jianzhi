class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int nLength = sequence.size();
		
		if(nLength == 0)
		{
			return false;
		}
		
		return judge(sequence, 0, nLength - 1);
    }
private:
	bool judge(vector<int> &sequence, int start, int end)
	{
		if(sequence.empty() || start > end)
		{
			return false;
		}
	
		int nRoot = sequence[end];
		
		int i = start;
		//根结点大于左子树节点
		for(; i < end; i++)
		{
			if(sequence[i] > nRoot)
			{
				break;
			}
		}
		
		//根节点小于右子树节点
		int j = i;
		for(; j < end; j++)
		{
			if(sequence[j] < nRoot)
			{
				return false;
			}
		}
		
		bool bLeftFlag = true;
		if(i > 0)
		{
			bLeftFlag = judge(sequence, 0, i - 1);
		}
		
		bool bRightFlag = true;
		if(i < end)
		{
			bRightFlag = judge(sequence, i, end - 1);
		}
		
		return bLeftFlag && bRightFlag;
	}
};

























































class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size() - 1);
    }
private:
    bool bst(vector<int> seq, int begin, int end){
        // 边界条件
        if(seq.empty() || begin > end)
            return false;
 
        // 划分左右子树，并判断左右子树和根节点的关系
        int i = begin;
        for(; i < end; ++i)
            if(seq[i] > seq[end])
                break;
 
        int j = i;
        for(; j < end; ++j)
            if(seq[j] < seq[end])
                return false;
 
        // 判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin)
            left = bst(seq, begin, i - 1);
 
        // 判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1)
            right = bst(seq, i , end - 1);
 
        return left && right;
    }
};


/*
//递归
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
 
        int size = sequence.size();
        if(0==size)
        {
            return false;
        }
 
        return isLastOrder(sequence, 0, size-1);
    }
 
private:
    bool isLastOrder(vector<int>& sequece, int b, int e)
    {
        if(b==e)
        {
            return true;
        }
        int mid = b;
        while(sequece[mid++]<sequece[e] && mid<e);
 
        int tmp = mid;
        while (sequece[tmp++]>sequece[e] && tmp<e);
        if(tmp<e)
        {
            return false;
        }
 
        if(mid==b || mid==e)
        {
            return isLastOrder(sequece, b, e-1);
        }
        else
        {
            return (isLastOrder(sequece, b, mid-1) && isLastOrder(sequece, mid, e-1));
        }
    }
};*/
 
//非递归 
//非递归也是一个基于递归的思想：
//左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
//最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
//即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理
 
//对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
//只需看看右子树的右子树是否符合要求即可
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size)
        {
            while(sequence[i++]<sequence[size]);
            while(sequence[i++]>sequence[size]);
 
            if(i<size)return false;
            i=0;
        }
        return true;
    }
};
