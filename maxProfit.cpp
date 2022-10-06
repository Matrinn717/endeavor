class Solution{
    int maxProfit(vector<int>& prices){
        int minprice=INT_MAX;
        int best=0;
        for(int price:prices){
            minprice=min(minprice,price);
            best=max(price-minprice,best);
        }
        return best;
    }
}