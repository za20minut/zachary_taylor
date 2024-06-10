#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>

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
   int returnMieszkancy(){
    return mieszkancy;
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

    vector<string> returnMiasta(){
        vector<string>miasta;
        for (int i = 0; i < this->miasta.size(); i++)
        {
            miasta.push_back(this->miasta[i]->returnMiasta());

        }
            return miasta;  
    }

};
panstwo* currentDir=nullptr;
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


   vector<panstwo*> panstwa;

   void printKontynent(){
    cout<<this->nazwa_kontynentu<<endl;
   }
};


void changeDir(kontynent* &a,panstwo* &b) {
    string input, input2;
    
    cout << "podaj nazwe panstwa\n";
    cin >> input;
    
    for(auto kraj : a->panstwa) {
        if(kraj->returnNazwaPanstwa() == input) {
           b = kraj;
            return;
        }
    }
}

void PolskiChangerDir(kontynent* &a,panstwo* &b){
   string input, input2;
    
   
     input="Polska";
    
    for(auto kraj : a->panstwa) {
        if(kraj->returnNazwaPanstwa() == input) {
           b = kraj;
            return;
        }
    } 
}

void LitewskiChangerDir(kontynent* &a,panstwo* &b){
   string input, input2;
    
   
     input="Litwa";
    
    for(auto kraj : a->panstwa) {
        if(kraj->returnNazwaPanstwa() == input) {
           b = kraj;
            return;
            
        }
    } 
}




void LotewskiChangerDir(kontynent* &a,panstwo* &b){
   string input, input2;
    
   
     input="Lotwa";
    
    for(auto kraj : a->panstwa) {
        if(kraj->returnNazwaPanstwa() == input) {
           b = kraj;
            return;
        }
    } 
}




void dodawanie(kontynent* &a, panstwo* &b){
    string nazwa;
    int liczba;
cout<<"Nazwa miasta\n";
cin>>nazwa;
cout<<"liczba mieszkancow\n";
cin>>liczba;
miasto* temp = new miasto(nazwa, liczba,b->returnNazwaPanstwa(),a->returnKontynent());
    b->miasta.emplace_back(temp);

   

}





void usuwanie( panstwo* &b){

string usumiasto;
 cout << "Jakie miasto usunac\n";
    cin>> usumiasto;
  int g = 0;
    while(g < b->miasta.size()){
        if(b->miasta[g]->returnMiasta() == usumiasto){

            b->miasta.erase(b->miasta.begin()+g);
            
            
            
            break;
        }   
        g++;
    }
}




void modyfikacja( panstwo* &b){
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
    while(q < b->miasta.size()){
       
        if(b->miasta[q]->returnMiasta() == mod){
         
            b->miasta[q]->modyfikacja(modmia,modmie);
           
            break;
            
        }
        q++;
        }
}




void odczyt(kontynent* &a, panstwo* &b){
    string temp3;
 cout << "Jakie miasto\n";
    cin>> temp3;
  int n = 0;
    while(n < b->miasta.size()){
        if(b->miasta[n]->returnMiasta() == temp3){
            b->miasta[n]->printMiasto();
            b->printPanstwo();
            a->printKontynent();
            
            
            break;
        }   
        n++;
    }
}





void drzewko(kontynent* &a, panstwo* &b){
    a->printKontynent();
    for(auto  c: a->panstwa) {
        cout<<endl<<c->returnNazwaPanstwa()<<" ";
        for (auto  h: c->miasta)
        {
            h->printMiastoBezEnter();
       }
        
        
    } 
}

bool got(vector<string> &tog, string &a){

    for (auto &hog:tog)
    {
        if (hog==a)
        {
            return false;
        }
        
    }
    return true;
}





void save(kontynent* &a, panstwo* &b){


    ofstream f ("plik.txt");
if (f.is_open())
{
   
for(auto  c: a->panstwa) {
        
        for (auto  h: c->miasta)
        {
           f<< h->returnMiasta()<<","<<h->returnMieszkancy()<<";";
       }
       f<<'\n'; 
        
    } 




    f.close();
}


}





void load(kontynent* &a, panstwo* &b){

    ifstream inf("plik.txt");
    cout << "1\n";
if (inf.is_open())
{
    string temp,temp2,temp3;
    string line;
    vector<string> loaded;
    
    

for(int countCountries=0;countCountries < 3; countCountries++)
{
   getline(inf,line);
        stringstream ss(line);
        while(getline(ss, temp, ';')){

        stringstream ss2(temp);
        while(getline(ss2, temp2, ',')) {
                loaded.push_back(temp2);
            }
    }

    for(int i = 0; i < loaded.size(); i+=2){
        vector<string>temp=a->panstwa[countCountries]->returnMiasta();
        if (got(temp,loaded[i]))
        a->panstwa[countCountries]->miasta.push_back(new miasto(loaded[i], stoi(loaded[i+1]),a->panstwa[countCountries]->returnNazwaPanstwa(),a->returnKontynent()));
    }
    //clear
    loaded.clear();
            }
        }
    }








   // string nazwa;
  //  int liczba;

//miasto* temp = new miasto(nazwa, liczba,b->returnNazwaPanstwa(),a->returnKontynent());
    //b->miasta.emplace_back(temp);




  


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
    panstwo* cd=new panstwo("");

    PolskiChangerDir(kont,cd);
    miasto* temp = new miasto("Warszawa", 100000,cd->returnNazwaPanstwa(),kont->returnKontynent());
    cd->miasta.emplace_back(temp);
    temp = new miasto("Radom", 1,cd->returnNazwaPanstwa(),kont->returnKontynent());
    cd->miasta.emplace_back(temp);
    LitewskiChangerDir(kont,cd);
    temp = new miasto("Wilno", 600000,cd->returnNazwaPanstwa(),kont->returnKontynent());
    cd->miasta.emplace_back(temp);
    LotewskiChangerDir(kont,cd);
    temp = new miasto("Riga", 450000,cd->returnNazwaPanstwa(),kont->returnKontynent());
    cd->miasta.emplace_back(temp);
    temp = new miasto("Dyneburg", 50000,cd->returnNazwaPanstwa(),kont->returnKontynent());
    cd->miasta.emplace_back(temp);


    
   
   
    
  //  for(auto  b: kont->panstwa) {
   //     cout<<b->returnNazwaPanstwa()<<" "<<endl;
  //      for (auto  a: b->miasta)
   //     {
  //          a->printMiastoBezEnter();
   //    }
        
        
  //  } 



changeDir(kont,cd);


while (true)
{
   


string kom;
cout<<endl<<"save-zapisywanie"<<endl<<"load-wczytywanie"<<endl<<"cd-zmiana wezla"<<endl<<"mo-dodawanie obiektu"<<endl<<"do-usuwanie obiektu"<<endl<<"mdo-modyfikacja obiektu"<<endl<<"show-wyswietlenie informacji"<<endl<<"tree-wyswietlenie drzewka"<<endl<<"0=wyjdz"<<endl;
cin>>kom;
if (kom=="load")
{
    load(kont,cd);
}

if (kom=="save")
{
    save(kont,cd);
}

if(kom=="cd"){
changeDir(kont,cd);
}
if (kom=="mo")
{
  dodawanie(kont,cd);  
}
if (kom=="do")
{
    usuwanie(cd);
}
if (kom=="mdo")
{
    modyfikacja(cd);
}
if (kom=="show")
{
    odczyt(kont,cd);
}
if (kom=="tree")
{
    drzewko(kont,cd);
}
if(kom=="0"){
    break;
}

}


    }



