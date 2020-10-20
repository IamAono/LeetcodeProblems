class Solution {
    public class Person {
        int val;
        ArrayList<Person> friends;
        Person(int v) {
            val = v;
            friends = new ArrayList<Person>();
        }
        void add(Person p) {
            friends.add(p);
        }
    }
    public int findCircleNum(int[][] M) {
        ArrayList<Person> l = new ArrayList<Person>();
        int circles = 0;
        for(int i = 0; i < M.length; i++) {
            l.add(new Person(i));
        }
        for(int i = 0; i < M.length; i++) {
            Person p = l.get(i);
            for(int j = 0; j < M[i].length; j++) {
                if(M[i][j] == 1 && i != j) {
                    p.add(l.get(j));
                }
            }
        }
        Set<Integer> visited = new HashSet<Integer>();
        while(l.size() > 0) {
            Person p = l.get(0);
            visited.add(p.val);
            l.remove(l.get(0));
            Queue<Person> f = new LinkedList<Person>();
            for(Person p2 : p.friends) {
                f.add(p2);
            }
            while(f.size() > 0) {
                int fs = f.size();
                while(fs > 0) {
                    Person p2 = f.peek();
                    l.remove(p2);
                    f.remove();
                    visited.add(p2.val);
                    for(Person p3 : p2.friends) {
                        if(!visited.contains(p3.val)) {
                            f.add(p3);
                            visited.add(p3.val);
                        }
                    }
                    fs--;
                }
            }
            circles++;
        }
        return circles;
    }
}