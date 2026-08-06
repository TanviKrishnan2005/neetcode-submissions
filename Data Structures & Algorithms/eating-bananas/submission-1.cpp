class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible speed:
        // Koko must eat at least 1 banana per hour
        int l = 1;

        // Maximum useful speed:
        // eating faster than the biggest pile is unnecessary
        int r = *max_element(piles.begin(), piles.end());

        // Start with the maximum speed as a valid answer
        int res = r;

        // Binary search for the smallest speed that works
        while(l <= r) {

            // Try the middle speed
            int k = (l + r) / 2;

            // Calculate total hours needed at speed k
            long long time = 0;

            for(int p : piles) {

                // Hours needed for this pile
                // Example: pile = 7, speed = 3
                // ceil(7 / 3) = 3 hours
                time += ceil(static_cast<double>(p) / k);
            }

            // If Koko finishes within h hours,
            // this speed works
            if(time <= h) {

                // Save it as a possible answer
                res = k;

                // But maybe a smaller speed also works,
                // so search the LEFT side
                r = k - 1;
            }
            else {

                // Koko is too slow
                // She needs a faster speed,
                // so search the RIGHT side
                l = k + 1;
            }
        }

        return res;
    }
};