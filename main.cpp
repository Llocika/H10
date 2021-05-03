/*Izveidot programmu valodâ C++.  Ja programma darbojas ar failu, nedrîkst dublçt visa faila saturu operatîvajâ atmiòâ.
Ar faila komponenti tiek saprasts fiksçta garuma ieraksts. Sîkâkâs prasîbas sk. Laboratorijas darbu noteikumos.
H10. Doti divi binâri faili f1 un f2, kuru komponentes ir ieraksti ar struktûru: atslçga (int), vârds (nepârsniedz 30 simbolus).
Failu komponentes sakârtotas pçc atslçgâm dilstoðâ secîbâ. Uzrakstît programmu, kas apvieno failus f1 un f2 failâ f3 tâ,
lai arî f3 komponentes bûtu dilstoðâ secîbâ (failos nedrîkst parâdîties divas komponentes ar vienâdu atslçgu vçrtîbu).
Programmu veidot tâ, lai pilns faila saturs netiktu ielâdçts operatîvajâ atmiòâ.
Uzrakstît arî palîgprogrammas, kas ïauj izveidot failus f1 un f2 un izdrukâ failu saturu.*/
#include<iostream>
#include<fstream>
#include <cstring>
using namespace std;
const int wLen = 30; //vārda maks. garums

void joinDesc(fstream& f1, fstream& f2, fstream& f3)
{

    //Inicializējam failu mainīgos
    //fstream f1("f1", ios::in | ios::binary);
    //fstream f2("f2", ios::in | ios::binary);
    //fstream f3("f3", ios::out | ios::binary);

    int n1;
    int n2;
    char word1[wLen + 1]; //vārda maksimālais garums + beigu simbols
    char word2[wLen + 1];

    f1.read((char*)&n1, sizeof(n1));
    f1.read(word1, sizeof(word1));
    f2.read((char*)&n2, sizeof(n2));
    f2.read(word2, sizeof(word2));

    do
    {
        if (n1 > n2)
        {
            do {
                f3.write((char*)&n1, sizeof(n1));
                f3.write(word1, sizeof(word1));
                f1.read((char*)&n1, sizeof(n1));
                f1.read(word1, sizeof(word1));
            } while (n1 > n2);
            f3.write((char*)&n2, sizeof(n2));
            f3.write(word2, sizeof(word2));
            f2.read((char*)&n2, sizeof(n2));
            f2.read(word2, sizeof(word2));
        }
        else if (n2 > n1)
        {
            do {
                f3.write((char*)&n2, sizeof(n2));
                f3.write(word2, sizeof(word2));
                f2.read((char*)&n2, sizeof(n2));
                f2.read(word2, sizeof(word2));
            } while (n2 > n1);

            f3.write((char*)&n1, sizeof(n1));
            f3.write(word1, sizeof(word1));
            f1.read((char*)&n1, sizeof(n1));
            f1.read(word1, sizeof(word1));
        }
        else if (n1 == n2) {

            f1.read((char*)&n1, sizeof(n1));
            f1.read(word1, sizeof(word1));
            f2.read((char*)&n2, sizeof(n2));
            f2.read(word2, sizeof(word2));
        }
    } while (f1 && f2);

    while (!f1.eof()) {
        f1.read((char*)&n1, sizeof(n1));
        f1.read(word1, sizeof(word1));
        f3.write((char*)&n1, sizeof(n1));
        f3.write(word1, sizeof(word1));
    }

    while (!f2.eof()) {
        f2.read((char*)&n2, sizeof(n2));
        f2.read(word2, sizeof(word2));
        f3.write((char*)&n2, sizeof(n2));
        f3.write(word2, sizeof(word2));
    }

    f1.close();
    f2.close();
    f3.close();
}


int main()
{
    //char f1[] = "f1";
    //char f2[] = "f2";
    //char f3[] = "f3";
    fstream f1("f1", ios::in | ios::binary);
    fstream f2("f2", ios::in | ios::binary);
    fstream f3("f3", ios::out | ios::binary);
    joinDesc(f1, f2, f3);
    int n3;
    char word3[wLen + 1];
    //pārbaudām, kas tika ielikts f3
    f3.open("f3", ios::in | ios::binary);
    f3.read((char*)&n3, sizeof(n3));
    f3.read(word3, sizeof(word3));
    while (f3)
    {
        cout << n3 << " " << word3 << endl;
        f3.read((char*)&n3, sizeof(n3));
        f3.read(word3, sizeof(word3));
    }
    return 0;
}
