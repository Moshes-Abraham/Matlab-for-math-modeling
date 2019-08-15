#include <string>
#include <iostream>
using namespace std;

#include <Eigen/Eigen>
#define LEN 33		// 33 bytes
#define NUM 20		// 20 chromosomes

template<typename T> string toString(const T& t)
{
	ostringstream oss;
	oss << t;
	return oss.str();
}

class GA
{
	private:
	//	int gen; 		// repeat times
	//	string objFunc; // container for the objective function.
		vector<string> v;	// group

	public:
	//	GA(string func, int n) :objFunc(func), gen(n)
	//	{
	//		
	//		
	//	}

		void InitGroup();
		string generateChromosome();


};


string GA::generateChromosome()
{
	Eigen::ArrayXd temp;
	string s;
	
	temp = temp.Random(LEN);
	temp = temp.abs();
	temp = round(temp);

	for (short i = 0; i != LEN; ++i)
	{
		s += toString(temp(i));
	}

	return s;
}

void GA::InitGroup()
{
	string a ;
	for (int i = 0; i != NUM; ++i)
	{
		a = generateChromosome();
		v.push_back(a);
	}

	// test
	for (auto id : v)
	{
		cout << id << endl;
	}

}
