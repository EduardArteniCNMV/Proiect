#include <iostream>
using namespace std;

template <typename T>
class ArrayList{

private:
    int marime = 0;
    int limita;
    T* valori;

public:

    int getSize(){
        return this->marime;
    }

    void add(T* x, int sizeofx){
        T copieValori[this->limita];
        for(int i = 0; i < this->limita; i++){
            copieValori[i] = this->valori[i];
        }
        this->valori = new T[limita + sizeofx + 1];
        for(int i = 0; i < this->limita; i++){
            this->valori[i] = copieValori[i];
        }
        this->limita = this->limita + sizeofx + 1;

        for(int i = 0; i <  sizeofx; i++){
            this->valori[i + this->marime] = x[i];
        }
        this->marime = this->marime + sizeofx;

    }

    void add(T x){
        if(this->marime==this->limita){
            T copieValori[this->limita];
            for(int i = 0; i < this->limita; i++){
                copieValori[i] = this->valori[i];
            }
            this->valori = new T[limita + 10];
            for(int i = 0; i < this->limita; i++){
                this->valori[i] = copieValori[i];
            }
            this->limita = this->limita+10;

        }
        this->valori[marime] = x;
        this->marime++;
    }

    T get(int index){
        if(index >= marime){
            return NULL;
        }
        return valori[index];
    }

    void print(){
        cout<<"[";
        for(int i = 0; i < this->marime; i++){
            if(i < this->marime - 1){
                cout<<this->valori[i]<<", ";
            }else{
                cout<<this->valori[i];
            }
        }
        cout<<"]"<<endl;
    }

    ArrayList(){
        this->limita = 10;
        this->valori = new T[10];
    }
    ArrayList(int limita){
        this->limita = limita;
        this->valori = new T[limita];
    }
};

class String{

};

int main(){

    ArrayList<bool> test(10);
    bool v[]= {true,false,false,true,1,2,1,1,1,1,1,0};
    test.add(v, sizeof(v)/sizeof(bool));
    test.add(23);
    test.print();

    return 0;
}
