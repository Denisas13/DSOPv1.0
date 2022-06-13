#include "func.h"
#include <random>

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(1,10);

void IvestisFailu(std::vector<student>& A, int&ndk, int&stud){

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

void Ivestis(int i, std::vector<student>& A){
int input, input2, rand;
student b;

cout << "Iveskite studento varda: ";
cin >> b.v;
cout << "Iveskite studento pavarde: ";
cin >> b.p;
b.n=0;
while(input!=0){
    cout << "Iveskite " << b.n+1 << "-ojo namu darbo ivertinima (iveskite -1, jeigu norite sugeneruoti atsitiktini ivertinima, arba 0, jeigu jau ivesti visi ivertinimai): ";
    cin >> input;
    if(input==-1){
        rand=dist(mt);
        b.ND.push_back(rand);
        b.n++;
        cout << rand << endl;
    }
    else{
    if(input==0)break;
    b.ND.push_back(input);
    b.n++;
    }
}
cout << "Iveskite egzamino ivertinima (arba 0, jeigu norite sugeneruoti atsitiktini ivertinima): ";
cin >> input2;
if(input2==0){
    rand=dist(mt);
    b.egz=rand;
    cout << rand << endl;
}
else b.egz=input2;

A.push_back(b);
}

void IsvestisBendrai(std::vector<student>& A,int stud){
cout << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(8)  << std::right << "med." << setw(8) << std::right << "vid." << endl;
cout << "--------------------------------------------------------------------" << endl;
for(int i=0; i<stud; i++){
    cout << setw(20) << std::left << A[i].v << std::left << setw(20) << A[i].p << setw(8) << std::right << fixed << setprecision(2) << A[i].galmed << setw(8) << std::right << fixed << setprecision(2) << A[i].galutinis << endl;
}
}

void Isvestis(std::vector<student>& A,int kiek, char vidmed){
if(vidmed=='v')cout << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(28)  << std::right << "Galutinis ivertinimas (vid.)" << endl;
if(vidmed=='m')cout << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(28)  << std::right << "Galutinis ivertinimas (med.)" << endl;
cout << "--------------------------------------------------------------------" << endl;
for(int i=0; i<kiek; i++){
    cout << setw(20) << std::left << A[i].v << std::left << setw(20) << A[i].p << setw(28) << std::right << fixed << setprecision(2) << A[i].galutinis << endl;
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