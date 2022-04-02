#include <iostream>


class Person {
	int id ;
	std::string name ;

	public :
		virtual void aboutMe(){
			std::cout << "person\n" ;
		} 

		void print_id(){
			std::cout << id << "\n" ;
		}

		void set(std::string name, int id = 3){
			this->id = id;
			this->name = name ;
		}

		int get_id(){return id;}

		virtual bool addCourse(std::string s) = 0 ;


		Person(){}
		Person(int a) : id(a) {}
		virtual ~Person() {
			std::cout<< "delete person\n";
		}
} ;

class Student : public Person {
	public :
		void aboutMe(){
			std::cout << "student\n" ;
		}

		bool addCourse(std::string s){
			std::cout << "added" << "\n";
			return true;
		}

		void operator+(Student & other){
			std::cout << other.get_id() + this->get_id() << "\n";
		}
		Student(std::string name){set(name);}
		Student(std::string name, int id){set(name, id);}
		~Student(){
			std::cout << "delete student\n";
		}

};


int main(){
	//Student * p = new Student(1);
	Person * p =  new Student("sungyu"); //Static binding
	Student * s = new Student("gururu", 5) ;
	*s + *((Student *)p) ;
	p->aboutMe();
	p->print_id();
	delete p ; 
	return 0 ;
}

