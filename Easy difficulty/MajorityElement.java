class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        if(nums.length == 1) {
            return(nums[0]);
        }
        for(int i = 0; i < nums.length; i++) {
            if(count.containsKey(nums[i])) {
                int c = count.get(nums[i]);
                c++;
                if(c > (nums.length / 2)) {
                    return(nums[i]);
                }
                count.put(nums[i], c);
            }
            else {
                count.put(nums[i], 1);
            }
        }
        return 0;
    }
}