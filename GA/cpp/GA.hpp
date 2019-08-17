#include <string>
#include <iostream>
#include <iterator>
#include <cmath>
#include <random>
using namespace std;

#include <Eigen/Eigen>
#define LEN 33		// 33 bytes

#define NUM 20		/* 20 chromosomes */
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
	public:
	//	int gen; 			// repeat times
	//	string objFunc; 		// container for the objective function.
		vector<string> v;		// group
		Eigen::ArrayXd record{NUM};	// must init with "{}" not with "()", or it will recognized record as a function! 
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
		void adapt(double (*)(double, double));
		void maxrecord();
		double bin_x(string, char);
		void chfather();		// choose father chromosom
		void opcrossover();		// one point crossover
		vector<string> onecross(string, string, int);
		string vari(string, int);
		void variation(); 		// variate operator

		
	//	double objFunc(double, double);
};


string GA::generateChromosome()
{
	Eigen::ArrayXd temp{LEN};
	string s;
	std::random_device rd;		// generate real random numbers
	for (int i = 0; i != LEN; ++i)	
	{
		temp(i) = std::round((rd() % 100) / (double)100);
	}

//	temp = temp.Random(LEN);	// fake random numbers
//	temp = temp.abs();
//	temp = round(temp);

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
/*void GA::adapt(double (* objFunc)(double, double))	// my original method, runs well but not quite efficient
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
		record(i, 0) = (* objFunc)(bin_x(temp2[i],'1'),bin_x(temp3[i],'2'));
	}
}*/
// This is a more efficient way
void GA::adapt(double (* objFunc)(double, double))
{
	string temp1; 
	vector<string> temp2, temp3;
	for (int i = 0; i != NUM; ++i)
	{
		for (int j = 0; j != NUM; ++j)
		{
			temp1 = v[j];
			temp2.push_back(temp1.substr(0,18-1));	// stands for x1
			temp3.push_back(temp1.substr(18));	// stands for x2
		}
		record(i, 0) = (* objFunc)(bin_x(temp2[i],'1'),bin_x(temp3[i],'2'));
	}
	
}

void GA::maxrecord()
{
	Eigen::Array3d::Index i;	// Index of m
	double m = record.maxCoeff(&i);
	maxrec(0) = m;
	string temp1 = v[i];
	string temp2 = temp1.substr(0,18-1);
	string temp3 = temp1.substr(18);
//	cout << endl << temp2 << "\t" << temp3 << endl << endl;	// test
	maxrec(1) = bin_x(temp2,'1');
	maxrec(2) = bin_x(temp3,'2');
}

double GA::bin_x(string bin, char opt)
{
	double num = 0.0;

	switch (opt)
	{
		case '1':
			return num = -3.0 + bin2dec(bin) * ((12.1 - (-3.0))/(pow(2,18) - 1));
			break;
		case '2':
			return num = 4.1 + bin2dec(bin) * ((5.8 - 4.1)/(pow(2,15) - 1));
			break;
		default:
			break;
	}
	return num;
	
}

void GA::chfather()
{ 
	double F = 0.0;
	int k;
	vector<string> temp;
	Eigen::ArrayXd pk{NUM};
	Eigen::ArrayXd qk{NUM};
	Eigen::ArrayXd r{NUM};
	for (int i = 0; i != NUM; ++i)
	{
		F += record(i);		// the sun of all values in record
	}
	pk = record / F;
	
	qk = qk.LinSpaced(NUM,0,0); 
	//qk(0) = pk(0);
	for (int i = 0; i != NUM; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			qk(i) += pk(j); 
		}
	}
	// test
//	cout << endl << qk << endl;

	std::random_device rd;		// generate real random numbers
	for (int i = 0; i != NUM; ++i)	
	{
		r(i) = (rd() % 100) / (double)100;
	}
	for (int i = 0; i != NUM; ++i)
	{
		k = 1;
		while (r(i) > qk(k))
		{
			k += 1;
		}
		r(i) = k;
	}
	// test
//	cout << endl << r << endl;

	temp = v;
	for (int i = 0; i != NUM; ++i)
	{
		v[i] = temp[r(i)];
	}
	// test
//	for (auto &it : v)
//		cout << it << endl;


}

void GA::opcrossover()
{
	vector<string> g;
	std::random_device rd;		// generate real random numbers
	Eigen::ArrayXd r{NUM};
	Eigen::ArrayXi mk{0};
	const float pc = 0.25;
	int l = 1;
	while (l == 1)
	{
		for (int i = 0; i != NUM; ++i)	
		{
			r(i) = (rd() % 100) / (double)100;
		}
		for (int i = 0, j = 0; i != NUM; ++i)
		{
			if (r(i) < pc)
			{
				mk.conservativeResize(j + 1);
				mk(j) = i;
				++j;
			}
		}
		l = mk.rows();
	}
	// test
//	cout << l << endl << mk << endl;

	if (l % 2 == 1)
	{
		mk.conservativeResize(l - 1);
		l -= 1;
	}
	// test
	cout << endl << mk << endl;

	Eigen::ArrayXi r1{l/2};
	//int rt = 0;		// temp random number
	for (int i = 0; i != (l / 2); ++ i)
	{
		// TODO: change to 0 ~ 31
	//	rt = ((rd() % 100) / (double)100 ) * (NUM - 1);
	//	if (rt != 0) 
	//	{
	//		r1(r) = rt; 	// bug! it should be: r1(i) = rt;
	//	}
	//	else
	//		r1(i) = 1;
			r1(i) = ((rd() % 100) / (double)100 ) * (NUM - 1);
	}

	// test
//	cout << endl << r1 << endl;

	for (int i = 0; i != (l / 2); ++i)
	{
		g = onecross(v[mk(2 * i)], v[mk(2 * i + 1)], r1(i));
		v[mk(2 * i)] = g[0];
		v[mk(2 * i + 1)] = g[1];
	}
}

vector<string> GA::onecross(string gene1, string gene2, int pos)
{
	//int len = gene1.size();
	vector<string> s;
	string g1 = gene1.substr(0,pos) + gene2.substr(pos);	// swap	
	string g2 = gene2.substr(0,pos) + gene1.substr(pos);
	s.push_back(g1);
	s.push_back(g2);
	return s;
}

string GA::vari(string gold, int pos)
{
	string gnew(gold);
	if (gnew[pos] == '1')
		gnew[pos] = '0';
	else
		gnew[pos] = '1';
	return gnew;
}

void GA::variation()
{
	std::random_device rd;
	Eigen::ArrayXd r{33};
	Eigen::ArrayXi k{0};
	const float pm = 0.01;
	for (int i = 0; i != NUM; ++i)
	{
		for (int j = 0; j != LEN; ++j)
		{
			r(j) = (rd() % 100) / (double)100;
		}

		for (int j = 0, m = 0; j != LEN; ++j)
		{
			if (r(j) < pm)
			{
				k.conservativeResize(m + 1);
				k(m) = j;
				++m;
			}
		}
		
		for (int j = 0; j != k.rows(); ++j)
		{
			v[i] = vari(v[i], k(j));
		}
	}
}
