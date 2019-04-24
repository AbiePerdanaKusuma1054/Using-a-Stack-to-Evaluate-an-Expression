#include <iostream>
using namespace std;

struct node{
	char element;
	node *next;
};

class stack{
	private:
		node *head=NULL;
	public:
		bool isEmpty(){
			if(head==NULL)
				return true;
			return false;
			}
		void pushtostack(char a){
			node *baru=new node;
			baru->element=a;
			baru->next=NULL;
			if(isEmpty()){
				head=baru;
			}
			else{
				baru->next=head;
				head=baru;
			}
		}
    	char popfromstack(){
			if(isEmpty()){
				cout<<"Stack kosong!"<<endl;
			return 0;
			}
      		else{
				char ch=head->element;
				node *tmp=head->next;
				delete head;
				head=tmp;
				return ch;
			}
		}
		char top(){
			return head->element;
		}	
    	void cetak(){
			if(isEmpty()){
				cout<<"Stack Kosong!";
			}
      		else{
				node *bantu=head;
				while(bantu!=NULL){
					cout<<bantu->element<<endl;
					bantu=bantu->next;
				}
			}
		}    
};

int cek(char cekoprtr){	
	if(cekoprtr=='*'||cekoprtr=='/')
		return 2;
	else
		return 1;
}

int main(){
	stack S;
	int i=0,n=0,A,B,C;
	char postfix[20];
	char infix[20];
