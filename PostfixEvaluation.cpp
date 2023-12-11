#include <iostream>
#include <string>
using namespace std;
template <class T>
class stack{
	T*s;
	int capacity,top;
	public:
		stack(int c){
			capacity=c;
			s=new T [capacity];
			top=-1;
		}
		void push(T e){
			top++;
			s[top]=e;
		}
		T pop(){
			T ele=s[top];
			top--;
			return ele;
		}
		void display(){
			cout<<"The stack is: "<<endl;
			for(int i=0;i<top+1;i++){
				cout<<s[i]<<endl;
			}
		}
		
		void postfix(string str){
			int count=0;
			for(int i=0; str[i];i++){
				count++;
			}
			//cout<<count;
			for(int i=0;i<count;i++){
				if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/'){
				
				//if (isdigit(str[i])){             //isdigit: it takes a single argument(int representing char) as a value.
                                                // it returns 1(non-zer) if char is a digit(0-9) n 0 if char not a digit.				
					//cout<<str[i]<<endl;
					
					push(str[i]-'0');           // when you subt the ASCII value of '0'(48) from the ASCII value of the char 
					                    //representing a digit, you get the integer value of that digit. eg: 2(50)-0(48)=2
				}
				else{
					int x1=pop();
					cout<<x1<<endl;
					int x2=pop();
					cout<<x2<<endl;
				    switch(str[i]){
						case '+':
							cout<<"value: "<<x1+x2;
							push(x1+x2);
							break;
						case '-':
							push(x1-x2);
							break;
						case '*':
							push(x1*x2);
							break;
						case '/':
							push(x1/x2);
							break;
				}		
				}
			}
		}
};
int main(){
	stack<char> ob(40);
	ob.postfix("24+");
	ob.display();
}
