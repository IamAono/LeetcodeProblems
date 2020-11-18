class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> m = new HashMap<Integer, Integer>();
        for(int i = 0; i < arr.length; i++) {
            if(m.containsKey(arr[i])) {
                m.put(arr[i], m.get(arr[i]) + 1);
            }
            else {
                m.put(arr[i], 1);
            }
        }
        ArrayList<Integer> a = new ArrayList<Integer>(m.values());
        Collections.sort(a);
        int removed = 0;
        int index = 0;
        while(removed < k) {
            removed += a.get(index);
            index++;
        }
        if(removed > k) {
            return a.size() - (index - 1);
        }
        return a.size() - index;
    }
}