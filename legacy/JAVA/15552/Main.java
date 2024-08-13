import java.io.* ;
import java.util.* ;

class Main{

	static ArrayList<Integer> graph[] = new ArrayList[100000] ;
        public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(bf.readLine());
	for(int i = 0 ; i < 100000 ; i++){
		graph[i] = new ArrayList<Integer>();
	}

        for(int i = 0 ; i < N ; i++){
            int ans ;
            StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
            ans = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());
            bw.write(ans + "\n");
        }
        
        bf.close();
        bw.flush(); 
        bw.close();
    }
}
