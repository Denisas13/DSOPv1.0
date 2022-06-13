#include "func.h"
#include <random>

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(1,10);

void IvestisFailu(std::list<student>& A, int&ndk, int&stud){

    ifstream in ("studentai10000.txt");

    student b;
    int nd;

    string str;
    getline(in, str);
    istringstream ss(str);

    string temp;
    while(!ss.eof())
    {
        ss >> temp;
        ndk++;
    }

    string t;
    while(!in.eof()){
    in >> b.v >> b.p;
    for(int i=0; i<ndk; i++) {
        in >> nd;
        b.ND.push_back(nd);
    }
    in >> b.egz;
    A.push_back(b);
    stud++;
    }
}

double NDvidurkis(std::vector<double>& A, int n){
try{
    if(n==0){
        throw 0;
    }
    }catch(std::exception& ex){
        cout << "Negalima apskaiciuoti vidurkio, kai nera ne vieno pazymio" << endl;
    }

double sum=0;
for(int i=0; i<n; i++){
sum=sum+A[i];
}
return sum/n;
}

double Galutinis(double egz, double nd){
return egz*0.6+nd*0.4;
}

double NDmediana(std::vector<double>& A, int n){
    double med;
if(n%2==0)med=(A[n/2]+A[n/2+1])/2;
else if(n%2==1)med=A[n/2];
return med;
}

void generate(int size, int nd){

string file = "random" + std::to_string(size) + ".txt";
ofstream out (file);

out << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde";
for(int i=0; i<nd; i++){
	out << "ND" << setw(5) << i+1;
}
out << setw(6) << "Egz.";

for(int i=0; i<size; i++){
    out << endl;
out << std::left << "Vardas" << setw(14) << i+1 << std::left << "Pavarde" << setw(13) << i+1;

for(int j=0; j<nd; j++){
	out << setw(7) << dist(mt); 
}
out << setw(6) << dist(mt);
}
out.close();
}

void read(int size, std::list<student>& A, int&ndk, int&stud){

string file = "random" + std::to_string(size) + ".txt";
ifstream in (file);

student b;
int nd;

string str;
getline(in, str);
istringstream ss(str);

string temp;
while(ss >> temp)
{
    ndk++;
}

string t, line;
while(getline(in, line)){
    istringstream iss(line);
    iss >> b.v >> b.p;
    for(int i=0; i<ndk; i++) {
        iss >> nd;
        b.ND.push_back(nd);
    }
    b.NDv=NDvidurkis(b.ND,ndk);
    iss >> b.egz;
    b.galutinis=Galutinis(b.egz,b.NDv);
    A.push_back(b);
    b.ND.clear();
    stud++;
}
in.close();
}

void split(std::list<student>& A, std::list<student>& B, std::list<student>& C, int&size, int nd){

int temp=size;

for(student it : A){
	if(it.galutinis<5){
        B.push_back(it);
        temp--;
    }
    else{
        C.push_back(it);
    }
}
size=temp;
A.clear();
}

void IsvestisFaile(std::list<student>& A, std::list<student>& B, int size, int size1, int size2){
string file = "galvociai" + std::to_string(size) + ".txt";
ofstream out (file);


out << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(8) << std::right << "vid." << endl;
out << "-------------------------------------------------" << endl;
for(student it : A){
    out << setw(20) << std::left << it.v << std::left << setw(20) << it.p << setw(8) << std::right << fixed << setprecision(2) << it.galutinis << endl;
}
out.close();

file = "vargsai" + std::to_string(size) + ".txt";
out.open(file);

out << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(8) << std::right << "vid." << endl;
out << "-------------------------------------------------" << endl;
for(student it : B){
    out << setw(20) << std::left << it.v << std::left << setw(20) << it.p << setw(8) << std::right << fixed << setprecision(2) << it.galutinis << endl;
}
out.close();
}
