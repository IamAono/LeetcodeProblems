class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> l = new ArrayList<List<String>>();
        Arrays.sort(products);
        List<String> p = new ArrayList<String>();
        String s = "";
        for(int i = 0; i < products.length; i++) {
           p.add(products[i]);
        }
        for(int i = 0; i < searchWord.length(); i++) {
            s += searchWord.charAt(i);
            int sLen = s.length();
            List<String> l2 = new ArrayList<String>();
            for(int j = 0; j < p.size(); j++) {
                String s2 = p.get(j);
                if(s2.substring(0, Math.min(sLen, s2.length())).equals(s)) {
                    l2.add(s2);
                }
                else {
                    p.remove(s2);
                    j--;
                }
                if(l2.size() == 3) {
                    break;
                }
            }
            l.add(l2);
        }
        return l;
    }
}