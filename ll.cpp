#include <iostream>
using namespace std;

class stringnode{
	private:
		string elem;
		stringnode* next;
	friend class linkedlist;
};
class linkedlist{
	public:
		linkedlist();
		~linkedlist();
		bool empty() const;
		const string & front() const;
		void addfront(const string & e);
		void add_atend(const string & e);
		void add_atindex(const string & e,int index);
		void add_afterindex(const string & e,int index);
		void add_beforeval(const string & e,const string & value);
		void add_afterval(const string & e,const string & value);
		void removefront();
		void remove_atend();
		void remove_beforeindex(int index);
		void remove_atindex(int index);
		void remove_afterindex(int index);
		void remove_value(const string & value);
		void remove_beforevalue(const string & value);
		void remove_aftervalue(const string & value);
		void reverse();
		void display();
	private:
		stringnode* head;
};
linkedlist::linkedlist():head(NULL){};
linkedlist::~linkedlist(){
	while(!empty()) removefront();
}
bool linkedlist::empty() const{
	return(head==NULL);
}
const string & linkedlist::front() const{
	return(head->elem);
}
void linkedlist::addfront(const string & e){
	stringnode*v= new stringnode;
	v->elem=e;
	if (head==NULL){
		head=v;
		v->next=NULL;
	}
	else{
		v->next=head;
		head=v;	
	}
} 
void linkedlist::add_atend(const string & e){
	stringnode*v=new stringnode;
	v->elem=e;
	v->next=NULL;
	if(head==NULL){
		head=v;
	}
	else{
		stringnode*p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=v;
	}
	
}
void linkedlist::add_atindex(const string & e,int index){
	stringnode*v=new stringnode;
	v->elem=e;
	v->next=0;
	if(head==NULL){
		head=v;
	}
	else if(index==0){
		addfront(e);
	}
	else{
		stringnode*p=head;
		int counter=0;
		while(p->next!=NULL && counter!=index-1){
			p=p->next;
			counter++;
		}
		if(counter==index-1){
			v->next=p->next;
			p->next=v;	
		}
		else{
			cout<<"Wrong index passed!";
		}
		
	}
} 
void linkedlist::add_afterindex(const string & e,int index){
	stringnode*v=new stringnode;
	v->elem=e;
	v->next=0;
	if(head==NULL){
		head=v;
	}
	else{
		stringnode*p=head;
		int counter=0;
		while(p->next!=NULL && counter!=index){
			p=p->next;
			counter++;
		}
		if(counter==index){
			v->next=p->next;
			p->next=v;		
		}
		else{
			cout<<"Wrong index passed";
		}
	
	} 	
}
void linkedlist::add_afterval(const string & e,const string & value){
	stringnode*v=new stringnode;
	v->elem=e;
	v->next=0;
	if(head==NULL){
		head=v;
	}
	else{
		stringnode*p=head;
		while(p->next!=NULL && p->elem!=value){
			p=p->next;
		}
		if(p->elem==value){
			v->next=p->next;
			p->next=v;		
		}
		else{
			cout<<"The value you are trying to acceess is wrong!"<<endl;
		}
	}
}
void linkedlist::add_beforeval(const string & e,const string & value){
	stringnode*v=new stringnode;
	v->elem=e;
	v->next=0;
	if(head==NULL){
		head=v;
	}
	else{
		stringnode*p=head;
		stringnode*r=NULL;
		while(p->next!=NULL && p->elem!=value){
			r=p;
			p=p->next;
		}
		if(r!=NULL && p->elem==value){
			v->next=p;
			r->next=v;		
		}
		else if(r==NULL && p->elem==value){
			addfront(e);
		}
	}	
}

