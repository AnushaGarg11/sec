#include <iostream>
using namespace std;
#include <process.h>
template <class T>
class myarray{
	T*a;
	int size;
	public:
		myarray(int n){
			size=n;
			a=new T[n];
		}
		int getdata(){
			cout<<"Enter the elements: ";
			for (int i=0;i<size;i++){
				cin>>a[i];
			}
		}
		int sum(){
			int s=0;
			for(int i=0;i<size;i++){
				s+=a[i];
			}
			return s;	
		}
		float avg(){
			float su=sum();
			float avg=su/size;
			return avg;
		}
		int largest(){
			int l=a[0];
			for(int i=1;i<size;i++){
				if(a[i]>l){
					l=a[i];
				}
			}
			return l;
		}
		int smallest(){
			int l=a[0];
			for(int i=1;i<size;i++){
				if(a[i]<l){
					l=a[i];
				}
			}
			return l;
		}
		int linsearch(int item){
			for(int i=0;i<size;i++){
				if(a[i]==item)
					return i;
			}
			return -1;
		}
		int binsearch(int item){
			int beg=0;
			int last=size-1;
			while(beg<=last){
				int mid=(beg+last)/2;
				if(item==a[mid]){
					return mid;
				}
				else if(item>a[mid]){
					beg=mid+1;
				}
				else{
					last=mid-1;
				}
			}
			return -1;
		}
		int findpos(int item){
			int pos;
			if (a[0]>item)
				pos=0;
			else{
				for(int i=0;i<size;i++){
					if(a[i]<item && a[i+1]>item){
						pos=i+1;
						break;
					}
					else if(i==size-1){
						pos=size;
					}
				}
				}
			return pos;
			}
	int insert(){
		char op='y';
			int item;
			while(op=='y'||op=='Y'){
				cout<<"Enter the element you want to insert: ";
				cin>>item;
				//cout<<endl;
				int index=findpos(item);
				for(int i=size;i>index;i--){
					a[i]=a[i-1];
					cout<<"g "<<a[i-1]<<"and"<<a[i];
				}
				a[index]=item;
				size++;
				cout<<"Do you want to add more?(y/n): ";
				cin>>op;
				cout<<endl;	
			}
		cout<<"The updated array is: "<<endl;
		for(int i=0;i<size;i++){
			cout<<a[i]<<" ";
		}
	}
	
