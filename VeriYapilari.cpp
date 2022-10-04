#include<iostream>
using namespace std;


//Hasan Genis 201713171060
//Kod DevC++ ile derlenmistir


const int MAX = 10;

class Dugum {
	
	public:
		int veri;   // listedeki dugumm icersindeki veriyi tutacak.
		
		Dugum *sonraki;     //sonraki d���m adresi tutan eleman
		Dugum *geri;
		
		Dugum(){};     //kurucu fonksiyon
		
		Dugum(int a) {		//ilk eleman ekleyen kurucu fonksiyon
			
			veri = a;
			sonraki = 0;
		}
	
	int veriDondur() {   //veri dond�rmek icin fonkisyon
		
		return veri;
	}	
};

class Liste {
	

		Dugum *gecici;  //gecici bir adres tutma 
		int elemanSayisi;

	public:
		Dugum *bas;		//ilk d���m�n adresi
		Dugum *son;		//son d���m�n adresi
	
		void yigin(){
			elemanSayisi =0;
			gecici = NULL;
		}
		
		Liste() {
			
			bas = 0;
			son = 0;
		}
		
		Liste(int a) {  	//listeye ilk d���m ekleme 
			
			Dugum *p = new Dugum(a);
			bas = son = p;
		}
		
		 void ekle(int a)
      {
           if(bas == 0) // liste bo� ise
           {
                  bas = new Dugum(a);  
                  son = bas;  
				  elemanSayisi++;         
           }
           else // e�er listede d���m var ise
           {
               Dugum *yeniDugum = new Dugum(a); // yeni d���m olu�turulur. 
               (*son).sonraki = yeniDugum;   
               son = yeniDugum;   
			   elemanSayisi++;          
           }
           cout<<"dugum basariyla eklendi."<<endl;                 
      }
      
       void yiginYazdir() // yigini  yazd�r�r.
      {
           Dugum *temp; 
           temp = bas; 
          
           if( bas!= 0 )  // listede eleman varsa                     
           {
               while( temp != 0 )  // liste bitene kadar
               {
                  cout<<"\t| "<<(*temp).veriDondur()<<" | "<<endl;
				  cout<<"\t ----"<<endl; 
                  temp = (*temp).sonraki;        
               }
               cout<<endl;
			            }
           else
           cout<<"listede eleman bulunmamaktadir.";
      }
      
      void kuyrukYazdir() { //kuyrugu yazdirir.
      	
		  Dugum *temp; 
           temp = bas; 
          
           if( bas!= 0 )  // listede eleman varsa                     
           {
               while( temp != 0 )  // liste bitene kadar
               {
                  cout<<"| "<<(*temp).veriDondur()<<"| "; 
                  temp = (*temp).sonraki;        
               }
               cout<<endl;
			            }
           else
           cout<<"listede eleman bulunmamaktadir.";
      	
	  }
	  
	  void elemansayisi(){		//listedeki eleman sayisini g�sterir.
	  	cout<<"Eleman Sayisi: ";
			   cout<<elemanSayisi-1<<endl; 
	  }
      
		void herseyiSil() {
			
			bas = son = 0;  	//bas� ve sonu s�f�ra e�itlersek ortada g�sterilecek eleman kalmaz.
		}  
		
		 
		 
		 void aradanSilme(int a)
      {
           Dugum *temp = 0;
           Dugum *birOnceki = 0;
          
           if( bas != 0 )  // e�er liste bo� de�ilse
           {
               temp = bas;  
              
               while( (*temp).sonraki != 0 && (*temp).veriDondur() != a ) // listenin sonuna kadar VE sayi bulunana kadar
               {
                      birOnceki = temp;  
                      temp = (*temp).sonraki; 
               }
              
               if( (*temp).veriDondur() == a ) // e�er silinecek eleman listede bulunuyorsa
               {
                   if( bas == son )   // listede tek eleman varsa
                   {
                       bas = son = 0;  // liste bo�alt�ld�.
                   }
                  
                   else if(birOnceki == 0) // silinecek eleman en ba�ta ise 
                   {
                        bas = (*bas).sonraki;
                   }
                  
                   else // silinecek eleman arada ise
                   {
                        (*birOnceki).sonraki = (*temp).sonraki;
                   }
                  
                   if ( temp == son ) // silinecek eleman en sonda ise
                   {
                        son = birOnceki;
                   }
                 
                   cout<<"dugum basariyla silindi."<<endl;               }
              
               else
               {
                   cout<<"silmek istediginiz eleman listede bulunamadi..."<<endl;               }     
           } 
      }
      
