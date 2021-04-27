#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
const int wLen = 30;
int main_dis()
{

    map<int, string>::iterator itr1;
    map<int, string> vardnica1;
    //REORDER??? ikesejais sort

    // izveidojam vārdnīcu, ar kuru piepildīsim pirmo failu
    vardnica1.insert(pair<int, string>(50, "aa"));
    vardnica1.insert(pair<int, string>(46, "bb "));
    vardnica1.insert(pair<int, string>(36, "cc"));
    vardnica1.insert(pair<int, string>(20, "dd"));
    vardnica1.insert(pair<int, string>(11, "ee"));
    vardnica1.insert(pair<int, string>(1, "ff"));

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



    for (map<int, string>::reverse_iterator it = vardnica1.rbegin(); it != vardnica1.rend(); it++)
        {

        std::cout << it->first << " => " << it->second << '\n';
        int num1 = it->first;
        string n1 = it->second;
        //new
        char char_n1[wLen + 1];
        strcpy_s(char_n1, n1.c_str());

        f1.write((char*)&num1, sizeof(num1));
        f1.write(char_n1, wLen + 1);



        }

  //  for (auto& x : vardnica1) {

  //      std::cout << x.first << " => " << x.second << '\n';
  //      int num1 = x.first;
  //      string n1 = x.second;
  //      //new
		//char char_n1[wLen+1];
		//strcpy_s(char_n1, n1.c_str());

  //      f1.write((char*)&num1, sizeof(num1));
  //      f1.write(char_n1, wLen + 1);

  //  }


    for (map<int, string>::reverse_iterator it = vardnica2.rbegin(); it != vardnica2.rend(); it++)
    {

        std::cout << it->first << " => " << it->second << '\n';
        int num1 = it->first;
        string n1 = it->second;
        //new
        char char_n1[wLen + 1];
        strcpy_s(char_n1, n1.c_str());

        f2.write((char*)&num1, sizeof(num1));
        f2.write(char_n1, wLen + 1);
    }



    //for (auto& x : vardnica2) {
    //    std::cout << x.first << " => " << x.second << '\n';
    //    int num1 = x.first;
    //    string n1 = x.second;

    //    //const char* tmp = n1.c_str();
    //    char char_n1[wLen + 1];
    //    strcpy_s(char_n1, n1.c_str());

    //    f2.write((char*)&num1, sizeof(num1));
    //    f2.write(char_n1, wLen + 1);

    //}


    return 0;
}

