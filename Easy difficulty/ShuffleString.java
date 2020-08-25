class Solution {
    public String restoreString(String s, int[] indices) {
        Queue<Pair> pq = new PriorityQueue<Pair>(new Comparator<Pair>() {
            @Override
            public int compare(Pair a, Pair b) {
                return Integer.compare((int) a.getValue(), (int) b.getValue());
            }
        });
        for(int i = 0; i < s.length(); i++) {
            Pair p = new Pair(s.charAt(i), indices[i]);
            pq.offer(p);
        }
        String s2 = "";
        while(!pq.isEmpty()) {
            Pair p = pq.poll();
            s2 += p.getKey();
        }
        return s2;
    }
}