void linkedlist::removefront(){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		stringnode*old=head;
		head=old->next;
		delete old;	
	}
}
void linkedlist::remove_atend(){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		stringnode*r;
		stringnode*d=head;
		while(d->next!=NULL){
			r=d;
			d=d->next;
		}
		delete d;
		r->next=0;
	}
}
void linkedlist::remove_atindex(int index){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		int counter=0;
		stringnode*d=head;
		stringnode*r=NULL;
		while(d->next!=NULL && counter!=index){
			r=d;
			d=d->next;
			counter++;
		}
		if(r==NULL && counter==index){
			removefront();
		}
		else if(counter==index){
			r->next=d->next;
			delete d;		
		}
		else{
			cout<<"The index you are tring to delete is wrong!"<<endl;
		}
		
	}
}
void linkedlist::remove_beforeindex(int index){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else if(index==0){
		cout<<"There is no element before 0th index."<<endl;
	}
	else{
		int counter=0;
		stringnode*d=head;
		stringnode*r;
		while(d->next!=NULL && counter!=index-1){
			r=d;
			d=d->next;
			counter++;
		}
		if(counter==index-1){
			r->next=d->next;
			delete d;	
		}
		else{
			cout<<"Wrong index passed!"<<endl;
		}
	}	
}
void linkedlist::remove_afterindex(int index){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		int counter=0;
		stringnode*d=head;
		stringnode*r;
		while(d->next!=NULL && counter!=index+1){
			r=d;
			d=d->next;
			counter++;
		}
		if (counter==index+1){
			r->next=d->next;
			delete d;	
		}
		else{
			cout<<"Wrong index passed!"<<endl;
		}
	}
}
void linkedlist::remove_value(const string & value){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		stringnode*r=NULL;
		stringnode*d=head;
		while(d->next!=NULL && d->elem!=value){
			r=d;
			d=d->next;
		}
		if(r!=NULL && d->elem==value){
			r->next=d->next;
			delete d;		
		}
		else if(r==NULL && d->elem==value){
			removefront();
		}
		else{
			cout<<"The value you are tring to delete is wrong!"<<endl;
		}
	}
}
void linkedlist::remove_beforevalue(const string & value){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		stringnode*r=NULL;
		stringnode*d=head;
		stringnode*q=d->next;
		while(d->next!=NULL && q->elem!=value && d->elem!=value){
			r=d;
			d=d->next;
			q=q->next;
		}
		if(r!=NULL && q->elem==value){
			r->next=q;
			delete d;
		}	
		else if(r==NULL && q->elem==value){
			removefront();
		}
		else{
			cout<<"There is no element before this value!"<<endl;
		}			
	}
}
void linkedlist::remove_aftervalue(const string & value){
	if (empty()==1)
		cout<<"Error! The list is empty!";
	else{
		stringnode*r=NULL;
		stringnode*d=head;
		while(d->next!=NULL && d->elem!=value){
			d=d->next;
		}
		if(d->next!=NULL && d->elem==value){
			r=d->next;
			d->next=r->next;
			delete r;	
		}
		else{
			cout<<"Wrong value passed!"<<endl;
		}
	}
}

void linkedlist::reverse(){
	stringnode*d=head;
	int counter=0;
	while (d->next!=NULL){
		if(counter==n-counter)
		d=d->next;
	}

}

