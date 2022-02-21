# LD v0.1
Programa, skaičiuojanti studentų įvertinimą, turint visus jo namų darbų įvertinimus bei egzamino įvertinimą.<br>

**Naudojimosi instrukcija:**<br>
-Atsisiųsti v0.1.cpp arba v0.1.2.cpp (v0.1 namų darbų įvertinimai yra įrašomi į C masyvą, o v0.1.2 – į std::vector tipo konteinerį)<br>
-Per terminalą, su cd komanda nueiti ten, kur yra atsisiųstas .cpp failas<br>
-Terminale įrašyti "g++ -o main v0.1.2.cpp" arba "g++ -o main v0.1.cpp", priklausomai nuo pasirinkto .cpp failo<br>
-Norint programą paleisti, terminale reikia įrašyti "./main"<br>

**Paleidus programą, Jums reikės:**<br>
-Pasirinkti, kaip skaičiuoti namų darbų įvertinimą – vidurkį ar medianą<br>
-Pasirinkti, ar į sąrašą norite pridėti studentą<br>
-Įvesti to studento vardą, pavardę, namų darbų ir egzamino įvertinimus (galima pasirinkti įvertinimus generuoti atsitiktinai)<br>

Kai visi duomenys yra suvesti, programa lentelės pavidalu išves kiekvieno pridėto studento galutinį įvertinimą. Galutinis įvertinimas skaičiuojamas taip: Galutinis = 0.4 x NamųDarbai + 0.6 x Egzaminas.