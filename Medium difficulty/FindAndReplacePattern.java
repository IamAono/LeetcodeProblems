class Solution {
    public String getPattern(String word) {
        List<Character> l = new ArrayList<Character>();
        String p = "";
        int n = 0;
        for(int i = 0; i < word.length(); i++) {
            if(l.contains(word.charAt(i))) {
                int j = l.indexOf(word.charAt(i));
                p += Integer.toString(j);
            }
            else {
                p += Integer.toString(n);
                l.add(word.charAt(i));
                n++;
            }
        }
        return p;
    }
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        String p = getPattern(pattern);
        List<String> l = new ArrayList<String>();
        for(int i = 0; i < words.length; i++) {
            if(getPattern(words[i]).equals(p)) {
                l.add(words[i]);
            }
        }
        return l;
    }
}