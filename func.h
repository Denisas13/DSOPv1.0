# ifndef FUNC_H
# define FUNC_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

struct student{
int n;
string v, p;
double egz, NDv, galutinis, mediana, galmed;
std::vector<double> ND;
};

void IvestisFailu(std::vector<student>& A, int&ndk, int&stud);
void Ivestis(int i, std::vector<student>& A);
void IsvestisBendrai(std::vector<student>& A,int stud);
void Isvestis(std::vector<student>& A, int kiek, char vidmed);
double NDvidurkis(std::vector<double>& A, int n);
double Galutinis(double egz, double nd);
double NDmediana(std::vector<double>& A, int n);

#endif