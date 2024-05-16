#include <iostream>
#include <vector>
#include <string>

using namespace std;

class miasto{
    private:
     string nazwa_miasta;
    int mieszkancy;
    string nazwa_panstwa;
    public:
   string returnMiasta(){
    return nazwa_miasta;
   }
    miasto(string a, int b, string c){
        this->nazwa_miasta = a;
        this->mieszkancy = b;
        this->nazwa_panstwa = c;
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

    void kasujto(){
        
    }
};

class panstwo{
    private:
    string nazwa_panstwa;
   
    public:
    string jopek(){
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



int main(){
  
    panstwo* kraj = new panstwo("Polska");
    string temp3;
    int temp2;
    string nazwa;
    int liczba;
    
    miasto* temp = new miasto("Warszawa", 100000,kraj->jopek());
    kraj->miasta.emplace_back(temp);
   temp = new miasto("Radom", 1,kraj->jopek());
    kraj->miasta.emplace_back(temp);
   temp = new miasto("Kazimierz", 2,kraj->jopek());
    kraj->miasta.emplace_back(temp);

cout<<"Nazwa miasta\n";
cin>>nazwa;
cout<<"liczba mieszkancow\n";
cin>>liczba;
temp = new miasto(nazwa, liczba,kraj->jopek());
    kraj->miasta.emplace_back(temp);

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
           cout<<"j1"<<endl;
            kraj->miasta[q]->modyfikacja(modmia,modmie);
            cout<<"j2"<<endl;
            break;
            
        }
        q++;
        }



    int m =0;
    while (m<kraj->miasta.size())
    {
        kraj->miasta[m]->printMiastoBezEnter();
        m++;
    }

    }



