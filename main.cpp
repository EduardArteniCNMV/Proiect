#include <iostream>
using namespace std;

template <typename T>
class ArrayList{

public:
    int marime = 0;
    int limita;
    T* valori;

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

int main(){

    ArrayList<int> test(10);
    test.add(1);
    test.add(6);
    test.add(7);
    test.print();
    cout<<test.get(1)<<endl;
    cout<<test.get(7)<<endl;




    return 0;
}
