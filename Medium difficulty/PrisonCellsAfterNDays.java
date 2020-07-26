class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        if(N == 0 || cells == null || cells.length == 0) {
            return cells;
        }
        int c = 0;
        Set<String> s = new HashSet<String>();
        int N2 = 0;
        while(N2 < N) {
            int[] next = nextDay(cells);
            String s2 = Arrays.toString(next);
            if(!s.contains(s2)) {
                s.add(s2);
                c++;
            }
            else {
                break;
            }
            cells = next;
            N2++;
        }
        if(N2 < N) {
            N %= c;
            while(N > 0) {
                cells = nextDay(cells);
                N--;
            }
        }
        return cells;
    }
    public int[] nextDay(int[] cells) {
        int[] a = new int[cells.length];
        for(int i = 1; i < cells.length - 1; i++) {
            if(cells[i - 1] == cells[i + 1]) {
                a[i] = 1;
            }
            else {
                a[i] = 0;
            }
        }
        return a;
    }
}