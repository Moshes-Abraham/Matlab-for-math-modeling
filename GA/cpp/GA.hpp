#include <string>
#include <iostream>
#include <iterator>
using namespace std;

#include <Eigen/Eigen>
#define LEN 33		// 33 bytes
#define NUM 20		// 20 chromosomes
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211704
template<typename T>
string toString(const T& t)
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
		Eigen::ArrayXXd record(NUM,1);
		Eigen::Array3d maxrec;
		

	public:
	//	GA(string func, int n) :objFunc(func), gen(n)
	//	{
	//		
	//		
	//	}

		void InitGroup();
		string generateChromosome();

		int bin2dec(string);
	//	double objFunc(double, double);
		void adapt(double (*)(double, double));
		void maxrecord();
		double bin_x();
		
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
//	for (auto id : v)
//	{
//		cout << id << endl;
//	}

}

int GA::bin2dec(string s)
{
	// TODO: check string
	int value = 0;	

	for (int i = s.size() - 1, j = 0; i >= 0; --i, ++j)	
	{
		if (s[j] == '1')
			value += static_cast<int>(pow(2,i));
	}
//	cout << value << endl;
	return value;
}

//Eigen::ArrayXXd GA::adapt(double (* objFunc)(double, double))
void GA::adapt(double (* objFunc)(double, double))
{
	string temp1; 
	string tmp;
	vector<string> temp2, temp3;

	for (int i = 0; i != NUM; ++i)
	{
		for (int j = 0; j != NUM; ++j)
		{
			temp1 = v[j];
			for (auto it = temp1.cbegin(); it != (temp1.cbegin() + 18); ++it)
			{
				tmp += *it;
			}

			temp2.push_back(tmp);		// stands for x1
			tmp.clear();
			for (auto it = (temp1.cbegin() + 18); it != temp1.cend(); ++it)
			{
				tmp += *it;
			}

			temp3.push_back(tmp);		// stands for x2
			tmp.clear();
			
		}
		// TODO: Use function pointer
		record(i, 0) = (* objFunc)(bin2dec(temp2[i]),bin2dec(temp3[i]));
	}
}

void maxrecord()
{
	Eigen::Array3d::Index i;	// Index of m
	double m = record.maxCoeff(&i);
	maxrec(0) = m;
	string temp1 = v[i];
	string temp2 = temp1.substr(0,18-1);
	string temp3 = temp1.substr(18);
	maxrec(1) = bin_x(temp2,1);
	maxrec(2) = bin_x(temp3,2);
}
