#include <iostream>
using namespace std;

template <typename T>
class ArrayList{

public:
    int marime;
    int limita;
    T* valori;

    ArrayList(){
        this->limita = 10;
    }
    ArrayList(int limita){
        this->limita = limita;
    }
};

int main(){

    ArrayList<int> test(100);
    cout<<test.limita;


    return 0;
}
