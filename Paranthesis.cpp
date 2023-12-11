#include <iostream>
using namespace std;
#include <string>
template <class T>
class mystack{
	T*A;
	int capacity,top;
	public:
	mystack(int c){
		capacity=c;
		A=new T[capacity];
		top=-1;
	}
	T pop(){
			if (isempty()){
				cout<<"UNDERFLOW";
			}
			else{
				T e=A[top];
				top--;
				return e;
			}
	}
	void push(T e){
		top++;
		A[top]=e;
	}
	bool isempty(){
		return (top==-1);
	}
	
	bool parcheck(string str){
		int n=0;
		for (int i=0;str[i];i++){
		n++; }
	for (int i=0;i<n;i++){
		if (str[i]=='{' || str[i]=='[' || str[i]=='('){
			push(str[i]);
			continue;
		}
		
		if (isempty())
		{return false; }
		
		switch(str[i]){
			
			case ')':
				if (A[top]=='('){
				pop();
			}
			    else{
			    	return false;
				}
				break;
				
			case ']':
				if (A[top]=='['){
				pop();
			}
			    else{
			    	return false;
				} 
				break;
				
			case '}' :
				if (A[top]=='{'){
				pop();	
			}
			    else{
			    	return false;
				}
				break;
				
		}
		
	}
	return isempty();
	}
	
	void display(){
			cout<<"The stack is : "<<endl;
			for (int i=0;i<top+1;i++)
			{
				cout<<A[i]<<" ";
			}
		}
};

int main(){
	mystack<char> ob(40);
	string st="{pt[t()][u}";
	bool result=ob.parcheck(st);
	if (result){
		cout<<"Parenthesis are balanced.";
	}
	else{
		cout<<"Parenthesis are not balanced.";
	}
	cout<<endl;
	//ob.pop();
	ob.display();
}
