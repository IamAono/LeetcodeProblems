class MapSum {
    Map<String, Integer> m = new HashMap<String, Integer>();
    Map<String, Integer> prefixes = new HashMap<String, Integer>();
    /** Initialize your data structure here. */
    public MapSum() {
        
    }
    
    public void insert(String key, int val) {
        boolean contains = false;
        int prev = 0;
        if(m.containsKey(key)) {
            prev = m.get(key);
            m.put(key, val);
            contains = true;
        }
        else {
            m.put(key, val);
        }
        String s = "";
        for(int i = 0; i < key.length(); i++) {
            s += key.charAt(i);
            if(contains) {
                prefixes.put(s, prefixes.get(s) - prev + val);
            }
            else {
                prefixes.put(s, prefixes.getOrDefault(s, 0) + val);
            }
        }
    }
    
    public int sum(String prefix) {
        return(prefixes.getOrDefault(prefix, 0));
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */