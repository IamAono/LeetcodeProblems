class Solution {
    public int countHomogenous(String s) {
        int mod = 1000000007;
        Map<Integer, Integer> h = new HashMap<Integer, Integer>();
        Pair<Integer, Integer> p = new Pair<Integer, Integer>(1,1);
        h.put(1,1);
        int ans = 0;
        char c = s.charAt(0);
        int chain = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s.charAt(i) == c) {
                chain++;
            }
            else {
                if(h.containsKey(chain)) {
                    ans += h.get(chain);
                }
                else {
                    while(p.getKey() < chain) {
                        int current = p.getKey();
                        p = new Pair<Integer, Integer>(current + 1, (h.get(current) + h.values().size() + 1) % mod);
                        h.put(p.getKey(), p.getValue());
                    }
                    ans += h.get(chain);
                }
                chain = 1;
                c = s.charAt(i);
            }
        }
        if(h.containsKey(chain)) {
            ans += h.get(chain);
        }
        else {
            while(p.getKey() < chain) {
                int current = p.getKey();
                p = new Pair<Integer, Integer>(current + 1, (h.get(current) + h.values().size() + 1) % mod);
                h.put(p.getKey(), p.getValue());
            }
            ans += h.get(chain);
        }
        return ans;
    }
}