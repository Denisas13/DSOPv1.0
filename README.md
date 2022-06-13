Programa, skaičiuojanti studentų įvertinimą, turint visus jo namų darbų įvertinimus bei egzamino įvertinimą. Programa duomenis gauna iš tekstinių failų, kuriuos pati atsitiktinai sugeneruoja. Studentai suskirstomi pagal jų vidurkius į dvi grupes (tie, kurių vidurkis mažesnis negu 5 ir tie, kurių vidurkis 5 arba daugiau) ir išveda rezultatus į du atskirus tekstinius failus.
Pakeitimai nuo v0.4: ta pati programa realizuota panaudojant list ir deque konteinerius, laikas matuojamas tik ties tais žingsniais, kurie ir parodo skirtumus tarp vector, deque ir list konteinerių.

Naudojimosi instrukcija:
-Atsisiųsti v0.5.cpp, func.cpp ir func.h failus (arba kitus failus, tais pačiais pavadinimais, esančius aplankuose "deque" ir "list")
-Per terminalą, su cd komanda nueiti ten, kur yra atsisiųsti failai
-Terminale įrašyti "g++ -c func.cpp" ir "g++ -o main v0.5.cpp func.o"
-Norint programą paleisti, terminale reikia įrašyti "./main"

Paleidus programą:
-Sugeneruojami tekstiniai duomenų failai (su 1000, 10 000, 100 000, 1 000 000, 10 000 000 studentų)
-Failai yra nuskaitomi ir duomenys suvedami į pasirinkto tipo konteinerį
-Studentai paskirstomi į dvi grupes
-Rezultatai išvedami į du atskirus tekstinius failus
-Skaičiuojamas failų nuskaitymų ir paskirstymų į grupes veikimo laikas

Galutinis įvertinimas skaičiuojamas taip: Galutinis = 0.4 x NamųDarbai + 0.6 x Egzaminas.

vector.png, deque.png, list.png - programos veikimo pavyzdžiai su atitinkamais konteineriais