void linkedlist::display(){
	stringnode*d=head;
	while(d!=NULL){
		cout<<d->elem<<"->";
		d=d->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	linkedlist a;
	int ch1,ch2,ch3;
	char choice='y';
	
	cout<<"Hello, welcome to Menu-driven program of SINGLY LINKED LIST!"<<endl;
	cout<<endl;
	cout<<"If you want to create a new LL press 1 and if you want an already created LL press 2: ";
	cin>>ch1;
	cout<<endl;
	if (ch1==1){
		int n;
		string str;
		cout<<"Enter the number of elements you want to enter: ";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Enter the "<<i+1<<" element: ";
			cin>>str;
			a.addfront(str);
		}
	}
	else{
		a.addfront("3");
		a.addfront("5");
		a.addfront("4");	
	}
	cout<<"The Linked List is: "<<endl;
	a.display();
	cout<<endl;
	while (choice=='y'||choice=='Y'){
	cout<<"Operations you can perform:-"<<endl;
	cout<<"Enter 1 for INSERTION."<<endl;
	cout<<"Enter 2 for DELETION."<<endl;
	cout<<"Enter 3 for REVERSAL."<<endl;
	cout<<"Enter 4 for DISPLAY."<<endl;
	cout<<"To perform these operations on your LL enter your choice: ";
	cin>>ch2;
	if(ch2==1){
		cout<<"Enter 1 to insert an element at front."<<endl;
		cout<<"Enter 2 to insert an element at end."<<endl;
		cout<<"Enter 3 to insert an element at a particular index."<<endl;
		cout<<"Enter 4 to insert an element after a particular index."<<endl;
		cout<<"Enter 5 to insert an element before a particular value."<<endl;
		cout<<"Enter 6 to insert an element after a particular value."<<endl;
		cout<<"To perform these insertions enter your choice: ";
		cin>>ch3;
		if(ch3==1){
			string s;
			cout<<"Enter the element you want to add: ";
			cin>>s;
			a.addfront(s);
			cout<<"LL after Insertion is: ";
			a.display();
		}
		else if(ch3==2){
			string s;
			cout<<"Enter the element you want to add: ";
			cin>>s;
			a.add_atend(s);
			cout<<"LL after Insertion is: ";
			a.display();			
		}
		else if(ch3==3){
			string s;
			int in;
			cout<<"Enter the element you want to add: ";
			cin>>s;
			cout<<"Enter the index: ";
			cin>>in;
			a.add_atindex(s,in);
			cout<<"LL after Insertion is: ";
			a.display();			
		}
		else if(ch3==4){
			string s;
			int in;
			cout<<"Enter the element you want to add: ";
			cin>>s;
			cout<<"Enter the index: ";
			cin>>in;
			a.add_afterindex(s,in);
			cout<<"LL after Insertion is: ";
			a.display();			
		}
		else if(ch3==5){
			string s;
			string val;
			cout<<"Enter the element you want to add: ";
			cin>>s;
			cout<<"Enter the value: ";
			cin>>val;
			a.add_beforeval(s,val);
			cout<<"LL after Insertion is: ";
			a.display();			
		}
		else if(ch3==6){
			string s;
			string val;
			cout<<"Enter the element you want to add: ";
			cin>>s;
			cout<<"Enter the value: ";
			cin>>val;
			a.add_afterval(s,val);
			cout<<"LL after Insertion is: ";
			a.display();			
		}	
	}
	else if(ch2==2){
		cout<<"Enter 1 to delete an element at front."<<endl;
		cout<<"Enter 2 to delete an element at end."<<endl;
		cout<<"Enter 3 to delete an element at a particular index."<<endl;
		cout<<"Enter 4 to delete an element after a particular index."<<endl;
		cout<<"Enter 5 to delete an element before a particular index."<<endl;
		cout<<"Enter 6 to delete an element with a particular value."<<endl;
		cout<<"Enter 7 to delete an element before a particular value."<<endl;
		cout<<"Enter 8 to delete an element after a particular value."<<endl;
		cout<<"To perform these deletions enter your choice: ";
		cin>>ch3;		
		if(ch3==1){
			a.removefront();
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==2){
			a.remove_atend();
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==3){
			int in;
			cout<<"Enter the index: ";
			cin>>in;
			a.remove_atindex(in);
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==4){
			int in;
			cout<<"Enter the index: ";
			cin>>in;
			a.remove_afterindex(in);
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==5){
			int in;
			cout<<"Enter the index: ";
			cin>>in;
			a.remove_beforeindex(in);
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==6){
			string val;
			cout<<"Enter the value: ";
			cin>>val;
			a.remove_value(val);
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==7){
			string val;
			cout<<"Enter the value: ";
			cin>>val;
			a.remove_beforevalue(val);
			cout<<"LL after deletion is: ";
			a.display();
		}
		else if(ch3==8){
			string val;
			cout<<"Enter the value: ";
			cin>>val;
			a.remove_aftervalue(val);
			cout<<"LL after deletion is: ";
			a.display();
		}
	}
	else if(ch2==3){
		a.reverse();
	}
	else{
		a.display();	
	}
	cout<<"Do you want to continue?(y/n)";
	cin>>choice;
	if(choice=='n'||choice=='N'){
		cout<<"Byee!";
		break;
	}	
	}
	
}
