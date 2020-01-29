class Solution {
    public boolean canJump(int[] nums) {
        int maxJump = nums[0];
        int current = 0;
        int destination = nums.length - 1;
        if(current + maxJump >= destination) {
            return true;
        }
        while(current != destination) {
            int maxJump2 = 0;
            int current2 = current;
            for(int i = current + 1; i <= current + maxJump; i++) {
                if(nums[i] + i >= maxJump2 + current2) {
                    maxJump2 = nums[i];
                    current2 = i;
                    if(current2 + maxJump2 >= destination) {
                        return true;
                    }
                }
            }
            if(maxJump2 == 0) {
                return false;
            }
            current = current2;
            maxJump = maxJump2;
        }
        return false;
    }
}