class Solution {
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> l = new ArrayList<Integer>();
        List<Integer> r = new ArrayList<Integer>();
        if(nums.length == 0) {
            return l;
        }
        if(nums.length == 1) {
            l.add(0);
            return l;
        }
        for(int i = nums.length - 1; i >= 0; i--){
            l.add(nums[i]);
            Collections.sort(l);
            r.add(0, l.indexOf(nums[i]));
        }
        return r;
    }
}