      void arayaEkle(Dugum *bas, Dugum *yeni,int index) {   
 
      	for(int i = 0;i<index;i++)
      		bas = bas->sonraki;
      		yeni->sonraki = bas->sonraki;
      		bas->sonraki = yeni;	  
	  }	
};

struct dugum 
{
	
	int sayi;
	dugum *sol;
	dugum *sag;
};	
struct tree
{
	dugum *kok;
	int elemanSayisi;			//eleman say�s� g�sterecek fonksiyon
	void agacOlusturma();		//aga� olu�turma
	void sil(dugum *);			//silme fonksiyonu
	void ekle(dugum *);			//eleman ekleme fonksiyonu
	void yazdirInorder();      
	void yazdirPreorder();
	void yazdirPostorder();
	void preorder(dugum *);
    void inorder(dugum *);
    void postorder(dugum *);
	void temizleme();			//genel temizleme fonksiyonu
};

void tree::temizleme() //agactaki t�m elemanlari temizleme
{
	kok = NULL;
}	


void tree::preorder(dugum *p) //preorder yazdirma  k�k-sol-sag
{
	if(p){
        cout << p->sayi << "  ";
        preorder(p->sol);
        preorder(p->sag);
    }
}

void tree::inorder(dugum *p){	//inorder yazdirma sol-k�k-sa�
    if(p){
        inorder(p->sol);
        cout << p->sayi << "  ";
        inorder(p->sag);
    }
}

void tree::postorder(dugum *p){	//postorder yazdirma sol-sa�-k�k
    if(p){
        postorder(p->sol);
        postorder(p->sag);
        cout << p->sayi << "  ";
    }
}

void tree::agacOlusturma(){		//agac olusturma 
    kok = NULL;
    
    cout << "Agac olusturuldu" <<endl;
}
int elemansayisi = 0;






void tree::ekle(dugum *eklenecek){
    bool eklendi = false;
    dugum *tara; dugum *yeni = new dugum;
    tara = kok;
    *yeni = *eklenecek; yeni->sol = NULL; yeni->sag = NULL;
  
    if(kok == NULL){		//kok bo�sa ilk eleman� eklemi� oluruz
        kok = yeni;
        cout << "Ilk eleman eklendi ! (" << kok->sayi << ")"<<endl;
        elemansayisi++;
        return;
    }
    while((tara != NULL) && (!eklendi))
    {
        if( yeni->sayi < tara->sayi)  
        {
            if(tara->sol != NULL) { tara = tara->sol; }
            else
            {
                cout << tara->sayi << " dugumunun soluna " << yeni->sayi << " elemani eklendi." << endl;
                tara->sol = yeni;
                eklendi = true;
            }
        }
        else if ( yeni->sayi > tara->sayi)
        {
          if(tara->sag != NULL) tara = tara->sag;
          else
          {
              cout << tara->sayi << " dugumunun sagina " << yeni->sayi << " elemani eklendi" << endl;
              tara->sag = yeni;
              eklendi = true;
          }
        }else { cout << "Ayni eleman zaten agacta bulunmakta" << endl;  return;} 		
    }
    if(eklendi == true) { elemansayisi++; }
    cout << "PREORDER :\t\t"; preorder(kok);		//preorder yazd�rma
    cout << endl;
    cout << "INORDER :\t\t"; inorder(kok);			//inorder yazd�rma
    cout << endl;
    cout << "POSTORDER :\t\t"; postorder(kok);		//postoreder yazd�rma
    cout << endl;
}



