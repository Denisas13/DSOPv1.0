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
double egz, NDv, galutinis, mediana;
std::vector<double> ND;
};

void Ivestis(int i, std::vector<student> A);
void Isvestis(std::vector<student> A, int kiek, char vidmed);
double NDvidurkis(std::vector<double>& A, int n);
double Galutinis(double egz, double nd);
double NDmediana(std::vector<double>& A, int n);

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(1,10);

int main(){

std::vector<student> A;
char yn, vidmed, input;
int kiek=0;
string txt;

do{
cout << "Duomenis nuskaityti is failo 'kursiokai.txt', ar ivesti dabar? (f/d): ";
cin >> input;
if(input=='f' || input=='d')break;
}while(true);

if(input=='d')
{
do{
cout << "Galutini ivertinima isvesti kaip vidurki, ar kaip mediana? (v/m): ";
cin >> vidmed;
if(vidmed=='v' || vidmed=='m')break;
}while(true);

for(int i=0; i<50;i++){
    cout << "Ar norite prideti studenta? (y/n): ";
    cin >> yn;
    if(yn=='y'){
        Ivestis(i,A);
        kiek++;
        sort(A[i].ND.begin(), A[i].ND.end());
        A[i].NDv=NDvidurkis(A[i].ND,A[i].n);
        A[i].mediana=NDmediana(A[i].ND,A[i].n);
        if(vidmed=='v') A[i].galutinis=Galutinis(A[i].egz,A[i].NDv);
        else if(vidmed=='m') A[i].galutinis=Galutinis(A[i].egz,A[i].mediana);
    }
    else if(yn=='n'){
        break;
    }
    else{
        i--;
    }
}

Isvestis(A,kiek,vidmed);
}
else
{
    ifstream in ("kursiokai.txt");

    string str;
    getline(in, str); 
    istringstream ss(str);

    int k=-3;
    string temp;
    while(!ss.eof())
    {
        ss >> temp;
        k++;
    }
cout << k;
}

system("pause");
return 0;
}

void Ivestis(int i, std::vector<student> A){
    int input, input2, rand;
cout << "Iveskite studento varda: ";
cin >> A[i].v;
cout << "Iveskite studento pavarde: ";
cin >> A[i].p;
A[i].n=0;
for(int j=0; j<50; j++){
    cout << "Iveskite " << j+1 << "-ojo namu darbo ivertinima (iveskite -1, jeigu norite sugeneruoti atsitiktini ivertinima, arba 0, jeigu jau ivesti visi ivertinimai): ";
    cin >> input;
    if(input==-1){
        rand=dist(mt);
        A[i].ND.push_back(rand);
        A[i].n++;
        cout << rand << endl;
    }
    else{
    if(input==0)break;
    A[i].ND.push_back(input);
    A[i].n++;
    }
}
cout << "Iveskite egzamino ivertinima (arba 0, jeigu norite sugeneruoti atsitiktini ivertinima): ";
cin >> input2;
if(input2==0){
    rand=dist(mt);
    A[i].egz=rand;
    cout << rand << endl;
}
else A[i].egz=input2;
}

void Isvestis(std::vector<student> A,int kiek, char vidmed){
if(vidmed=='v')cout << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(28)  << std::right << "Galutinis ivertinimas (vid.)" << endl;
if(vidmed=='m')cout << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(28)  << std::right << "Galutinis ivertinimas (med.)" << endl;
cout << "--------------------------------------------------------------------" << endl;
for(int i=0; i<kiek; i++){
    cout << setw(20) << std::left << A[i].v << std::left << setw(20) << A[i].p << setw(28) << std::right << fixed << setprecision(2) << A[i].galutinis << endl;
}
}

double NDvidurkis(std::vector<double>& A, int n){
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