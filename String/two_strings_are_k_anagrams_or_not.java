import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class two_strings_are_k_anagrams_or_not {

    private static int[] hash1 = new int[256];
    private static int[] hash2 = new int[256];
    private static int k;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        int asc = 0;
        int diff_charcters = 0;

        String s = br.readLine();
        k = Integer.parseInt(s);

        for(int i=0; i < s1.length(); i++) {
            asc = (int) s1.charAt(i);
            hash1[asc]++;
        }
        for(int i=0; i < s2.length(); i++) {
            asc = (int) s2.charAt(i);
            hash2[asc]++;
        }

        for(int i = 0; i<256; i++) {
            if(hash1[i] != hash2[i]) {
                diff_charcters = Math.abs(hash1[i] - hash2[i]);
            }
        }

        if(diff_charcters <= k) {
            System.out.println("Two strings are k anagrams");
        } else {
            System.out.println("Not k anagrams of each other");
        }
    }

}
