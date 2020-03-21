class Solution {
    public int firstUniqChar(String s) {
        if(s.length() == 0) {
            return -1;
        }
        List<Character> l = new ArrayList<Character>();
        Set<Character> u = new HashSet<Character>();
        for(int i = 0;i < s.length(); i++) {
            if(l.contains(s.charAt(i))) {
                u.add(s.charAt(i));
            }
            else {
                l.add(s.charAt(i));
            }
        }
        for(char c : u) {
            l.remove(l.indexOf(c));
        }
        String s2 = "";
        if(l.size() == 0) {
            return -1;
        }
        s2 += l.get(0);
        System.out.println(l.size());
        return s.indexOf(s2);
    }
}