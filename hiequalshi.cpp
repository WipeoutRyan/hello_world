using namespace std;
#include <iostream>
#include <string>
string string1;
string string2;
int longer;
int strcmp_case_insensitive(string string1, string string2){
    if(string1.length()>string2.length()){
        longer = string1.length();
    }else if(string2.length()>string1.length()){
        longer = string2.length();
    }else{
        longer = string1.length();
    }
    for(int i = 0; i < longer; i++){
            if(string1[i]>string2[i]){
                cout << "The comparison of string1 and string 2 returns 1" << endl;
                break;
            }else if(string1[i]<string2[i]){
                cout << "The comparison of string1 and string 2 returns -1" << endl;
                break;
            }
    }
    if(string1==string2){
        cout << "The comparison of string1 and string2 returns 0" << endl;
    }else{
        cout << "these strings dont match by crikey!" << endl;
    }
    return 0;
}

int main(){
    cout << "Enter a string." << endl;
    getline(cin, string1);
    cout << "Enter another string." << endl; 
    getline(cin, string2);
    strcmp_case_insensitive(string1, string2);
    return 0;
}

