#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>


typedef struct{

    std::string name ;
    int kor ;
    int eng ;
    int math ;

} Student ;

bool compare(Student a, Student b){
    if(a.kor != b.kor){
        return a.kor > b.kor ; 
    } else if(a.eng != b.eng){
        return a.eng < b.eng ;
    } else if(a.math != b.math){
        return a.math > b.math ;
    } else 
        return a.name < b.name ;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0x0);
    std::cout.tie(0x0);
    
    int n ;
    std::cin >> n ;

    std::vector<Student> students ; 

    for(int i = 0 ; i < n ; i++){
        std::string name ;
        std::cin >> name;
        int kor, eng, math ;
        std::cin >> kor >> eng >> math;
        Student s = {name, kor, eng, math};
        students.push_back(s);
    }

    std::sort(students.begin(), students.end(), compare);

    for(int i = 0 ; i < students.size() ; i++){ 
        printf("%s\n", students[i].name.c_str()) ;
    }

    return 0 ;
}