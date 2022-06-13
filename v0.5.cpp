#include "func.h"
#include <chrono>

using namespace std;

int main(){

std::vector<student> A,B,C;
int kiek=0, k=-3;
string txt;

int ndk, stud=0;
int ndkiek=10, size1, size2;

for(int i=1000; i<=10000000; i=i*10){
    size1=i;
    generate(i,ndkiek);

    auto start = std::chrono::high_resolution_clock::now();
    ndk=-3;
    stud=0;
    read(i,A,ndk,stud);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << i << " irasu skaitymas uztruko: "<< diff.count() << " s" << endl;

    start = std::chrono::high_resolution_clock::now();
    split(A,B,C,size1,ndk);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    cout << i << " irasu paskirstymas i dvi grupes uztruko: "<< diff.count() << " s" << endl;

    size2=i-size1;
    IsvestisFaile(C,B,i,size1,size2);
    
    cout << endl;
}

system("pause");
return 0;
}