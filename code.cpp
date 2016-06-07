/*********************************************************************************************
利用二分法，分别找到第一个出现的下标和最后一个出现的下标，得到出现的次数，在找到相等的时候还需
判断是不是第一次出现和最后一次出现。
***********************************************************************************************/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) 
    {
        int number = 0;
        int length = data.size();
        if(length > 0)
        {
            int start = GetFirstK(data,0,length-1,k);
        	int end = GetLastK(data,0,length-1,k,length);
            if(start > -1 && end > -1)
                number = end-start+1;
        }
      
        return number;
    }
private:
    int GetFirstK(vector<int> data, int start, int end, int k)
    {
        if(start > end)
            return -1;
        
        int middle = (end+start)/2;
        int middleData = data[middle];
        
        if(middleData == k)
        {
            if((middle-1>0 && middleData!=data[middle-1]) || middle == 0)
                return middle;
            else
                end = middle -1;
        }
        if(middleData > k)
        {
            end = middle -1;
        }
        if(middleData < k)
        {
            start = middle+1;
        }
         return  GetFirstK(data,start,end,k) ; 
    }
       int GetLastK(vector<int> data, int start, int end, int k,int length)
    {
        if(start > end)
            return -1;
        
        int middle = (end+start)/2;
        int middleData = data[middle];
        
        if(middleData == k)
        {
            if((middle+1< length-1 && middleData!=data[middle+1]) || middle == length-1)
                return middle;
            else
                start = middle +1;
        }
        if(middleData > k)
        {
            end = middle -1;
        }
        if(middleData < k)
        {
            start = middle+1;
        }
         return  GetLastK(data,start,end,k,length) ; 
    }
};
