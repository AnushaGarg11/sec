#include <iostream>
using namespace std;
template <class T>
class myqueue
{
	T* Q;
	int f,r,capacity,n;
	public:
	myqueue(int c){
	capacity=c;
	Q=new T[capacity];
	n=0;
	f=r=0;
}
	bool isempty(){
		return(n==0);
		
	}
	bool isfull(){
		return(n==capacity);
	}
	int size(){
		return n;
	}
	void Qinsert(T e){
		if (isfull())
			cout<<"Queue is ful!!";
		else{
			Q[r]=e;
			r=(r+1)%capacity;
			n++;
		}
	}
	
	T Qdelete(){
		if (isempty())
			cout<<"Queue is empty!!";
		else{
			T e=Q[f];
			if(f==r){
				f=r=0; }
			f=(f+1)% capacity;
			n--;
			return e;
		}
	}
	
	void display(){
		cout<<"The stack is: "<<endl;
		for(int i=f;i<r;i++){
			cout<<Q[i]<<" ";
		}
	}
	

};

	int main(){
		myqueue<int> ob(40);
		char ch='y';
		int choice;
		while(ch=='y'||ch=='Y'){
			cout<<"1. To insert an element in the queue."<<endl;
			cout<<"2. To delete an element from the queue."<<endl;
			cout<<"3. To display the elements of the queue."<<endl;
			cout<<"4. To display the size of the queue."<<endl;
			cout<<"Enter your choice: "<<endl;
			cin>>choice;
			if (choice==1){
				int b;
				cout<<"Enter the number of elements u want to add(max:40)";
				cin>>b;
				for(int i=0;i<b;i++){
					int a;
					cout<<"Enter the element: ";
					cin>>a;
					ob.Qinsert(a);
		}
		}
			if (choice==2){
				cout<<"Deleted element is: "<<ob.Qdelete()<<endl;
			}
			if (choice==3){
				ob.display();
				cout<<endl;
			}
			if (choice==4){
				cout<<"Size of the queue is: "<<ob.size()<<endl;
			}
			
			cout<<"Do yo want to continue?(y/n)";
			cin>>ch;
			if (ch=='n'){
				break;
			}
		}
		

	}








