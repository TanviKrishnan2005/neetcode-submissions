class Solution {
public:
    int maxProfit(vector<int>& price) {
        int l =0;
        int r =0;
        int maxP=0;

        while(r<price.size()){
          if(price[l]<price[r]){
            int profit = price[r]-price[l];
            maxP = max(maxP,profit);
          }else{
            l =r;
          }
          r++;
        }
        return maxP;
    }
};
