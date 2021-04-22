class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        int[] a = new int[k];
        Map<Integer, HashSet<Integer>> m = new HashMap<Integer, HashSet<Integer>>();
        for(int i = 0; i < logs.length; i++) {
            int id = logs[i][0];
            int time = logs[i][1];
            if(!m.containsKey(id)) {
                HashSet<Integer> s = new HashSet<Integer>();
                s.add(time);
                m.put(id, s);
            }
            else {
                HashSet<Integer> s = m.get(id);
                s.add(time);
                m.put(id, s);
            }
        }
        for(int i : m.keySet()) {
            a[m.get(i).size() - 1]++;
        }
        return a;
    }
}