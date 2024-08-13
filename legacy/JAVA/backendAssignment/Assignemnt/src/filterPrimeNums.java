import java.io.BufferedReader ;
import java.io.IOException ;
import java.io.InputStreamReader ;
import java.io.BufferedWriter ;
import java.io.OutputStreamWriter ;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashSet ;
import java.lang.Math ;


public class filterPrimeNums {
    static BufferedWriter bw ; static BufferedReader br ;
    public static int repeatUntilDone(int order) throws IOException{
        int num ;
        while(true) {
            try {
                bw.write("숫자 "); bw.write(order + " : ");
                bw.flush();
                num = Integer.parseInt(br.readLine()) ;
                break ;
            } catch (NumberFormatException e) {
                bw.write("[입력 오류] : 숫자로 입력해주세요.\n");
            }
        }
        return num ;
    }

    static int sieve[] = new int[500000] ;
    public static void sieveInit(){
        for(int i = 2 ; i < 500000 ; i++){
            sieve[i] = 1 ;
        }

        for(int i = 2 ; i < 500000 ; i++){
            if(sieve[i] == 0) continue ;
            for(int j = i + i ; j < 500000 ; j += i){
                sieve[j] = 0 ;
            }
        }
    }

    public static boolean isPrime(int num) {
        if(num < 500000){
            if(sieve[num] != 0){
                return true ;
            } else{
                return false ;
            }
        } else {
            for(int i = 2 ; i < (int)Math.sqrt(num) ; i++){
                if(num % i == 0) return false ;
            }
        }
        return true ;
    }

    public static void main(String[] args) throws IOException {

        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader((new InputStreamReader(System.in)));

        LinkedHashSet<Integer> set = new LinkedHashSet<Integer>();
        ArrayList<Integer> arr = new ArrayList<Integer>();

        sieveInit();

        int order = 1 ;
        while(true){
            int num = repeatUntilDone(order);
            if(num == 0) break ;
            int prev_sz = set.size();
            set.add(num);
            if(prev_sz == set.size()){
                bw.write("[입력오류] : 이미 입력된 숫자 입니다.\n");
                bw.flush();
                continue ;
            }
            if(isPrime(num)){
                arr.add(num);
            }
            order++ ;
        }

        bw.write("결과 : ");
        Iterator<Integer> it = arr.iterator();
        while(it.hasNext()){
            bw.write(it.next().toString());
            if(it.hasNext()) bw.write(", ");
        }

        bw.flush();
        bw.close();
    }
}

