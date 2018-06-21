import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/** Very naive approach, we check string by string O(N*M) **/
public class longestCommonPrefix {

    public static StringBuilder LCP(StringBuilder a,StringBuilder b) {

        StringBuilder prefix = new StringBuilder("");

        for(int i=0; (i < a.length() && i < b.length()); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                break;
            }
            prefix.append(a.charAt(i));
        }

        return prefix;
    }

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int n = Integer.parseInt(s);
        String[] str = br.readLine().split(" ");

        for(int i=0;i<str.length; i++){
            System.out.print(str[i]+" ");
        } System.out.println();

        StringBuilder prefix = new StringBuilder(str[0]);
        for(int i=1; i<str.length; i++) {
            StringBuilder p = new StringBuilder(str[i]);
            prefix = LCP(prefix,p);
        }

        if(prefix.length() == 0) {
            System.out.println("Longest common prefix does not exists.");
        } else {
            System.out.println("Longest common prefix is "+prefix);
        }
    }

}
