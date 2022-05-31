#include "func.h"

using namespace std;

int main(){

student A[50];
char yn, vidmed, input;
int kiek=0, k=-3;
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
    int ndk=-3, stud=0;
    IvestisFailu(A,ndk,stud);

    for(int i=0; i<stud; i++){
        sort(A[i].ND.begin(), A[i].ND.end());
        A[i].NDv=NDvidurkis(A[i].ND,ndk);
        A[i].mediana=NDmediana(A[i].ND,ndk);
        A[i].galutinis=Galutinis(A[i].egz,A[i].NDv);
        A[i].galmed=Galutinis(A[i].egz,A[i].mediana);
    }
IsvestisBendrai(A,stud);
}

system("pause");
return 0;
}