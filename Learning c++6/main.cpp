#include <iostream>
#include <fstream>


using namespace std;  //进行类读写的时候写入的是数据域
 

class Student
{
	public:
		Student()
		{
			sum = 0;
			name = "";
		}
		Student(int c, string a)
		{
			sum = c;
			name = a ;
		}
	private:
		int sum;
		string name;
	
};

int main(int argc, char** argv) {
	fstream binaryio;
	binaryio.open("1.dat", ios::out | ios::binary); 
	
	Student student1(10, "asd");
	Student student2(20, "assd");
	
	binaryio.write(reinterpret_cast<char *>(&student1),sizeof(Student));
	binaryio.write(reinterpret_cast<char *>(&student2),sizeof(Student));
	
	binaryio.close();
	
	return 0;
}
