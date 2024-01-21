#include <iostream>
#include <string>
using namespace std;

string sentence; 
string input; 
char letterInSentence;
string partInSentence;
int a;
int findIndex(char letterInSentence){
	a=0;
	for(int i = 0; i < sentence.length(); i++){
		if(letterInSentence==sentence[i]){
			cout << "Matching letter found at: " << i << endl;
			a+1;	
		}
 	} 
	if(a==0){
		cout << "The letter entered was not found in the sentence inputted."; 
	} 
	
	return 0;
}

int findIndex(string partInSentence){
	if(sentence.find(partInSentence) > sentence.length()){
		cout << "The part entered was not in the sentence inputted." << endl; 
	}else{
		cout << "The position of the part entered is: " << sentence.find(partInSentence) << endl; 
	}
	return 0; 
}

int main() {
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	cout << "Enter a letter, word, or phrase: ";
	getline(cin, input);
	if(input.length()>1){
		partInSentence = input;
		findIndex(partInSentence);
	}else{
		letterInSentence = input[0];
		findIndex(letterInSentence);
	}
	return 0;  
}


