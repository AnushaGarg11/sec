#include <iostream>
using namespace std;
template <class T>
class array{
	int rows,columns;
	T**a;
	public:
		array(int m,int n){
			rows=m;
			columns=n;
			a=new T*[m];
			for(int i=0;i<m;i++){
				a[i]=new T[n];
			}
		}
		int getdata(){
			cout<<"Enter the elements: "<<endl;
			for(int i=0;i<rows;i++){
				for(int j=0;j<columns;j++){
					cout<<"a["<<i<<"]"<<"["<<j<<"] ";
					cin>>a[i][j];
				}
			}
			
		}	
		void sum(const array<T> &A1, const array<T> &A2){
			if(A1.rows!=A2.rows||A1.columns!=A2.columns){
				cout<<"Arrays can't be added."<<endl;
			}
			else{
				cout<<"Sum of arrays is: "<<endl;
				for(int i=0;i<rows;i++){
					for(int j=0;j<columns;j++){
						cout<<A1.a[i][j]+A2.a[i][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
		void diff(const array<T> &A1, const array<T> &A2){
			if(A1.rows!=A2.rows||A1.columns!=A2.columns){
				cout<<"Arrays can't be subracted."<<endl;
			}
			else{
				cout<<"Difference of arrays is: "<<endl;
				for(int i=0;i<rows;i++){
					for(int j=0;j<columns;j++){
						cout<<A1.a[i][j]-A2.a[i][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
		void multiply(const array<T> &A1, const array<T> &A2){
			if(A1.rows!=A2.rows||A1.columns!=A2.columns){
				cout<<"Arrays can't be multiplied."<<endl;
			}
			else{
				cout<<"Multiply of arrays is: "<<endl;
				for(int i=0;i<A1.rows;i++){
					for(int j=0;j<A1.columns;j++){
						int c[i][j]=0;
						for(int ip=0;ip<A1.columns;++ip){
							c[i][j]+=A1.a[i][ip]*A2.a[ip][j];
						}
						cout<<c[i][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
};

int main(){
	array<int> ob(2,3);  
	array<int> ob1(2,3); 
	ob.getdata();
	ob1.getdata();
	ob.sum(ob,ob1);
}
