class Solution {
private:
    bool solve(vector<int>& price, int mid, int k) {
        int count = 1, last = price[0];
        for (int i = 1; i < price.size(); i++) {
            if (price[i] - last >= mid) {
                count++;
                last = price[i];
            }
        }
        return count >= k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 0, high = price.back() - price.front();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(price, mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

/*all the problems where we have to find h=the minimum max value we can get.
 We check for every mid and start from 0 index if we can place an element from every postion i+mid and we will have a count if the count is in the required then
 we output true.like if the array is 1 3 5 8 14 and mid is 5 then we can place in 1 then on 8 as 1+5=6 and 8 is the first element greater than equal to 6 
 and so on 6+5=11 14>11 so total count is 2*/
