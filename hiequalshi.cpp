using namespace std;
#include <iostream>
#include <string>
#include <cctype>
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
            if(tolower(string1[i])>tolower(string2[i])){
                cout << "The comparison of string1 and string 2 returns something greater than zero" << endl;
                break;
            }else if(tolower(string1[i])<tolower(string2[i])){
                cout << "The comparison of string1 and string 2 returns something less than zero" << endl;
                break;
            }else if(i==longer-1){
               cout << "The comparison of string1 and string 2 returns zero" << endl; 
            }
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

