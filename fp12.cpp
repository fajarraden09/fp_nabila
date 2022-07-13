#include <iostream> 
#include <stdlib.h> 
#define max 100 
using namespace std; 

struct buku{ 
	int top; 
    int kode[max], pinjam[max];
    string judul[max], pengarang[max] ,penerbit[max], tahun[max];
}book;



void awal(){ 
    book.top = -1;
}

bool isEmpty(){ 
    if(book.top == -1){
        return 1;
    }else{
        return 0;
    }
}

bool full(){ 
    if(book.top == max-1){
        return 1;
    }else{
        return 0;
    }
}

void input(){ 
    cout<<"\t\t\t INPUT BUKU"<<endl;
    cout<<"\t================================================"<<endl;
    if(isEmpty()==1){ 

        book.top++;
        cout<<"\n\tMasukkan Kode \t\t : "; cin>>book.kode[book.top];
        cout<<"\n\tMasukkan Judul \t\t : "; cin>>book.judul[book.top];
        cout<<"\n\tMasukkan Pengarang \t : "; cin>>book.pengarang[book.top];
        cout<<"\n\tMasukkan Penerbit \t : "; cin>>book.penerbit[book.top];
        cout<<"\n\tMasukkan Tahun Terbit \t : "; cin>>book.tahun[book.top];
        book.pinjam[book.top]=0;
    } else if(full()==0){ 
        book.top++;
		 cout<<"\n\tMasukkan Kode \t\t : "; cin>>book.kode[book.top];
        cout<<"\n\tMasukkan Judul \t\t : "; cin>>book.judul[book.top];
        cout<<"\n\tMasukkan Pengarang \t : "; cin>>book.pengarang[book.top];
        cout<<"\n\tMasukkan Penerbit \t : "; cin>>book.penerbit[book.top];
        cout<<"\n\tMasukkan Tahun Terbit \t : "; cin>>book.tahun[book.top];
    }else{
        cout<<"\n\t\t\tDATA PENUH";
    }
    cout<<endl<<endl<<endl;
	system("cls");
}

void sorting(){  
    int tempKode, tempPinjam; 
    string tempJudul, tempPengarang, tempPenerbit, tempTahun;
    for(int i=0; i<=book.top; i++)
    {
        for(int j=i+1; j<=book.top; j++)
        {
            if(book.kode[i]>book.kode[j])
            {
                tempKode=book.kode[i];
                tempJudul=book.judul[i];
                tempPengarang=book.pengarang[i];
                tempPenerbit=book.penerbit[i];
                tempTahun=book.tahun[i];
                tempPinjam=book.pinjam[i];

                book.kode[i]=book.kode[j];
                book.judul[i]=book.judul[j];
                book.pengarang[i]=book.pengarang[j];
                book.penerbit[i]=book.penerbit[j];
                book.tahun[i]=book.tahun[j];
                book.pinjam[i]=book.pinjam[j];

                book.kode[j]=tempKode;
                book.judul[j]=tempJudul;
                book.pengarang[j]=tempPengarang;
                book.penerbit[j]=tempPenerbit;
                book.tahun[j]=tempTahun;
                book.pinjam[j]=tempPinjam;
            }
         }
    }
}

void hapus(){ 
    int hapus;
    cout<<"\t\t\tHAPUS BUKU"<<endl;
    cout<<"\t================================================"<<endl;
    if(isEmpty()==0){
        cout<<"\n\tKode Buku :  ";cin>>hapus;
        for(int a=0; a<=book.top; a++){
            if(book.kode[a]==hapus){
                book.kode[a]=book.kode[book.top]+1;
                sorting();
                book.top--;
                cout<<"\n\tBuku " <<hapus<< " Telah Terhapus !"<<endl;
            }
        }
    }else{
        cout<<"\n\t\t DATA KOSONG";
    }
    cout<<endl<<endl<<endl<<endl;
}
void tampil(){ 
	int  z;
	cout<<endl;
	cout<<endl;
    cout<<"=================================================== DAFTAR BUKU ===================================================\n\n";
    cout<<"||\tNomor\t||\tKode\t||\tJudul\t||\tNama Pengarang\t||\tNama Penerbit\t||\tTahun\t||\n";
    z = 0;
	sorting();
    for(int i=0; i<=book.top; i++){
		z = z + 1;
        cout<<"===================================================================================================================\n";
        cout<<"||\t"<<z<<"\t||";
        cout<<book.kode[i]<<"\t\t||";
        cout<<book.judul[i]<<"\t\t||";
        cout<<book.pengarang[i]<<"\t\t\t||";
        cout<<book.penerbit[i]<<"\t\t\t||";
        cout<<book.tahun[i]<<"\t\t||";
		cout<<endl;
    }
	cout<<"===================================================================================================================\n";
    if(book.top==-1){
        cout<<"\n\t\tTIDAK ADA DATA BUKU"<<endl;
    }
    cout<<endl<<endl<<endl<<endl;
}
 
void searching(){ 
    int cari, x=0;
    cout<<"\t\t\tCARI BUKU "<<endl;
      cout<<"\t================================================"<<endl;
      cout<<"\n\tMasukkan Kode Buku : "; cin>>cari;
      for(int i=0; i<=book.top; i++){
        if(book.kode[i]==cari){
        cout<<"\n\n\t Judul \t\t: "<<book.judul[i];
        cout<<"\n\t Pengarang \t: "<<book.pengarang[i];
        cout<<"\n\t Penerbit \t: "<<book.penerbit[i];
        cout<<"\n\t Tahun \t\t: "<<book.tahun[i];
        x=1;
		}
    }
    if(x==0){
        cout<<"\n\tBUKU YANG DICARI TIDAK ADA";
    }
	cout<<endl;
	cout<<endl;
}



struct TNode{
    string judul, nama, nim;
    TNode *next; 
};

TNode *head = NULL; //
TNode *currentNode = NULL;

void init(){ 
    head = NULL;
    currentNode = NULL;
}


int Empty() 
{
    if(head==NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insert(){
	TNode *baru = NULL;
	baru=new TNode;
	
	cout << "\n\tJudul \t: "; cin >> baru->judul;
	cout << "\n\tNama \t: "; cin >> baru->nama;
	cout << "\n\tNIM \t: "; cin >> baru->nim;
	baru->next=NULL; 
		
	if(Empty()==1){ 
		head=baru;
		head->next=NULL;
		cout << "\n\tData Masuk!!!" << endl;
	} else {
		currentNode->next = baru;
		cout << "\n\n\tData Masuk....... " << endl;
	}
	currentNode = baru;//
	currentNode->next=NULL;//
	cout << endl << endl << endl << endl << endl;
}

void tampil1(){
	TNode *i = head;
	cout << "\t\t\tTAMPIL" << endl;
	cout << "\t=====================================" << endl;
	
	if(Empty()==0){
		while (i != NULL) { 
			cout << " \tJudul\t: "<< i->judul << endl;
			cout << " \tNama\t: "<< i->nama << endl;
			cout << " \tNIM\t: " << i->nim << endl;
			cout << "\t=====================================" << endl;
			i=i->next; 
		}
	}else{
		cout << "\n\t\tDATA MASIH KOSONG";
	} cout << endl << endl << endl << endl << endl;
}

void hapusdepan()
{
	if(!isEmpty())
	{
		TNode *hapus = head;
		head = head->next;
		delete hapus;
		cout << endl;
		cout << endl;
		cout<<"\t\tHAPUS DATA PINJAM DEPAN"<<endl;
		cout<<"\t================================================"<<endl;
        cout<<"\tData pinjam bagian depan telah terhapus!!!\n";
	}else{
		cout<<"Masih kosong\n";
	}
}
void hapussemua()
{
    TNode *bantu, *hapus;
    bantu = head; 
    
    while (bantu->next != currentNode)
    {
        hapus = bantu;
        bantu = bantu->next; 
        delete hapus;
    }
    head = NULL;
    currentNode = NULL;
	cout << endl;
	cout << endl;
	cout<<"\t\tHAPUS SEMUA PEMINJAM BUKU"<<endl;
    cout<<"\t================================================"<<endl;
    cout << "\tDaftar Pinjam berhasil dikosongkan!!!\n" << endl << endl;
}

int main(){
	awal();
	int pilihan, pil, pil2, x=0, kode;
	system("cls");
	menu:
	cout << " " << endl;
	cout << "|================================================================================================|" << endl;
	cout << " " << endl;
	
	cout<<"'::::::::::::::::'####################:::::::::::::::'"<<endl;
	cout<<" :::::::::::::::'#                 # #::::::::::::::: "<< "\t  <======= Perpustakaan =======> "<<endl;
	cout<<" ::::::::::::::'###################  ##:::::::::::::: "<<endl;
	cout<<" :::::::::::::::'# -------------- # # #:::::::::::::: "<< "\t <============ MENU  ============> "<<endl;
	cout<<" ::::::::::::::'####################  ###:::::::::::: "<<endl;       
	cout<<" ::::::::::::'#####################  ##  #::::::::::: "<<"\t 1. Kelola buku"<<endl;
	cout<<" :::::::::::::'# ----------       # ##   #::::::::::: "<<endl;
	cout<<" ::::::::::::: #      ----- ---   ###   #:::::::::::: "<<"\t 2. Baca Buku"<<endl;
	cout<<" ::::::::::::'######################   #::::::::::::: "<<endl;
	cout<<" ::::::::::'#######################   #:::::::::::::: "<<"\t 3. Keluar"<<endl;
	cout<<" :::::::::::'#-----   ----      --#  #::::::::::::::: "<<endl;
	cout<<" ::::::::::: #     ---   -------  # #:::::::::::::::: "<<endl;
	cout<<" ::::::::::'########################::::::::::::::::: "<<endl;
	cout << " " << endl;
	cout << "|================================================================================================|" << endl;
	cout << " " << endl;
		cout << "\tMasukkan pilihan : "; cin >> pilihan;
		system("cls");
		
		switch(pilihan){
		case 1:
		system("cls");
		do{
			cout<<"               <~~~~~~~~~~~~~~~~~~ KELOLA BUKU ~~~~~~~~~~~~~~~~~~~>"<<endl;
			cout<<"               v                                                  v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   1. Input                                       v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   2. Tampil                                      v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   3. Hapus                                       v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   4. Kembali                                     v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>"<<endl;
			cout << "\tMasukkan pilihan : "; cin >> pil;
			switch(pil){
				case 1:
					system("cls");
					input();
					break;
				case 2:
					system("cls");
					tampil();
					break;
				case 3:
					system("cls");
					hapus();
					break;	
				case 4:
				system("cls");
				goto menu;
		}
		} while(pil!=4);
		return 0;
		
		case 2:
		    system("cls");
			cout<<"               <~~~~~~~~~~~~~~~~~~~ BACA BUKU ~~~~~~~~~~~~~~~~~~~~>"<<endl;
			cout<<"               v                                                  v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   1. Cari                                        v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   2. Pinjam                                      v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   3. Daftar Pinjam                               v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   4. Hapus depan                                 v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   5. Hapus Semua                                 v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               v   6. Kembali                                     v"<<endl;
			cout<<"               ^                                                  ^"<<endl;
			cout<<"               <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>"<<endl;
			cout << "\tMasukkan pilihan : "; cin >> pil2;
			
			if (pil2==1) {
				system("cls");
				searching();
			} else if (pil2==2) { 
				system("cls");
				cout<<" <~~~~~~~~~~~~~~~~~~~ PINJAM BUKU ~~~~~~~~~~~~~~~~~~~~>"<<endl;
				cout << "\t=====================================" << endl;
				cout << "\tMasukkan kode : "; cin >> kode;
						for(int i=0; i<=book.top; i++){
							if(book.kode[i]==kode){
						    	if(book.pinjam[i]==0){
							        insert();
							        x=1;
						        }
				    	    }
				        }
				if(x==0){
				    cout << "\n\t\t\tBUKU TIDAK TERSEDIA";
					cout << endl << endl << endl << endl << endl;
				}
			} else if (pil2==3) {
				system("cls");
				tampil1();
			}else if (pil2==4) {
			    system("cls");
			    hapusdepan();
			}else if (pil2==5) {
			     system("cls");
			    hapussemua();
			} else if (pil2==6) {
				system("cls");
				goto menu;
			} else {
			    cin.get();
			    goto menu;
			}
			
			cin.get();
			goto menu;
			
	}
	

}