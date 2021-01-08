class Solution {
    int euclideanAlgorithm(int n1, int n2) {
        if (n2 == 0) {
            return n1;
        }
        return euclideanAlgorithm(n2, n1 % n2);
    }
    public String helper(String s1, String s2) {
        String[] a = s1.split("/");
        String[] b = s2.split("/");
        int aNum = Integer.parseInt(a[0]);
        int aDen = Integer.parseInt(a[1]);
        int bNum = Integer.parseInt(b[0]);
        int bDen = Integer.parseInt(b[1]);
        int cNum = cNum = aNum * bDen + bNum * aDen;
        int cDen = aDen * bDen;
        int gcd = euclideanAlgorithm(Math.abs(cNum), Math.abs(cDen));
        cNum /= gcd;
        cDen /= gcd;
        String s = Integer.toString(cNum) + '/' + Integer.toString(cDen);
        return s;
    }
    public String fractionAddition(String expression) {
        List<Integer> denominators = new ArrayList<Integer>();
        String prev = "";
        String current = "";
        boolean d = false;
        int start = 0;
        for(int i = 0; i < expression.length(); i++) {
            prev += expression.charAt(i);
            if(d) {
                if(i + 1 < expression.length() && expression.charAt(i + 1) == '0') {
                    continue;
                }
                start = i + 1;
                d = false;
                break;
            }
            else if(expression.charAt(i) == '/') {
                d = true;
            }
        }
        for(int i = start; i < expression.length(); i++) {
            current += expression.charAt(i);
            if(d) {
                if(i + 1 < expression.length() && expression.charAt(i + 1) == '0') {
                    continue;
                }
                d = false;
                prev = helper(prev, current);
                current = "";
            }
            else if(expression.charAt(i) == '/') {
                d = true;
            }
        }
        return prev;
    }
}