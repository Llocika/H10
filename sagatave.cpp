#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
int main()
{

    map<int, string>::iterator itr1;
    map<int, string> vardnica1;

    // izveidojam vārdnīcu, ar kuru piepildīsim pirmo failu
    vardnica1.insert(pair<int, string>(50, "aa"));
    vardnica1.insert(pair<int, string>(46, "bb "));
    vardnica1.insert(pair<int, string>(36, "cc"));
    vardnica1.insert(pair<int, string>(20, "dd"));
    vardnica1.insert(pair<int, string>(11, "ee"));

    map<int, string>::iterator itr2;
    map<int, string> vardnica2;

    //-||- otro failu
    vardnica2.insert(pair<int, string>(51, "aaa"));
    vardnica2.insert(pair<int, string>(44, "bbb"));
    vardnica2.insert(pair<int, string>(33, "ccc"));
    vardnica2.insert(pair<int, string>(21, "ddd"));
    vardnica2.insert(pair<int, string>(8, "eee"));


    fstream f1("f1", ios::out | ios::binary);
    fstream f2("f2", ios::out | ios::binary);

    for (auto& x : vardnica1) {
        std::cout << x.first << " => " << x.second << '\n';
        int num1 = x.first;
        string n1 = x.second;
        f1.write((char*)&num1, sizeof(num1));
        f1.write((char*)&n1, sizeof(n1));

    }

    for (auto& x : vardnica2) {
        std::cout << x.first << " => " << x.second << '\n';
        int num1 = x.first;
        string n1 = x.second;
        f2.write((char*)&num1, sizeof(num1));
        f2.write((char*)&n1, sizeof(n1));

    }



}

