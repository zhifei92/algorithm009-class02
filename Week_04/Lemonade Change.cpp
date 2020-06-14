class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(5 == bills[i]) five++;
            else if(10 == bills[i]) five--, ten++;
            else if(ten > 0) five--, ten--;
            else five -= 3;
            if(five < 0) return false;
        }
        return true;
    }
};