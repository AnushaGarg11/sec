#include <iostream>
using namespace std;
template <class T>
class Mystack
{
	T*s;
	int capacity,n,top;
	public:
		Mystack(int c){
			capacity=c;
			s=new T[capacity];
			top=-1;
			n=0;
		}
		int size()
		{
			return (top+1);
		}
		bool isempty(){
			return(top==-1);
		}
		bool isfull(){
			return(top==capacity-1);
		}
		void push(T e)
		{
			if (isfull())
			{cout<<"OVERFLOW";}		
			
			else{
				top++;
				s[top]=e;
			}
			}
		
		T pop(){
			if (isempty()){
				cout<<"UNDERFLOW";
			}
			else{
				T e=s[top];
				top--;
				return e;
			}
		}
		
		void display(){
			cout<<"The stack is : "<<endl;
			for (int i=0;i<top+1;i++)
			{
				cout<<s[i]<<" ";
			}
		}
			
};
int main(){
	Mystack<int> ob(10);
	
	ob.push(4);
	ob.push(5);
	ob.push(6);
	cout<<"Size is: "<<ob.size()<<endl;
	ob.display();
	cout<<endl;
	ob.pop();
	ob.display();
}
