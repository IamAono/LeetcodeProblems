class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(n == 0) {
            return true;
        }
        if(flowerbed.length == 1) {
            if(flowerbed[0] == 1) {
                return false;
            }
            if(n == 1) {
                return true;
            }
            return false;
        }
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
            if(n == 0) {
                return true;
            }
        }
        for(int i = 1; i < flowerbed.length - 1; i++) {
            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
                if(n == 0) {
                    return true;
                }
            }
        }
        if(flowerbed[flowerbed.length - 1] == 0 && flowerbed[flowerbed.length - 2] == 0) {
            n--;
            if(n==0) {
                return true;
            }
        }
        return false;
    }
}