void tree::sil(dugum *eklenecek){  		//sayiyi �nce agacta arayip bulunca silme i�lemi yapan fonksiyon
dugum *tara;
tara = kok;
bool bulundu = false;
int kacinci = 1;
cout << "ARADIGIM : " << eklenecek-> sayi <<endl ;
while((tara != NULL) && !bulundu){
  if(eklenecek->sayi < tara->sayi)
  {
    tara = tara->sol;
    kacinci++;
  }
  else if(eklenecek->sayi > tara->sayi)
  {
      tara = tara->sag;
      kacinci++;
  }
  else { cout << "girilen sayi " << eklenecek->sayi << " aranan eleman" << tara->sayi << kacinci << ".denemede bulundu. " << endl;  return;}
}
cout << "Agacta bulunmayan bir deger aratt�n. " << endl;

delete tara;  
}


void tree::yazdirInorder() 				//inorder yazdirma 
{	
	cout << "INORDER :\t\t"; inorder(kok);
    cout << endl;
}

void tree::yazdirPreorder()				//preorder yazdirma 
{
	cout << "PREORDER :\t\t"; preorder(kok);
    cout << endl;	
}

void tree::yazdirPostorder()  			//postorder yazdirma 
{
	cout << "POSTORDER :\t\t"; postorder(kok);
	cout << endl;		
}

int elemanHashsayisi = 0;

class Node
{
	public:
	int data;
	int Anahtar;
	Node* pSonraki;
	Node(int Anahtar)
	{
		this->Anahtar = Anahtar;
		pSonraki = NULL;
	}
	
	int dataDondur() {
		return data;
	}
	
};

class HashTablosu
{

	public:
		Node *key;
		HashTablosu();		
		Node* Veri[MAX];
		void Ekle(int Anahtar);			//eleman ekleme fonksiyonu
		Node* Bul(int Anahtar);			//bulma fonksiyonu
		void Sil(int Anahtar);		//silme fonksiyonu
		void tabloYazdir();			//yazd�rma fonksiyonu
		void tabloTemizleme();		//tabloyu temizleme fonksiyonu
};	

HashTablosu::HashTablosu()
{
	for(int i = 0;i < MAX; i++)
		Veri[i] = NULL;
}

void HashTablosu::Ekle(int Anahtar)
{
	Node* pYeni = new Node(Anahtar);
	int mod = Anahtar % MAX;
	
	if(!Veri[mod])
	{
		Veri[mod] = pYeni;
		elemanHashsayisi++;
		return;	
	}
	
	Node* pTemp = Veri[mod];
	while(pTemp->pSonraki != NULL)		//son elemana kadar gezme i�lemi
	{
		pTemp = pTemp->pSonraki;	
	}	
	
	pTemp->pSonraki = pYeni;	
	
	elemanHashsayisi++;
}

Node* HashTablosu::Bul(int Anahtar)
{
	int mod = Anahtar % MAX;
	Node* pTemp = Veri[mod];
	
	while(pTemp != NULL)		//arad��m�z� bulmam�za yarayan fonksiyon
	{
		if(pTemp->Anahtar == Anahtar)
			return pTemp;
		
		pTemp = pTemp->pSonraki;
		
	}	
	return NULL;		//arad�g�m�z� bulamad�ysak �yle bir�ey yoktur	
}

