import java.util.Scanner;

class Solution{
	public static void main(String args[]) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
        for(int t=1;t<=n;t++){
            int[] arr=new int[sc.nextInt()];
            int c=0;
            for(int i=0;i<arr.length;i++)
                arr[i]=sc.nextInt();
            for(int i=1;i<arr.length-1;i++)
                if((arr[i-1]>arr[i+1]&&(arr[i]<arr[i-1]&&arr[i]>arr[i+1]))||(arr[i-1]<arr[i+1]&&(arr[i]>arr[i-1]&&arr[i]<arr[i+1])))	c++;
            System.out.println("#"+t+" "+c);
        }
	}
}