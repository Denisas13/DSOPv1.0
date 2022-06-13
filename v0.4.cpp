#include "func.h"
#include <chrono>

using namespace std;

int main(){

std::vector<student> A,B,C;
int kiek=0, k=-3;
string txt;

auto startmain = std::chrono::high_resolution_clock::now();
auto endmain = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diffmain = endmain-startmain;

int ndk, stud=0;
int ndkiek=10, size1, size2;

for(int i=1000; i<=10000000; i=i*10){
    size1=i;
    auto start = std::chrono::high_resolution_clock::now();
    generate(i,ndkiek);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << "Failo su " << i << " irasu generavimas uztruko: "<< diff.count() << " s" << endl;
    diffmain+=diff;

    start = std::chrono::high_resolution_clock::now();
    ndk=-3;
    stud=0;
    read(i,A,ndk,stud);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " irasu skaitymas uztruko: "<< diff.count() << " s" << endl;
    diffmain+=diff;

    start = std::chrono::high_resolution_clock::now();
    split(A,B,C,size1,ndk);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " irasu paskirstymas i dvi grupes uztruko: "<< diff.count() << " s" << endl;
    diffmain+=diff;

    start = std::chrono::high_resolution_clock::now();
    size2=i-size1;
    IsvestisFaile(C,B,i,size1,size2);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " irasu isvedimas i du failus uztruko: "<< diff.count() << " s" << endl;
    diffmain+=diff;
    
    system("pause");
}

cout << "Programa uztruko: " << diffmain.count() << " s" << endl;
// IvestisFailu(A,ndk,stud);

// for(int i=0; i<stud; i++){
//     sort(A[i].ND.begin(), A[i].ND.end());
//     A[i].NDv=NDvidurkis(A[i].ND,ndk);
//     A[i].mediana=NDmediana(A[i].ND,ndk);
//     A[i].galutinis=Galutinis(A[i].egz,A[i].NDv);
//     A[i].galmed=Galutinis(A[i].egz,A[i].mediana);
// }
// IsvestisBendrai(A,stud);


system("pause");
return 0;
}