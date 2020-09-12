class MapSum {
    Map<String, Integer> m = new HashMap<String, Integer>();
    /** Initialize your data structure here. */
    public MapSum() {
        
    }
    
    public void insert(String key, int val) {
        m.put(key, val);
    }
    
    public int sum(String prefix) {
        int x = 0;
        Set<String> s = m.keySet();
        for(String s2 : s) {
            if(prefix.length() > s2.length()) {
                continue;
            }
            if(s2.substring(0, prefix.length()).equals(prefix)) {
                x += m.get(s2);
            }
        }
        return x;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */