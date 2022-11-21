#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char nama[30];
	char nim[30];
	struct node* link;
}NODE;

NODE * Front=NULL;
NODE * Rear=NULL;
NODE * newNode;

void enqueue(){
	newNode=(NODE*)malloc (sizeof (NODE));
	printf("Masukkan nama anda : ");fflush(stdin);
	fgets(newNode->nama, 30, stdin);
	printf("Masukkan NIM anda : ");fflush(stdin);
	fgets(newNode->nim, 30, stdin);
	newNode->link=NULL;
	
	if(Rear==NULL){
		Front=Rear=newNode;
		Rear->link=Front;
	}else{
		Rear->link=newNode;
		Rear=newNode;
		Rear->link=Front;
	}
}

void dequeue(){
	NODE *temp=Front;
	if(Front==NULL && Rear==NULL){
		printf("Maaf saat ini QUEUE tidak ada data/kosong\n");
	}else if(Front==Rear){
		Front=Rear=NULL;
		free(temp);
	}else{
		Front=Front->link;
		Rear->link=Front;
		free(temp);
	}
}

void display(){
	NODE *temp=Front;
	int jum;
	int i=0;
	if(Front==NULL && Rear==NULL){
		printf("Maaf saat ini QUEUE tidak ada data/kosong\n");
	}else{
	do{
		printf("Antrian %d\t NIM = %s\n",i++ + 1, temp->nim);
		printf("\t\t Nama = %s\n", temp->nama);
//		jum = i;
		temp=temp->link;	
	}while(temp!=Rear->link);
	printf("Jumlah Antrian sekarang : %d",i);
	printf("\n\n");
	}
}

void displayRear(){
	if(Front==NULL && Rear==NULL){
		printf("Maaf saat ini QUEUE tidak ada data/kosong\n");
	}else{
	printf("\nNIM = %s\n",Rear->nim);
	printf("Nama = %s\n",Rear->nama);
	}
}

void displayFront(){
	if(Front==NULL && Rear==NULL){
		printf("Maaf saat ini QUEUE tidak ada data/kosong\n");
	}else{
	printf("\nNIM = %s\n",Front->nim);
	printf("Nama = %s\n",Front->nama);
	}
}

int main(){
	int pilihan;
	
	do{
		printf("\n============================================\n");
		printf("DAFTAR MENU\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Display data antrian paling terakhir\n");
		printf("5. Display data antrian paling depan\n");
		printf("6. Exit\n");
		printf("\n============================================\n");	
		
		printf("Masukkan pilihan menu yang anda inginkan : ");
		scanf("%d",&pilihan);
		
		if(pilihan==1){
			enqueue();
		}else if(pilihan==2){
			dequeue();
		}else if(pilihan==3){
			display();
		}else if(pilihan==4){
			displayRear();
		}else if(pilihan==5){
			displayFront();
		}
	}while(pilihan!=6);
	printf("\nTERIMAKASIH SUDAH MENGGUNAKAN PROGRAM INI");
}
