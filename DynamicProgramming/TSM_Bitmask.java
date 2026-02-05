package DynamicProgramming;

import java.util.Arrays;

public class TSM_Bitmask {
    private static int tsp(int[][] graph,int[][] memo, int mask,int pos, int n) {
        if(mask == (1<<n) - 1){
            return graph[pos][0];
        }
        if(memo[mask][pos] != -1){
            return memo[mask][pos];
        }
        int res = Integer.MAX_VALUE;
        for(int i=1;i<n;i++){
            if((mask & (1<<i)) == 0){
                res = Math.min(res,tsp(graph, memo, (mask | (1<<i)), i, n)+ graph[pos][i]);
            }
        }

        return memo[mask][pos] = res;
        
    }

    public static void main(String[] args) {
        int[][] graph = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}
        };
        int n = graph.length;
        int[][] memo = new int[1<<n][n];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        System.out.println(tsp(graph,memo, 1, 0, n));
    }
}
