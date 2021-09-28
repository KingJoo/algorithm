import java.util.*;
class Solution{
	static int result;
    static int N;
    static int K;
    static int[] arr;
    public static void main(String args[]) throws Exception{
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++){
			//for (int tc = 1; tc <= T; tc++) {
          		N = sc.nextInt();
            	K = sc.nextInt();
            	arr = new int[N];
            	result=0;
            	for (int i = 0; i < N; i++)
                	arr[i] = sc.nextInt();
                solve(0, 0);
    	        System.out.println("#"+test_case+ " "+result);//System.out.println("#"+tc+ " "+result);
            //}
		}
    }
    public static void solve(int index, int sum) {
        sum+=arr[index];
        if(K==sum)
            result++;
        if(index >=N-1)
            return;
        solve(index+1, sum);
        solve(index+1, sum-arr[index]);
    }
}