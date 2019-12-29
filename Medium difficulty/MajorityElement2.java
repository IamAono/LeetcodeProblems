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
                int c = count.get(nums[i]);
                c++;
                if(c > n && !l.contains(nums[i])) {
                    l.add(nums[i]);
                }
                count.put(nums[i], c);
            }
            else {
                count.put(nums[i], 1);
                if(1 > n) {
                    l.add(nums[i]);
                }
            }
        }
        return l;
    }
}