class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> ss = new HashSet<String>();
        Set<String> answers = new HashSet<String>();
        if(s.length() < 10) {
            return new ArrayList<String>();
        }
        else {
            for(int i = 0; i <= s.length() - 10; i++) {
                String s2 = s.substring(i, i + 10);
                if(!ss.add(s2)) {
                    answers.add(s2);
                }
            }
        }
        return new ArrayList<String>(answers);
    }
}