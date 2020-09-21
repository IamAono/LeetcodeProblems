class Solution {
    public int candy(int[] ratings) {
        int candies = 0;
        if(ratings.length == 0) {
            return 0;
        }
        if(ratings.length == 1) {
            return 1;
        }
        int[] c = new int[ratings.length];
        if(ratings[0] > ratings[1]) {
            c[0] = 2;
        }
        else {
            c[0] = 1;
        }
        for(int i = 1; i < ratings.length; i++) {
            if(ratings[i] > ratings[i - 1]) {
                c[i] = c[i - 1] + 1;
            }
            else {
                c[i] = 1;
            }
        }
        if(ratings[ratings.length - 1] > ratings[ratings.length - 2]) {
            c[c.length - 1] = c[c.length - 2] + 1;
        }
        for(int i = ratings.length - 2; i > -1; i--) {
            if(ratings[i] > ratings[i + 1]) {
                c[i] = Math.max(c[i + 1] + 1, c[i]);
            }
            else {
                c[i] = c[i];
            }
        }
        for(int i = 0; i < c.length; i++) {
            candies += c[i];
        }
        return candies;
    }
}