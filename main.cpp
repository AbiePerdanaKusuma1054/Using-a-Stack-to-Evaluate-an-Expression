/*Anggota Kelompok :
Ridho Alrafi 1817051009
Eggy Bintang Negara 1817051013
Yuan Ferdinand A. Kailuhu 1817051014
Abie Perdana Kusuma 1817051054*/

#include <iostream>
using namespace std;

struct node{
	char element;
	node *next;
};
//Deklarasi Stack
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
//Fungsi untuk mengecek nilai operator *dan/ > +dan-
int cek(char cekoprtr){	
	if(cekoprtr=='*'||cekoprtr=='/')
		return 2;
	else
		return 1;
}

int main(){
	stack S; //Stack yang bernama S
	int i=0,n=0,A,B,C;
	char postfix[20]; //Deklarasi postfix
	char infix[20]; //Deklarasi infix
	
	cin>>infix;
	while(infix[i]!='\0'){ //Selama belum mencapai akhir dari infix
		if(isdigit(infix[i])){ //Jika di infix ditemukan angka
			postfix[n]=infix[i]; //Masukkan ke dalam postfix
			n++;
		}
		else if(infix[i]=='('){ //Jika di infix ditemukan "("
			S.pushtostack(infix[i]); //Masukkan ke dalam S
		}
		else if(infix[i]==')'){ //Jika di infix ditemukan ")"
			while(!S.isEmpty() && S.top()!='('){ //Selama S tidak kosong DAN elemen pertama S bukan "("
				postfix[n]=S.popfromstack(); //Keluarkan elemen pertama S lalu masukkan ke dalam postfix
				n++;
			}
			S.popfromstack(); //Keluarkan "(" dari S lalu buang/hilangkan
		}
		else{ //Jika di infix ditemukan Operator
			if(S.isEmpty() || S.top()=='('){ //Jika S kosong ATAU elemen pertama S adalah "("
				S.pushtostack(infix[i]); //Masukkan ke dalam S
			}
			else{
				while(!S.isEmpty() && S.top()!='(' && cek(infix[i])<=cek(S.top())){ /*Selama S tidak kosong DAN elemen
												pertama S bukan "(" DAN operator yang 
												ditemukan nilainya lebih kecil dari
												operator [elemen pertama] di S*/
					postfix[n]=S.popfromstack(); //Keluarkan elemen pertama S lalu masukkan ke postfix
					n++;
				}
				S.pushtostack(infix[i]); //Masukkan operator yang ditemukan ke dalam S
			}
		}
		i++;
	}
	while(!S.isEmpty()){ //Selama S tidak kosong
		postfix[n]=S.popfromstack(); //Keluarkan seluruh elemen di S lalu masukkan ke postfix
		n++;
	}
	n=0;
  	while(postfix[n]!='\0'){  //Selama belum mencapai akhir dari postfix
    		if(isdigit(postfix[n])){ //Jika di postfix ditemukan angka
				S.pushtostack(postfix[n]); //Masukkan ke dalam S
			}
	  	else{ //Jika di postfix ditemukan operator
		 		A=S.popfromstack()-'0'; /*Keluarkan elemen pertama  S lalu jadikan A [pengurangan dengan'0' digunakan 
							untuk merubah elemen yang dikeluarkan dari S yg bertipe char agar nantinya dapat
							dioperasikan]*/
		 		B=S.popfromstack()-'0'; /*Keluarkan elemen pertama  S lalu jadikan B [pengurangan dengan '0' digunakan 
							untuk merubah elemen yang dikeluarkan dari S yg bertipe char agar nantinya dapat 
							dioperasikan]*/
				if(postfix[n]=='*'){ //Jika operator yg ditemukan adalah *
					C=B*A; //operasikan
					S.pushtostack(C+'0'); /*Hasil dari operasinya dimasukkan ke S [penambahan dengan '0' digunakan
								untuk merubah kembali menjadi bertipe char*/
		  		}
      				else if(postfix[n]=='/'){ //Jika operator yg ditemukan adalah /
			 		C=B/A;
		 			S.pushtostack(C+'0');
		  		}
				else if(postfix[n]=='+'){ //Jika operator yg ditemukan adalah +
			 		C=B+A;
					S.pushtostack(C+'0');	
		  		}
				else if(postfix[n]=='-'){ ////Jika operator yg ditemukan adalah -
					C=B-A;
					S.pushtostack(C+'0');
		  		}
				else{
					cout<<"Stack tidak ada"<<endl;
		  		}
			}
	  	n++;
  	}
	cout<<S.popfromstack()-'0'; /*tampilkan elemen yg dikeluarkan dari S [pengurangan dengan'0' digunakan untuk merubah elemen yang 
					dikeluarkan dari S yg bertipe char*/
	return 0;
}
