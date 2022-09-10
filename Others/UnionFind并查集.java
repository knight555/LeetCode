//https://www.nowcoder.com/profile/819087490/codeBookDetail?submissionId=200088328
import java.util.*;

class UnionFind {

    //存放结点对应的父节点 <子,父>
    Map<Integer, Integer> mp = new HashMap<>();

    public UnionFind(Set<Integer> sets){
        for(Integer i:sets){
            mp.put(i,i);
        }
    }

    public Integer find(int i){
        if(mp.get(i) == i){
            return i;
        }
        else{
            int pa = mp.get(i);
            mp.put(i, find(pa));
            return mp.get(i);
        }
    }

    public boolean union(int e1, int e2){
        int p1 = find(e1);
        int p2 = find(e2);
        mp.put(p1, p2);
        return true;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int i=0;i<T;i++){
            Set<Integer> s = new HashSet<>();
            int n = sc.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            for(int j=0;j<n;j++){
                x[j] = sc.nextInt();
                y[j] = sc.nextInt();
                s.add(x[j]);
                s.add(y[j]);
            }
            System.out.println(get_max_group(x,y,s));
        }
    }

    public static int get_max_group(int[] x, int[] y, Set<Integer> s){
        UnionFind uf = new UnionFind(s);
        for(int j=0;j<x.length;j++){
            uf.union(x[j], y[j]);
        }
        Map<Integer, Integer> times = new HashMap<>();
        for(Integer i: s){
            int root = uf.find(i);
            times.put(root, times.getOrDefault(root, 0)+1);
        }
        int maxNum = 0;
        for(Integer i:times.keySet()){
            maxNum = Math.max(times.get(i), maxNum);
        }
        return maxNum;
    }

}