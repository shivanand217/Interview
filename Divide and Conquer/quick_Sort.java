import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class quick_Sort {

    public static int partition(int arr[],int low,int high){
        /** taking last element as pivot **/
        int pivot = arr[high];
        int i=low-1;

        int j=low;
        while(j < high){
            if(arr[j] < pivot) {
                i++;

                /** swapping values **/
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            j++;
        }

        /** swapping i+1 with pivot to fix the pivot at right position **/
        int temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;

        return (i+1);
    }

    public static void quickSort(int arr[],int low,int high){
        if(low < high) {
            int pivot = partition(arr, low, high);
            /** sort the two subarray after partition **/
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int n = Integer.parseInt(s);
        int[] arr = new int[n];

        String[] str = br.readLine().split(" ");
        for(int i=0; i<n; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }
        System.out.println("Before Sorting");
        for(int i: arr) {
            System.out.print(i+" ");
        }   System.out.println();

        quickSort(arr, 0, n-1);

        System.out.println("After sorting");
        for(int i: arr) {
            System.out.print(i+" ");
        } System.out.println();

    }

}
