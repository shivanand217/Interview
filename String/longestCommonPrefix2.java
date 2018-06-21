import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class longestCommonPrefix2 {

    /** This is another naive approach but we match character wise, we check string by string O(N*M) **/
    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int n = Integer.parseInt(s);
        String[] str = br.readLine().split(" ");

        int min=Integer.MAX_VALUE;
        for(int i=0; i < str.length; i++){
            min=Math.min(str[i].length(),min);
        }

        char same;
        StringBuilder prefix = new StringBuilder("");
        boolean indicator=false;

        for(int i=0;i<min;i++) {
            same=str[0].charAt(i);
            indicator=true;
            for (int j=1; j < str.length; j++) {
                if(str[j].charAt(i) != same) {
                    indicator=false;
                    break;
                }
            }
            if(indicator==true) {
                prefix.append(same);
            } else {
                break;
            }
        }

        if(prefix.length() == 0) {
            System.out.println("Longest common prefix does not exists.");
        } else {
            System.out.println("Longest common prefix is "+prefix);
        }

    }
}
