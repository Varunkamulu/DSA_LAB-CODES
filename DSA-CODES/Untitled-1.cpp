#include <fstream>
#include <string>
#include <iostream>
using namespace std;


int main(){
    ofstream out2;
    out2.open("file2.txt");
    ofstream out3;
    out3.open("file3.txt");
    ofstream out1;
    out1.open("file1.txt");
    string word,sentence;
    cout<<"enter a sentence : \n";
    getline(cin,sentence);
    out1<<sentence;
    out1.close();
    ifstream in;
    in.open("file1.txt");
    while(in>>word){
        if(word.length()>=6) out2<<word<<" ";

        else out3<<word<<" ";
    }
    out2.close();
    out3.close();
    in.close();
    return 0;
}