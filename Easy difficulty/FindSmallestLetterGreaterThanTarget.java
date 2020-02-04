class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        int min = 27;
        char minI = letters[0];
        String s = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0; i < s.length(); i++) {
            m.put(s.charAt(i), i);
        }
        int t = m.get(target);
        for(int i = 0; i < letters.length; i++) {
            int j = m.get(letters[i]);
            int dif;
            if(t < j) {
                dif = j - t;
            }
            else if(j < t) {
                dif = j - t + 26;
            }
            else {
                dif = 26;
            }
            if(dif < min) {
                min = dif;
                minI = letters[i];
            }
        }
        return minI;
    }
}