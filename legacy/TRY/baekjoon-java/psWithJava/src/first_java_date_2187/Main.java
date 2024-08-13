package first_java_date_2187;

import java.io.* ;
import java.util.* ;

class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while(true){
            String line = bf.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            int day = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken()) ;
            int year = Integer.parseInt(st.nextToken());
            int ans = 0 ;
            if(day == 0 && month == 0 && year == 0) break;

            ans += day ;
            for(int i = 1 ; i <= 12 ; i++){
                if(i < month){
                    if(i == 1 || i == 3 || i ==5 || i ==7 || i ==8 || i ==10){
                        ans += 31 ;
                    } else if(i == 4 || i == 6 || i == 9 || i == 11){
                        ans += 30 ;
                    } else {
                        if((year % 4 == 0 && year % 100 != 0) ||
                                (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)){
                            ans += 29 ;
                        } else {
                            ans += 28 ;
                        }
                    }
                } else {
                    break ;
                }

            }

            bw.write(ans+"\n");
            bw.flush();
        }

        bf.close();
        bw.close();
    }
}