void HashTablosu::Sil(int Anahtar)
{
	
	int mod = Anahtar % MAX;
	if(!Veri[mod]) return;		//hi� eleman yoksa
	if(!Veri[mod]->pSonraki)
	{
		if(Veri[mod]->Anahtar == Anahtar)
		{
			delete Veri[mod];
			Veri[mod] = NULL;
		}
		return;
	}
	
	if(Veri[mod]->Anahtar == Anahtar)
	{
		Node* pDon = Veri[mod]->pSonraki;
		delete Veri[mod];
		Veri[mod] = pDon;
		return;	
	}
	
	Node* pTemp = Veri[mod];
	while(pTemp->pSonraki != NULL)
	{
		if(pTemp->pSonraki->Anahtar == Anahtar)
		{
			Node* pDon = pTemp->pSonraki;
			pTemp->pSonraki = pDon->pSonraki;
			delete pDon;
			return;
		}	
		pTemp = pTemp->pSonraki;	
	}				
}

void HashTablosu::tabloYazdir() {
	
Node *temp;
	temp = key;
	
	if(key != 0)  //eleman say�s� s�f�r de�ilse
	{
		
		while ( temp != 0) //liste bitene kadar
		{
			cout<<"Elemanlar: "<<(*temp).dataDondur()<<"|";
			temp = (*temp).pSonraki;
		}
		cout<<endl;
	}
	
	else
	cout<<"Listede eleman yok!";		

}

void HashTablosu::tabloTemizleme() {
	

	
	Veri[MAX] = 0;

	
}







