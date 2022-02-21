#include <iostream>
#include <iomanip>

using namespace std;

struct student{
string v, p;
double ND[50], egz, NDv, galutinis, mediana;
};

void Ivestis(int i, int n, student A[]);
void Isvestis(student A[], int n, int kiek);
double NDvidurkis(double A[], int n);
double Galutinis(double egz, double nd);
double NDmediana(double A[], int n);
void SortArray(double A[], int n);

int main(){

student A[50];
char yn, vidmed;
int n, kiek=0;

cout << "Kiek buvo namu darbu? ";
cin >> n;

do{
cout << "Galutini ivertinima isvesti kaip vidurki, ar kaip mediana? (v/m): ";
cin >> vidmed;
if(vidmed=='v' || vidmed=='m')break;
}while(true);

for(int i=0; i<50;i++){
    cout << "Ar norite prideti studenta? (y/n): ";
    cin >> yn;
    if(yn=='y'){
        Ivestis(i,n,A);
        kiek++;
        SortArray(A[i].ND,n);
        A[i].NDv=NDvidurkis(A[i].ND,n);
        A[i].mediana=NDmediana(A[i].ND,n);
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
cout << setw(20) << std::left << "Vardas" << std::left << setw(20) << "Pavarde" << setw(21)  << std::right << "Galutinis ivertinimas" << endl;
cout << "-------------------------------------------------------------" << endl;
for(int i=0; i<kiek; i++){
    cout << setw(20) << std::left << A[i].v << std::left << setw(20) << A[i].p << setw(21) << std::right << A[i].galutinis << endl;
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

double NDmediana(double A[], int n){
    double med;
if(n%2==0)med=(A[n/2]+A[n/2+1])/2;
else if(n%2==1)med=A[n/2];
return med;
}

void SortArray(double A[], int n){
    double t;
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(A[i]>A[j]){
            t=A[j];
            A[j]=A[i];
            A[i]=t;
        }
    }
}
}