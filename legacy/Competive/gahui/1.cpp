#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>

typedef struct {
	int no ; 
	std::string city ;
	long double dist_from_Seoul ; 
	long double start_time ;
	long double arrival_time;
} Station ;

Station stations[44] ;

int main(){

	for(int i = 1 ; i <= 43 ; i++){
		Station s = {i, "", 0, 0, 0} ; stations[i] = s ;
	}
	stations[1].city = "Seoul"; stations[1].dist_from_Seoul = 0.0 ;
	stations[2].city = "Yeongdeungpo"; stations[2].dist_from_Seoul = 9.1 ;	
	stations[3].city = "Anyang"; stations[3].dist_from_Seoul = 23.9 ;
	stations[4].city = "Suwon"; stations[4].dist_from_Seoul = 41.5 ;
	stations[5].city = "Osan"; stations[5].dist_from_Seoul = 56.5 ;

	stations[6].city = "Seojeongri"; stations[6].dist_from_Seoul = 66.5 ;
	stations[7].city = "Pyeongtaek"; stations[7].dist_from_Seoul = 75.0 ;
	stations[8].city = "Seonghwan"; stations[8].dist_from_Seoul = 84.4 ;
	stations[9].city = "Cheonan"; stations[9].dist_from_Seoul = 96.6 ;
	stations[10].city = "Sojeongni"; stations[10].dist_from_Seoul = 107.4 ;

	stations[11].city = "Jeonui"; stations[11].dist_from_Seoul = 114.9 ;
	stations[12].city = "Jochiwon"; stations[12].dist_from_Seoul = 129.3 ;
	stations[13].city = "Bugang"; stations[13].dist_from_Seoul = 139.8 ;
	stations[14].city = "Sintanjin"; stations[14].dist_from_Seoul = 151.9 ;
	stations[15].city = "Daejeon"; stations[15].dist_from_Seoul = 166.3 ;
	
	stations[16].city = "Okcheon"; stations[16].dist_from_Seoul = 182.5 ;
	stations[17].city = "Iwon"; stations[17].dist_from_Seoul = 190.8 ;
	stations[18].city = "Jitan"; stations[18].dist_from_Seoul = 196.4 ;
	stations[19].city = "Simcheon"; stations[19].dist_from_Seoul = 200.8 ;
	stations[20].city = "Gakgye"; stations[20].dist_from_Seoul = 204.6 ;

	stations[21].city = "Yeongdong"; stations[21].dist_from_Seoul = 211.6 ;
	stations[22].city = "Hwanggan"; stations[22].dist_from_Seoul = 226.2 ;
	stations[23].city = "Chupungnyeong"; stations[23].dist_from_Seoul = 234.7 ;
	stations[24].city = "Gimcheon"; stations[24].dist_from_Seoul = 253.8 ;
	stations[25].city = "Gumi"; stations[25].dist_from_Seoul = 276.7 ;

	stations[26].city = "Sagok"; stations[26].dist_from_Seoul = 281.3 ;
	stations[27].city = "Yangmok"; stations[27].dist_from_Seoul = 289.5 ;
	stations[28].city = "Waegwan"; stations[28].dist_from_Seoul = 296.0 ;
	stations[29].city = "Sindong"; stations[29].dist_from_Seoul = 305.9 ;
	stations[30].city = "Daegu"; stations[30].dist_from_Seoul = 323.1 ;

	stations[31].city = "Dongdaegu"; stations[31].dist_from_Seoul = 326.3 ;
	stations[32].city = "Gyeongsan"; stations[32].dist_from_Seoul = 338.6 ;
	stations[33].city = "Namseonghyeon"; stations[33].dist_from_Seoul = 353.1 ;
	stations[34].city = "Cheongdo"; stations[34].dist_from_Seoul = 361.8 ;
	stations[35].city = "Sangdong"; stations[35].dist_from_Seoul = 372.2 ;

	stations[36].city = "Miryang"; stations[36].dist_from_Seoul = 381.6 ;
	stations[37].city = "Samnangjin"; stations[37].dist_from_Seoul = 394.1 ;
	stations[38].city = "Wondong"; stations[38].dist_from_Seoul = 403.2 ;
	stations[39].city = "Mulgeum"; stations[39].dist_from_Seoul = 412.4 ;
	stations[40].city = "Hwamyeong"; stations[40].dist_from_Seoul = 421.8 ;

	stations[41].city = "Gupo"; stations[41].dist_from_Seoul = 425.2 ;
	stations[42].city = "Sasang"; stations[42].dist_from_Seoul = 430.3 ;
	stations[43].city = "Busan"; stations[43].dist_from_Seoul = 441.7 ;
	

	int N ; int Q ; std::cin >> N >> Q ;

	for(int i = 1 ; i <= N ; i++){
		std::string s1, s2 ,s3 ;
		std::cin >> s1 >> s2 >> s3;
		long double sh = 0; long double ah = 0;

		if(s2[0] != '-'){
			int h = s2[1] - '0';
			if(s2[0] >= 1) h += (s2[0] - '0') * 10;
			int m = s2[4] - '0' ;
			if(s2[3] >= 1) m += (s2[3] - '0') * 10;
			ah += (long double)h + (long double)m/60 ;
		}

		if(s3[0] != '-'){
			int h = s3[1] - '0' ;
			if(s3[0] >= 1) h += (s3[0] - '0') * 10;
			int m = s3[4] - '0' ;
			if(s3[3] >= 1) m += (s3[3] - '0') * 10; 
			sh += (long double)h + (long double)m/60 ;	
		}

		int j ;
		for(j = 1 ; j <= 43 ; j++){
			if(stations[j].city == s1){
				stations[j].start_time = sh;
				stations[j].arrival_time = ah;
				break; 
			} 
		}
		//assert(j != 44);
	}

	for(int q = 0 ; q < Q ; q++){
		std::string ss, as ;
		std::cin >> ss >> as ;
		int si, ai ;
		for(si = 1 ; si <= 43 ; si++) if(stations[si].city == ss) break;
		for(ai = 1 ; ai <= 43 ; ai++) if(stations[ai].city == as) break;

		//assert(si != 44 && ai != 44);

		long double dist ; 
		if(stations[si].dist_from_Seoul > stations[ai].dist_from_Seoul) 
			dist = stations[si].dist_from_Seoul - stations[ai].dist_from_Seoul ;
		else 
			dist = stations[ai].dist_from_Seoul - stations[si].dist_from_Seoul ;
	
		long double time = 0;
		if(stations[si].start_time > stations[ai].arrival_time) time += 24;
		time += stations[ai].arrival_time - stations[si].start_time ;
        //assert(time >= 0 && time <= 24);
        //printf("%Lf\n", dist/time);
		//std::cout << time << "\n";
		std::cout.precision(12);
		std::cout << dist/time << "\n";
	}


	return 0;
}