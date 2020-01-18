class Solution {
    public int lengthOfLongestSubstring(String s) {
        List<Character> l = new ArrayList<Character>();
        int longest = 0;
        for(int i = 0; i < s.length(); i++) {
            if(!l.contains(s.charAt(i))) {
                l.add(s.charAt(i));
            }
            else {
                longest = Math.max(l.size(), longest);
                int e = l.indexOf(s.charAt(i));
                for(int j = 0; j <= e; j++) {
                    l.remove(0);
                }
                l.add(s.charAt(i));
            }
        }
        longest = Math.max(l.size(), longest);
        return longest;
    }
}