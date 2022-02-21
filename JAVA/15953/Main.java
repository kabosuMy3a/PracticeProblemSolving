import java.io.* ;
import java.util.* ;
import java.lang.Math;

class Main{
        public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(bf.readLine());
        for(int t = 0 ; t < T ; t++){
            int ans ;
            StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
            int a1 = Integer.parseInt(st.nextToken());
            int a2 = Integer.parseInt(st.nextToken());

            int[] a1_prize = {5000000, 3000000, 2000000, 500000, 300000, 100000};
            int[] a2_prize = {5120000, 2560000, 1280000, 640000, 320000} ; 
            int cur = 0; int total= 0 ;
            for(int i = 1 ; i <= 6 ; i++){
                cur += i ;
                if(a1 <= cur){
                    total += a1_prize[i-1];
                    break ;
                }
            }
            cur = 0 ;
            for(int i = 0 ; i < 5 ; i++){
                cur += (int)Math.pow(2,i);
                if(a2 <= cur){
                    total += a2_prize[i];
                    break;
                }
            }

            bw.write(total + "\n");
            
        }
        
        bf.close();
        bw.flush(); 
        bw.close();
    }
}
