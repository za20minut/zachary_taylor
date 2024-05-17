#include <iostream>
#include <vector>
#include <string>

using namespace std;

class miasto{
    private:
     string nazwa_miasta;
    int mieszkancy;
    string nazwa_panstwa;
    string nazwa_kontynentu;
    public:
   string returnMiasta(){
    return nazwa_miasta;
   }
    miasto(string a, int b, string c,string d){
        this->nazwa_miasta = a;
        this->mieszkancy = b;
        this->nazwa_panstwa = c;
        this->nazwa_kontynentu = d;
    }

    void printMiasto() {
        cout<<this->nazwa_miasta<<endl;
        cout<<this->mieszkancy<<endl;
    }

    void printMiastoBezEnter() {
        cout<<this->nazwa_miasta<<" ";
        
    }

    void modyfikacja(string g,int h){

        this->nazwa_miasta = g;
        this->mieszkancy = h;
    }

    
};

class panstwo{
    private:
    string nazwa_panstwa;
   
    public:
    string returnNazwaPanstwa(){
        return nazwa_panstwa;
    }
     vector<miasto*> miasta;
    panstwo(string a){
        this->nazwa_panstwa = a;
    }
    
    void printPanstwo(){
         cout<<this->nazwa_panstwa<<endl;
    }
};

class kontynent {
   

    private:
    string nazwa_kontynentu;
    public:
    string returnKontynent(){
    return nazwa_kontynentu;
   }
   kontynent(string a){
    this->nazwa_kontynentu = a;
   }


   vector<panstwo> panstwa;
};





void dodawanie(){
    string nazwa;
    int liczba;
cout<<"Nazwa miasta\n";
cin>>nazwa;
cout<<"liczba mieszkancow\n";
cin>>liczba;
temp = new miasto(nazwa, liczba,kraj->returnNazwaPanstwa(),kont->returnKontynent());
    kraj->miasta.emplace_back(temp);

   

}





void usuwanie(){

string usumiasto;
 cout << "Jakie miasto usunac\n";
    cin>> usumiasto;
  int g = 0;
    while(g < kraj->miasta.size()){
        if(kraj->miasta[g]->returnMiasta() == usumiasto){

            kraj->miasta.erase(kraj->miasta.begin()+g);
            
            
            
            break;
        }   
        g++;
    }
}




void modyfikacja(){
string mod;
cout<<"ktore zmodyfikowac?"<<endl;
    cin>>mod;
    int q = 0;
    string modmia;
    int modmie;
    cout<<"nazwa miasta"<<endl;
    cin>>modmia;
     cout<<"mieszkancy"<<endl;
    cin>>modmie;
    while(q < kraj->miasta.size()){
       
        if(kraj->miasta[q]->returnMiasta() == mod){
         
            kraj->miasta[q]->modyfikacja(modmia,modmie);
           
            break;
            
        }
        q++;
        }
}




void odczyt(){
    string temp3;
 cout << "Jakie miasto\n";
    cin>> temp3;
  int n = 0;
    while(n < kraj->miasta.size()){
        if(kraj->miasta[n]->returnMiasta() == temp3){
            kraj->miasta[n]->printMiasto();
            kraj->printPanstwo();
            
            
            break;
        }   
        n++;
    }
}





void drzewko(){
    int m =0;
    while (m<kraj->miasta.size())
    {
        kraj->miasta[m]->printMiastoBezEnter();
        m++;
    }
}
int main(){
    kontynent* kont = new kontynent("Europa");
    panstwo* kraj = new panstwo("Polska");
    panstwo* kraj2 = new panstwo("Litwa");
    panstwo* kraj3 = new panstwo("Lotwa");

    kont->panstwa.emplace_back(kraj);
    kont->panstwa.emplace_back(kraj2);
    kont->panstwa.emplace_back(kraj3);
    string temp3;
    int temp2;
    string nazwa;
    int liczba;
    
    miasto* temp = new miasto("Warszawa", 100000,kraj->returnNazwaPanstwa(),kont->returnKontynent());
    kraj->miasta.emplace_back(temp);
   temp = new miasto("Radom", 1,kraj->returnNazwaPanstwa(),kont->returnKontynent());
    kraj->miasta.emplace_back(temp);
    temp = new miasto("Wilno", 600000,kraj2->returnNazwaPanstwa(),kont->returnKontynent());
    kraj->miasta.emplace_back(temp);
    temp = new miasto("Riga", 450000,kraj3->returnNazwaPanstwa(),kont->returnKontynent());
    kraj->miasta.emplace_back(temp);
    temp = new miasto("Dyneburg", 50000,kraj3->returnNazwaPanstwa(),kont->returnKontynent());
    kraj->miasta.emplace_back(temp);












































    }



