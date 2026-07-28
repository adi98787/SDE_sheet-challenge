class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Sum of array elements
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Sum of numbers from 0 to n
        int total = n * (n + 1) / 2;

        return total - sum;
    }
};