#include<bits/stdc++.h>
using namespace std;

/*
    My string split logic with istringstream
    function tested on leetcode
*/
vector<string> my_split(string data,char sep){
    vector<string> out;
    istringstream ss(data);
    while(ss.tellg() != -1){
        string aux;
        getline(ss,aux,sep);
        out.push_back(aux);
    }
    return out;
}
int main(void){
    /*
        Split string with spaces
    */

    // istringstream ss("data2 data1_ d3 d4");
    // string curr;
    // ss >> curr;
    // cout << curr << endl;
    // ss >> curr;
    // cout << curr << endl;
    // ss >> curr;
    // cout << curr << endl;
    
    /*
        split string spreated by char
        for eg ','
    */

    //    istringstream ss2("hello,i am string,hello,1");
    //    getline(ss2,curr,',');
    //    cout << curr << endl;
    //    getline(ss2,curr,',');
    //    cout << curr << endl;
    //    getline(ss2,curr,',');
    //    cout << curr << endl;
    //    getline(ss2,curr,',');
    //    cout << curr << endl;
    //    getline(ss2,curr,',');
    //    cout << curr << endl;

   vector<string> out = my_split("string1#string2 string3#string4 #string5",'#');
    for(auto i: out){
        cout << i << endl;
    }
}