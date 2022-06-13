# ifndef FUNC_H
# define FUNC_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include <list>
#include <deque>

#include <string>

using namespace std;

struct student{
int n;
string v, p;
double egz, NDv, galutinis, mediana, galmed;
std::vector<double> ND;
};

void IvestisFailu(std::list<student>& A, int&ndk, int&stud);
void Isvestis(std::list<student>& A, int kiek, char vidmed);

double NDvidurkis(std::vector<double>& A, int n);
double Galutinis(double egz, double nd);
double NDmediana(std::vector<double>& A, int n);

void generate(int size, int nd);
void read(int size, std::list<student>& A, int&ndk, int&stud);
void split(std::list<student>& A, std::list<student>& B, std::list<student>& C, int&size, int nd);
void IsvestisFaile(std::list<student>& A, std::list<student>& B, int size, int size1, int size2);

#endif