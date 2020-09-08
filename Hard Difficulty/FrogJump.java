class Solution {
    public boolean canCross(int[] stones) {
        // have a map with key being stones[i] and value being where the jump came from
        Map<Integer, HashSet<Integer>> m = new HashMap<Integer, HashSet<Integer>>();
        int goal = stones[stones.length - 1];
        for(int i = 0; i < stones.length; i++) {
            m.put(stones[i], new HashSet<Integer>());
        }
        if(!m.containsKey(1)) {
            return false;
        }
        else {
            m.get(1).add(0);
        }
        for(int i = 1; i < stones.length - 1; i++) {
            int stone = stones[i];
            HashSet<Integer> hs = m.get(stones[i]);
            for(int j : hs) {
                int k = stone - j;
                if(m.containsKey(stone + (k - 1)) && (k - 1) != 0) {
                    m.get(stone + (k - 1)).add(stone);
                }
                if(m.containsKey(stone + k)) {
                    m.get(stone + k).add(stone);
                }
                if(m.containsKey(stone + (k + 1))) {
                    m.get(stone + (k + 1)).add(stone);
                }
            }
        }
        if(m.get(goal).size() > 0) {
            return true;
        }
        return false;
    }
}