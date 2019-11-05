class Solution {
    public int missingNumber(int[] nums) {
        int x = 0;
        int y = 0;
        for(int i = 0; i < nums.length; i++) {
            x += nums[i];
        }
        for(int i = 0; i <= nums.length; i++) {
            y += i;
        }
        return y - x;
    }
}