int main()
{
	Liste liste;
	int a;
	tree tree1;
	
	HashTablosu hTablo;
	
	
	while(1) {

	int sayi;
	cout<<"Yapmak istediginiz uygulamayi seciniz:"<<endl;
	cout<<"1-Yigin Uygulamasi"<<endl;
	cout<<"2-Kuyruk Uygulamasi"<<endl;
	cout<<"3-Tek Yonlu Bagli Liste Uygulamasi"<<endl;
	cout<<"4-Ikili Agac Uygulamasi"<<endl;
	cout<<"5-Cirpilama Uygulamasi"<<endl;
	cout<<"6-Programdan Cikis"<<endl;
	cin>>sayi; 
	
	switch(sayi)
	{
		case 1: 
			cout<<"Yigin icin islem seciniz:"<<endl;
			cout<<"1-Yigina eleman ekle"<<endl;
			cout<<"2-Yigindan eleman cikar"<<endl;
			cout<<"3-Yigini temizle"<<endl;
			cout<<"4-Yigindaki elemanlari goster"<<endl;
			cout<<"5-Yigindaki eleman sayisini goster"<<endl;
			cout<<"6-Ana menuye geri don"<<endl;
			
			int sayi2;
			cin>>sayi2;
	
			switch(sayi2)
			{
				case 1: {
						cout<<"1-Yigina eklenecek elemani giriniz:"<<endl;
						cin>>a;
						liste.ekle(a);
							
						cout<<"Eleman yigina basariyla eklendi."<<a<<endl;
						
				break;
			}
				case 2: {
					cout<<"Lutfen son elemani giriniz: "<<endl;
					
				cin>>a;	
				liste.aradanSilme(a);
							
				break;
			}
				case 3:{
					cout<<"3-Yigini temizle "<<endl;	
					liste.herseyiSil();
				break;
			}
				case 4:	{
					cout<<"4-Yigindaki elemanlar gosteriliyor..."<<endl;
					
					liste.yiginYazdir();	
				}
				break;
				
				case 5:{
					cout<<"5-Yigindaki eleman sayisi: "<<endl;
					liste.elemansayisi();		
				break;
		}
				case 6:
					cout<<"6-Ana menuye geri don"<<endl;		
				break;					
			}
				
		break;
		
		case 2:
			cout<<"Kuyruk icin islem seciniz:"<<endl;
			cout<<"1-Kuyruga eleman ekleme"<<endl;
			cout<<"2-Kuyruktan eleman cikar"<<endl;
			cout<<"3-Kuyrugu temizle"<<endl;
			cout<<"4-Kuyruktaki elemanlari goster"<<endl;
			cout<<"5-Kuyruktaki eleman sayisini goster"<<endl;
			cout<<"6-Ana menuye don"<<endl;
			
			int sayi3;
			cin>>sayi3;
			
			switch(sayi3) {
				
				case 1: {
					cout<<"Kuyruga eklenecek elemani giriniz:"<<endl;
					
					cin>>a;
					liste.ekle(a);
					
					cout<<"Eleman kuyruga basariyla eklendi."<<a<<endl;
				break;
			}
				case 2:{
					cout<<"Lutfen ilk elemani giriniz:"<<endl;
					cin>>a;
					liste.aradanSilme(a);
				break;
			}
				case 3:{
					cout<<"3-Kuyrugu temizle "<<endl;
					liste.herseyiSil();
				break;
			}
				case 4:{
					cout<<"4-Kuyruktaki elemanlari goster"<<endl;
					liste.kuyrukYazdir();	
				break;
			}
				case 5:{
					cout<<"5-Kuyruktaki eleman sayisini goster"<<endl;
					liste.elemansayisi();
				break;
			}
				case 6:
				cout<<"6-Ana menuye don sectin"<<endl;
				break;	
				
			}
			
		break;
		
		case 3:
			cout<<"Bagli Liste icin islem seciniz:"<<endl;
			cout<<"1-Listeye eleman ekleme"<<endl;
			cout<<"2-Listeden eleman cikarma"<<endl;
			cout<<"3-Listeyi temizle"<<endl;
			cout<<"4-Listedeki elemanlari goster"<<endl;
			cout<<"5-Listedeki eleman sayisini goster"<<endl;
			cout<<"6-Ana menuye don"<<endl;
			
			int sayi4;
			cin>>sayi4;
			
			switch(sayi4) {
				
				case 1:
					cout<<"Ekleme turunu seciniz:"<<endl;
					cout<<"1-Araya eleman ekle"<<endl;
					cout<<"2-Sona eleman ekle"<<endl;
					cout<<"3-Liste islemlerine geri don"<<endl;	
					
					int sayi5;
					cin>>sayi5;
					
					switch(sayi5) 
					{
						case 1: {
							
							cout<<"1-Araya eklenecek elemani giriniz:"<<endl;
						
						//liste.arayaEkle(d1,c,a);	
						break;
					}
						case 2:{
							cout<<"2-Sona eklenecek elemani giriniz:"<<endl;
							cin>>a;
						liste.ekle(a);
						break;
				}
						case 3:
						cout<<"3-Liste islemlerine geri don"<<endl;
						break;	
						
					}
				break;
				
				case 2:
					cout<<"Cikarma turunu seciniz:"<<endl;
					cout<<"1-Aradan eleman cikar"<<endl;
					cout<<"2-Sondan eleman cikar"<<endl;
					cout<<"3-Liste islemlerine geri don"<<endl;	
					
					int sayi6;
					cin>>sayi6;
					
					switch(sayi6)
					{
						case 1: {
							cout<<"1-Aradan cikarmak istediginiz elemani giriniz: "<<endl;
							cin>>a;
							liste.aradanSilme(a);							
						
						break;
					}
						case 2:{
							cout<<"Lutfen son elemani giriniz:"<<endl;
							cin>>a;
							liste.aradanSilme(a);
						break;
					}
						case 3:
							cout<<"3-Liste islemlerine geri don"<<endl;	
						break;	
					}
					
				break;
				
				case 3:{
					cout<<"3-Listeyi temizle"<<endl;
					liste.herseyiSil();
				break;
		}
				case 4:
					cout<<"4-Listedeki elemanlari goster "<<endl;
					liste.kuyrukYazdir();
				break;
			
				case 5:{
					cout<<"5-Listedeki eleman sayisini goster "<<endl;
					liste.elemansayisi();
				break;
			}
				case 6:
					cout<<"6-Ana menuye don "<<endl;
				break;	
				
			}	
			
		break;
		
		case 4:
			
			cout<<"1-Agaca Eleman Ekle"<<endl;
			cout<<"2-Agactan Eleman Sil"<<endl;
			cout<<"3-Agacic Temizle"<<endl;
			cout<<"4-Agactaki Eleman Sayisini goster"<<endl;
			cout<<"5-Agaci InOrder dolasarak Elemanlari Goster"<<endl;
			cout<<"6-Agaci PreOrder dolasarak Elemanlari Goster"<<endl;
			cout<<"7-Agaci PostOrder dolasarak Elemanlari Goster"<<endl;
			cout<<"8-Ana menuye geri don"<<endl;
			
			int sayi7;
			cin>>sayi7;	
			
			switch(sayi7){
				
				case 1: {
					cout<<"Agaca eklenecek eleman sayisini giriniz: ";
				
					int eklenecek;
					cin>>eklenecek;
				
					typedef tree veriyapisi;		
   					veriyapisi kayit;
    				dugum yenikayit;
    				kayit.agacOlusturma();		//agac yap�s� olu�turuyorum
  			
  					cout<<"Agaca eklenecek elemani giriniz: ";
					  	
     				for(int i=1;i<=eklenecek ;i++){  		//kullan�c�dan kac eleman girece�ini al�p d�ng�ye sokuyorum
   					 cout << endl << "Eleman : ";
    				cin>>yenikayit.sayi;
    				kayit.ekle(&yenikayit);			//al�nan degeri agaca ekleme yap�yorum
    			}
		
					break;
				}
				
				case 2: {
					
				
				//	tree1.sil();
					
					break;
				}
				
				case 3:{
					
					tree1.temizleme(); 
					cout<<"Agactaki t�m elemanlar silindi."<<endl;
					break;
				}
				
				case 4:{
					
					cout<<"Eleman Sayisi: "<< elemansayisi <<endl; //eleman sayisi yazdirma
					
					
					break;
				}
				
				case 5:{
				
					tree1.yazdirInorder();
				
					break;
				}
				
				case 6:{
					
					tree1.yazdirPreorder();
					
					break;
				}
				
				case 7:{
					
					tree1.yazdirPostorder();
					
					break;
				}
				
				case 8:{
					
					
					break;
				}
				
				
				
			}		
		
			
		break;
		
		case 5:{
			
			cout<<"1-Hash Tabloya Eleman Ekle"<<endl;
			cout<<"2-Hash Tablodan Eleman Sil"<<endl;
			cout<<"3-Hash Tabloyu Temizle"<<endl;
			cout<<"4-Hash Tablodaki Eleman Sayisini goster"<<endl;
			cout<<"5-Hash Tablodaki Elemanlari goster"<<endl;
			cout<<"6-Ana menuye geri don"<<endl;
			
			int sayi9;
			cin>>sayi9;
			
			switch(sayi9){
				
				case 1:{
					
					cout<<"Eklenecek Sayiyi Giriniz: "<<endl;				
					int a;
					cin>>a;
					
					hTablo.Ekle(a);
					
					break;
				}
				
				case 2: {
					
					int b;
					cin>>b;
					cout<<"Silmek istediginiz elemani giriniz: "<<endl;
					hTablo.Sil(b);
					cout<<"Eleman basariyla silindi."<<endl;
					
					break;
				}
				
				case 3:{
					
					hTablo.tabloTemizleme();
					cout<<"Tablo temizlendi..."<<endl;
					
					
					break;
				}
				
				case 4:{
					
					cout<<"Eleman Sayisi: "<< elemanHashsayisi <<endl;
					
					
					break;
				}
				
				case 5:{
					
					cout<<"Elemanlar: "<<endl;
					hTablo.tabloYazdir();
					
				
					
					
					break;
				}
				
				case 6:{
					
					cout<<"Programdan Cikiliyor..."<<endl;
					return 0;	
					
					break;
				}
				
			}
		
			break;
		}
	
		case 6:
			cout<<"Programdan Cikiliyor..."<<endl;
			return 0;
		break;		
	}

  }
	return 0;	
} 
