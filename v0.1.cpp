#include <iostream>
#include <iomanip>

using namespace std;

struct student{
string v, p;
double ND[50], egz, NDv, galutinis;
};

void Ivestis(int i, int n, student A[]);
void Isvestis(student A[], int n, int kiek);
double NDvidurkis(double A[], int n);
double Galutinis(double egz, double nd);

int main(){

student A[50];
char yn;
int n, kiek=0;

cout << "Kiek buvo namu darbu? ";
cin >> n;

for(int i=0; i<50;i++){
    cout << "Ar norite prideti studenta? (y/n): ";
    cin >> yn;
    if(yn=='y'){
        Ivestis(i,n,A);
        kiek++;
        A[i].NDv=NDvidurkis(A[i].ND,n);
        A[i].galutinis=Galutinis(A[i].egz,A[i].NDv);
    }
    else if(yn=='n'){
        break;
    }
    else{
        i--;
    }
}

Isvestis(A,n,kiek);

system("pause");
return 0;
}

void Ivestis(int i, int n, student A[]){
cout << "Iveskite studento varda: ";
cin >> A[i].v;
cout << "Iveskite studento pavarde: ";
cin >> A[i].p;
for(int j=0; j<n; j++){
    cout << "Iveskite " << j+1 << "-ojo namu darbo ivertinima: ";
    cin >> A[i].ND[j];
}
cout << "Iveskite egzamino ivertinima: ";
cin >> A[i].egz;
}

void Isvestis(student A[], int n, int kiek){
cout << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis ivertinimas" << endl;
cout << "----------------------------------------------" << endl;
for(int i=0; i<kiek; i++){
    cout << setw(20) << A[i].v << setw(20) << A[i].p << setw(15) << A[i].galutinis << endl;
}
}

double NDvidurkis(double A[], int n){
    double sum=0;
for(int i=0; i<n; i++){
sum=sum+A[i];
}
return sum/n;
}

double Galutinis(double egz, double nd){
return egz*0.6+nd*0.4;
}
