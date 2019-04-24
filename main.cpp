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
