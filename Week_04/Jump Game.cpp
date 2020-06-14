class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag=1;
        if (nums[0]==0){
            if (nums.size()==1)return true;
            else return false;
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                flag=0;
                for(int j=i;j>=0;--j){
                    if((nums[j]>i-j)||(nums[j]==(i-j)&&i==nums.size()-1)){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {return false;}
            }
        }
        return true;
    }
};