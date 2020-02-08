class Node {
    List<Integer> l = new ArrayList<Integer>();
    int val;
    Node(int v) {
        val = v;
    }
    void add(int i) {
        l.add(i);
    }
    List<Integer> getList() {
        return l;
    }
}
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        List<Node> l = new ArrayList<Node>();
        List<Node> canVisit = new ArrayList<Node>();
        for(int i = 0; i < rooms.size(); i++) {
            Node n = new Node(i);
            for(int j = 0; j < rooms.get(i).size(); j++) {
                n.add(rooms.get(i).get(j));
            }
            l.add(n);
            if(i == 0) {
                canVisit.add(n);
            }
        }
        Set<Integer> visited = new HashSet<Integer>();
        visited.add(0);
        for(int i = 0; i < canVisit.size(); i++) {
            for(int j = 0; j < canVisit.get(i).getList().size(); j++) {
                int k = canVisit.get(i).getList().get(j);
                if(!visited.contains(k)) {
                    canVisit.add(l.get(k));
                    visited.add(k);
                }
            }
        }
        if(canVisit.size() == rooms.size()) {
            return true;
        }
        return false;
    }
}