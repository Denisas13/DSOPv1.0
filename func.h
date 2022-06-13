# ifndef FUNC_H
# define FUNC_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

#include <string>

using namespace std;

struct student{
int n;
string v, p;
double egz, NDv, galutinis, mediana, galmed;
std::vector<double> ND;
};

void IvestisFailu(std::vector<student>& A, int&ndk, int&stud);
void IsvestisBendrai(std::vector<student>& A,int stud);
void Isvestis(std::vector<student>& A, int kiek, char vidmed);
double NDvidurkis(std::vector<double>& A, int n);
double Galutinis(double egz, double nd);
double NDmediana(std::vector<double>& A, int n);

void generate(int size, int nd);
void read(int size, std::vector<student>& A, int&ndk, int&stud);
void split(std::vector<student>& A, std::vector<student>& B, std::vector<student>& C, int&size, int nd);
void IsvestisFaile(std::vector<student>& A, std::vector<student>& B, int size, int size1, int size2);

#endif