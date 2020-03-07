class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        char c = 'a';
        for(int i = 0; i < s.length(); i++) {
            if(m.containsKey(s.charAt(i))) {
                m.put(s.charAt(i), m.get(s.charAt(i)) + 1);
            }
            else {
                m.put(s.charAt(i), 1);
            }
        }
        for(int i = 0; i < t.length(); i++) {
            if(!m.containsKey(t.charAt(i))) {
                c = t.charAt(i);
                break;
            }
            if(m.get(t.charAt(i)) == 0) {
                c = t.charAt(i);
                break;
            }
            m.put(t.charAt(i), m.get(t.charAt(i)) - 1);
        }
        return c;
    }
}