	void delele(){
		char ch='y';
		while (ch=='y'||ch=='Y'){
			int item;
			cout<<"Enter the element you want to delete: ";
			cin>>item;
			int index=linsearch(item);
			if (index!=-1)
				a[index]=0;
			else
				cout<<"Element not found!"<<endl;
			for(int j=index;j<size-1;j++){
				a[j]=a[j+1]; }
			size--;
			cout<<"Want to delete more elements? (y/n): ";
			cin>>ch;		
		}
		cout<<"The updated array is: "<<endl;
		for(int i=0;i<size;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		}
	
	void selsort(){
		int small,pos,temp;
		for (int i=0;i<size-1;i++){
			small=a[i];
			pos=i;
			for(int j=i+1;j<size;j++){
				if(small>a[j]){
					small=a[j];
					pos=j;
				}
			}
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
			cout<<"The array after pass "<<i+1<<" is: ";
			for(int j=0;j<size;j++){
				cout<<a[j]<<" ";
			}
			cout<<endl;
		}
	}
	
	void bubsort(){
		int temp,ctr=0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size-i-1;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
				cout<<"Array after iteration "<<++ctr<<" is: ";
				for(int k=0;k<size;k++){
					cout<<a[k]<<" ";
				}
				cout<<endl;
			}
		}
	}
	
	void inssort(){
		int i,key,j;
		for(i=1;i<size;i++){
			key=a[i];
			j=i-1;
			while(j>=0 && a[j]>key){
				a[j+1]=a[j];
				j=j-1;
			}
			a[j+1]=key;
		}
		cout<<"The sorted array is: ";
		for(int k=0;k<size;k++){
			cout<<a[k]<<" ";
		}
		cout<<endl;
	}
	
	void merging(){
		int n1,n2;
		cout<<"Enter the size of 1st array: ";
		cin>>n1;
		int a1[n1];
		cout<<"Enter the elements of 1st array: ";
		for(int i=0;i<n1;i++){
			cin>>a1[i];
		}
		cout<<"Enter the size of 2nd array: ";
		cin>>n2;
		int a2[n2];
		cout<<"Enter the elements of 2nd array: ";
		for(int i=0;i<n2;i++){
			cin>>a2[i];
		}
		int n3=n1+n2;
		int a3[n3];
		int i=0,j=0,k=0;
		while(i<n1){
			a3[k++]=a1[i++];
		}
		while(j<n2){
			a3[k++]=a2[j++];
		}
		cout<<"Merged array is: ";
		for(int t=0;t<n3;t++){
			cout<<a3[t]<<" ";
		}
		cout<<endl;
	}
	
	void adding(){
		int n1,n2;
		cout<<"Enter the size of 1st array: ";
		cin>>n1;
		int a1[n1];
		cout<<"Enter the elements of 1st array: ";
		for(int i=0;i<n1;i++){
			cin>>a1[i];
		}
		cout<<"Enter the size of 2nd array: ";
		cin>>n2;
		int a2[n2];
		cout<<"Enter the elements of 2nd array: ";
		for(int i=0;i<n2;i++){
			cin>>a2[i];
		}
		int a3[n1];
		for(int i=0;i<n1;i++){
			a3[i]=a1[i]+a2[i];
		}
		cout<<"Array having sum of corresponding elements: ";
		for(int i=0;i<n1;i++){
			cout<<a3[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	cout<<"Hello, Welcome to the menu driven program of operations on 1-D Array."<<endl;
	cout<<endl;
	int arrsize;
	cout<<"Enter the number of elements u want to add: ";
	cin>>arrsize;
	myarray<int> ob(arrsize);
	char ch='y';
	int choice;
	while(ch=='y'||ch=='Y'){
		cout<<"Press 1. to ENTER the elements in array."<<endl;
		cout<<"Press 2. to find the SUM of the elements of the array."<<endl;	
		cout<<"Press 3. to find the AVERAGE of the elements of the array."<<endl;	
		cout<<"Press 4. to find the LARGEST element of the array."<<endl;	
		cout<<"Press 5. to find the SMALLEST element of the array."<<endl;	
		cout<<"Press 6. to SEARCH for an element in the array."<<endl;	
		cout<<"Press 7. to SORT the array."<<endl;	
		cout<<"Press 8. to INSERT an element at a particular index."<<endl;
		cout<<"Press 9. to DELETE an element at a particular index."<<endl;	
		cout<<"Press 10. to ADD corresponding elements of the array."<<endl;
		cout<<"Press 11. to MERGE two arrays."<<endl;	
		cout<<"Enter your choice: ";
		cin>>choice;	
		if (choice==1){
			ob.getdata();}
		else if(choice==2){
			cout<<"The sum of all the elements is: "<<ob.sum()<<endl;}
		else if (choice==3){
			cout<<"The average of all the elements is: "<<ob.avg()<<endl;}
		else if(choice==4){
			cout<<"The Largest of all the elements is: "<<ob.largest()<<endl;}
		else if(choice==5){
			cout<<"The Smallest of all the elements is: "<<ob.smallest()<<endl;}
		else if (choice==6){
			char c;
			cout<<"Which techinque you want to search by linear or binary?(L/B) ";
			cin>>c;			
			if (c=='L'||c=='l'){
				cout<<"Enter the element you want to search: ";
				int it;
				cin>>it;
				int L=ob.linsearch(it);
				if (L==-1)
					cout<<"Element not found"<<endl;
				else
					cout<<"Element is found at index "<<L<<" and position "<<L+1<<endl;
			}
			else if(c=='B'||c=='b'){
				cout<<"Enter the element you want search: ";
				int it;
				cin>>it;
				int B=ob.binsearch(it);
				if (B==-1)
					cout<<"Element not found!"<<endl;
				else
					cout<<"Element is found at "<<B<<" and position "<<B+1<<endl;
			}
			else
				cout<<"Wrong choice!"<<endl;
		}
		else if(choice==7){
			int ch;
			cout<<"1. Selection sort"<<endl;
			cout<<"2. Bubble sort"<<endl;
			cout<<"3. Insertion sort"<<endl;
			cout<<"What method do you want to sort by?"<<endl;
			cin>>ch;
			if(ch==1)
				ob.selsort();
			if(ch==2)
				ob.bubsort();
			if(ch==3)
				ob.inssort();
		}
		else if(choice==8){
			ob.insert();
		}
		else if(choice==9){
			ob.delele();
		}
		else if(choice==10){
			ob.adding();
		}
		else if(choice==11){
			ob.merging();
		}
		else 
			cout<<"Wrong choice"<<endl; 
		cout<<"Do you want to continue? (y/n)";
		cin>>ch;
		if(ch=='n'){
			cout<<"Bye!!";
	 		break; }
		
}
return 0;
}
