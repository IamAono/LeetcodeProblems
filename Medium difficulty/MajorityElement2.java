class Solution {
    public List<Integer> majorityElement(int[] nums) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        List<Integer> l = new ArrayList<Integer>();
        if(nums.length == 0) {
            return l;
        }
        int n = nums.length / 3;
        for(int i = 0; i < nums.length; i++) {
            if(count.containsKey(nums[i])) {
                count.put(nums[i], count.get(nums[i]) + 1);
            }
            else {
                count.put(nums[i], 1);
            }
        }
        Set<Integer> s = count.keySet();
        for(int i : s) {
            if(count.get(i) > n) {
                l.add(i);
            }
        }
        return l;
    }
}