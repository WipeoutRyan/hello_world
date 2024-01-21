 #include <iostream>
 using namespace std;
int value;
void askUser(){
                  cout << "Please type a number between 0 and 100\n";
                  cin >> value;
}
int main(){ 
	askUser();
	 if(value>100 || value<0){
		cout << "Your value is invalid\n";
		askUser();
	 }else{
		cout << "The value chosen by the user is " << value << endl;
		return 0;
       	}
 }
