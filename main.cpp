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

    void add(T* x){
        cout<<"x size = "<<sizeof(x)/sizeof(T)<<endl;
        int marimeaX = sizeof(x) + 1;
        cout<<marimeaX<<endl;
        cout<<endl;
        for(int i = 0; i < marimeaX; i++)
            cout<<x[i]<<" ";
        cout<<endl;

        T copieValori[this->limita];
        for(int i = 0; i < this->limita; i++){
            copieValori[i] = this->valori[i];
        }
        this->valori = new T[limita + marimeaX + 1];
        for(int i = 0; i < this->limita; i++){
            this->valori[i] = copieValori[i];
        }
        this->limita = this->limita + marimeaX + 1;

        for(int i = 0; i <  marimeaX; i++){
            this->valori[i + this->marime] = x[i];
        }
        this->marime = this->marime + marimeaX;
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

int main(){

    ArrayList<int> test(10);
    test.add(1);
    test.add(6);
    test.add(7);
    cout<<test.getSize()<<endl;
    test.print();
    int v[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    test.add(v);
    cout<<test.getSize()<<endl;
    test.print();

    return 0;
}
