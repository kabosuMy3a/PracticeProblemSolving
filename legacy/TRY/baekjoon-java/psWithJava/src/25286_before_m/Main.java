import java.io.* ;
import java.util.* ;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for(int t = 0 ; t < T ; t++){
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int year = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if(m == 1){
                bw.write((year-1) + " 12 31\n");
            } else if(m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11){
                bw.write(year + " " + (m-1) +" 31\n");
            } else if(m == 5 || m == 7 || m== 10 || m == 12){
                bw.write(year +" " + (m-1) + " 30\n");
            } else {
                if((year % 4 == 0 && year % 100 != 0) ||
                        (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)){
                    bw.write(year+" 2 29\n");
                } else {
                    bw.write(year+" 2 28\n");
                }
            }
            bw.flush();
        }

        br.close();
        bw.close();
    }
}